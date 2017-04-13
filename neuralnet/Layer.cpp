/* 
 * File:   Layer.cpp
 * Author: abel
 * 
 * Created on 2 de Dezembro de 2016, 14:54
 */

#include "Layer.h"
#include "neuron/AbstractNeuron.h"
#include <vector>
#include <map>
#include "../core/ObjectID.h"
#include "LayerType.h"

using namespace std;

Layer::Layer() {
}

Layer::Layer(LayerType type){
    this->setType(type);
}

Layer::Layer(const Layer& orig) {
}

Layer::~Layer() {
}

void Layer::addNeuron(AbstractNeuron* neuron){
    this->neurons.insert(make_pair(&neuron->getId(),neuron));
}

AbstractNeuron& Layer::getNeuron(int i){
    AbstractNeuron* tmp = NULL;
    for(auto &n : this->neurons){
        if(n.first->getValue() == i){
            tmp = n.second;
            break;
        }
    }
    if(tmp == NULL){
        throw runtime_error("There is no neuron with the informed ID in the layer.");
    }
    return *tmp;
}

/**
 * 
 */
vector<AbstractNeuron*> Layer::getNeurons(){
    vector<AbstractNeuron*> nL;
    for(auto &n : this->neurons){
        nL.push_back(n.second);
    }
    return nL;
}

LayerType Layer::getType(){
    return this->type;
}

void Layer::setType(LayerType type){
    this->type = type;
}

