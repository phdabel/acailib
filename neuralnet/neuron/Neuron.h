/* 
 * File:   Neuron.h
 * Author: abel
 *
 * Created on 14 de Novembro de 2016, 11:58
 */

#ifndef NEURON_H
#define NEURON_H

#include "AbstractNeuron.h"

using namespace std;

class Neuron: public AbstractNeuron {
    
public:
    Neuron();
    Neuron(const Neuron& orig);
    virtual ~Neuron();
    std::string getIndex();
    void setIndex(std::string idx);
    double getValue();
    void setValue(double value);
private:
    std::string index;
    double value = -1.0;
};

#endif /* NEURON_H */

