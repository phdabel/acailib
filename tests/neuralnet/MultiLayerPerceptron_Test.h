/*
 * File:   MultiLayerPerceptron_Test.h
 * Author: abel
 *
 * Created on 08/12/2016, 11:21:18
 */

#ifndef MULTILAYERPERCEPTRON_TEST_H
#define MULTILAYERPERCEPTRON_TEST_H

#include <cppunit/extensions/HelperMacros.h>

class MultiLayerPerceptron_Test : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(MultiLayerPerceptron_Test);

    CPPUNIT_TEST(testAddingLayers);

    CPPUNIT_TEST_SUITE_END();

public:
    MultiLayerPerceptron_Test();
    virtual ~MultiLayerPerceptron_Test();
    void setUp();
    void tearDown();

private:
    void testAddingLayers();
};

#endif /* MULTILAYERPERCEPTRON_TEST_H */

