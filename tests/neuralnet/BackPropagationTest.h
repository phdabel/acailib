/*
 * File:   BackPropagationTest.h
 * Author: abel
 *
 * Created on 10/04/2017, 14:30:15
 */

#ifndef BACKPROPAGATIONTEST_H
#define BACKPROPAGATIONTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../neuralnet/MultiLayerPerceptron.h"
#include "../../neuralnet/functions/FuncSigmoid.h"
#include "../../neuralnet/algorithms/BackPropagationLearning.h"

class BackPropagationTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(BackPropagationTest);
    
    CPPUNIT_TEST(testPropagationPhase);
    
    CPPUNIT_TEST_SUITE_END();

public:
    BackPropagationTest();
    virtual ~BackPropagationTest();
    void setUp();
    void tearDown();
    void testPropagationPhase();

private:
    FuncSigmoid * fs;
    BackPropagationLearning * learning;
    MultiLayerPerceptron * mlp;
};

#endif /* BACKPROPAGATIONTEST_H */