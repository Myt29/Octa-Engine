#pragma once

#include <cmath>
#include <functional>
#include <iostream>

namespace ActivationFunctions {
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

    bool TestSigmoid()
    {
        return (Sigmoid(1) == 0.7310585786300049);
    }

    bool TestSigmoidD() {
        return (SigmoidDerivative(1) == 0.19661193324148185);
    }

    bool TestReLU() {
        return (ReLU(1) == 1.0);
    }

    bool TestReLUD() {
        return (ReLUDerivative(1) == 1.0);
    }

    bool TestTanh() {
        return (Tanh(1) == 0.7615941559557649);
    }

    bool TestTanhD() {
        return (TanhDerivative(1) == 0.41997434161402614);
    }

    bool TestFunctions(int option) {
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
