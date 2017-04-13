/*
 * File:   BiasNeuronTest.cpp
 * Author: abel
 *
 * Created on 13/04/2017, 12:34:20
 */

#include "BiasNeuronTest.h"

#include "../../neuralnet/neuron/BiasNeuron.h"
#include "../../core/ObjectID.h"

CPPUNIT_TEST_SUITE_REGISTRATION(BiasNeuronTest);

BiasNeuronTest::BiasNeuronTest() {
}

BiasNeuronTest::~BiasNeuronTest() {
}

void BiasNeuronTest::testBiasNeuronOutputIndex(){
    CPPUNIT_ASSERT(this->b->getIndex() == "0");
}

void BiasNeuronTest::testBiasNeuronOutputValue(){
    CPPUNIT_ASSERT(this->b->getValue() == 1.0);
}

void BiasNeuronTest::testBiasNeuronSetIndex(){
    CPPUNIT_ASSERT_THROW(this->b->setIndex("1"), runtime_error);
}

void BiasNeuronTest::testBiasNeuronSetValue() {
    CPPUNIT_ASSERT_THROW(this->b->setValue(0.0), runtime_error);
}


void BiasNeuronTest::setUp() {
    this->o = new ObjectID();
    this->b = new BiasNeuron();
}

void BiasNeuronTest::tearDown() {
    delete this->b;
    delete this->o;
}

