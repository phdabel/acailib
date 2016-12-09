/* 
 * File:   Edge.cpp
 * Author: abel
 * 
 * Created on 17 de Novembro de 2016, 10:47
 */

#include "Edge.h"
#include "ObjectID.h"
#include "UnitType.h"
#include "IUnit.h"
#include <typeinfo>
#include <iostream>

using namespace std;

Edge::Edge(IUnit &v1, IUnit &v2) {
    this->v1 = &v1;
    this->v2 = &v2;
    this->type = UnitType::EDGE;
}

UnitType Edge::getType(){
    return this->type;
}

ObjectID& Edge::getId(){
    return *this->id;
}

void Edge::setId(ObjectID *obj){
    this->id = obj;
    this->setWeight(this->id->random());
}

double Edge::eval(int time){
    return this->getWeight()*this->getVertex1().eval(time);
}

std::string Edge::toString(){
    return "Object of type "+string(typeid(this).name())+" with ID "+to_string(this->getId().getValue())+" between "
            +"vertex "+to_string(this->getVertex1().getId().getValue())+" and vertex "+to_string(this->getVertex2().getId().getValue())
            +" with weight "+to_string(this->getWeight())+".";
}

IUnit& Edge::getVertex1(){
    return *this->v1;
}

IUnit& Edge::getVertex2(){
    return *this->v2;
}

void Edge::setWeight(double w){
    this->weight = w;
}

double Edge::getWeight(){
    return this->weight;
}

Edge::Edge(const Edge& orig) {
}

Edge::~Edge() {
}

