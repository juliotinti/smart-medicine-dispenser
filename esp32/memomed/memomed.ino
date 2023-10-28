#include <Servo.h>
#include <dummy.h>
#include <Arduino_JSON.h>
#include <WebServer.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <String.h> 
#include <cstring>


// change this to whichever pin you want to use
int buzzer = 4;

//Passo
const int DIR = 12;
const int STEP = 14;
float variavel = 2.2; 
int fixo = 2000;

float cons_gavetas[2]= {2.2,0.6};

int gavetas[2] = {0,0};

int records[2] = {0,0};

 
//Fim de curso
const int FIM = 19;
bool homeFeito=false;

//Servo
static const int servoPin = 13;  // defines pin number for PWM
Servo servo1;
float tempoCentoOitenta = 360*180/188;
float tempoUmRemedio = tempoCentoOitenta*55/180;
float offset = tempoCentoOitenta*20/180;
float offsetVolta = tempoCentoOitenta*5/180;
float entrePas = tempoCentoOitenta*267.5/180;

//Wi-Fi
const char* ssid = "beterraba"; //wifi local
const char* password = "1234567890";
//const char* ssid = "Huawei 2102 2.4G"; //wifi local
//const char* password = "tanapared3";

//Banco de Dados
String allMeds = "https://memomed-acc.herokuapp.com//esp32-med";
String getID = "https://memomed-acc.herokuapp.com//get-user/memomed@123.com";
const char* serverName = "https://memomed-acc.herokuapp.com/esp32-medshedule/2";
const char* getEspMed = "https://memomed-acc.herokuapp.com/getesp";
const char* endEspRecord = "https://memomed-acc.herokuapp.com/endesp/";
char* httpesp_get;
String meds;
String ID;
unsigned long lastTime = 0;
unsigned long timerDelay = 2000; 
String sensorReadings;

String sensorReadingsEND ;
float IDArr[10];
float sensorReadingsArr[3][12];
JSONVar keys;
JSONVar myObject;
JSONVar nome;
JSONVar value;

int drawer = 0;
int totalRemedio = 12; 
int qtsFaltam = 0; 
String proximaDose = " "; 
bool deleted = false; 

void girarServo(int direc, float delay_)
{
  servo1.attach(servoPin);
  servo1.write(direc);
  delay(delay_);
  servo1.detach();
  delay(500);
}

void descerPasso(int gaveta)
{
  digitalWrite(DIR, HIGH);
  for(int i = 0; i<cons_gavetas[gaveta-1]*fixo; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(700);
    digitalWrite(STEP, LOW);
    delayMicroseconds(700);
  }  
}

void subirPasso()
{
  digitalWrite(DIR, LOW);
  while (digitalRead(FIM)==HIGH)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(700);
    digitalWrite(STEP, LOW);
    delayMicroseconds(700); 
  } 
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void setup()
{
  Serial.begin(115200);
  girarServo(180, offset); 
  Serial.print("Conecting...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  };
  pinMode(FIM, INPUT_PULLUP);
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  subirPasso();
}

void loop() 
{
 if ((millis() - lastTime) > timerDelay) 
 {
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED)
  {
            
    sensorReadings = httpGETRequest(getEspMed);
    Serial.println(sensorReadings);
    JSONVar myObject = JSON.parse(sensorReadings);

    // JSON.typeof(jsonVar) can be used to get the type of the var
    if (JSON.typeof(myObject) == "undefined") 
    {
      Serial.println("Parsing input failed!");
      return;
    }
  
    Serial.print("JSON object = ");
    Serial.println(myObject);
  
    // myObject.keys() can be used to get an array of all the keys in the object
    JSONVar keys = myObject.keys();
    JSONVar keys2 = myObject[0].keys();
    Serial.print("Lenght:");
    Serial.println(myObject.length());
 
    
    for (int j = 0; j<myObject.length();j++)
    {
      Serial.println(myObject[j]);
      gavetas[j]= myObject[j]["Drawer"];
      records[j]= myObject[j]["RecordID"];
   }

  Serial.println("Comecando movimentacao do motor"); 

  for (int i=0; i<2;i++)
  {
    Serial.println(gavetas[i]);
    if (gavetas[i] != 0)
    {
     
      descerPasso(gavetas[i]); 
      delay(1000);
      gavetas[i] = 0;
      girarServo(180, tempoUmRemedio);
      girarServo(0, entrePas+1.48*tempoUmRemedio);
      girarServo(180, entrePas-0.65*tempoUmRemedio);
      delay(1000);
      subirPasso(); 
      tone(buzzer, 500, 15000);
      delay(15000);
      String httpesp = endEspRecord + String(records[i]);
      httpesp_get = (char*)malloc(httpesp.length()+1);
      strcpy (httpesp_get, httpesp.c_str());
      sensorReadingsEND  = httpGETRequest(httpesp_get);    
    }
  }
  
    
  }
  else 
  {
    Serial.println("WiFi Disconnected");
  }
  lastTime = millis();
  }


}
