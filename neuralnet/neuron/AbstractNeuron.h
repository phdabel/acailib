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
#include "../../core/Edge.h"
#include "../../neuralnet/functions/IActivationFunction.h"
#include <vector>
#include <map>

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
    double getCacheValue(int time);
    void addEdge(Edge *edge);
    void setFunction(IActivationFunction &func);
    IActivationFunction& getFunction();
    std::vector<Edge*> getEdges();
    Edge& getEdge(int ij);
    double getDelta();
    void setDelta(double delta);
    double getError();
    void setError(double error);
protected:
    double computeNetwork();
private:
    IActivationFunction *f;
    UnitType type;
    ObjectID* id;
    std::vector<Edge*> edges;
    double delta = 0.0;
    double error = 0.0;
    int timeCache = -1;
};

#endif /* ABSTRACTNEURON_H */

