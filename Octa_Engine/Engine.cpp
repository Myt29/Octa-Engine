#include <iostream>

#include "Engine.h"

void Engine::Initialize() {
	bool activationFunctionsTrue = false, NeuronMDLEcho = false;
	activationFunctionsTrue = TestFunctions(0);
	NeuronMDLEcho = GetEcho();
	if (activationFunctionsTrue && NeuronMDLEcho) {
		std::cout << "Engine successfully initialized\n";
	}
	else {
		std::cout << "Engine initialization failure\n";
	}
}

Neuron Engine::CreateNeuron(std::function<double(double)> actFunction, double bias)
{
	Neuron temprorary(actFunction, bias);
	return temprorary;
}

