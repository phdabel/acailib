/* 
 * File:   BiasNeuron.h
 * Author: abel
 *
 * Created on 12 de Abril de 2017, 16:02
 */

#ifndef BIASNEURON_H
#define BIASNEURON_H

#include "AbstractNeuron.h"

using namespace std;

class BiasNeuron: public AbstractNeuron {
public:
    BiasNeuron();
    BiasNeuron(const BiasNeuron& orig);
    virtual ~BiasNeuron();
    double getValue();
    void setValue(double value);
    std::string getIndex();
    void setIndex(std::string idx);
private:
    std::string index;
    double value = 1.0;
};

#endif /* BIASNEURON_H */

