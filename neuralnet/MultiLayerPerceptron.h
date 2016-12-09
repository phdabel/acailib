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


using namespace std;

struct compareLayerOrder{
    bool operator()(int a, int b){
        return a < b;
    }
};

class MultiLayerPerceptron: public INeuralNetwork<Layer> {
public:
    MultiLayerPerceptron();
    MultiLayerPerceptron(const MultiLayerPerceptron& orig);
    void addLayer(Layer* layer);
    Layer* getLayer(int i);
    bool checkNetworkConstraints();
    int countLayers();
    void configure(vector<int> layerNeurons, bool randomWeight = true);
    virtual ~MultiLayerPerceptron();
private:
    map<int, Layer*, compareLayerOrder> layers;
    bool inputLayer = false;
    bool hiddenLayer = false;
    bool outputLayer = false;
    int countLayer = 0;
    

};

#endif /* MULTILAYERPERCEPTRON_H */

