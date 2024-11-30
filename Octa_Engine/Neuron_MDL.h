#pragma once
#include <functional>
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
	std::function<double(double)> activationFunction;
	double weights;
	double bias;
	int inputsCount;
	double output = 0;

public:
	Neuron();
	Neuron(std::function<double(double)> actFunction, double weights, double bias, int inputsCount);
	double GetOutput(double input)
	{
		double linearOutput = weights * input + bias;
		return activationFunction(linearOutput);
	}
};