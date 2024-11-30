#include "Neuron_MDL.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

int executionCode;

// Static methods for checking module reliability
bool Check_MDL::Check_Connection() {
	return true;
}
bool Check_MDL::Check_ControlPoint()
{
	return 1;
}

// Methods of class Neuron

Neuron::Neuron() {
	bias = 0;
	output = 0;
}
Neuron::Neuron(std::function<double(double)> actFunction, double bias) {
	activationFunction = actFunction;
	this->bias = bias;
}

void Neuron::ComputeOutput()
{
	double sum = bias;
	for (size_t i = 0; i < inputs.size(); ++i) {
		sum += inputs[i] * weights[i];
	}
	output = activationFunction(sum);
}
double& Neuron::GetOutput(double input)
{
	return output;
}
