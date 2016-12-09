/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncTanH.cpp
 * Author: abel
 * 
 * Created on 29 de Novembro de 2016, 11:43
 */

#include "FuncTanH.h"
#include <cmath>

FuncTanH::FuncTanH() {
}

double FuncTanH::run(double x){   
    return (2/(1+exp(-2*x)))-1;
}

double FuncTanH::derive(double x){
    return 1 - pow(this->run(x),2);
}

FuncTanH::FuncTanH(const FuncTanH& orig) {
}

FuncTanH::~FuncTanH() {
}

