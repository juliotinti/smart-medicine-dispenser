# MemoMed Project

## Introduction
Non-compliance or non-adherence to prescribed medical treatments is a significant clinical, social, and economic issue, affecting the quality of life of patients and increasing healthcare costs, impacting the general population. For chronic diseases such as diabetes and hypertension, the World Health Organization estimates an average of 50% non-adherence to treatments (CHISHOLM-BURNS et al., 2012).

In the United States, this problem is associated with 125,000 deaths, 10% of hospitalizations, and annual losses ranging from 100 to 290 billion dollars (ZULIG et al., 2018). In Europe, the financial burden exceeds 1.25 billion euros (CUTLER et al., 2018).

This project aims to address the issue of medication non-adherence and offer an affordable, low-cost solution to assist patients, especially the elderly, in adhering to their medication regimens.

## Features
- Programmable medication schedules: Users can set specific times for medication intake.
- Alarm notifications: The device provides audio and visual alerts to remind users to take their medications.
- User-friendly interface: The accompanying web portal allows users to easily manage their medication schedules and receive reminders.

## Repository Structure

The repository is organized as follows:

- `flask`: contains the code for web page.
- `3dModel`: contains the 3D models of the project.
- `esp32`: contains the ESP32 code.  

## Usage
1. Access the MemoMed web portal in your browser.
2. Create an account and log in.
3. Add your medications to the system, specifying the medication name, dosage, and schedule.
4. Connect the MemoMed device to a power source and ensure it is connected to the internet.
5. The device will automatically sync with the web portal and start dispensing medications according to the programmed schedule.
6. When it's time to take your medication, the device will emit an audio and visual alert.
7. Repeat the process for each scheduled medication intake.

## Technology

The following technologies were used in this project:

- 3D modelling: used to model how the project would be. 
- ESP32: used to deliver the medicine based on the web service call. 
- Flask: used to create the web page and jobs.
- AWS RDS: used to persist data related to user and medicines.
- Heroku: used to deploy the web page. 

## Results

The physical implementation looks as the following:

<p align="center"> <img src="https://iili.io/Jfqy5F4.png" width="400" height="600"/>  <img src="https://iili.io/JfqyUiJ.jpg" width="400" height="600"/> </p>

The medicine is pushed by the rotary movement of the motor until it falls into the region that the user has access to.

<p align="center"> <img src="https://iili.io/JfB3hla.png" width="300"/><img src="https://iili.io/JfBHxBs.png" width="300"/> </p>

The web portal responsible for adding and controlling the medication looked as following.

<p align="center"> <img src="https://iili.io/JfoYByv.jpg" width="600"/> </p>
<p align="center"> <img src="https://iili.io/JfoY8MP.jpg" width="300"/> </p>

This video shows how the Memomed works: https://youtu.be/K7hPWc2ooWE

## Conclusion
The MemoMed project aims to offer an affordable and low-cost solution to enhance medication adherence, especially among the elderly population. We hope that this prototype, developed using technologies like 3D printing and microcontrollers, can contribute to better medication management and, consequently, improve the quality of life for patients.

## Contributing
We welcome contributions from the open-source community. If you would like to contribute to MemoMed, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature`
3. Make your changes and commit them: `git commit -m "Add your feature"`
4. Push to the branch: `git push origin feature/your-feature`
5. Submit a pull request.

## Authors <img src="https://content.linkedin.com/content/dam/me/business/en-us/amp/brand-site/v2/bg/LI-Bug.svg.original.svg" width="25" height="25" /> 

- [Flávio Neto](https://www.linkedin.com/in/flavio-sidnei-dos-santos-neto/)
- [Júlio Tinti](https://www.linkedin.com/in/juliotinti/)
- [Lucas Moletta](https://www.linkedin.com/in/lucasmoletta/)
- [Nithael Sampaio](https://www.linkedin.com/in/nsampaio/)

For more details about the project, please refer to the subsequent chapters of this README or contact us.


