/* 
 * File:   INeuralNetwork.h
 * Author: abel
 *
 * Created on 2 de Dezembro de 2016, 16:02
 */

#ifndef INEURALNETWORK_H
#define INEURALNETWORK_H

#include "IAbstractLayer.h"

template <class IAbstractLayer>
class INeuralNetwork {
public:
    virtual IAbstractLayer* getLayer(int i) = 0;
    virtual void addLayer(IAbstractLayer* layer) = 0;
protected:
    virtual bool checkNetworkConstraints() = 0;
private:
};


#endif /* INEURALNETWORK_H */

