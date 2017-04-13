/* 
 * File:   FuncSigmoid.cpp
 * Author: sim
 * 
 * Created on 26 de Dezembro de 2016, 22:12
 */

#include "FuncSigmoid.h"
#include <cmath>

FuncSigmoid::FuncSigmoid() {
}

double FuncSigmoid::run(double x){
    return (1/(1+exp(-x)));
}

double FuncSigmoid::derive(double x){
    double r = this->run(x);
    return ((1 - r) * r);
}

FuncSigmoid::FuncSigmoid(const FuncSigmoid& orig) {
}

FuncSigmoid::~FuncSigmoid() {
}

