/* 
 * File:   ILearningAlgorithm.h
 * Author: abel
 *
 * Created on 2 de Dezembro de 2016, 16:05
 */

#ifndef ILEARNINGALGORITHM_H
#define ILEARNINGALGORITHM_H

#include "../INeuralNetwork.h"
#include "../IAbstractLayer.h"

template <class INeuralNetwork>
class ILearningAlgorithm {
public:
    virtual void setIterations(int itr) = 0;
    virtual int getIterations() = 0;
    virtual void setLearningRate(double lrt) = 0;
    virtual double getLearningRate() = 0;
    virtual void run() = 0;
    virtual void setNetwork(INeuralNetwork* network) = 0;
    virtual INeuralNetwork* getNetwork() = 0;
protected:
    virtual void learn() = 0;
private:
    
};


#endif /* ILEARNINGALGORITHM_H */

