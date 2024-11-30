#include <iostream>
#include "Neuron_MDL.h"

#define DEBUG

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
	
	return 0;
}

Engine::Engine() {
	bool Neu_MDL_Connected = Check_MDL::Check_Connection();
	bool Neu_MDL_ControlSumm = Check_MDL::Check_Control_Summ();
	if (Neu_MDL_Connected && Neu_MDL_ControlSumm){
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
	Neuron A(Activation_Functions::Tanh, 0.5, 0.1, 2);
	std::cout << "Neuron Output:\t\t" << A.GetOutput(0.7) << std::endl;
#ifdef DEBUG
	std::cout << "RAM is allocated:\t" << ArrSum/1000.0 << " kB\n\n";
#endif		//DEBUG

}