//
// Created by djnic on 18.11.2020.
//

#include <iostream>
#include "BasicCalculator.h"

Value BasicCalculator::calculate(double firstVar, double secondVar, std::string sign) {
    double result;
    if (sign == "+") result = firstVar + secondVar;
    else if (sign == "-") result = firstVar - secondVar;
    else if (sign == "*") result = firstVar * secondVar;
    else if (sign == "/") result = firstVar / secondVar;
    saveInMemory(firstVar, secondVar, sign, result);
    return Value(result);
}

Value BasicCalculator::calculate(double *vars, size_t size, std::string sign) {
    double result;
    if (sign == "+") for (int i = 0; i < size; i++) result += vars[i];
    else if (sign == "-") {
        result = vars[0];
        for (int i = 1; i < size; i++) result -= vars[i];
    } else if (sign == "*") {
        result = vars[0];
        for (int i = 1; i < size; i++) result *= vars[i];
    } else if (sign == "/") {
        result = vars[0];
        for (int i = 1; i < size; i++) result /= vars[i];
    }
    saveInMemory(vars, size, sign, result);
    return Value(result);
}

void BasicCalculator::memory() {
    if (this->historyAvailable) {
        std::string vars = "[";
        for (int i = 0; i < this->size; i++)
            vars += std::to_string(this->vars[i]) + " " + (i != this->size - 1 ? sign : "");
        std::string memoryState = "[" +
                                  (!this->varsPopulated ? std::to_string(firstVar) + " " + sign + " " +
                                                          std::to_string(secondVar)
                                                        : vars)
                                  + " = " + std::to_string(result) + "]";
        std::cout << memoryState << std::endl;
    } else
        std::cout << "There's no memory available..." << std::endl;
}

void BasicCalculator::saveInMemory(double firstVar, double secondVar, std::string sign, double result) {
    this->firstVar = firstVar;
    this->secondVar = secondVar;
    this->sign = sign;
    this->result = result;
    this->size = 0;
    this->varsPopulated = false;
    this->historyAvailable = true;
}

void BasicCalculator::saveInMemory(double *vars, size_t size, std::string sign, double result) {
    this->vars = vars;
    this->sign = sign;
    this->result = result;
    this->size = size;
    this->varsPopulated = true;
    this->historyAvailable = true;
}
