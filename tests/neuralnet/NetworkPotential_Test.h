/*
 * File:   NetworkPotential_Test.h
 * Author: abel
 *
 * Created on 21/11/2016, 16:09:46
 */

#ifndef NETWORKPOTENTIAL_TEST_H
#define NETWORKPOTENTIAL_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../neuralnet/neuron/Neuron.h"
#include "../../core/Edge.h"
#include "../../core/ObjectID.h"
#include "../../neuralnet/functions/FuncRectifier.h"
#include "../../neuralnet/functions/FuncTanH.h"
#include "../../neuralnet/functions/FuncSigmoid.h"

class NetworkPotential_Test : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(NetworkPotential_Test);

    CPPUNIT_TEST(testInputNeuronValues);
    CPPUNIT_TEST(testTanHFunc);
    CPPUNIT_TEST(testSigmoidFunc);
    CPPUNIT_TEST(testRectifier);
    CPPUNIT_TEST_SUITE_END();

public:
    NetworkPotential_Test();
    virtual ~NetworkPotential_Test();
    void setUp();
    void tearDown();
    //list of object ids for every component of the network
    ObjectID o1,o2,o3,o4,o5;
    ObjectID e11,e12,e13,e21,e22,e23;
    //input neurons
    Neuron x1;
    Neuron x2;
    //hidden layer neurons
    Neuron i1;
    Neuron i2;
    Neuron i3;
    //activation functions
    FuncTanH fTH;
    FuncRectifier fR;
    FuncSigmoid fS;
    
    //edges of the first input neuron
    Edge ed11 {this->x1,this->i1};
    Edge ed12 {this->x1,this->i2};
    Edge ed13 {this->x1,this->i3};
    //edges of the second input neuron
    Edge ed21 {this->x2,this->i1};
    Edge ed22 {this->x2,this->i2};
    Edge ed23 {this->x2,this->i3};
    
private:
    void testInputNeuronValues();
    void testTanHFunc();
    void testSigmoidFunc();
    void testRectifier();
};

#endif /* NETWORKPOTENTIAL_TEST_H */

