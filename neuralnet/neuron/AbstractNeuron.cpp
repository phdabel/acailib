/*
 * File:   AbstractNeuron.cpp
 * Author: abel
 *
 * Created on 13 de Abril de 2017, 09:45
 */

#include "AbstractNeuron.h"

#include "../../core/UnitType.h"
#include "../../core/ObjectID.h"
#include <typeinfo>

using namespace std;

AbstractNeuron::AbstractNeuron() {
}

UnitType AbstractNeuron::getType(){
    return this->type;
}

void AbstractNeuron::setType(UnitType type){
    this->type = type;
}

ObjectID& AbstractNeuron::getId(){
    return *this->id;
}

void AbstractNeuron::setId(ObjectID *obj){
    this->id = obj;
}

void AbstractNeuron::setFunction(IActivationFunction &func){
    this->f = &func;
}

IActivationFunction& AbstractNeuron::getFunction(){
    return *this->f;
}

double AbstractNeuron::eval(int time){
    return this->getValue();
}

double AbstractNeuron::getDelta(){
    return this->delta;
}

void AbstractNeuron::setDelta(double delta){
    this->delta = delta;
}

double AbstractNeuron::getError(){
    return this->error;
}

void AbstractNeuron::setError(double error){
    this->error = error;
}

double AbstractNeuron::getNet(){
    return this->net;
}

void AbstractNeuron::setNet(double net){
    this->net = net;
}

string AbstractNeuron::toString(){
    return "Object of type "+string(typeid(this).name())+" with ID "+to_string(this->getId().getValue());
}

AbstractNeuron::AbstractNeuron(const AbstractNeuron& orig) {
}

AbstractNeuron::~AbstractNeuron() {
}
