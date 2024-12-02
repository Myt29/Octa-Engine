#include "Neuron_MDL.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>

int executionCode;

bool GetEcho() {
	return true;
}

// List of constructor methods
Neuron::Neuron()
{
	bias = 0;
	output = 0;
}
Neuron::Neuron(std::function<double(double)> actFunction, double Mbias) {
	activationFunction = actFunction;
	this->bias = Mbias;
}

// List of Setter methods
void Neuron::SetWeights(const std::vector<double>& newWeights) {
	if (newWeights.empty()) {
		std::cout << "Weights could not contain empty value!\n";
	}
	else {
		weights = newWeights;
	}
}
void Neuron::SetInputs(const std::vector<double>& newInputs)
{
	if (newInputs.size() != weights.size()) {
		std::cout << "Count of weights and inputs need to be the same!\n";
	}
	if (newInputs.empty()) {
		std::cout << "Weights could not contain empty value!\n";
	}
	else {
		inputs = newInputs;
	}
}
void Neuron::SetBias(double newBias)
{
	bias = newBias;
}
void Neuron::SetAFunc(std::function<double(double)> newFunction)
{
	activationFunction = newFunction;
}

// Method for computing output of neuron
void Neuron::ComputeOutput()
{
	double weightedSum = 0.0;
	for (size_t i = 0; i < inputs.size(); i++) {
		weightedSum += inputs[i] * weights[i];
	}
	weightedSum += bias;
	output = activationFunction(weightedSum);
}

// List of Getter methods
double Neuron::GetOutput()
{
	return output;
}
void Neuron::GetWeights(std::vector<double>& outWeights)
{
		outWeights = weights;
}
void Neuron::GetInputs(std::vector<double>& outInputs)
{
	outInputs = inputs;
}
double Neuron::GetBias()
{
	return bias;
}

// List of methods for adding new weight and input
void Neuron::AddWeight(double newWeight) {
	weights.push_back(newWeight);
}
void Neuron::AddInput(double newInput) {
	inputs.push_back(newInput);
}

void Neuron::Reset()
{
	activationFunction = NULL;
	weights = {};
	inputs = {};
	bias = 0;
	output = 0;
}
