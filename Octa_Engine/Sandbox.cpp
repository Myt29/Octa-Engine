#include "Engine.h"
#include "ActivationFunctions.h"

#include <iostream>

int main() {
	Engine Session;
	int input;

	Session.Initialize();

	Neuron a = Session.CreateNeuron(SigmoidDerivative, 0.7);
	std::cout << "Neuron A. Address: " << &a << "\t Output: " << a.GetOutput(1) << std::endl;

	std::cin >> input;
	
	return 0;
}