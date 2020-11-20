//
// Created by djnic on 18.11.2020.
//

#ifndef CLASS_TRAINIG_BASICCALCULATOR_H
#define CLASS_TRAINIG_BASICCALCULATOR_H


#include "Calculator.h"

class BasicCalculator : public Calculator {
private:
    double firstVar;
    double secondVar;
    double *vars;
    double result;

    size_t size = 0;
    bool varsPopulated = false;
    bool historyAvailable = false;
    std::string sign;

    void saveInMemory(double firstVar, double secondVar, std::string sign, double result);

    void saveInMemory(double *vars, size_t size, std::string sign, double result);

public:
    Value calculate(double firstVar, double secondVar, std::string sign) override;

    Value calculate(double vars[], size_t size, std::string sign);

    void memory();

};


#endif //CLASS_TRAINIG_BASICCALCULATOR_H
