#include "Engine.h"
#include "ActivationFunctions.h"

#include <iostream>

int main() {
	Engine session;
	int input;
	std::vector<double> weights, inputs;

	session.Initialize();

	Neuron A = session.CreateNeuron(Sigmoid, 0.01);

	A.SetWeights({ 0.25, 0.55, 0.11, 0.95 });
	A.SetInputs({ 0.75, 0.22, 0.96, 0.88 });
	A.ComputeOutput();
	std::cout << "Neuron Sigmoid output:\t|\t" << A.GetOutput() << std::endl;

	A.AddWeight(0.25); A.AddInput(0.71);
	A.ComputeOutput();
	std::cout << "New neuron output:\t\t" << A.GetOutput() << std::endl;

	A.GetWeights(weights);
	for (size_t i = 0; i < weights.size(); i++) {
		std::cout << "Weight: " << i << "\t" << weights[i] << std::endl;
	}
	std::cout << "\n";
	A.GetInputs(inputs);
	for (size_t i = 0; i < weights.size(); i++) {
		std::cout << "Inputs: " << i << "\t" << inputs[i] << std::endl;
	}

	A.Reset();
	
	std::cin >> input;
	
	return 0;
}