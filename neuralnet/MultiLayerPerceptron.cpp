/* 
 * File:   MultiLayerPerceptron.cpp
 * Author: sim
 * 
 * Created on 3 de Dezembro de 2016, 20:27
 */

#include "MultiLayerPerceptron.h"
#include "Layer.h"
#include "LayerType.h"
#include "neuron/Neuron.h"
#include "neuron/BiasNeuron.h"
#include "../core/ObjectID.h"
#include "../core/Edge.h"
#include "functions/IActivationFunction.h"
#include <iostream>
#include <vector>

using namespace std;

MultiLayerPerceptron::MultiLayerPerceptron() {
}

MultiLayerPerceptron::MultiLayerPerceptron(IActivationFunction* f){
    this->setActivationFunction(f);
}

MultiLayerPerceptron::MultiLayerPerceptron(const MultiLayerPerceptron& orig) {
}

MultiLayerPerceptron::~MultiLayerPerceptron() {
}

int MultiLayerPerceptron::countLayers(){
    return this->countLayer;
}

/**
 * Esse metodo adiciona uma camada a rede neural.
 * Retorna erro se a primeira cada nao for uma camada de entrada.
 * E retorna erro se esta sendo adicionada uma camada oculta apos uma camada de saida.
 * Caso contrario a camada e adicionada e o contador de camadas e incrementado.
 * O metodo altera as variaveis booleanas inputLayer, hiddenLayer e outputLayer, que sao usadas no metodo checkcontraints.
 * 
 * @param layer
 */
void MultiLayerPerceptron::addLayer(Layer* layer){
    if(this->countLayer == 0){
        if(layer->getType() == LayerType::INPUT){
            this->layers.insert(make_pair(this->countLayer,layer));
            this->countLayer++;
            this->inputLayer = true;
        }else{
            throw runtime_error("The first layer should be an input layer.");
        }
    }else if(this->countLayer > 0){
        if(this->layers.at(this->countLayer - 1)->getType() == LayerType::OUTPUT){
            throw runtime_error("The last layer is an output layer. You can't add another layer.");
        }else{
            this->layers.insert(make_pair(this->countLayer,layer));
            this->countLayer++;
            if(layer->getType() == LayerType::OUTPUT){
                this->outputLayer = true;
            }else if(this->hiddenLayer == false){
                this->hiddenLayer = true;
            }
        }
    }
}

void MultiLayerPerceptron::configure(vector<int> ln, bool randomWeight){
    if(this->f == 0){
        throw runtime_error("The activation function can not be null.");
    }
        
    if(ln.size() < 2){
        throw runtime_error("The Multi Layer Perceptron must have at least two layers.");
    }else{
        for(int l = 0; l < ln.size(); l++){
            Layer *layer = new Layer;
            if(l == 0){
                layer->setType(LayerType::INPUT);
            }else if(l == (ln.size() - 1)){
                layer->setType(LayerType::OUTPUT);
            }else{
                layer->setType(LayerType::HIDDEN);
            }
            this->setNeurons(layer,ln.at(l));
            this->addLayer(layer);
        }
        this->setEdges(randomWeight);
    }
}

/**
 * 
 * @param l Layer - camada que recebera os neuronios
 * @param n int - quantidade de neuronios da camada
 */
void MultiLayerPerceptron::setNeurons(Layer *l, int n){
    if(l->getType() != LayerType::OUTPUT){
        ObjectID *b = new ObjectID;
        BiasNeuron *bN = new BiasNeuron;
        bN->setId(b);
        bN->setFunction(*this->f);
        l->addNeuron(bN);
    }
    for(int i = 1; i <= n; i++){
        ObjectID *o = new ObjectID;
        Neuron *n = new Neuron;
        n->setId(o);
        n->setValue(1.0);
        n->setIndex(to_string(i));
        n->setFunction(*this->f);
        l->addNeuron(n);
    }
}

/**
 * Cria as arestas de conexao dos nos nas camadas da rede, 
 * comecando pela ultima camada ate a primeira.
 * 
 * @param randomWeight boolean, se randomWeight == true entao os pesos sao inicializados aleatoriamente
 */
void MultiLayerPerceptron::setEdges(bool randomWeight){
    for(int l = (this->countLayer-1); l > 0; l--){
        for(auto &n2 : this->getLayer(l)->getNeurons()){
            for(auto &n1 : this->getLayer(l-1)->getNeurons()){
                ObjectID * o = new ObjectID;
                Edge e {*n1,*n2};
                e.setId(o);
                if(randomWeight){
                    e.setWeight(o->random());
                }
                n2->addEdge(&e);
            }
        }
    }
}

/**
 * Adiciona a funcao de ativacao dos neuronios dessa MLP
 */
void MultiLayerPerceptron::setActivationFunction(IActivationFunction* f){
    this->f = f;
}

/**
 * Retorna a funcao de ativacao que foi definida para os neuronios da rede neural.
 * 
 * @return 
 */
IActivationFunction* MultiLayerPerceptron::getActivationFunction(){
    return this->f;
}

/**
 * Verifica se a rede possui uma camada de entrada e outra de saida.
 */
bool MultiLayerPerceptron::checkNetworkConstraints(){
    return this->inputLayer && this->outputLayer;
}

/**
 * Retorna a camada de indice 'i'.
 */
Layer* MultiLayerPerceptron::getLayer(int i){
    return this->layers.at(i);
}


double MultiLayerPerceptron::getMeanSquaredError(){
    return this->meanSquaredError;
}

double MultiLayerPerceptron::getSumSquaredError(){
    return this->sumSquaredError;
}

/**
 *  Calculations of the mean squared error must be performed by the learning algorithm. 
 */
void MultiLayerPerceptron::setMeanSquaredError(){
    
}

/**
 * Calculations of the sum squared error must be performed by the learning algorithm. 
 */
void MultiLayerPerceptron::setSumSquaredError(){
    
}