import pandas as pd
import talib as ta
import ST_GetInfo


def talib_SAM(strTable, lstData, intPeriod):
    #lstData= [230.12, 230.13, 230.93, 231.23, 231.75, 231.89, 231.51, 231.18, 230.75, 231.2]
    #strTable = 'close'
    #intPeriod = 3
    df = pd.DataFrame(pd.Series(lstData), columns=["close"])
    lstSMA = ta.SMA(df.close.values, timeperiod=intPeriod)
    print(lstSMA)
    strLogs = "[st_"+strTable+"]: SAM of "+str(intPeriod)+" days is created."
    ST_GetInfo.Logs(strLogs)
    return lstSMA
    
    
if __name__ == "__main__":
    lstData= [230.12, 230.13, 230.93, 231.23, 231.75, 231.89, 231.51, 231.18, 230.75, 231.2]
    strTable = '1234'
    intPeriod = 3
    talib_SAM(strTable, lstData, intPeriod)

