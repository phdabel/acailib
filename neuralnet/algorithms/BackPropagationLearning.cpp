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
#include "../../problem/WeightMatrix.h"
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
    int nLayers = this->network->countLayers();

    // Seta os valores dos neurônios de entrada (ignora bias)
    Layer* inputLayer = this->network->getLayer(0);
    vector<AbstractNeuron*> inputNeurons = inputLayer->getNeurons();
    int inputIdx = 0;
    for (auto &n : inputNeurons) {
        if (n->getType() == UnitType::BIAS) continue;
        n->setValue(this->currentInputs[inputIdx++]);
    }

    // Forward pass: x_{l} = f( W[l] · x_{l-1} )
    for (int l = 1; l < nLayers; l++) {
        this->network->getLayer(l)->forward(this->network->getLayer(l - 1));
    }
}

void BackPropagationLearning::backpropagate() {
    int nLayers = this->network->countLayers();

    // Deltas da camada de saída
    Layer* outputLayer = this->network->getLayer(nLayers - 1);
    vector<AbstractNeuron*> outputNeurons = outputLayer->getNeurons();
    int targetIdx = 0;
    for (auto &n : outputNeurons) {
        double output = n->getValue();
        double target = this->currentTargets[targetIdx++];
        double delta = (target - output) * n->getFunction().derive(n->getNet());
        n->setDelta(delta);
    }

    // Deltas das camadas ocultas: δ_i = f'(net_i) · Σ_j W[l+1][j][i] · δ_j
    for (int l = nLayers - 2; l > 0; l--) {
        Layer* currentLayer = this->network->getLayer(l);
        Layer* nextLayer    = this->network->getLayer(l + 1);
        WeightMatrix* W     = nextLayer->getWeights();
        vector<AbstractNeuron*> currentNeurons = currentLayer->getNeurons();
        vector<AbstractNeuron*> nextNeurons    = nextLayer->getNeurons();

        // 1. Zera os deltas
        for (auto &ni : currentNeurons) {
            if (ni->getType() == UnitType::BIAS) continue;
            ni->setDelta(0.0);
        }

        // 2. Acumula: W[l+1]ᵀ · δ_{l+1}
        //    W[j][i]: j = neurônio não-bias de nextLayer, i = posição em currentNeurons
        int j = 0;
        for (auto &nj : nextNeurons) {
            if (nj->getType() == UnitType::BIAS) continue;
            for (int i = 0; i < (int)currentNeurons.size(); i++) {
                if (currentNeurons[i]->getType() == UnitType::BIAS) continue;
                currentNeurons[i]->setDelta(
                    currentNeurons[i]->getDelta() + W->getCell(j, i) * nj->getDelta()
                );
            }
            j++;
        }

        // 3. Aplica f'(net_i)
        for (auto &ni : currentNeurons) {
            if (ni->getType() == UnitType::BIAS) continue;
            ni->setDelta(ni->getFunction().derive(ni->getNet()) * ni->getDelta());
        }
    }

    // Atualização dos pesos: W[l][j][i] += η · δ_j · x_i
    for (int l = 1; l < nLayers; l++) {
        Layer* layer     = this->network->getLayer(l);
        Layer* prevLayer = this->network->getLayer(l - 1);
        WeightMatrix* W  = layer->getWeights();
        vector<AbstractNeuron*> currNeurons = layer->getNeurons();
        vector<AbstractNeuron*> prevNeurons = prevLayer->getNeurons();

        int j = 0;
        for (auto &nj : currNeurons) {
            if (nj->getType() == UnitType::BIAS) continue;
            for (int i = 0; i < (int)prevNeurons.size(); i++) {
                double update = this->learningRate * nj->getDelta() * prevNeurons[i]->getValue();
                W->setCell(j, i, W->getCell(j, i) + update);
            }
            j++;
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
