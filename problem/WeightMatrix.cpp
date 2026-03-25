/*
 * File:   WeightMatrix.cpp
 * Author: sim
 *
 * Created on 23 de Março de 2017, 16:56
 */

#include "WeightMatrix.h"
#include "../core/ObjectID.h"

WeightMatrix::WeightMatrix(int rows, int cols) {
    this->define(rows, cols);
}

WeightMatrix::WeightMatrix(const WeightMatrix& orig) :
    rows(orig.rows), cols(orig.cols), matrix(orig.matrix) {
}

void WeightMatrix::define(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->matrix.assign(rows, std::vector<double>(cols, 0.0));
}

double WeightMatrix::getCell(int row, int col) {
    return this->matrix[row][col];
}

void WeightMatrix::setCell(int row, int col, double value) {
    this->matrix[row][col] = value;
}

void WeightMatrix::randomize() {
    ObjectID tmp;
    for (int j = 0; j < this->rows; j++)
        for (int i = 0; i < this->cols; i++)
            this->matrix[j][i] = tmp.random();
}

int WeightMatrix::getRows() {
    return this->rows;
}

int WeightMatrix::getCols() {
    return this->cols;
}

void WeightMatrix::load() {
}

WeightMatrix::~WeightMatrix() {
}
