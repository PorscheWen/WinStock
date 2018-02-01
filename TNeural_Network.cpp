#include <fstream>
#include <iostream>
using namespace std;

#include "TNeural_NetWork.h"




TNeural_NetWork::TNeural_NetWork(void)
{
    _stock_num = -1;
    _stock_price_day = -1;
    _stock_idx = NULL;
	_stock_date = NULL;
    _stock_close = NULL;
    _stock_open = NULL;
    _stock_highest = NULL;
    _stock_lowest = NULL;
    _stock_piece = NULL;
    _stock_name = NULL;

    _5average_point = _10average_point = _15average_point = _20average_point = NULL;

    _9K = NULL;
    _9D = NULL;
    _DII = NULL;
    _12EMA = NULL;
    _26EMA = NULL;
    _MACD_DIF = NULL;
    _MACD_DEM = NULL;
    _MACD_OSC = NULL;

    _trainData = NULL;
    _desireOutput = NULL;
    _predictData = NULL;
    _actualOutput = NULL;

    _neurons_weight = NULL;
    _delta_neurons_weight = NULL;
    _neurons_input = NULL;
    _neurons_output = NULL;
    _delta_neurons_output =  NULL;

    _outLayer_weight = NULL;
    _delta_outLayer_weight = NULL;
    _outLayer_input = NULL;
    _outLayer_output = NULL;
    _delta_outLayer_output = NULL;
}
TNeural_NetWork::~TNeural_NetWork()
{
    if(_stock_idx)
    {
		delete [] _stock_idx;
        _stock_idx = NULL;
    }
	if(_stock_date)
    {
		delete [] _stock_date;
        _stock_date = NULL;
    }
	if(_stock_close)
    {
		delete [] _stock_close;
        _stock_close = NULL;
    }
	if(_stock_open)
    {
		delete [] _stock_open;
        _stock_open = NULL;
    }
	if(_stock_highest)
    {
		delete [] _stock_highest;
        _stock_highest = NULL;
    }
	if(_stock_lowest)
    {
		delete [] _stock_lowest;
        _stock_lowest = NULL;
    }
	if(_stock_piece)
    {
		delete [] _stock_piece;
        _stock_piece = NULL;
    }
	if(_stock_name)
    {
		delete [] _stock_name;
        _stock_name = NULL;
    }


    if(_5average_point)
    {
        delete [] _5average_point;
        _5average_point = NULL;
    }
    if(_10average_point)
    {
		delete [] _10average_point;
        _10average_point = NULL;
    }
    if(_15average_point)
    {
		delete [] _15average_point;
        _15average_point = NULL;
    }
    if(_20average_point)
    {
		delete [] _20average_point;
        _20average_point = NULL;
    }

    if(_9K)
    {
		delete [] _9K;
        _9K = NULL;
    }
    if(_9D)
    {
		delete [] _9D;
        _9D = NULL;
    }
    if(_DII)
    {
		delete [] _DII;
        _DII = NULL;
    }
    if(_12EMA)
    {
		delete [] _12EMA;
        _12EMA = NULL;
    }
    if(_26EMA)
    {
		delete [] _26EMA;
        _26EMA = NULL;
    }
    if(_MACD_DIF)
    {
		delete [] _MACD_DIF;
        _MACD_DIF = NULL;
    }
    if(_MACD_DEM)
    {
		delete [] _MACD_DEM;
        _MACD_DEM = NULL;
    }
    if(_MACD_OSC)
    {
		delete [] _MACD_OSC;
        _MACD_OSC = NULL;
    }

    if(_trainData)
    {
		delete [] _trainData;
        _trainData = NULL;
    }
    if(_desireOutput)
    {
		delete [] _desireOutput;
        _desireOutput = NULL;
    }
    if(_predictData)
    {
		delete [] _predictData;
        _predictData = NULL;
    }
    if(_actualOutput)
    {
		delete [] _actualOutput;
        _actualOutput = NULL;
    }

    if(_neurons_weight)
    {
		delete [] _neurons_weight;
        _neurons_weight = NULL;
    }
    if(_delta_neurons_weight)
    {
		delete [] _delta_neurons_weight;
        _delta_neurons_weight = NULL;
    }
    if(_neurons_input)
    {
		delete [] _neurons_input;
        _neurons_input = NULL;
    }
    if(_neurons_output)
    {
		delete [] _neurons_output;
        _neurons_output = NULL;
    }
    if(_delta_neurons_output)
    {
		delete [] _delta_neurons_output;
        _delta_neurons_output =  NULL;
    }

    if(_outLayer_weight)
    {
		delete [] _outLayer_weight;
        _outLayer_weight = NULL;
    }
    if(_delta_outLayer_weight)
    {
		delete [] _delta_outLayer_weight;
        _delta_outLayer_weight = NULL;
    }
    if(_outLayer_input)
    {
		delete [] _outLayer_input;
        _outLayer_input = NULL;
    }
    if(_outLayer_output)
    {
		delete [] _outLayer_output;
        _outLayer_output = NULL;
    }
    if(_delta_outLayer_output)
    {
        delete [] _delta_outLayer_output;
        _delta_outLayer_output = NULL;
    }
}
void TNeural_NetWork::_readData(CString file_name)
{
    int i(0) , j(0);
    fstream stock_file;
    





    stock_file.open(file_name , ios::in);
    if(!stock_file)
    {
    }
    else
    {

        //讀入資料
        stock_file  >> _stock_num >> _stock_price_day;

        _stock_idx = new int [_stock_num];
		_stock_date = new double [_stock_price_day];
        _stock_close = new float* [_stock_num];
		_stock_open = new float* [_stock_num];
		_stock_highest = new float* [_stock_num];
		_stock_lowest = new float* [_stock_num];
        _stock_name = new char* [_stock_num];
		_stock_piece = new float* [_stock_num];

        for(i=0 ; i<_stock_num ; i++)
        {
            _stock_close[i] = new float[_stock_price_day];
			_stock_open[i] = new float[_stock_price_day];
			_stock_highest[i] = new float[_stock_price_day];
			_stock_lowest[i] = new float[_stock_price_day];
            _stock_name[i] = new char[100];
			_stock_piece[i] = new float[_stock_price_day];
        }

		for(i=0 ; i<_stock_num ; i++)
        {
			for(j=0 ; j<_stock_price_day ; j++)
			{
				_stock_close[i][j] = 0.0f;
				_stock_open[i][j] = 0.0f;
				_stock_highest[i][j] = 0.0f;
				_stock_lowest[i][j] = 0.0f;
				_stock_piece[i][j] = 0.0f;
			}
        }

		for(i=0 ; i<_stock_price_day ; i++)
			stock_file  >> _stock_date[i];

        for(i=0 ; i<_stock_num ; i++)
        {
            stock_file >> _stock_idx[i] >> _stock_name[i];

            for(j=0 ; j<_stock_price_day ; j++)
                stock_file >> _stock_close[i][j] >> _stock_open[i][j] >> _stock_highest[i][j] >> _stock_lowest[i][j] >> _stock_piece[i][j];
        }
        stock_file.close();
    }




    ////
    _calculateAverage();
	_calculateIndicators();
}
void TNeural_NetWork::_readData_fromPorsche(CString file_name)
{
	int i(0),j(0);
	fstream stock_file;






	stock_file.open(file_name,ios::in);
	if(!stock_file)
	{
	}
	else
	{

		//讀入資料
		stock_file  >> _stock_price_day;
		_stock_num = 1;

		_stock_idx = new int[_stock_num];
		_stock_date = new double[_stock_price_day];
		_stock_close = new float*[_stock_num];
		_stock_open = new float*[_stock_num];
		_stock_highest = new float*[_stock_num];
		_stock_lowest = new float*[_stock_num];
		_stock_name = new char*[_stock_num];
		_stock_piece = new float*[_stock_num];

		for(i=0 ; i<_stock_num ; i++)
		{
			_stock_close[i] = new float[_stock_price_day];
			_stock_open[i] = new float[_stock_price_day];
			_stock_highest[i] = new float[_stock_price_day];
			_stock_lowest[i] = new float[_stock_price_day];
			_stock_name[i] = new char[100];
			_stock_piece[i] = new float[_stock_price_day];
		}

		for(i=0 ; i<_stock_num ; i++)
		{
			for(j=0 ; j<_stock_price_day ; j++)
			{
				_stock_close[i][j] = 0.0f;
				_stock_open[i][j] = 0.0f;
				_stock_highest[i][j] = 0.0f;
				_stock_lowest[i][j] = 0.0f;
				_stock_piece[i][j] = 0.0f;
			}
		}

		for(i=0 ; i<_stock_num ; i++)
		{
			for(j=0 ; j<_stock_price_day ; j++)
				stock_file >> _stock_date[j] >> _stock_open[i][j] >> _stock_highest[i][j] >> _stock_lowest[i][j] >> _stock_close[i][j];
		}

		stock_file.close();
	}




	////
	_calculateAverage();
	_calculateIndicators();
}
void TNeural_NetWork::_calculateAverage()
{
    int i(0) , j(0) , k(0);
    float average(0.0f);






    if(_stock_price_day >= 6)
    {
        _5average_point = new float* [_stock_num];
        for(i=0 ; i<_stock_num ; i++)
            _5average_point[i] = new float[_stock_price_day-5+1];
    }
    if(_stock_price_day >= 11)
    {
        _10average_point = new float* [_stock_num];
        for(i=0 ; i<_stock_num ; i++)
            _10average_point[i] = new float[_stock_price_day-10+1];
    }
    if(_stock_price_day >= 16)
    {
        _15average_point = new float* [_stock_num];
        for(i=0 ; i<_stock_num ; i++)
            _15average_point[i] = new float[_stock_price_day-15+1];
    }
    if(_stock_price_day >= 21)
    {
        _20average_point = new float* [_stock_num];
        for(i=0 ; i<_stock_num ; i++)
            _20average_point[i] = new float[_stock_price_day-20+1];
    }




    for(i=0 ; i<_stock_num ; i++)
	{
        if(_stock_price_day >= 6)
        {
		    for(j=4 ; j<_stock_price_day ; j++)
		    {     
                average = 0.0;
                for(k=0 ; k<5 ; k++)
                    average += _stock_close[i][j-k];
                average /= 5.0;	

                _5average_point[i][j-4] = average;
		    }
        }

        if(_stock_price_day >= 11)
        {
		    for(j=9 ; j<_stock_price_day ; j++)
		    {     
                average = 0.0;
                for(k=0 ; k<10 ; k++)
                    average += _stock_close[i][j-k];
                average /= 10.0;	

                _10average_point[i][j-9] = average;
		    }
        }

		if(_stock_price_day >= 16)
        {
		    for(j=14 ; j<_stock_price_day ; j++)
		    {     
                average = 0.0;
                for(k=0 ; k<15 ; k++)
                    average += _stock_close[i][j-k];
                average /= 15.0;	

                _15average_point[i][j-14] = average;
		    }
        }

		if(_stock_price_day >= 21)
        {
		    for(j=19 ; j<_stock_price_day ; j++)
		    {     
                average = 0.0;
                for(k=0 ; k<20 ; k++)
                    average += _stock_close[i][j-k];
                average /= 20.0;	

                _20average_point[i][j-19] = average;
		    }
        }
    }
}
void TNeural_NetWork::_calculateIndicators()
{
	int i(0) , j(0) , k(0);
	double one_third;
	double min,max;




	one_third = 0.3333333333333333333333333333333333;


	_9K = new float*[_stock_num];
	_9D = new float*[_stock_num];
	_DII = new float*[_stock_num];
	_12EMA = new float*[_stock_num];
	_26EMA = new float*[_stock_num];
	_MACD_DIF = new float*[_stock_num];
	_MACD_DEM = new float*[_stock_num];
	_MACD_OSC = new float*[_stock_num];


	for(i=0 ; i<_stock_num ; i++)
	{
		_9K[i] = new float[_stock_price_day];
		_9D[i] = new float[_stock_price_day];
		_DII[i] = new float[_stock_price_day];
		_12EMA[i] = new float[_stock_price_day];
		_26EMA[i] = new float[_stock_price_day];
		_MACD_DIF[i] = new float[_stock_price_day];
		_MACD_DEM[i] = new float[_stock_price_day];
		_MACD_OSC[i] = new float[_stock_price_day];
	}

	for(i=0 ; i<_stock_num ; i++)
	{
		for(j=_stock_price_day-1 ; j>=0 ; j--)
		{
			if(j > _stock_price_day-1-7)
			{
				_9K[i][j] = 0.0;
				_9D[i][j] = 0.0;
				_DII[i][j] = 0.0;
				_12EMA[i][j] = 0.0;
				_26EMA[i][j] = 0.0;
				_MACD_DIF[i][j] = 0.0;
				_MACD_DEM[i][j] = 0.0;
				_MACD_OSC[i][j] = 0.0;
			}
			else if(j == _stock_price_day-1-7)
			{
				_9K[i][j] = 50.0;//第八天初始值
				_9D[i][j] = 50.0;//第八天初始值
				_DII[i][j] = (_stock_highest[i][j] + _stock_lowest[i][j] + 2*_stock_close[i][j]) / 4.0;
				_12EMA[i][j] = _12EMA[i][j+1] + 2 / (12 + 1)*(_DII[i][j] - _12EMA[i][j+1]);
				_26EMA[i][j] = _26EMA[i][j+1] + 2 / (26 + 1)*(_DII[i][j] - _26EMA[i][j+1]);
				_MACD_DIF[i][j] = _12EMA[i][j] - _26EMA[i][j];
				_MACD_DEM[i][j] = _MACD_DEM[i][j+1] + 2 / (9 + 1)*(_12EMA[i][j] - _26EMA[i][j] - _MACD_DEM[i][j+1]);
				_MACD_OSC[i][j] = _MACD_DIF[i][j] - _MACD_DEM[i][j];
			}
			else
			{
				for(k=0 ; k<9 ; k++)
				{
					if(k == 0)
					{
						min = _stock_lowest[i][j+k];
						max = _stock_highest[i][j+k];
					}
					else
					{
						min = (min < _stock_lowest[i][j+k]) ? min : _stock_lowest[i][j+k];
						max = (max > _stock_highest[i][j+k]) ? max : _stock_highest[i][j+k];
					}
				}
				_9K[i][j] = (1 - one_third)*_9K[i][j+1] + one_third*(_stock_close[i][j] - min) / (max - min) * 100;
				_9D[i][j] = one_third*_9K[i][j] + (1 - one_third)*_9D[i][j+1];
				_DII[i][j] = (_stock_highest[i][j] + _stock_lowest[i][j] + 2*_stock_close[i][j]) / 4.0;
				_12EMA[i][j] = _12EMA[i][j+1] + 2 / (12 + 1)*(_DII[i][j] - _12EMA[i][j+1]);
				_26EMA[i][j] = _26EMA[i][j+1] + 2 / (26 + 1)*(_DII[i][j] - _26EMA[i][j+1]);
				_MACD_DIF[i][j] = _12EMA[i][j] - _26EMA[i][j];
				_MACD_DEM[i][j] = _MACD_DEM[i][j+1] + 2 / (9 + 1)*(_12EMA[i][j] - _26EMA[i][j] - _MACD_DEM[i][j +1]);
				_MACD_OSC[i][j] = _MACD_DIF[i][j] - _MACD_DEM[i][j];
			}
		}
	}




	//FILE *fp(NULL);
	//fp = _tfopen(_T("d:\\_stock.txt"),_T("w"));
	//for(i=0 ; i<1 ; i++)
	//{
	//	for(j=0 ; j<_stock_price_day ; j++)
	//	{
	//		fprintf(fp ," %.6f        %.6f        %.6f\n" , _9K[i][j] , _9D[i][j] , _stock_close[i][j]);
	//	}
	//}

	//fclose(fp);
}


////
void TNeural_NetWork::_buildNeural(const int &_inputNum , const int &_hiddenLayerNum , int *_neuronsNum , const int &_outputNum)
{
    double _desire_max(-DBL_MAX) , desire_min(DBL_MAX);


	bool op_coincidence(true);
	int _training_period(400);
	int _predict_period(0);






	_initialNeural(_inputNum , _hiddenLayerNum , _neuronsNum , _outputNum);
	_setTrainingData(1, 
					               _inputNum, 
							       _training_period , _predict_period , op_coincidence,
							       _desire_max , desire_min);
	_learning(_inputNum , _hiddenLayerNum , _neuronsNum , _outputNum,
			         _training_period);
	_predict(_inputNum , _hiddenLayerNum , _neuronsNum , _outputNum,
			       _predict_period,
				   _desire_max , desire_min);
    _deleteData();
}
//
void TNeural_NetWork::_initialNeural(const int &_inputNum , const int &_hiddenLayerNum , int *_neuronsNum , const int &_outputNum)
{
    int i(0) , j(0) , k(0);






    srand(time(NULL));


    _neurons_weight = new double**[_hiddenLayerNum];
    _delta_neurons_weight = new double**[_hiddenLayerNum];
    _neurons_input = new double*[_hiddenLayerNum];
    _neurons_output = new double*[_hiddenLayerNum];
    _delta_neurons_output = new double*[_hiddenLayerNum];

    for(i=0 ; i<_hiddenLayerNum ; i++)
    {
	    _neurons_weight[i] = new double*[_neuronsNum[i]];
	    _delta_neurons_weight[i] = new double*[_neuronsNum[i]];
	    for(j=0 ; j<_neuronsNum[i] ; j++)
	    {
			if(i == 0)
			{
				_neurons_weight[i][j] = new double[_inputNum];
				_delta_neurons_weight[i][j] = new double[_inputNum];
				for(k=0 ; k<_inputNum ; k++)
				{
					_neurons_weight[i][j][k] = (double)(rand()) / (32767 / 2) - 1;
					_delta_neurons_weight[i][j][k] = 0.0;
				}
			}
			else
			{
				_neurons_weight[i][j] = new double[_neuronsNum[i-1]];
				_delta_neurons_weight[i][j] = new double[_neuronsNum[i - 1]];
				for(k=0 ; k<_neuronsNum[i-1] ; k++)
				{
					_neurons_weight[i][j][k] = (double)(rand()) / (32767 / 2) - 1;
					_delta_neurons_weight[i][j][k] = 0.0;
				}
			}
	    }

        _neurons_input[i] = new double[_neuronsNum[i]];
	    _neurons_output[i] = new double[_neuronsNum[i]];
	    _delta_neurons_output[i] = new double[_neuronsNum[i]];
	    for(j=0 ; j<_neuronsNum[i] ; j++)
	    {
            _neurons_input[i][j] = 0.0;
		    _neurons_output[i][j] = 0.0;
		    _delta_neurons_output[i][j] = 0.0;
	    }
    }




	_outLayer_weight = new double* [_outputNum];
	_delta_outLayer_weight = new double* [_outputNum];
    _outLayer_input = new double[_outputNum];
	_outLayer_output = new double[_outputNum];
	_delta_outLayer_output = new double[_outputNum];
	for(i=0 ; i<_outputNum ; i++)
	{
		_outLayer_weight[i] = new double[_neuronsNum[_hiddenLayerNum-1]];
		_delta_outLayer_weight[i] = new double[_neuronsNum[_hiddenLayerNum-1]];

		for(j=0 ; j<_neuronsNum[_hiddenLayerNum-1] ; j++)
		{	
			_outLayer_weight[i][j] = (double)(rand())/(32767/2) - 1;
			_delta_outLayer_weight[i][j] = 0.0;
		}

        _outLayer_input[i] = 0.0;
        _outLayer_output[i] = 0.0;
		_delta_outLayer_output[i] = 0.0;
	}
}
void TNeural_NetWork::_setTrainingData(const int &flag, 
									                                     const int &_inputNum,
															             const int &_training_period , int &_predict_period , const bool &op_coincidence,
															             double &_desire_max , double &_desire_min)
{
    int i(0);
    double _5_max(-DBL_MAX) , _10_max(-DBL_MAX) , _15_max(-DBL_MAX) , _20_max(-DBL_MAX);
    double _5_min(DBL_MAX) , _10_min(DBL_MAX) , _15_min(DBL_MAX) , _20_min(DBL_MAX);
	double _9k_max(-DBL_MAX) , _9d_max(-DBL_MAX);
	double _9k_min(DBL_MAX) , _9d_min(DBL_MAX);






    if(flag == 1)
    {
        //訓練期間
        _trainData = new double* [_training_period];
        _desireOutput = new double[_training_period];
        for(i=0 ; i<_training_period ; i++)
            _trainData[i] = new double[_inputNum];


		_5_max = -DBL_MAX;
		_10_max = -DBL_MAX;
		_15_max = -DBL_MAX; 
		_20_max = -DBL_MAX;
		_9k_max = -DBL_MAX;
		_9d_max = -DBL_MAX;
		_desire_max = -DBL_MAX;
		_5_min = DBL_MAX;
		_10_min = DBL_MAX;
		_15_min = DBL_MAX;
		_20_min = DBL_MAX;
		_9k_min = DBL_MAX;
		_9d_min = DBL_MAX;
		_desire_min = DBL_MAX;
		for(i=_predict_period ; i<_predict_period+_training_period ; i++)
        {
			_trainData[i - _predict_period][0] = _5average_point[0][i + 1];
			_trainData[i - _predict_period][1] = _10average_point[0][i + 1];
			_trainData[i - _predict_period][2] = _15average_point[0][i + 1];
			_trainData[i - _predict_period][3] = _20average_point[0][i + 1];
			_trainData[i - _predict_period][4] = _9K[0][i + 1];
			_trainData[i - _predict_period][5] = _9D[0][i + 1];

            if(_5average_point[0][i + 1] > _5_max)  _5_max = _5average_point[0][i + 1];
            if(_10average_point[0][i + 1] > _10_max)  _10_max = _10average_point[0][i + 1];
            if(_15average_point[0][i + 1] > _15_max)  _15_max = _15average_point[0][i + 1];
            if(_20average_point[0][i + 1] > _20_max)  _20_max = _20average_point[0][i + 1];
			if(_9K[0][i + 1] > _9k_max)  _9k_max = _9K[0][i + 1];
			if(_9D[0][i + 1] > _9d_max)  _9d_max = _9D[0][i + 1];

            if(_5average_point[0][i + 1] < _5_min)  _5_min = _5average_point[0][i + 1];
            if(_10average_point[0][i + 1] < _10_min)  _10_min = _10average_point[0][i + 1];
            if(_15average_point[0][i + 1] < _15_min)  _15_min = _15average_point[0][i + 1];
            if(_20average_point[0][i + 1] < _20_min)  _20_min = _20average_point[0][i + 1];
			if(_9K[0][i + 1] < _9k_min)  _9k_min = _9K[0][i + 1];
			if(_9D[0][i + 1] < _9d_min)  _9d_min = _9D[0][i + 1];

            //
			_desireOutput[i - _predict_period] = _stock_close[0][i];

             if(_stock_close[0][i] > _desire_max)  _desire_max = _stock_close[0][i];
             if(_stock_close[0][i] < _desire_min)  _desire_min = _stock_close[0][i];
        }

		for(i=_predict_period ; i<_predict_period+_training_period ; i++)
        {
			_trainData[i - _predict_period][0] = (_5average_point[0][i + 1] - _5_min) / (_5_max - _5_min);
			_trainData[i - _predict_period][1] = (_10average_point[0][i + 1] - _10_min) / (_10_max - _10_min);
			_trainData[i - _predict_period][2] = (_15average_point[0][i + 1] - _15_min) / (_15_max - _15_min);
			_trainData[i - _predict_period][3] = (_20average_point[0][i + 1] - _20_min) / (_20_max - _20_min);
			_trainData[i - _predict_period][4] = (_9K[0][i + 1] - _9k_min) / (_9k_max - _9k_min);
			_trainData[i - _predict_period][5] = (_9D[0][i + 1] - _9d_min) / (_9d_max - _9d_min);

			_desireOutput[i - _predict_period] = (_stock_close[0][i] - _desire_min) / (_desire_max - _desire_min);
        }




		////
		if(op_coincidence)
			_predict_period = _training_period;
		_predictData = new double*[_predict_period];
		_actualOutput = new double[_predict_period];
		for(i=0 ; i<_predict_period ; i++)
			_predictData[i] = new double[_inputNum];


		for(i=0 ; i<_predict_period ; i++)
		{
			_predictData[i][0] = (_5average_point[0][i + 1] - _5_min) / (_5_max - _5_min);
			_predictData[i][1] = (_10average_point[0][i + 1] - _10_min) / (_10_max - _10_min);
			_predictData[i][2] = (_15average_point[0][i + 1] - _15_min) / (_15_max - _15_min);
			_predictData[i][3] = (_20average_point[0][i + 1] - _20_min) / (_20_max - _20_min);
			_predictData[i][4] = (_9K[0][i + 1] - _9k_min) / (_9k_max - _9k_min);
			_predictData[i][5] = (_9D[0][i + 1] - _9d_min) / (_9d_max - _9d_min);

			_actualOutput[i] = (_stock_close[0][i] - _desire_min) / (_desire_max - _desire_min);
		}

	}
}
//
void TNeural_NetWork::_learning(const int &_inputNum , const int &_hiddenLayerNum , int *_neuronsNumList , const int &_outputNum,
								                           const int &_training_period)
{
	int iIter(0) , iPeriod(0) , iLayer(0) , iNeuron(0) , iInput(0) , iOutput(0);
	bool op_stop(false);





	
	_learning_rate = 1.0;
	for(iIter=0 ; iIter<2000 ; iIter++)
	{
		for(iPeriod=0 ; iPeriod<_training_period ; iPeriod++)
		{
            //中間層
			for(iLayer=0 ; iLayer<_hiddenLayerNum ; iLayer++)
            {
				if(iLayer == 0)
					_hiddenCalculate(iLayer , _neuronsNumList[iLayer],
                                                   _trainData[iPeriod] , _inputNum);
                else
					_hiddenCalculate(iLayer , _neuronsNumList[iLayer],
					                               _neurons_output[iLayer-1] , _neuronsNumList[iLayer-1]);
            }

            //輸出層
			for(iOutput=0 ; iOutput<_outputNum ; iOutput++)
			{
                _outLayer_input[iOutput] = 0.0;
				_outLayer_output[iOutput] = 0.0;
				for(iNeuron=0 ; iNeuron<_neuronsNumList[_hiddenLayerNum-1] ; iNeuron++)
					_outLayer_input[iOutput] += (_neurons_output[_hiddenLayerNum - 1][iNeuron] * _outLayer_weight[iOutput][iNeuron]);

                _outLayer_output[iOutput] = _sigmoid(_outLayer_input[iOutput]);
			}




            //back-propagation
			for(iOutput=0 ; iOutput<_outputNum; iOutput++)
			{
				_delta_outLayer_output[iOutput] = (_desireOutput[iPeriod] - _outLayer_output[iOutput]);
                //if(fabs(_delta_output[iOutput]) < 10e-10)
                //    op_stop = true;

				for(iNeuron=0 ; iNeuron<_neuronsNumList[_hiddenLayerNum-1] ; iNeuron++)
                {
					_delta_outLayer_weight[iOutput][iNeuron] = _learning_rate *
                                                                                                _partialError_partialOLOutput(iOutput , 0)* 
                                                                                                _partialOLOutput_partialOLInput(iOutput , 1)*
																				                _partialOLInput_partialOLWeight(_hiddenLayerNum-1 , iNeuron);
                    //立刻更新hidden output的weigth
                    //_weight_hidden2Output[iOutput][iHidden] = _weight_hidden2Output[iOutput][iHidden] + _delta_weight_hidden2Output[iOutput][iHidden];
                }
            }

			for(iLayer=_hiddenLayerNum-1 ; iLayer>=0 ; iLayer--)
            {
				if(iLayer == 0)
					_hiddenBackPropagationCalculate(_trainData[iPeriod] , _inputNum,
					                                                              iLayer , _neuronsNumList[iLayer],
																	              _hiddenLayerNum , _neuronsNumList,
					                                                              _outputNum);
				else
					_hiddenBackPropagationCalculate(_neurons_output[iLayer-1] , _neuronsNumList[iLayer-1],
					                                                              iLayer , _neuronsNumList[iLayer],
																		          _hiddenLayerNum , _neuronsNumList,
																	              _outputNum);
				
            }


			//更新weight
			for(iOutput=0 ; iOutput<_outputNum ; iOutput++)
			{
				for(iNeuron=0 ; iNeuron<_neuronsNumList[_hiddenLayerNum-1] ; iNeuron++)
				{
					_outLayer_weight[iOutput][iNeuron] += _delta_outLayer_weight[iOutput][iNeuron];
				}
			}

			for(iLayer=0 ; iLayer<_hiddenLayerNum ; iLayer++)
			{
				if(iLayer == 0)
				{
					for(iNeuron=0 ; iNeuron<_neuronsNumList[iLayer] ; iNeuron++)
					{
						for(iInput=0 ; iInput<_inputNum ; iInput++)
							_neurons_weight[iLayer][iNeuron][iInput] += _delta_neurons_weight[iLayer][iNeuron][iInput];
					}
				}
				else
				{
					for(iNeuron=0 ; iNeuron<_neuronsNumList[iLayer] ; iNeuron++)
					{
						for(iInput=0 ; iInput<_neuronsNumList[iLayer-1] ; iInput++)
							_neurons_weight[iLayer][iNeuron][iInput] += _delta_neurons_weight[iLayer][iNeuron][iInput];
					}
				}
			}

		}//for(iPeriod=0 ; iPeriod<_training_period ; iPeriod++)
		if(op_stop)
			break;
	}

	int roger = 100;

 }
void TNeural_NetWork::_hiddenCalculate(const int &_which_hiddenLayer , const int &_neuronsNum,
                                                                          double *_inputData , const int &_inputNum)
{
    int iNeurons(0) , iInput(0);


    for(iNeurons=0 ; iNeurons<_neuronsNum ; iNeurons++)
    {
        _neurons_input[_which_hiddenLayer][iNeurons] = 0.0;
        _neurons_output[_which_hiddenLayer][iNeurons] = 0.0;

        for(iInput=0 ; iInput<_inputNum ; iInput++)
             _neurons_input[_which_hiddenLayer][iNeurons] += (_inputData[iInput] * _neurons_weight[_which_hiddenLayer][iNeurons][iInput]);

        _neurons_output[_which_hiddenLayer][iNeurons] = _sigmoid(_neurons_input[_which_hiddenLayer][iNeurons]);
    }
}
double  TNeural_NetWork::_partialError_partialOLOutput(const int &_which_output , const int &flag)
{
    double result(0.0);


    if(flag == 0)
		result = _delta_outLayer_output[_which_output];
    return result;
}
double TNeural_NetWork::_partialOLOutput_partialOLInput(const int &_which_output , const int &flag)
{
    double result(0.0);


    if(flag == 0)
		result = _derivativeOfSigmoid(_outLayer_input[_which_output] , flag);
    else if(flag == 1)
		result = _derivativeOfSigmoid(_outLayer_output[_which_output] , flag);
    return result;
}
double TNeural_NetWork::_partialOLInput_partialOLWeight(const int &_which_hiddenLayer , const int &_which_neuron)
{
	return _neurons_output[_which_hiddenLayer][_which_neuron];
}
double TNeural_NetWork::_partialOLInput_partialHLOutput(const int &_which_neuron,
														                                                 const int &_which_output)
{
	return _outLayer_weight[_which_output][_which_neuron];
}
void TNeural_NetWork::_hiddenBackPropagationCalculate(double *_inputData , const int &_inputNum,
	                                                                                                     const int &_which_hiddenLayer , const int &_neuronsNum, 
																					                     const int &_hiddenLayerNum , int *_neuronsNumList,
																					                     const int & _outputNum)
{
	int iInput(0) , iNeurons(0);



	for(iNeurons=0 ; iNeurons<_neuronsNum ; iNeurons++)
	{
		for(iInput=0 ; iInput<_inputNum ; iInput++)
		{
			_delta_neurons_weight[_which_hiddenLayer][iNeurons][iInput] = _learning_rate *
				                                                                                                             _partialError_partialHLOutput(_which_hiddenLayer , iNeurons,
																										                                                                         _hiddenLayerNum , _neuronsNumList,
																										                                                                         _outputNum)*
			                                                                                                                 _partialHLOutput_partialHLInput(_which_hiddenLayer , iNeurons , 1)*
																										                     _partialHLInput_partialHLWeight(_inputData , iInput);
		}
	}



}
double TNeural_NetWork::_partialError_partialHLOutput(const int &_which_hiddenLayer , const int &_which_neuron,
													                                               const int &_hiddenLayerNum , int *_neuronsNumList,
													                                               const int & _outputNum)
{
	int i(0);
	int iOutput(0);


	_delta_neurons_output[_which_hiddenLayer][_which_neuron] = 0.0;
	for(iOutput=0 ; iOutput<_outputNum ; iOutput++)
	{
		_delta_neurons_output[_which_hiddenLayer][_which_neuron] += _partialError_partialOLOutput(iOutput , 0)*
			                                                                                                             _partialOLOutput_partialOLInput(iOutput , 1)*
			                                                                                                             _partialOLInput_partialHLOutput(_which_neuron,
			                                                                                                                                                                       iOutput);
	}

	for(i=_hiddenLayerNum-1 ; i>_which_hiddenLayer ; i--)
	{
		_delta_neurons_output[_which_hiddenLayer][_which_neuron] *= _partialHLOutput_partialHLInput(i , 0 , 1);//先都從第0個neuron經過
		_delta_neurons_output[_which_hiddenLayer][_which_neuron] *= _partialHLInput_partialHLOutput(i , 0 , _which_neuron);
	}

	return _delta_neurons_output[_which_hiddenLayer][_which_neuron];
}
double TNeural_NetWork::_partialHLOutput_partialHLInput(const int &_which_hiddenLayer , const int &_which_neuron , const int &flag)
{
	double result(0.0);


	if(flag == 0)
		result = _derivativeOfSigmoid(_neurons_input[_which_hiddenLayer][_which_neuron] , flag);
	else if(flag == 1)
		result = _derivativeOfSigmoid(_neurons_output[_which_hiddenLayer][_which_neuron] , flag);
	return result;

}
double TNeural_NetWork::_partialHLInput_partialHLWeight(double *_inputData , const int &_which_neuron)
{
    return _inputData[_which_neuron];
}
double TNeural_NetWork::_partialHLInput_partialHLOutput(const int &_which_hiddenLayer , const int &_which_neuron,
														                                                 const int &_which_output)
{
	return _neurons_weight[_which_hiddenLayer][_which_neuron][_which_output];
}

double TNeural_NetWork::_sigmoid(const double &a)
{
	double result(0.0);


	result = 1.0 / (1.0 + exp(-a));
	return result;
}
double TNeural_NetWork::_derivativeOfSigmoid(const double &a , const int &flag)
{
    double result(0.0);


    if(flag == 0)
        result = _sigmoid(a)*(1-_sigmoid(a));
    else if(flag == 1)
        result = a*(1-a);
    return result;
}
double TNeural_NetWork::_relu(const double &a)
{
	double result(0.0);


    if(a <= 0.0)
        result = 0.0;
    else
        result = a;
	return result;
}
double TNeural_NetWork::_softmax_denominator_sum(const double *denominator , const int &_denominator_count)
{
    int i(0);
    double result(0.0);


    for(i=0 ; i<_denominator_count ; i++)
        result += exp(denominator[i]);
    return result;
}
double TNeural_NetWork::_softmax(const double &numerator , const double &denominator)
{
    double result(0.0);


    result = exp(numerator)/denominator;
    return result;
}
//
void TNeural_NetWork::_predict(const int &_inputNum , const int &_hiddenLayerNum , int *_neuronsNumList , const int &_outputNum,
							                             const int &_predict_period,
												         double &_desire_max , double &_desire_min)
{
	int iPeriod(0) , iLayer(0) , iInput(0) , iOutput(0) , iNeuron(0);
	FILE *fp(NULL);






	fp = _tfopen(_T("d:\\_stock.txt"),_T("w"));
	for(iPeriod=_predict_period-1 ; iPeriod>=0 ; iPeriod--)
	{
        //中間層
		for(iLayer=0 ; iLayer<_hiddenLayerNum ; iLayer++)
        {
			if(iLayer == 0)
				_hiddenCalculate(iLayer , _neuronsNumList[iLayer],
                                                _predictData[iPeriod] , _inputNum);
            else
				_hiddenCalculate(iLayer , _neuronsNumList[iLayer],
					                            _neurons_output[iLayer-1] , _neuronsNumList[iLayer-1]);
        }

        //輸出層
		for(iOutput=0 ; iOutput<_outputNum ; iOutput++)
		{
            _outLayer_input[iOutput] = 0.0;
			_outLayer_output[iOutput] = 0.0;
			for(iNeuron=0 ; iNeuron<_neuronsNumList[_hiddenLayerNum-1] ; iNeuron++)
				_outLayer_input[iOutput] += (_neurons_output[_hiddenLayerNum - 1][iNeuron] * _outLayer_weight[iOutput][iNeuron]);

            _outLayer_output[iOutput] = _sigmoid(_outLayer_input[iOutput]);
		}

        for(iOutput=0 ; iOutput<_outputNum ; iOutput++)
        {
            _delta_outLayer_output[iOutput] = (_actualOutput[iPeriod] - _outLayer_output[iOutput]);
			
			_actualOutput[iPeriod] = (_actualOutput[iPeriod] * (_desire_max - _desire_min)) + _desire_min;
			_outLayer_output[iOutput] = (_outLayer_output[iOutput] * (_desire_max - _desire_min)) + _desire_min;

			fprintf(fp," %.6f %.6f\n",_actualOutput[iPeriod] , _outLayer_output[iOutput]);
        }
	//	for(iHidden=0 ; iHidden<_hiddenNum; iHidden++)
	//	{
	//		_hidden_output[iHidden] = 0;
	//		for(iInput=0 ; iInput<_inputNum ; iInput++)
	//			_hidden_output[iHidden] = _hidden_output[iHidden] + (_predictData[iPeriod][iInput] * _weight_input2Hidden[iHidden][iInput]);

	//		_hidden_output[iHidden] = 1.0 / (1.0 + exp(-_hidden_output[iHidden]));
	//	}


	//	for(iOutput=0 ; iOutput<_outputNum ; iOutput++)
	//	{
	//		_output[iOutput] = 0;
	//		for(iHidden=0 ; iHidden<_hiddenNum ; iHidden++)
	//			_output[iOutput] = _output[iOutput] + (_hidden_output[iHidden] * _weight_hidden2Output[iOutput][iHidden]);

	//		_output[iOutput] = 1.0 / (1.0 + exp(-_output[iOutput]));
	//	}

	//	for(iOutput=0 ; iOutput<_outputNum ; iOutput++)
	//	{
	//		_delta_output[iOutput] = (_actualOutput[iPeriod] - _output[iOutput]);
	//		
	//		_actualOutput[iPeriod] = (_actualOutput[iPeriod] * (_desire_max - _desire_min)) + _desire_min;
	//		_output[iOutput] = (_output[iOutput] * (_desire_max - _desire_min)) + _desire_min;

	//		fprintf(fp," %.6f %.6f\n",_actualOutput[iPeriod] , _output[iOutput]);
	//		int roger = 100;
	//	}
	}
	fclose(fp);
}
//
void TNeural_NetWork::_deleteData()
{
    if(_stock_idx)
    {
		delete [] _stock_idx;
        _stock_idx = NULL;
    }
	if(_stock_date)
    {
		delete [] _stock_date;
        _stock_date = NULL;
    }
	if(_stock_close)
    {
		delete [] _stock_close;
        _stock_close = NULL;
    }
	if(_stock_open)
    {
		delete [] _stock_open;
        _stock_open = NULL;
    }
	if(_stock_highest)
    {
		delete [] _stock_highest;
        _stock_highest = NULL;
    }
	if(_stock_lowest)
    {
		delete [] _stock_lowest;
        _stock_lowest = NULL;
    }
	if(_stock_piece)
    {
		delete [] _stock_piece;
        _stock_piece = NULL;
    }
	if(_stock_name)
    {
		delete [] _stock_name;
        _stock_name = NULL;
    }


    if(_5average_point)
    {
        delete [] _5average_point;
        _5average_point = NULL;
    }
    if(_10average_point)
    {
		delete [] _10average_point;
        _10average_point = NULL;
    }
    if(_15average_point)
    {
		delete [] _15average_point;
        _15average_point = NULL;
    }
    if(_20average_point)
    {
		delete [] _20average_point;
        _20average_point = NULL;
    }

    if(_9K)
    {
		delete [] _9K;
        _9K = NULL;
    }
    if(_9D)
    {
		delete [] _9D;
        _9D = NULL;
    }
    if(_DII)
    {
		delete [] _DII;
        _DII = NULL;
    }
    if(_12EMA)
    {
		delete [] _12EMA;
        _12EMA = NULL;
    }
    if(_26EMA)
    {
		delete [] _26EMA;
        _26EMA = NULL;
    }
    if(_MACD_DIF)
    {
		delete [] _MACD_DIF;
        _MACD_DIF = NULL;
    }
    if(_MACD_DEM)
    {
		delete [] _MACD_DEM;
        _MACD_DEM = NULL;
    }
    if(_MACD_OSC)
    {
		delete [] _MACD_OSC;
        _MACD_OSC = NULL;
    }

    if(_trainData)
    {
		delete [] _trainData;
        _trainData = NULL;
    }
    if(_desireOutput)
    {
		delete [] _desireOutput;
        _desireOutput = NULL;
    }
    if(_predictData)
    {
		delete [] _predictData;
        _predictData = NULL;
    }
    if(_actualOutput)
    {
		delete [] _actualOutput;
        _actualOutput = NULL;
    }

    if(_neurons_weight)
    {
		delete [] _neurons_weight;
        _neurons_weight = NULL;
    }
    if(_delta_neurons_weight)
    {
		delete [] _delta_neurons_weight;
        _delta_neurons_weight = NULL;
    }
    if(_neurons_input)
    {
		delete [] _neurons_input;
        _neurons_input = NULL;
    }
    if(_neurons_output)
    {
		delete [] _neurons_output;
        _neurons_output = NULL;
    }
    if(_delta_neurons_output)
    {
		delete [] _delta_neurons_output;
        _delta_neurons_output =  NULL;
    }

    if(_outLayer_weight)
    {
		delete [] _outLayer_weight;
        _outLayer_weight = NULL;
    }
    if(_delta_outLayer_weight)
    {
		delete [] _delta_outLayer_weight;
        _delta_outLayer_weight = NULL;
    }
    if(_outLayer_input)
    {
		delete [] _outLayer_input;
        _outLayer_input = NULL;
    }
    if(_outLayer_output)
    {
		delete [] _outLayer_output;
        _outLayer_output = NULL;
    }
    if(_delta_outLayer_output)
    {
        delete [] _delta_outLayer_output;
        _delta_outLayer_output = NULL;
    }
}