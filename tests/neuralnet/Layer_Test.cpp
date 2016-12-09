/*
 * File:   Layer_Test.cpp
 * Author: abel
 *
 * Created on 05/12/2016, 15:07:05
 */

#include "Layer_Test.h"
#include "../../neuralnet/Neuron.h"
#include "../../core/Edge.h"
#include "../../core/ObjectID.h"
#include "../../neuralnet/functions/FuncTanH.h"
#include "../../neuralnet/functions/FuncRectifier.h"
#include "../../neuralnet/Layer.h"
#include "../../neuralnet/LayerType.h"
#include <cmath>
#include <iostream>
#include <ctime>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(Layer_Test);

Layer_Test::Layer_Test() {
}

Layer_Test::~Layer_Test() {
}

void Layer_Test::setUp() {
    
    //sets the ObjectID of the bias neuron of the input layer
    this->x0.setId(&this->ox0);
    //this sets the ObjectIDs of the input and hidden layer neurons
    this->x1.setId(&this->ox1);
    this->x2.setId(&this->ox2);
    
    this->i0.setId(&this->oi0);
    this->i1.setId(&this->oi1);
    this->i2.setId(&this->oi2);
    
    this->y1.setId(&this->oy1);
    
    //this sets the ObjectIDs of the edges
    //between the input and hidden layer
    this->ed01.setId(&this->e01);
    this->ed11.setId(&this->e11);
    this->ed12.setId(&this->e12);
    this->ed02.setId(&this->e02);
    this->ed21.setId(&this->e21);
    this->ed22.setId(&this->e22);
        
    //edges to the output layer (between hidden and output)
    this->edi0y1.setId(&this->ei0y1);
    this->edi1y1.setId(&this->ei1y1);
    this->edi2y1.setId(&this->ei2y1);
    
    //values of the bias neurons (input and hidden layer)
    this->x0.setValue(1.0);
    this->i0.setValue(1.0);
    
    //values of input neurons
    this->x1.setValue(1.0);
    this->x2.setValue(-1.0);
    this->y1.setValue(1.0);
    
    //weights of the edges of the bias to hidden layer
    this->ed01.setWeight(0.1);
    this->ed02.setWeight(0.6);    
    //weights of the edges of the first neuron of the hidden layer
    this->ed11.setWeight(0.2);
    this->ed12.setWeight(0.5);
    //weights of the edges of the second neuron of the hidden layer
    this->ed21.setWeight(0.3);
    this->ed22.setWeight(0.5);
    
    //weights of the edges from hidden to output layer
    this->edi0y1.setWeight(0.1);
    this->edi1y1.setWeight(0.7);
    this->edi2y1.setWeight(0.3);
    
    
    //add edges of the hidden layer
    this->i1.addEdge(&this->ed01);
    this->i1.addEdge(&this->ed11);
    this->i1.addEdge(&this->ed21);
    this->i2.addEdge(&this->ed02);
    this->i2.addEdge(&this->ed12);
    this->i2.addEdge(&this->ed22);
    
    //add edges of the output layer
    this->y1.addEdge(&this->edi0y1);
    this->y1.addEdge(&this->edi1y1);
    this->y1.addEdge(&this->edi2y1);
    
    this->x0.setFunction(this->fTH);
    this->x1.setFunction(this->fTH);
    this->x2.setFunction(this->fTH);
    this->i0.setFunction(this->fTH);
    this->i1.setFunction(this->fTH);
    this->i2.setFunction(this->fTH);
    this->y1.setFunction(this->fTH);

}

void Layer_Test::tearDown() {
}

void Layer_Test::testInsertNeurons() {
    Layer inputL;
    Layer hiddenL;
    Layer outputL;
    inputL.setType(LayerType::INPUT);
    hiddenL.setType(LayerType::HIDDEN);
    outputL.setType(LayerType::OUTPUT);
    inputL.addNeuron(&this->x0);
    inputL.addNeuron(&this->x1);
    inputL.addNeuron(&this->x2);
    
    hiddenL.addNeuron(&this->i0);
    hiddenL.addNeuron(&this->i1);
    hiddenL.addNeuron(&this->i2);
    
    outputL.addNeuron(&this->y1);
    
    CPPUNIT_ASSERT(inputL.getNeurons().size() == 3);
    CPPUNIT_ASSERT(hiddenL.getNeurons().size() == 3);
    CPPUNIT_ASSERT(outputL.getNeurons().size() == 1);
    
}

void Layer_Test::testNeuronValueUpdate(){
    
    Layer inputL;
    Layer hiddenL;
    Layer outputL;
    inputL.setType(LayerType::INPUT);
    hiddenL.setType(LayerType::HIDDEN);
    outputL.setType(LayerType::OUTPUT);
    inputL.addNeuron(&this->x0);
    inputL.addNeuron(&this->x1);
    inputL.addNeuron(&this->x2);
    
    hiddenL.addNeuron(&this->i0);
    hiddenL.addNeuron(&this->i1);
    hiddenL.addNeuron(&this->i2);
    
    outputL.addNeuron(&this->y1);
    
    //check current values
    CPPUNIT_ASSERT(this->x0.getValue() == 1.0);
    CPPUNIT_ASSERT(this->x1.getValue() == 1.0);
    CPPUNIT_ASSERT(this->x2.getValue() == -1.0);
    CPPUNIT_ASSERT(this->y1.getValue() == 1.0);
    //check pointers
    for(auto &neuron: inputL.getNeurons()){
        if(neuron->getId().equals(this->x0.getId())){
            CPPUNIT_ASSERT(neuron->getValue() == this->x0.getValue());
        }
        if(neuron->getId().equals(this->x1.getId())){
            CPPUNIT_ASSERT(neuron->getValue() == this->x1.getValue());
        }
        if(neuron->getId().equals(this->x1.getId())){
            CPPUNIT_ASSERT(neuron->getValue() == this->x1.getValue());
        }
    }
    
    //check pointers of the output layer
    for(auto &neuron: outputL.getNeurons()){
        if(neuron->getId().equals(this->y1.getId())){
            CPPUNIT_ASSERT(neuron->getValue() == this->y1.getValue());
        }
    }
    
    //update values
    this->x0.setValue(1.0);
    this->x1.setValue(-1.0);
    this->x2.setValue(1.0);
    this->y1.setValue(-1.0);
    //checking pointers
    for(auto &neuron: inputL.getNeurons()){
        if(neuron->getId().equals(this->x0.getId())){
            CPPUNIT_ASSERT(neuron->getValue() == this->x0.getValue());
        }
        if(neuron->getId().equals(this->x1.getId())){
            CPPUNIT_ASSERT(neuron->getValue() == this->x1.getValue());
        }
        if(neuron->getId().equals(this->x1.getId())){
            CPPUNIT_ASSERT(neuron->getValue() == this->x1.getValue());
        }
    }
    //check pointers of the output layer
    for(auto &neuron: outputL.getNeurons()){
        if(neuron->getId().equals(this->y1.getId())){
            CPPUNIT_ASSERT(neuron->getValue() == this->y1.getValue());
        }
    }
}

void Layer_Test::testEvaluateLayers(){
    
    Layer inputL;
    Layer hiddenL;
    Layer outputL;
    inputL.setType(LayerType::INPUT);
    hiddenL.setType(LayerType::HIDDEN);
    outputL.setType(LayerType::OUTPUT);
    inputL.addNeuron(&this->x0);
    inputL.addNeuron(&this->x1);
    inputL.addNeuron(&this->x2);
    
    hiddenL.addNeuron(&this->i0);
    hiddenL.addNeuron(&this->i1);
    hiddenL.addNeuron(&this->i2);
    
    outputL.addNeuron(&this->y1);
    clock_t start;
    double duration;
    
    cout << "evaluation of the neurons of the input layer" << endl;
    //evaluate input layer neurons
    for(auto &neuron: inputL.getNeurons()){
        if(neuron->getId().equals(this->x0.getId())){
            start = clock();
            CPPUNIT_ASSERT(neuron->eval() == 1.0);
            duration = (clock() - start) / (double)CLOCKS_PER_SEC;
            cout << "evaluation of neuron " << to_string(neuron->getId().getValue()) << endl;
            cout << "timer: " << duration << endl;
        }
        if(neuron->getId().equals(this->x1.getId())){
            start = clock();
            CPPUNIT_ASSERT(neuron->eval() == 1.0);
            duration = (clock() - start) / (double)CLOCKS_PER_SEC;
            cout << "evaluation of neuron " << to_string(neuron->getId().getValue()) << endl;
            cout << "timer: " << duration << endl;
        }
        if(neuron->getId().equals(this->x2.getId())){
            start = clock();
            CPPUNIT_ASSERT(neuron->eval() == -1.0);
            duration = (clock() - start) / (double)CLOCKS_PER_SEC;
            cout << "evaluation of neuron " << to_string(neuron->getId().getValue()) << endl;
            cout << "timer: " << duration << endl;
        }
    }
    
    cout << "evaluation of the neurons of the hidden layer" << endl;
    //evaluate hidden layer neurons
    for(auto &neuron: hiddenL.getNeurons()){
        if(neuron->getId().equals(this->i0.getId())){
            start = clock();
            CPPUNIT_ASSERT(neuron->eval() == 1.0);
            duration = (clock() - start) / (double)CLOCKS_PER_SEC;
            cout << "evaluation of neuron " << to_string(neuron->getId().getValue()) << endl;
            cout << "timer: " << duration << endl;
        }
        if(neuron->getId().equals(this->i1.getId())){
            start = clock();
            CPPUNIT_ASSERT(neuron->eval() == 0.0);
            duration = (clock() - start) / (double)CLOCKS_PER_SEC;
            cout << "evaluation of neuron " << to_string(neuron->getId().getValue()) << endl;
            cout << "timer: " << duration << endl;
        }
        if(neuron->getId().equals(this->i2.getId())){
            start = clock();
            CPPUNIT_ASSERT(neuron->eval() >= 0.5370 && neuron->eval() < 0.5371);
            duration = (clock() - start) / (double)CLOCKS_PER_SEC;
            cout << "evaluation of neuron " << to_string(neuron->getId().getValue()) << endl;
            cout << "timer: " << duration << endl;
        }
    }
    
    cout << "evaluation of the neurons of the output layer" << endl;
    //evaluate output layer neurons
    for(auto &neuron : outputL.getNeurons()){
        
        if(neuron->getId().equals(this->y1.getId())){
            start = clock();
            CPPUNIT_ASSERT(neuron->eval() >= 0.2553 && neuron->eval() < 0.2554);
            duration = (clock() - start) / (double)CLOCKS_PER_SEC;
            cout << "evaluation of neuron " << to_string(neuron->getId().getValue()) << endl;
            cout << "timer: " << duration << endl;
        }
    }
    
}