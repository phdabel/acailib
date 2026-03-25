/*
 * File:   AbstractNeuron.h
 * Author: abel
 *
 * Created on 13 de Abril de 2017, 09:26
 */

#ifndef ABSTRACTNEURON_H
#define ABSTRACTNEURON_H

#include "../../core/IUnit.h"
#include "../../core/UnitType.h"
#include "../../core/ObjectID.h"
#include "../../neuralnet/functions/IActivationFunction.h"

using namespace std;

class AbstractNeuron: public IUnit {

public:
    AbstractNeuron();
    AbstractNeuron(const AbstractNeuron& orig);
    virtual ~AbstractNeuron();
    virtual std::string getIndex() = 0;
    virtual void setIndex(std::string idx) = 0;
    virtual double getValue() = 0;
    virtual void setValue(double value) = 0;
    UnitType getType();
    void setType(UnitType type);
    ObjectID& getId() override;
    void setId(ObjectID *obj) override;
    std::string toString() override;
    double eval(int time=0) override;
    void setFunction(IActivationFunction &func);
    IActivationFunction& getFunction();
    double getDelta();
    void setDelta(double delta);
    double getError();
    void setError(double error);
    double getNet();
    void setNet(double net);
private:
    IActivationFunction *f;
    UnitType type;
    ObjectID* id;
    double delta = 0.0;
    double error = 0.0;
    double net = 0.0;
};

#endif /* ABSTRACTNEURON_H */
