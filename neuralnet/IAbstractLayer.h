/* 
 * File:   IAbstractLayer.h
 * Author: abel
 *
 * Created on 2 de Dezembro de 2016, 15:51
 */

#ifndef IABSTRACTLAYER_H
#define IABSTRACTLAYER_H

#include <vector>
#include "neuron/AbstractNeuron.h"

using namespace std;

class IAbstractLayer {
public:
    virtual vector<AbstractNeuron*> getNeurons() = 0;
    virtual void addNeuron(AbstractNeuron *neuron) = 0;
    virtual AbstractNeuron& getNeuron(int i) = 0;
    virtual ~IAbstractLayer(){};
private:
};

#endif /* IABSTRACTLAYER_H */

