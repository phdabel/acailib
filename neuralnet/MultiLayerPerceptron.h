/* 
 * File:   MultiLayerPerceptron.h
 * Author: sim
 *
 * Created on 3 de Dezembro de 2016, 20:27
 */

#ifndef MULTILAYERPERCEPTRON_H
#define MULTILAYERPERCEPTRON_H

#include "INeuralNetwork.h"
#include <map>
#include "Layer.h"
#include <vector>
#include "functions/IActivationFunction.h"


using namespace std;

struct compareLayerOrder{
    bool operator()(int a, int b){
        return a < b;
    }
};

class MultiLayerPerceptron: public INeuralNetwork<Layer> {
public:
    MultiLayerPerceptron();
    MultiLayerPerceptron(IActivationFunction* f);
    MultiLayerPerceptron(const MultiLayerPerceptron& orig);
    Layer* getLayer(int i);
    bool checkNetworkConstraints();
    int countLayers();
    void configure(vector<int> layerNeurons, bool randomWeight = true);
    void setActivationFunction(IActivationFunction* f);
    IActivationFunction* getActivationFunction();
    virtual ~MultiLayerPerceptron();
    double getSumSquaredError() override;
    double getMeanSquaredError() override;
    //void setLearning(BackPropagationLearning& learning) override;
    //BackPropagationLearning* getLearning() override;
protected:
    void addLayer(Layer* layer);
    void setNeurons(Layer *l, int n);
    void setEdges(bool randomWeight = true);
    void setMeanSquaredError() override;
    void setSumSquaredError() override;
private:
    //BackPropagationLearning* learning;
    map<int, Layer*, compareLayerOrder> layers;
    bool inputLayer = false;
    bool hiddenLayer = false;
    bool outputLayer = false;
    int countLayer = 0;
    double meanSquaredError = 0;
    double sumSquaredError = 0;
    IActivationFunction* f = 0;
    

};

#endif /* MULTILAYERPERCEPTRON_H */

