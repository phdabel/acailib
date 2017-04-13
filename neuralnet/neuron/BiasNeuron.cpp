/* 
 * File:   BiasNeuron.cpp
 * Author: abel
 * 
 * Created on 12 de Abril de 2017, 16:02
 */

#include "BiasNeuron.h"

BiasNeuron::BiasNeuron() {
    AbstractNeuron::setType(UnitType::BIAS);
    this->index = "0";
    this->value = 1.0;
}

BiasNeuron::BiasNeuron(const BiasNeuron& orig) {
}

BiasNeuron::~BiasNeuron() {
}

double BiasNeuron::getValue(){
    return this->value;
}

void BiasNeuron::setValue(double value){
    throw runtime_error("The value of the bias cannot be modified.");
}

std::string BiasNeuron::getIndex(){
    return this->index;
}

void BiasNeuron::setIndex(std::string idx){
    throw runtime_error("The index of the bias cannot be modified.");
}