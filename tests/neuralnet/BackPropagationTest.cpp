/*
 * File:   BackPropagationTest.cpp
 * Author: abel
 *
 * Created on 10/04/2017, 14:30:16
 */

#include "BackPropagationTest.h"
#include "../../neuralnet/neuron/AbstractNeuron.h"
#include "../../neuralnet/neuron/Neuron.h"
#include "../../neuralnet/neuron/BiasNeuron.h"
#include "../../core/UnitType.h"
#include "../../neuralnet/MultiLayerPerceptron.h"
#include "../../neuralnet/functions/FuncSigmoid.h"
#include "../../neuralnet/algorithms/BackPropagationLearning.h"
#include <vector>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION(BackPropagationTest);

BackPropagationTest::BackPropagationTest() {
}

BackPropagationTest::~BackPropagationTest() {
}

void BackPropagationTest::setUp() {
    
    this->fs = new FuncSigmoid;
    this->learning = new BackPropagationLearning;
    this->mlp = new MultiLayerPerceptron(this->fs);
    
    this->learning->setNetwork(this->mlp);
    
    vector<int> n;
    n.push_back(2);
    n.push_back(3);
    n.push_back(1);
    
    this->mlp->configure(n,false);
    
    for(int l = 0; l < this->mlp->countLayers(); l++)
    {
        //cout << "The layer has " << this->mlp->getLayer(l)->getNeurons().size() << " neurons." << endl;
        for(AbstractNeuron* tmp : this->mlp->getLayer(l)->getNeurons()){
            cout << "The neuron ID is " << tmp->getIndex() << "." << endl;
            cout << "The type of the neuron is " << tmp->getType() << "." << endl;
        }
    }
    
}

void BackPropagationTest::tearDown() {
    delete this->fs;
    delete this->learning;
    delete this->mlp;
}

/**
 *  testing propagation
 */
void BackPropagationTest::testPropagationPhase() {
    
    for(int l = 0; l < this->mlp->countLayers(); l++)
    {
        cout << "The layer has " << this->mlp->getLayer(l)->getNeurons().size() << " neurons." << endl;
        for(AbstractNeuron* tmp : this->mlp->getLayer(l)->getNeurons()){
            cout << "The neuron ID is " << tmp->getIndex() << "." << endl;
        }
    }
    cout << "The network has " << this->mlp->countLayers() << " layers." << endl;
    
    
}

