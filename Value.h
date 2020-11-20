//
// Created by djnic on 19.11.2020.
//

#ifndef CLASS_TRAINIG_VALUE_H
#define CLASS_TRAINIG_VALUE_H


#include "Matrix.h"

class Value {
public:
    double dValue;
    Matrix *mValue;

    Value(double dValue) : dValue(dValue) {};

    Value(Matrix *mValue) : mValue(mValue) {};
};


#endif //CLASS_TRAINIG_VALUE_H
