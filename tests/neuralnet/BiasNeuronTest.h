/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   BiasNeuronTest.h
 * Author: abel
 *
 * Created on 13/04/2017, 12:34:20
 */

#ifndef BIASNEURONTEST_H
#define BIASNEURONTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../neuralnet/neuron/BiasNeuron.h"
#include "../../core/ObjectID.h"

class BiasNeuronTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(BiasNeuronTest);

    CPPUNIT_TEST(testBiasNeuronOutputValue);
    CPPUNIT_TEST(testBiasNeuronSetValue);
    CPPUNIT_TEST(testBiasNeuronSetIndex);
    CPPUNIT_TEST(testBiasNeuronOutputIndex);

    CPPUNIT_TEST_SUITE_END();

public:
    BiasNeuronTest();
    virtual ~BiasNeuronTest();
    void setUp();
    void tearDown();
    ObjectID *o;
    BiasNeuron *b;

private:
    void testBiasNeuronOutputValue();
    void testBiasNeuronSetValue();
    void testBiasNeuronSetIndex();
    void testBiasNeuronOutputIndex();
    
};

#endif /* BIASNEURONTEST_H */

