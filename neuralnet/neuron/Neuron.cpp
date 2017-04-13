/* 
 * File:   Neuron.cpp
 * Author: abel
 * 
 * Created on 14 de Novembro de 2016, 11:58
 */

#include "Neuron.h"

#include "../../core/UnitType.h"

using namespace std;

Neuron::Neuron() {
    AbstractNeuron::setType(UnitType::NEURON);
}

std::string Neuron::getIndex(){
    return this->index;
}

void Neuron::setIndex(std::string index){
    this->index = index;
}

double Neuron::getValue(){
    return this->value;
}

void Neuron::setValue(double value){
    this->value = value;
}

Neuron::Neuron(const Neuron& orig) {
}

Neuron::~Neuron() {

}

