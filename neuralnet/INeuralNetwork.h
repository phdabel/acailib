/* 
 * File:   INeuralNetwork.h
 * Author: abel
 *
 * Created on 2 de Dezembro de 2016, 16:02
 */

#ifndef INEURALNETWORK_H
#define INEURALNETWORK_H

#include "IAbstractLayer.h"
#include "functions/IActivationFunction.h"
#include "algorithms/ILearningAlgorithm.h"
#include <vector>

//template <class IAbstractLayer, class ILearningAlgorithm>
template <class IAbstractLayer>
class INeuralNetwork {
public:
    virtual IAbstractLayer* getLayer(int i) = 0;
    virtual void configure(vector<int> layerNeurons, bool randomWeight = true) = 0;
    virtual void setActivationFunction(IActivationFunction* f) = 0;
    virtual IActivationFunction* getActivationFunction() = 0;
    virtual double getSumSquaredError() = 0;
    virtual double getMeanSquaredError() = 0;
    //virtual void setLearning(ILearningAlgorithm& learning) = 0;
    //virtual ILearningAlgorithm* getLearning() = 0;
protected:
    virtual bool checkNetworkConstraints() = 0;
    virtual void addLayer(IAbstractLayer* layer) = 0;
    virtual void setNeurons(IAbstractLayer *l, int n) = 0;
    virtual void setEdges(bool randomWeight = true) = 0;
    virtual void setSumSquaredError() = 0;
    virtual void setMeanSquaredError() = 0;
private:
};


#endif /* INEURALNETWORK_H */

