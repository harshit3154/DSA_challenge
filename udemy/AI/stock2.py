from SmartApi.smartConnect import SmartConnect
import pyotp
from smartWebSocketV2 import SmartWebSocketV2
from logzero import logger
import pandas as pd
import json

API_KEY='Ue9jYS2x'
CLIENT_CODE='H182655'
PASSWORD='1103'
    

try:
    token='NLB4YQITCG23S74UNNMG7P4WCU'
    totp=pyotp.TOTP(token).now()
    smartApi=SmartConnect(API_KEY)
    data=smartApi.generateSession(CLIENT_CODE,PASSWORD,totp)
    if data['status']==True:
        print("Succesfully connected",data['status'])
        # print(data['data'])
        # print(data['data']['exchanges'])
        AUTH_TOKEN=data['data']['jwtToken']
        REFRESH_TOKEN=data['data']['refreshToken']
        FEED_TOKEN=smartApi.getfeedToken()
        PROFILE=smartApi.getProfile(REFRESH_TOKEN)
        try:
            # historicParam={
            # "exchange": "NSE",
            # "symboltoken": "3045",
            # "interval": "ONE_MINUTE",
            # "fromdate": "2024-05-18 09:00", 
            # "todate": "2024-05-19 12:16"
            # }

            historicParam={
            "exchange": "BSE",
            "symboltoken": "543320",
            "interval": "ONE_MINUTE",
            "fromdate": "2024-05-18 09:00", 
            "todate": "2024-05-19 12:16"
            }
            data=smartApi.getCandleData(historicParam)
            print(data)
            data=pd.DataFrame(data['data'])
            print(data)
            # data.to_csv("harshit.csv",index=False)  
            
        except Exception as e:
            print("Historic Api failed: {}".format(e.message))
    else:
        print(data['status'])
except Exception as e:
    print(e)