#include "Engine.h"
#include "ActivationFunctions.h"

#include <iostream>

int main() {
	Engine session;
	int input;
	std::vector<double> weights, inputs;

	session.Initialize();

	Neuron A = session.CreateNeuron(Softsign, 0.01);
	A.SetInputs({ 0.95, 0.21, 0.76 });
	A.SetWeights({ 0.51, 0.72, 0.33 });
	A.ComputeOutput();

	std::cout << "Neuron output:\t" << A.GetOutput() << std::endl;

	A.Reset();
	
	std::cin >> input;
	
	return 0;
}