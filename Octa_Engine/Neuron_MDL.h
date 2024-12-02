#pragma once
#include <functional>
#include <vector>

bool GetEcho();

class Neuron {
private:
	std::function<double(double)> activationFunction;
	std::vector<double> weights;
	std::vector<double> inputs;
	double bias;
	double output;

public:
	Neuron();
	Neuron(std::function<double(double)> actFunction, double bias);

	void SetWeights();
	void SetInputs();

	void ComputeOutput();
	double& GetOutput(double input);
	
};