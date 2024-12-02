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
	// Methods of constructors
	Neuron();
	Neuron(std::function<double(double)> actFunction, double bias);

	// Setters of neuron parameters
	void SetWeights(const std::vector<double>& newWeights);
	void SetInputs(const std::vector<double>& newInputs);
	void SetBias(double bias);
	void SetAFunc(std::function<double(double)> newFunction);

	// Method for computing output of neuron
	void ComputeOutput();

	// List of Getter methods
	double GetOutput();
	void GetWeights(std::vector<double>& outWeights);
	void GetInputs(std::vector<double>& outInputs);
	double GetBias();

	// List of methods for adding new weight and input
	void AddWeight(double newWeight);
	void AddInput(double newInput);

	// Method for reset neuron data
	void Reset();
};