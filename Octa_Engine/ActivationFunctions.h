#pragma once

#include <cmath>
#include <functional>
#include <iostream>

const int TESTING_VALUE = 1;

namespace ActivationFunctions {

    // Realization of activation functions
    inline double Sigmoid(double input)
    {
        return 1.0 / (1.0 + std::exp(-input));
    }
    inline double SigmoidDerivative(double input)
    {
        double sigmoid = Sigmoid(input);
        return sigmoid * (1 - sigmoid);
    }
    inline double ReLU(double input)
    {
        return std::max(0.0, input);
    }
    inline double ReLUDerivative(double input)
    {
        return (input > 0) ? 1.0 : 0.0;
    }
    inline double Tanh(double input)
    {
        return std::tanh(input);
    }
    inline double TanhDerivative(double input)
    {
        double tanh = Tanh(input);
        return 1 - tanh * tanh;
    }

    // Testing methods of activation functions
    inline bool TestSigmoid()
    {
        return (Sigmoid(TESTING_VALUE) == 0.7310585786300049);
    }
    inline bool TestSigmoidD() {
        return (SigmoidDerivative(TESTING_VALUE) == 0.19661193324148185);
    }
    inline bool TestReLU() {
        return (ReLU(TESTING_VALUE) == 1.0);
    }
    inline bool TestReLUD() {
        return (ReLUDerivative(TESTING_VALUE) == 1.0);
    }
    inline bool TestTanh() {
        return (Tanh(TESTING_VALUE) == 0.7615941559557649);
    }
    inline bool TestTanhD() {
        return (TanhDerivative(TESTING_VALUE) == 0.41997434161402614);
    }

    // Function of testin activation functions using testing option
    inline bool TestFunctions(int option) {
        bool correct = false;
        switch (option) {
        case 0: {
            bool sigmoid, sigmoidD, relu, reluD, tanh, tanhD;
            sigmoid = TestSigmoid();
            sigmoidD = TestSigmoidD();
            relu = TestReLU();
            reluD = TestReLUD();
            tanh = TestTanh();
            tanhD = TestTanhD();
            if (sigmoid && sigmoidD && relu && reluD && tanh && tanhD) {
                correct = true;
            }
            else{
                std::cout << "Activation functions testing failure\n";
            }
            break;
        }
        case 1:
            correct = TestSigmoid();
            break;
        case 2:
            correct = TestSigmoidD();
            break;
        case 3:
            correct = TestReLU();
            break;
        case 4:
            correct = TestReLUD();
            break;
        case 5:
            correct = TestTanh();
            break;
        case 6: {
            correct = TestTanhD();
            break;
        }
        default:
            std::cout << "Option from 0 to 6" << std::endl;
            break;
        }
        return correct;
    }
}
