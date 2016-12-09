/* 
 * File:   Neuron.cpp
 * Author: abel
 * 
 * Created on 14 de Novembro de 2016, 11:58
 */

#include "Neuron.h"

#include "../core/UnitType.h"
#include "../core/ObjectID.h"
#include "../core/Edge.h"
#include <typeinfo>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

Neuron::Neuron() {
    this->type = UnitType::NEURON;
}

UnitType Neuron::getType(){
    return this->type;
}

ObjectID& Neuron::getId(){
    return *this->id;
}

void Neuron::setId(ObjectID *obj){
    this->id = obj;
}

double Neuron::computeNetwork(){
    double net = 0.0;
    for(auto &edge : this->edges){
        net += edge->eval();
    }
    return net;
}

void Neuron::setFunction(IActivationFunction &func){
    this->f = &func;
}

IActivationFunction& Neuron::getFunction(){    
    return *this->f;
}

double Neuron::eval(int time){
    if(this->edges.size() == 0){
        return this->getValue();
    }else if(this->timeCache == -1 || this->timeCache != time){
        this->timeCache = time;
        this->setValue(this->getFunction().run(this->computeNetwork()));
    }
    return this->getValue();
}

double Neuron::getValue(){
    return this->value;
}

void Neuron::setValue(double value){
    this->value = value;
}

double Neuron::getDelta(){
    return this->delta;
}

void Neuron::setDelta(double delta){
    this->delta = delta;
}

double Neuron::getError(){
    return this->error;
}

void Neuron::setError(double error){
    this->error = error;
}

void Neuron::addEdge(Edge* edge){
    this->edges.push_back(edge);
}

vector<Edge*> Neuron::getEdges(){
    return this->edges;
}

string Neuron::toString(){
    return "Object of type "+string(typeid(this).name())+" with ID "+to_string(this->getId().getValue());
}

Neuron::Neuron(const Neuron& orig) {
}

Neuron::~Neuron() {

}

