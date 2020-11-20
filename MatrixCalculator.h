//
// Created by djnic on 19.11.2020.
//

#ifndef CLASS_TRAINIG_MATRIXCALCULATOR_H
#define CLASS_TRAINIG_MATRIXCALCULATOR_H


#include "BasicCalculator.h"
#include "Matrix.h"

class MatrixCalculator : public BasicCalculator {
public:
    Value calculate(Matrix firstVar, Matrix secondVar, std::string sign) {
        Matrix *result = new Matrix();
        if (sign == "+") result = &(firstVar + secondVar);
        else if (sign == "-") result = &(firstVar - secondVar);
        else if (sign == "*") result = &(firstVar * secondVar);
        else if (sign == "/") std::cerr << "Unsupported operation..." << std::endl;
        return Value(result);
    }
};


#endif //CLASS_TRAINIG_MATRIXCALCULATOR_H
