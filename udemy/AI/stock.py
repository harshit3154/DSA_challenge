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


        correlation_id = "abc123"
        action = 1
        mode = 1

        token_list = [
            {
                "exchangeType": 3,
                # "tokens": ["26009"]
                "tokens": ["543320"]
            }
        ]
        token_list1 = [
            {
                "action": 0,
                "exchangeType": 3,
                # "tokens": ["26009"]
                "tokens":["543320"]
            }
        ]

        sws = SmartWebSocketV2(AUTH_TOKEN, API_KEY, CLIENT_CODE, FEED_TOKEN)
        
    
        str1=""" def on_data(wsapp, message):
            # logger.info("Ticks: {}".format(message))
            price=(float)(message["last_traded_price"])/100.0
            print(price)
            # close_connection()"""

        i_p=0.0 
        c_p=0.0
        def on_data(ws, message):
            global i_p, c_p

            try:
                # Directly use the message if it is already a dictionary
                if isinstance(message, dict):
                    message_data = message
                else:
                    # Parse the message as a JSON object if it is a string
                    message_data = json.loads(message)

                # Extract the price
                price = float(message_data["last_traded_price"]) / 100.0
        
                if i_p == 0.0:
                    i_p = price
                    c_p = price * 40.0
                #     try:
                #         orderparams = {
                #             "variety": "NORMAL",
                #             "tradingsymbol": "5079",
                #             "symboltoken": "ZOMATO-EQ ",
                #             "transactiontype": "BUY",
                #             "exchange": "BSE",
                #             "ordertype": "LIMIT",
                #             "producttype": "INTRADAY",
                #             "duration": "DAY",
                #             "price": str(price),
                #             "squareoff": str(0.125*price),
                #             "stoploss": str(0.75*price),
                #             "quantity": 14
                #             }
                #         orderId=smartApi.placeOrder(orderparams)
                #         print("The order id is: {}".format(orderId))
                #     except Exception as e:
                #         print(e)
                #     print(f"Bought stock at {price}",f"worth {c_p}")
                # elif price*40.0-c_p > 20.0:
                #     print("Gained profit of:",price * 40.0-c_p)
                # elif abs(price-i_p)>=0.05:
                #      print(f'Buied stock again at {price}')
                # else:
                #     print(price)

            except Exception as e:
                print(f"Error processing message: {e}")
        
        def on_open(wsapp):
            logger.info("on open")
            sws.subscribe(correlation_id, mode, token_list)
            # sws.unsubscribe(correlation_id, mode, token_list1)

        def on_error(wsapp, error):
            logger.error(error)


        def on_close(wsapp):
            logger.info("Close")



        def close_connection():
            sws.close_connection()


        # Assign the callbacks.
        sws.on_open = on_open
        sws.on_data = on_data
        sws.on_error = on_error
        sws.on_close = on_close

        sws.connect()

        # try:
        #     historicParam={
        #     "exchange": "NSE",
        #     "symboltoken": "3045",
        #     "interval": "ONE_MINUTE",
        #     "fromdate": "2021-02-08 09:00", 
        #     "todate": "2021-02-08 09:16"
        #     }
        #     price_history=pd.DataFrame(smartApi.getCandleData(historicParam))
        #     print(price_history['data'])
        # except Exception as e:
        #     logger.exception(f"Historic Api failed: {e}")

    else:
        print("Connection failed")
except Exception as e:
    print(e)
