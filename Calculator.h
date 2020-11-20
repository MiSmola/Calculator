//
// Created by djnic on 18.11.2020.
//

#ifndef CLASS_TRAINIG_CALCULATOR_H
#define CLASS_TRAINIG_CALCULATOR_H


#include <string>
#include "Value.h"

class Calculator {
public:
    virtual Value calculate(double firstVar, double secondVar, std::string sign) = 0;
};


#endif //CLASS_TRAINIG_CALCULATOR_H
