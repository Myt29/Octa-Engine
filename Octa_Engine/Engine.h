#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <thread>

#include "Neuron_MDL.h"
#include "ActivationFunctions.h"


using namespace ActivationFunctions;

class Engine {
public:
	Engine() {
		std::cout << "Session started...\n\n";
	}
	void Initialize();
	Neuron CreateNeuron(std::function<double(double)> actFunction, double bias);



	~Engine() {
		std::cout << "\nSession killed..." << std::endl;
	}
};