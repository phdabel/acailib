/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IdGenerator.h
 * Author: abel
 *
 * Created on 14 de Novembro de 2016, 09:22
 */

#ifndef IDGENERATOR_H
#define IDGENERATOR_H

class IdGenerator {
public:
    static IdGenerator* getInstance();
    int getId();
    int totalObjects();
private:
    static IdGenerator* instance;
    unsigned int id;
    IdGenerator();
};

#endif /* IDGENERATOR_H */

