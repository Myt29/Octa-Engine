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
		std::cout << "Initialization ERROR:\n";
		if (!activationFunctionsTrue) {
			std::cout << "Activation functions are incorrect or not connected\n";
		}
		if (!NeuronMDLEcho) {
			std::cout << "Neuron module not connected\n";
		}
		std::cout << "\n";
	}

	std::cout << "Session address:\t" << this << std::endl;
	std::cout << "Thread iD:\t\t" << std::this_thread::get_id() << std::endl;

}

Neuron Engine::CreateNeuron(std::function<double(double)> actFunction, double bias)
{
	Neuron temprorary(actFunction, bias);
	return temprorary;
}

