/* 
 * File:   WeightMatrix.h
 * Author: sim
 *
 * Created on 23 de Março de 2017, 16:56
 */

#ifndef WEIGHTMATRIX_H
#define WEIGHTMATRIX_H

#include "IMatrix.h"

class WeightMatrix: public IMatrix {
public:
    int * matrix = NULL;
    WeightMatrix(int x, int y);
    WeightMatrix(const WeightMatrix& orig);
    double getCell(int x, int y);
    void setCell(int x, int y, double value);
    void load();
    virtual ~WeightMatrix();
private:
    void define(int x, int y);
    int x = 0;
    int y = 0;
};

#endif /* WEIGHTMATRIX_H */

