/* 
 * File:   Layer.cpp
 * Author: abel
 * 
 * Created on 2 de Dezembro de 2016, 14:54
 */

#include "Layer.h"
#include "Neuron.h"
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

void Layer::addNeuron(Neuron* neuron){
    this->neurons.insert(make_pair(&neuron->getId(),neuron));
}

vector<Neuron*> Layer::getNeurons(){
    vector<Neuron*> nL;
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

