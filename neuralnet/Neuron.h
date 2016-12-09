/* 
 * File:   Neuron.h
 * Author: abel
 *
 * Created on 14 de Novembro de 2016, 11:58
 */

#ifndef NEURON_H
#define NEURON_H
#include "../core/IUnit.h"
#include "../core/UnitType.h"
#include "../core/ObjectID.h"
#include "../core/Edge.h"
#include "../neuralnet/functions/IActivationFunction.h"
#include <vector>
#include <map>

class Neuron: public IUnit {
public:
    Neuron();
    Neuron(const Neuron& orig);
    virtual ~Neuron();
    UnitType getType();
    ObjectID& getId() override;
    void setId(ObjectID *obj) override;
    std::string toString() override;
    double eval(int time=0) override;
    double getValue();
    void setValue(double value);
    double getCacheValue(int time);
    void addEdge(Edge *edge);
    void setFunction(IActivationFunction &func);
    IActivationFunction& getFunction();
    std::vector<Edge*> getEdges();
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
    double value = 0.0;
    double delta = 0.0;
    double error = 0.0;
    int timeCache = -1;
};

#endif /* NEURON_H */

