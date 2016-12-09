/* 
 * File:   MultiLayerPerceptron.cpp
 * Author: sim
 * 
 * Created on 3 de Dezembro de 2016, 20:27
 */

#include "MultiLayerPerceptron.h"
#include "Layer.h"
#include "LayerType.h"
#include <iostream>
#include <vector>

using namespace std;

MultiLayerPerceptron::MultiLayerPerceptron() {
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
    if(ln.size() < 2){
        throw runtime_error("The Multi Layer Perceptron must have at least two layers.");
    }else{
        for(int l = 0; l < ln.size(); l++){
            cout << "layer " << l << endl;
            for(int k = 0; k < ln.at(l); k++){
                cout << "neuron " << k << endl;
            }
        }
    }
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

