/*
 * File:   Layer.cpp
 * Author: abel
 *
 * Created on 2 de Dezembro de 2016, 14:54
 */

#include "Layer.h"
#include "neuron/AbstractNeuron.h"
#include <stdexcept>
#include <vector>
#include <map>
#include "../core/ObjectID.h"
#include "../core/UnitType.h"
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
    delete this->weights;
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

/**
 * Cria a WeightMatrix para esta camada.
 * rows = número de neurônios não-bias desta camada.
 * cols = número total de neurônios da camada anterior (incluindo bias).
 */
void Layer::initWeights(int prevNeuronCount, bool random) {
    vector<AbstractNeuron*> curr = this->getNeurons();
    int nonBiasCount = 0;
    for (auto& n : curr)
        if (n->getType() != UnitType::BIAS) nonBiasCount++;

    delete this->weights;
    this->weights = new WeightMatrix(nonBiasCount, prevNeuronCount);
    if (random) this->weights->randomize();
}

WeightMatrix* Layer::getWeights() {
    return this->weights;
}

/**
 * Calcula as ativações desta camada a partir da camada anterior.
 * net_j = Σ_i W[j][i] * x_i   (i percorre todos os neurônios de prev, incluindo bias)
 * out_j = f(net_j)
 */
void Layer::forward(Layer* prev) {
    vector<AbstractNeuron*> prevNeurons = prev->getNeurons();
    vector<AbstractNeuron*> currNeurons = this->getNeurons();

    int j = 0;
    for (auto& nj : currNeurons) {
        if (nj->getType() == UnitType::BIAS) continue;
        double net = 0.0;
        for (int i = 0; i < (int)prevNeurons.size(); i++) {
            net += this->weights->getCell(j, i) * prevNeurons[i]->getValue();
        }
        nj->setNet(net);
        nj->setValue(nj->getFunction().run(net));
        j++;
    }
}
