import os

class Config(object):
    SECRET_KEY = os.environ.get('SECRET_KEY') or b'6\xe9\xda\xead\x81\xf7\x8d\xbbH\x87\xe8m\xdd3%'
    SQLALCHEMY_DATABASE_URI = "postgresql://memomed:memomedmemomed@mydb.cpvcbkzvvjux.us-east-1.rds.amazonaws.com:5432/memomed"
    SCHEDULER_API_ENABLED = True
    SQLALCHEMY_TRACK_MODIFICATIONS = False


 


    