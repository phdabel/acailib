/* 
 * File:   IUnit.h
 * Author: sim
 *
 * Created on 13 de Novembro de 2016, 21:41
 */

#ifndef IUNIT_H
#define IUNIT_H
#include "ObjectID.h"
#include <string>

class IUnit {
public:
    virtual ObjectID& getId() =0;
    virtual std::string toString()=0;
    virtual void setId(ObjectID *obj)=0;
    virtual double eval(int time=0)=0;
private:
    
};

#endif /* IUNIT_H */

