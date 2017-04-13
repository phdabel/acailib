/* 
 * File:   IMatrix.h
 * Author: sim
 *
 * Created on 22 de Março de 2017, 18:34
 */

#ifndef IMATRIX_H
#define IMATRIX_H

#include <map>
#include <vector>

using namespace std;

class IMatrix {
public:
    virtual double getCell(int x, int y) = 0;
    virtual void setCell(int x, int y, double value) = 0;
    virtual void load() = 0;
private:
    virtual void define(int x, int y) = 0;
    
};

#endif /* IMATRIX_H */

