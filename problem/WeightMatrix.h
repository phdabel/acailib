/*
 * File:   WeightMatrix.h
 * Author: sim
 *
 * Created on 23 de Março de 2017, 16:56
 */

#ifndef WEIGHTMATRIX_H
#define WEIGHTMATRIX_H

#include "IMatrix.h"
#include <vector>

class WeightMatrix: public IMatrix {
public:
    WeightMatrix(int rows, int cols);
    WeightMatrix(const WeightMatrix& orig);
    double getCell(int row, int col) override;
    void setCell(int row, int col, double value) override;
    void randomize();
    int getRows();
    int getCols();
    void load() override;
    virtual ~WeightMatrix();
private:
    void define(int rows, int cols);
    int rows = 0;
    int cols = 0;
    std::vector<std::vector<double>> matrix;
};

#endif /* WEIGHTMATRIX_H */
