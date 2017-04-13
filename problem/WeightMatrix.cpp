/* 
 * File:   WeightMatrix.cpp
 * Author: sim
 * 
 * Created on 23 de Março de 2017, 16:56
 */

#include "WeightMatrix.h"

WeightMatrix::WeightMatrix(int x, int y) {
    this->define(x,y);
}

WeightMatrix::WeightMatrix(const WeightMatrix& orig) {
}

double WeightMatrix::getCell(int x, int y){
    
}

void WeightMatrix::setCell(int x, int y, double value){
    
}

void WeightMatrix::define(int x, int y){
    
    this->x = x;
    this->y = y;
    //this->matrix = new int[x][y];
    
}

void WeightMatrix::load(){
    
}

WeightMatrix::~WeightMatrix() {
}

