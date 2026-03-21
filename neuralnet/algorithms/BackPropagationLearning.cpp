/*
 * File:   BackPropagationLearning.cpp
 * Author: sim
 *
 * Created on 3 de Dezembro de 2016, 17:40
 */

#include "BackPropagationLearning.h"
#include "../Layer.h"
#include "../neuron/Neuron.h"
#include "../../core/UnitType.h"
#include <vector>

using namespace std;

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

void BackPropagationLearning::setNetwork(MultiLayerPerceptron* network){
    this->network = network;
}

MultiLayerPerceptron* BackPropagationLearning::getNetwork(){
    return this->network;
}

void BackPropagationLearning::setTrainingData(vector<vector<double>> &inputs,
                                               vector<vector<double>> &targets) {
    this->inputData = inputs;
    this->targetData = targets;
}

void BackPropagationLearning::run() {
    for (int i = 0; i < this->iterations; i++) {
        this->learn();
    }
}

void BackPropagationLearning::learn() {
    for (int s = 0; s < (int)this->inputData.size(); s++) {
        this->currentInputs  = this->inputData[s];
        this->currentTargets = this->targetData[s];
        this->propagate();
        this->backpropagate();
    }
}

void BackPropagationLearning::propagate() {
    this->currentTime++;
    int nLayers = this->network->countLayers();

    // Seta os valores dos neurônios de entrada (ignora bias)
    Layer* inputLayer = this->network->getLayer(0);
    vector<AbstractNeuron*> inputNeurons = inputLayer->getNeurons();
    int inputIdx = 0;
    for (auto &n : inputNeurons) {
        if (n->getType() == UnitType::BIAS) continue;
        n->setValue(this->currentInputs[inputIdx++]);
    }

    // Avalia as camadas seguintes (forward pass)
    for (int l = 1; l < nLayers; l++) {
        Layer* layer = this->network->getLayer(l);
        for (auto &n : layer->getNeurons()) {
            if (n->getType() == UnitType::BIAS) continue;
            n->eval(this->currentTime);
        }
    }
}

void BackPropagationLearning::backpropagate() {
    int nLayers = this->network->countLayers();
    int time = this->currentTime;

    // Deltas da camada de saída
    Layer* outputLayer = this->network->getLayer(nLayers - 1);
    vector<AbstractNeuron*> outputNeurons = outputLayer->getNeurons();
    int targetIdx = 0;
    for (auto &n : outputNeurons) {
        double output = n->getValue();
        double target = this->currentTargets[targetIdx++];
        // Derivada da sigmoid: output*(1-output)
        double delta = (target - output) * output * (1.0 - output);
        n->setDelta(delta);
    }

    // Deltas das camadas ocultas (da última para a primeira)
    for (int l = nLayers - 2; l > 0; l--) {
        Layer* currentLayer = this->network->getLayer(l);
        Layer* nextLayer    = this->network->getLayer(l + 1);
        vector<AbstractNeuron*> currentNeurons = currentLayer->getNeurons();
        vector<AbstractNeuron*> nextNeurons    = nextLayer->getNeurons();

        for (auto &ni : currentNeurons) {
            if (ni->getType() == UnitType::BIAS) continue;
            double output_i = ni->getValue();
            double sum = 0.0;
            for (auto &nj : nextNeurons) {
                for (auto &edge : nj->getEdges()) {
                    if (&edge->getVertex1() == ni) {
                        sum += edge->getWeight() * nj->getDelta();
                        break;
                    }
                }
            }
            ni->setDelta(output_i * (1.0 - output_i) * sum);
        }
    }

    // Atualização dos pesos
    for (int l = 1; l < nLayers; l++) {
        Layer* layer = this->network->getLayer(l);
        for (auto &nj : layer->getNeurons()) {
            if (nj->getType() == UnitType::BIAS) continue;
            for (auto &edge : nj->getEdges()) {
                AbstractNeuron* ni = (AbstractNeuron*) &edge->getVertex1();
                double update = this->learningRate * nj->getDelta() * ni->eval(time);
                edge->setWeight(edge->getWeight() + update);
            }
        }
    }
}

double BackPropagationLearning::computeMeanSquaredError() {
    int nLayers = this->network->countLayers();
    Layer* outputLayer = this->network->getLayer(nLayers - 1);
    vector<AbstractNeuron*> outputNeurons = outputLayer->getNeurons();
    double mse = 0.0;
    int targetIdx = 0;
    for (auto &n : outputNeurons) {
        double err = this->currentTargets[targetIdx++] - n->getValue();
        mse += err * err;
    }
    return mse / (double)outputNeurons.size();
}

double BackPropagationLearning::computeSquaredError(Neuron &n) {
    return 0.5 * (this->currentTargets[0] - n.getValue())
               * (this->currentTargets[0] - n.getValue());
}
