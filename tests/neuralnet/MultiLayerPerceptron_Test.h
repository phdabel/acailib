/*
 * File:   MultiLayerPerceptron_Test.h
 * Author: abel
 *
 * Created on 08/12/2016, 11:21:18
 */

#ifndef MULTILAYERPERCEPTRON_TEST_H
#define MULTILAYERPERCEPTRON_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../neuralnet/MultiLayerPerceptron.h"
#include "../../neuralnet/functions/FuncSigmoid.h"
#include "../../neuralnet/algorithms/BackPropagationLearning.h"

class MultiLayerPerceptron_Test : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(MultiLayerPerceptron_Test);

    CPPUNIT_TEST(testCreatingNetwork);

    CPPUNIT_TEST_SUITE_END();

public:
    MultiLayerPerceptron_Test();
    virtual ~MultiLayerPerceptron_Test();
    void setUp();
    void tearDown();
    FuncSigmoid * fs;
    BackPropagationLearning * learning;
    MultiLayerPerceptron * mlp;
private:
    void testCreatingNetwork();
};

#endif /* MULTILAYERPERCEPTRON_TEST_H */

