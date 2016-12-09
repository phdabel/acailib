/* 
 * File:   IAbstractLayer.h
 * Author: abel
 *
 * Created on 2 de Dezembro de 2016, 15:51
 */

#ifndef IABSTRACTLAYER_H
#define IABSTRACTLAYER_H

#include <vector>
#include "Neuron.h"

using namespace std;

class IAbstractLayer {
public:
    virtual vector<Neuron*> getNeurons() = 0;
    virtual void addNeuron(Neuron *neuron) = 0;
    virtual ~IAbstractLayer(){};
private:
};

#endif /* IABSTRACTLAYER_H */

