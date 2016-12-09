/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncTanH.h
 * Author: abel
 *
 * Created on 29 de Novembro de 2016, 11:43
 */

#ifndef FUNCTANH_H
#define FUNCTANH_H

#include "IActivationFunction.h"

class FuncTanH : public IActivationFunction {
public:
    FuncTanH();
    double run(double x);
    double derive(double x);
    FuncTanH(const FuncTanH& orig);
    virtual ~FuncTanH();
private:

};

#endif /* FUNCTANH_H */

