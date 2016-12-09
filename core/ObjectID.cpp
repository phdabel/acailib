/* 
 * File:   ObjectID.cpp
 * Author: sim
 * 
 * Created on 13 de Novembro de 2016, 19:37
 */

#include "ObjectID.h"
#include <string>
#include <typeinfo>
#include "../utils/IdGenerator.h"
#include <random>
#include <chrono>

using namespace std;

ObjectID::ObjectID() {
    this->setId(IdGenerator::getInstance()->getId());
}

void ObjectID::setId(int id){
    this->id = id;
}

bool ObjectID::equals(ObjectID &o){
    return (typeid(o) == typeid(ObjectID) ? (this->id == o.getValue()) : false);
}

int ObjectID::getValue(){
    return this->id;
}

std::string ObjectID::toString(){
    return "Object of type "+string(typeid(this).name())+" has the value "+std::to_string(this->getValue())+".";
}

double ObjectID::random(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::uniform_real_distribution<double> dist(0, 1);
    std::mt19937_64 rng(seed);
    return dist(rng);
}

ObjectID::ObjectID(const ObjectID& orig) {
}

ObjectID::~ObjectID() {
}

