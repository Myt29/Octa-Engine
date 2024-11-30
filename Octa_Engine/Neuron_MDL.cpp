#include "Neuron_MDL.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int executionCode;

// Static methods for checking module reliability
bool Check_MDL::Check_Connection() {
	return true;
}
bool Check_MDL::Check_Control_Summ()
{
	const int CONTROL_INPUT = 0;

	bool sigmoid = false, sigmoidDerivative = false, relu = false, reluDerivative = false, tanh = false, tanhDerivative = false;
	sigmoid = Activation_Functions::Sigmoid(CONTROL_INPUT) == 0.5;
	sigmoidDerivative = Activation_Functions::SigmoidDerivative(CONTROL_INPUT) == 0.25;
	relu = Activation_Functions::ReLU(CONTROL_INPUT) == 0;
	reluDerivative = Activation_Functions::ReLUDerivative(CONTROL_INPUT) == 0;
	tanh = Activation_Functions::Tanh(CONTROL_INPUT) == 0;
	tanhDerivative = Activation_Functions::TanhDerivative(CONTROL_INPUT) == 1;
	if (sigmoid && sigmoidDerivative && relu && reluDerivative && tanh && tanhDerivative) {
		return true;
	}
	else {
		return false;
	}
}


Neuron::Neuron() {
	weights = 0;
	bias = 0;
	inputsCount;
	output = 0;
}
Neuron::Neuron(std::function<double(double)> actFunction, double weights, double bias, int inputsCount) {
	activationFunction = actFunction;
	this->weights = weights;
	this->bias = bias;
	this->inputsCount = inputsCount;
}

// Static methods of activation functions
double Activation_Functions::Sigmoid(double input)
{
	return 1.0/(1.0+std::exp(-input));
}
double Activation_Functions::SigmoidDerivative(double input)
{
	double sigmoid = Sigmoid(input);
	return sigmoid * (1 - sigmoid);
}
double Activation_Functions::ReLU(double input)
{
	return std::max(0.0, input);
}
double Activation_Functions::ReLUDerivative(double input)
{
	return (input > 0) ? 1.0 : 0.0;
}
double Activation_Functions::Tanh(double input)
{
	return std::tanh(input);
}
double Activation_Functions::TanhDerivative(double input)
{
	double tanh = Tanh(input);
	return 1 - tanh * tanh;
}
