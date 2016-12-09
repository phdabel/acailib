/* 
 * File:   FuncRectifier.cpp
 * Author: abel
 * 
 * Created on 29 de Novembro de 2016, 11:55
 */

#include "FuncRectifier.h"


FuncRectifier::FuncRectifier() {
}

double FuncRectifier::run(double x){
    return (x < 0.0) ? 0.0 : x;
}

double FuncRectifier::derive(double x){
    return (x < 0.0) ? 0.0 : 1.0;
}

FuncRectifier::FuncRectifier(const FuncRectifier& orig) {
}

FuncRectifier::~FuncRectifier() {
}

