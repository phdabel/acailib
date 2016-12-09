/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncRectifier.h
 * Author: abel
 *
 * Created on 29 de Novembro de 2016, 11:55
 */

#ifndef FUNCRECTIFIER_H
#define FUNCRECTIFIER_H
#include "IActivationFunction.h"

class FuncRectifier : public IActivationFunction {
public:
    FuncRectifier();
    double run(double x);
    double derive(double x);
    FuncRectifier(const FuncRectifier& orig);
    virtual ~FuncRectifier();
private:

};

#endif /* FUNCRECTIFIER_H */

