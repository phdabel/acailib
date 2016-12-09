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
#include "../../neuralnet/Neuron.h"
#include "../../neuralnet/MultiLayerPerceptron.h"
#include <vector>
#include <iostream>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(MultiLayerPerceptron_Test);

MultiLayerPerceptron_Test::MultiLayerPerceptron_Test() {
}

MultiLayerPerceptron_Test::~MultiLayerPerceptron_Test() {
}

void MultiLayerPerceptron_Test::setUp() {
}

void MultiLayerPerceptron_Test::tearDown() {
}

void MultiLayerPerceptron_Test::testAddingLayers(){
    
    MultiLayerPerceptron mlp;
    Layer inputL, hiddenL, outputL;
    
    for(int i = 0; i < 3; i++){
        ObjectID *o = new ObjectID;
        Neuron *n = new Neuron;
        n->setId(o);
        n->setValue(o->random());
        inputL.addNeuron(n);
    }
    
    for(int i = 0; i < 5; i++){
        ObjectID *o = new ObjectID;
        Neuron *n = new Neuron;
        n->setId(o);
        n->setValue(o->random());
        hiddenL.addNeuron(n);
    }
    
    for(int i = 0; i < 1; i++){
        ObjectID *o = new ObjectID;
        Neuron *n = new Neuron;
        n->setId(o);
        n->setValue(o->random());
        outputL.addNeuron(n);
    }
    inputL.setType(LayerType::INPUT);
    hiddenL.setType(LayerType::HIDDEN);
    outputL.setType(LayerType::OUTPUT);
    mlp.addLayer(&inputL);
    mlp.addLayer(&hiddenL);
    mlp.addLayer(&outputL);
    
    vector<int> neurons;
    neurons.push_back(2);
    neurons.push_back(2);
    neurons.push_back(1);
    
    
    mlp.configure(neurons);
    
    CPPUNIT_ASSERT(mlp.checkNetworkConstraints());
    CPPUNIT_ASSERT(mlp.countLayers() == 3);
        
}

