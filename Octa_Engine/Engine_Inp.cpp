#include <iostream>
#include "Neuron_MDL.h"
#include "ActivationFunctions.h"

#define DEBUG

using namespace ActivationFunctions;

class Engine {
private:
	int memorySize = 10;
	Neuron* pNeuronMemory;

public:
	Engine();
	~Engine()
	{
		delete[] pNeuronMemory;
		pNeuronMemory = nullptr;
		std::cout << "RAM cleared successfully\n";
	}
};

int main() {
	Engine engine;
	
	Neuron a(ReLU, 0.07);

	return 0;
}

Engine::Engine() {
	bool Neu_MDL_Connected = Check_MDL::Check_Connection();
	bool Neu_MDL_ControlPoint = Check_MDL::Check_ControlPoint();
	if (Neu_MDL_Connected && Neu_MDL_ControlPoint){
		std::cout << "Neuron module is able to work\n\n";
	}
	else {
		std::cout << "ERROR:\tNeuron module connecting failure\n\n";
	}

	int ArrSum = 0;
	pNeuronMemory = new Neuron[memorySize];
	for (int i = 0; i < memorySize; i++) {
		ArrSum += sizeof(pNeuronMemory[i]);
	}
	Neuron A(Tanh, 0.1);
	std::cout << "Neuron Output:\t\t" << A.GetOutput(0.7) << std::endl;
#ifdef DEBUG
	std::cout << "RAM is allocated:\t" << ArrSum/1000.0 << " kB\n\n";
#endif		//DEBUG

}