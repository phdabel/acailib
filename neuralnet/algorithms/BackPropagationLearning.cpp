/* 
 * File:   BackPropagationLearning.cpp
 * Author: sim
 * 
 * Created on 3 de Dezembro de 2016, 17:40
 */

#include "BackPropagationLearning.h"
#include "../MultiLayerPerceptron.h"
#include "../Layer.h"



BackPropagationLearning::BackPropagationLearning() {
}

BackPropagationLearning::BackPropagationLearning(const BackPropagationLearning& orig) {
}

BackPropagationLearning::~BackPropagationLearning() {
}

void BackPropagationLearning::setIterations(int itr){
    this->iterations = itr;
}

int BackPropagationLearning::getIterations() {
    return this->iterations;
}

void BackPropagationLearning::setLearningRate(double lrt) {
    this->learningRate = lrt;
}

double BackPropagationLearning::getLearningRate() {
    return this->learningRate;
}

void BackPropagationLearning::setNetwork(MultiLayerPerceptron * net) {
    this->network = net;
}

MultiLayerPerceptron* BackPropagationLearning::getNetwork() {
    return this->network;
}

void BackPropagationLearning::run() {

}

void BackPropagationLearning::learn(){
    
}

void BackPropagationLearning::propagate() {

}

void BackPropagationLearning::backpropagate() {

}

double BackPropagationLearning::computeMeanSquaredError() {

}

double BackPropagationLearning::computeSquaredError() {

}










