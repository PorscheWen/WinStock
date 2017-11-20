from twstock import Stock

def main():
    
    stock = Stock('2330')                             # 擷取
    ma_p = stock.moving_average(stock.price, 5)       # 計算五日均價
    strma_p=str(ma_p)
    ma_c = stock.moving_average(stock.capacity, 5)    # 計算五日均量
    strma_c=str(ma_c)
    ma_p_cont = stock.continuous(ma_p)                # 計算五日均價持續天數
    strma_p_cont=str(ma_p_cont)
    ma_br = stock.ma_bias_ratio(5, 10)                # 計算五日、十日乖離值
    strma_br=str(ma_br)
    
    print ("計算五日均價", strma_p)
    print ("計算五日均量", strma_c)
    print ("計算五日均價持續天數", strma_p_cont)
    print ("計算五日、十日乖離值", strma_br)
        
    
if __name__ == '__main__':

    main()