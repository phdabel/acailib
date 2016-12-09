/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Edge.h
 * Author: abel
 *
 * Created on 17 de Novembro de 2016, 10:47
 */

#ifndef EDGE_H
#define EDGE_H

#include "IUnit.h"
#include "UnitType.h"
#include "ObjectID.h"

class Edge : public IUnit {
public:
    Edge(IUnit &v1, IUnit &v2);
    UnitType getType();
    ObjectID& getId() override;
    void setId(ObjectID *obj) override;
    std::string toString() override;
    IUnit& getVertex1();
    IUnit& getVertex2();
    double getWeight();
    void setWeight(double w);
    Edge(const Edge& orig);
    virtual ~Edge();
    double eval(int time=0) override;
private:
    UnitType type;
    ObjectID* id;
    IUnit* v1;
    IUnit* v2;
    double weight=0.0;

};

#endif /* EDGE_H */

