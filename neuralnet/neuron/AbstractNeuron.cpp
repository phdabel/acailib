/* 
 * File:   AbstractNeuron.cpp
 * Author: abel
 * 
 * Created on 13 de Abril de 2017, 09:45
 */

#include "AbstractNeuron.h"

#include "../../core/UnitType.h"
#include "../../core/ObjectID.h"
#include "../../core/Edge.h"
#include <typeinfo>
#include <iostream>
#include <vector>
#include <map>

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

double AbstractNeuron::computeNetwork(){
    double net = 0.0;
    for(auto &edge : this->edges){
        net += edge->eval();
    }
    return net;
}

void AbstractNeuron::setFunction(IActivationFunction &func){
    this->f = &func;
}

IActivationFunction& AbstractNeuron::getFunction(){    
    return *this->f;
}

double AbstractNeuron::eval(int time){
    if(this->edges.size() == 0){
        return this->getValue();
    }else if(this->timeCache == -1 || this->timeCache != time){
        this->timeCache = time;
        this->setValue(this->getFunction().run(this->computeNetwork()));
    }
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

void AbstractNeuron::addEdge(Edge* edge){
    this->edges.push_back(edge);
}

vector<Edge*> AbstractNeuron::getEdges(){
    return this->edges;
}

Edge& AbstractNeuron::getEdge(int ij){
    Edge* tmp = NULL;
    for(auto &edge : this->edges){
        if(edge->getId().getValue() == ij){
            tmp = edge;
            break;
        }
    }
    if(tmp == NULL){
        throw runtime_error("There is no edge with the informed ID in the neuron.");
    }
    return *tmp;
}

string AbstractNeuron::toString(){
    return "Object of type "+string(typeid(this).name())+" with ID "+to_string(this->getId().getValue());
}

AbstractNeuron::AbstractNeuron(const AbstractNeuron& orig) {
}

AbstractNeuron::~AbstractNeuron() {

}

