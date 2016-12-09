/* 
 * File:   main.cpp
 * Author: sim
 *
 * Created on 13 de Novembro de 2016, 19:35
 */

#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <string>
#include <map>

#include "neuralnet/Neuron.h"
#include "core/UnitType.h"
#include "./utils/IdGenerator.h"
#include "./core/ObjectID.h"
#include "./core/Edge.h"
#include "./neuralnet/functions/FuncTanH.h"

using namespace std;

static string getType(UnitType type);

int main(int argc, char** argv) {
    
//    map<int, string, comp> words;
//    
//    words[1] = "abel";
//    words[2] = "correa";
//    words[3] = "da silva";
//    cout << "2: " << words[2] << endl;
//    words[2] = "poaopiasdiopiopasd";
//    cout << "2: " << words[2] << endl;
//    
//    ObjectID o1,o2,o3,o4,o5;
//    ObjectID e11,e12,e13,e21,e22,e23;
//    Neuron x1;
//    Neuron x2;
//    x1.setValue(-1.0);
//    x2.setValue(1.0);
//    cout << "eval neuron x1 " << to_string(x1.eval()) << endl;
//    
//    Neuron i1;
//    Neuron i2;
//    Neuron i3;
//    
//    FuncTanH f;
//    i1.setFunction(f);
//    i2.setFunction(f);
//    i3.setFunction(f);
//    
//    
//    x1.setId(&o1);
//    x2.setId(&o2);
//    
//    i1.setId(&o3);
//    i2.setId(&o4);
//    i3.setId(&o5);
//    
//    Edge ed11(x1,i1);
//    Edge ed12(x1,i2);
//    Edge ed13(x1,i3);
//    
//    Edge ed21(x2,i1);
//    Edge ed22(x2,i2);
//    Edge ed23(x2,i3);
//    
//    ed11.setId(&e11);
//    ed12.setId(&e12);
//    ed13.setId(&e13);
//    ed21.setId(&e21);
//    ed22.setId(&e22);
//    ed23.setId(&e23);
//    
//    i1.addEdge(&ed11);
//    i1.addEdge(&ed21);
//    i2.addEdge(&ed12);
//    i2.addEdge(&ed22);
//    i3.addEdge(&ed13);
//    i3.addEdge(&ed23);
//    
//    cout << "net value " << to_string(i1.eval()) << endl;
//    cout << "net value " << to_string(i2.eval()) << endl;
//    cout << "net value " << to_string(i3.eval()) << endl;
    /* how to cast from IUnit to Neuron */
    //Neuron *tmpN1;
    //tmpN1 = (Neuron*) &ed1.getVertex1();
    /* end of this fu¢#ing s#|t */
    
    
            
    return 0;
}


static std::string getType(UnitType type){
    switch(type){
        case 0:
            return "Node";
        case 1:
            return "Factor";
        case 2:
            return "Potential";
        case 3:
            return "Neuron";            
        case 4:
            return "Edge";
                    
    }
}
