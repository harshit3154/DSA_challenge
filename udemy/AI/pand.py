import pandas as pd

data=pd.read_csv('harshit.csv')
pd.Series(data)
print(pd.Series(data[0]))