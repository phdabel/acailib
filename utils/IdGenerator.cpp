/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IdGenerator.cpp
 * Author: abel
 * 
 * Created on 14 de Novembro de 2016, 09:22
 */

#include "IdGenerator.h"

IdGenerator* IdGenerator::instance = 0;

IdGenerator::IdGenerator() {
    this->id = 0;
}

IdGenerator* IdGenerator::getInstance() {
    if(instance == 0){
        instance = new IdGenerator();
    }
    return instance;
}

int IdGenerator::getId(){
    return ++this->id;
}

int IdGenerator::totalObjects(){
    return this->id;
}
