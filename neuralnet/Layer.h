/*
 * File:   Layer.h
 * Author: abel
 *
 * Created on 2 de Dezembro de 2016, 14:54
 */

#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <map>
#include "neuron/AbstractNeuron.h"
#include "LayerType.h"
#include "../core/ObjectID.h"
#include "../problem/WeightMatrix.h"
#include "IAbstractLayer.h"

using namespace std;

struct compareObjectID{
    bool operator()(ObjectID* a, ObjectID* b){
        return a->getValue() < b->getValue();
    }
};

class Layer: public IAbstractLayer {
public:
    Layer();
    Layer(LayerType type);
    Layer(const Layer& orig);
    virtual ~Layer();
    vector<AbstractNeuron*> getNeurons() override;
    void addNeuron(AbstractNeuron *neuron) override;
    LayerType getType();
    void setType(LayerType type);
    AbstractNeuron& getNeuron(int i) override;
    void initWeights(int prevNeuronCount, bool random);
    void forward(Layer* prev);
    WeightMatrix* getWeights();
private:
    map<ObjectID*,AbstractNeuron*,compareObjectID> neurons;
    LayerType type;
    WeightMatrix* weights = nullptr;
};

#endif /* LAYER_H */
