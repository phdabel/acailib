/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncSigmoid.h
 * Author: sim
 *
 * Created on 26 de Dezembro de 2016, 22:12
 */

#ifndef FUNCSIGMOID_H
#define FUNCSIGMOID_H
#include "IActivationFunction.h"

class FuncSigmoid : public IActivationFunction {
public:
    FuncSigmoid();
    FuncSigmoid(const FuncSigmoid& orig);
    double run(double x);
    double derive(double x);
    virtual ~FuncSigmoid();
private:

};

#endif /* FUNCSIGMOID_H */

