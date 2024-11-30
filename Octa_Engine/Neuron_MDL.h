#pragma once
#include <functional>
#include <vector>
#include "Net_MDL.cpp"

class Check_MDL {
private:
	const int CONTROL_INPUT;
public:
	static bool Check_Connection();
	static bool Check_ControlPoint();

};


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