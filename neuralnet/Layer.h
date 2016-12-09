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
#include "Neuron.h"
#include "LayerType.h"
#include "../core/ObjectID.h"
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
    vector<Neuron*> getNeurons() override;
    void addNeuron(Neuron *neuron) override;
    LayerType getType();
    void setType(LayerType type);
private:
    map<ObjectID*,Neuron*,compareObjectID> neurons;
    LayerType type;
};

#endif /* LAYER_H */

