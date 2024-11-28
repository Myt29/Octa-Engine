#pragma once
#include "Net_MDL.cpp"

class Check_MDL {
private:
	const int CONTROL_INPUT;
public:
	static bool Check_Connection();
	static bool Check_Control_Summ();

};

class Activation_Functions {
public:
	static double Sigmoid(double input);
	static double SigmoidDerivative(double input);
	static double ReLU(double input);
	static double ReLUDerivative(double input);
	static double Tanh(double input);
	static double TanhDerivative(double input);
};

class Neuron {
private:
	double weights;
	double bias;
	int inputsCount;

public:
	Neuron();
	Neuron(double weights, double bias, int inputsCount);

};