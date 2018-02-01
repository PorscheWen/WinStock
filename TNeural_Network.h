#pragma once
#include <afx.h>

class TNeural_NetWork
{
public:
    TNeural_NetWork(void);
	~TNeural_NetWork();

    void _readData(CString file_name);
	void _readData_fromPorsche(CString file_name);
    void _calculateAverage();
	void _calculateIndicators();


    ////
	void _buildNeural(const int &_inputNum , const int &_hiddenLayerNum , int *_neuronsNum , const int &_outputNum);
    //
	void _initialNeural(const int &_inputNum , const int &_hiddenLayerNum , int *_neuronsNum , const int &_outputNum);
    void _setTrainingData(const int &flag,
						                    const int &_inputNum, 
									        const int &_training_period , int &_predict_period , const bool &op_coincidence,
									        double &_desire_max , double &_desire_min);
	//
	void _learning(const int &_inputNum , const int &_hiddenLayerNum , int *_neuronsNumList , const int &_outputNum,
				              const int &_training_period);
    void _hiddenCalculate(const int &_which_hiddenLayer , const int &_neuronsNum,
                                            double *_inputData , const int &_inputNum);
	double _partialError_partialOLOutput(const int &_which_output , const int &flag);
	double _partialOLOutput_partialOLInput(const int &_which_output , const int &flag);
	double _partialOLInput_partialOLWeight(const int &_which_hiddenLayer , const int &_which_neuron);
	double _partialOLInput_partialHLOutput(const int &_which_neuron, 
										                                   const int &_which_output);
	void _hiddenBackPropagationCalculate(double *_inputData , const int &_inputNum,
										                                   const int &_which_hiddenLayer , const int &_neuronsNum,
															               const int &_hiddenLayerNum , int *_neuronsNumList,
															               const int & _outputNum);
	double _partialError_partialHLOutput(const int &_which_hiddenLayer , const int &_which_neuron,
										                             const int &_hiddenLayerNum , int *_neuronsNumList,
										                             const int & _outputNum);
	double _partialHLOutput_partialHLInput(const int &_which_hiddenLayer , const int &_which_neuron , const int &flag);
	double _partialHLInput_partialHLWeight(double *_inputData , const int &_which_neuron);
	double _partialHLInput_partialHLOutput(const int &_which_hiddenLayer , const int &_which_neuron,
															               const int &_which_output);

	double _sigmoid(const double &a);
    double _derivativeOfSigmoid(const double &a , const int &flag);
	double _relu(const double &a);
    double _softmax_denominator_sum(const double *denominator  , const int &_denominator_count);
    double _softmax(const double &numerator , const double &denominator);
	//
	void _predict(const int &_inputNum , const int &_hiddenLayerNum , int *_neuronsNumList , const int &_outputNum,
				           const int &_predict_period,
						   double &_desire_max , double &_desire_min);
    //
    void _deleteData();




    int _stock_num , _stock_price_day;
    int *_stock_idx;
	double *_stock_date;
	float **_stock_open , **_stock_highest , **_stock_lowest , **_stock_close;
	float **_stock_piece;
    char **_stock_name;

    float **_5average_point , **_10average_point , **_15average_point , **_20average_point;
	float **_9K;
	float **_9D;
	float **_DII;
	float **_12EMA;
	float **_26EMA;
	float **_MACD_DIF;
	float **_MACD_DEM;
	float **_MACD_OSC;


    //
    double **_trainData;
    double *_desireOutput;
	double **_predictData;
	double *_actualOutput;

    double *** _neurons_weight;
    double *** _delta_neurons_weight;
    double ** _neurons_input;
    double ** _neurons_output;
    double **_delta_neurons_output;

    double** _outLayer_weight;
	double** _delta_outLayer_weight;
    double* _outLayer_input;
    double* _outLayer_output;
	double* _delta_outLayer_output;

	double _learning_rate;
};