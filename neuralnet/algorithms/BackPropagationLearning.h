
/* 
 * File:   BackPropagationLearning.h
 * Author: sim
 *
 * Created on 3 de Dezembro de 2016, 17:40
 */

#ifndef BACKPROPAGATIONLEARNING_H
#define BACKPROPAGATIONLEARNING_H

#include "ILearningAlgorithm.h"
#include "../Layer.h"
#include "../neuron/Neuron.h"
#include "../MultiLayerPerceptron.h"

class BackPropagationLearning: public ILearningAlgorithm<MultiLayerPerceptron> {
public:
    BackPropagationLearning();
    BackPropagationLearning(const BackPropagationLearning& orig);
    virtual ~BackPropagationLearning();
    double computeSquaredError(Neuron &n);
    double computeMeanSquaredError();
    void setIterations(int itr) override;
    int getIterations() override;
    void setLearningRate(double lrt) override;
    double getLearningRate() override;
    void run() override;
    void setNetwork(MultiLayerPerceptron* network) override;
    MultiLayerPerceptron* getNetwork() override;
protected:
    void learn() override;
private:
    MultiLayerPerceptron* network;
    int iterations = 0;
    double learningRate = 0.0;
    double squaredError = 0.0;
    double meanSquaredError = 0.0;
    void propagate();
    void backpropagate();
    
};

#endif /* BACKPROPAGATIONLEARNING_H */

