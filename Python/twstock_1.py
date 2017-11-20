from twstock import Stock

def main():
    
    stock = Stock('2330')                             # �^��
    ma_p = stock.moving_average(stock.price, 5)       # �p�⤭�駡��
    strma_p=str(ma_p)
    ma_c = stock.moving_average(stock.capacity, 5)    # �p�⤭�駡�q
    strma_c=str(ma_c)
    ma_p_cont = stock.continuous(ma_p)                # �p�⤭�駡������Ѽ�
    strma_p_cont=str(ma_p_cont)
    ma_br = stock.ma_bias_ratio(5, 10)                # �p�⤭��B�Q�������
    strma_br=str(ma_br)
    
    print ("�p�⤭�駡��", strma_p)
    print ("�p�⤭�駡�q", strma_c)
    print ("�p�⤭�駡������Ѽ�", strma_p_cont)
    print ("�p�⤭��B�Q�������", strma_br)
        
    
if __name__ == '__main__':

    main()