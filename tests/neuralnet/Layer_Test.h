/*
 * File:   Layer_Test.h
 * Author: abel
 *
 * Created on 05/12/2016, 15:07:05
 */

#ifndef LAYER_TEST_H
#define LAYER_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../neuralnet/Neuron.h"
#include "../../core/Edge.h"
#include "../../core/ObjectID.h"
#include "../../neuralnet/functions/FuncTanH.h"
#include "../../neuralnet/functions/FuncRectifier.h"
#include "../../neuralnet/Layer.h"
#include "../../neuralnet/LayerType.h"
#include <cmath>

class Layer_Test : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(Layer_Test);

    CPPUNIT_TEST(testInsertNeurons);
    CPPUNIT_TEST(testNeuronValueUpdate);
    CPPUNIT_TEST(testEvaluateLayers);

    CPPUNIT_TEST_SUITE_END();

public:
    Layer_Test();
    virtual ~Layer_Test();
    void setUp();
    void tearDown();
    
    //list of object ids for every component of the network
    ObjectID ox0,ox1,ox2,oi0,oi1,oi2,oy1;
    ObjectID e01,e02,e11,e12,e21,e22;
    ObjectID ei0y1, ei1y1, ei2y1;
    
    //bias neuron
    Neuron x0;
    //input neurons
    Neuron x1;
    Neuron x2;
    //hidden layer neurons
    Neuron i0;
    Neuron i1;
    Neuron i2;
    //output layer neuron
    Neuron y1;
    //activation functions
    FuncTanH fTH;
    FuncRectifier fR;

    //edges of the bias neuron
    Edge ed01 {this->x0, this->i1};
    Edge ed02 {this->x0, this->i2};
    //edges of the first input neuron
    Edge ed11 {this->x1,this->i1};
    Edge ed12 {this->x1,this->i2};
    //edges of the second input neuron
    Edge ed21 {this->x2,this->i1};
    Edge ed22 {this->x2,this->i2};
    
    //edges from hidden to output layer
    Edge edi0y1 {this->i0, this->y1};
    Edge edi1y1 {this->i1, this->y1};
    Edge edi2y1 {this->i2, this->y1};
    
private:
    void testInsertNeurons();
    void testNeuronValueUpdate();
    void testEvaluateLayers();
};

#endif /* LAYER_TEST_H */

