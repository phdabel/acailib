/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ObjectID.h
 * Author: sim
 *
 * Created on 13 de Novembro de 2016, 19:37
 */

#ifndef OBJECTID_H
#define OBJECTID_H
#include <string>

class ObjectID {
public:
    ObjectID();
    bool equals(ObjectID &o);
    int getValue();
    std::string toString();
    ObjectID(const ObjectID& orig);
    virtual ~ObjectID();
    double random();
private:
    unsigned int id =0;
    void setId(int id);
};

#endif /* OBJECTID_H */

