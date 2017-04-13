/*
 * File:   MultiLayerPerceptron_Test.cpp
 * Author: abel
 *
 * Created on 08/12/2016, 11:21:18
 */

#include "MultiLayerPerceptron_Test.h"
#include "../../core/ObjectID.h"
#include "../../core/Edge.h"
#include "../../neuralnet/Layer.h"
#include "../../neuralnet/LayerType.h"
#include "../../neuralnet/neuron/Neuron.h"
#include "../../neuralnet/MultiLayerPerceptron.h"
#include "../../neuralnet/functions/FuncSigmoid.h"
#include "../../neuralnet/algorithms/BackPropagationLearning.h"
#include <vector>
#include <iostream>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(MultiLayerPerceptron_Test);

MultiLayerPerceptron_Test::MultiLayerPerceptron_Test() {
}

MultiLayerPerceptron_Test::~MultiLayerPerceptron_Test() {
}

void MultiLayerPerceptron_Test::setUp() {
    this->fs = new FuncSigmoid;
    this->learning = new BackPropagationLearning;
    this->mlp = new MultiLayerPerceptron(this->fs);
    
    this->learning->setNetwork(this->mlp);
    
    vector<int> n;
    n.push_back(2);
    n.push_back(3);
    n.push_back(1);
    this->mlp->configure(n);
    
}

void MultiLayerPerceptron_Test::tearDown() {
    delete this->fs;
    delete this->learning;
    delete this->mlp;
}

void MultiLayerPerceptron_Test::testCreatingNetwork(){
    
    //testa restricoes da rede (no minimo uma camada de entrada e uma de saida)
    CPPUNIT_ASSERT(this->mlp->checkNetworkConstraints());
    //testa se foram criadas tres camadas
    CPPUNIT_ASSERT(this->mlp->countLayers() == 3);
    
    //testa contagem de neuronios e arestas
    for(int l = (this->mlp->countLayers()-1); l > 0; l--){
        
        //contagem de neuronios de cada camada
        if((l+1) == this->mlp->countLayers()){
            CPPUNIT_ASSERT(this->mlp->getLayer(l)->getNeurons().size() == 1);
        }else if((l+1) == 1){
            CPPUNIT_ASSERT(this->mlp->getLayer(l)->getNeurons().size() == 3);
        }else{
            CPPUNIT_ASSERT(this->mlp->getLayer(l)->getNeurons().size() == 4);
        }
        
        for(auto &n1 : this->mlp->getLayer(l)->getNeurons()){
            //contagem de arestas entre as camadas
            if((l+1) == this->mlp->countLayers()){
                CPPUNIT_ASSERT(n1->getEdges().size() == 4);
            }else if((l+1) == 1){
                CPPUNIT_ASSERT(n1->getEdges().size() == 0);
            }else{
                CPPUNIT_ASSERT(n1->getEdges().size() == 3);
            }
        }
    }
        
}

