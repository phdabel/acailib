/* 
 * File:   main.cpp
 * Author: sim
 *
 * Created on 13 de Novembro de 2016, 19:35
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
#include <map>

#include "neuralnet/neuron/Neuron.h"
#include "core/UnitType.h"
#include "./utils/IdGenerator.h"
#include "./core/ObjectID.h"
#include "./core/Edge.h"
#include "./neuralnet/functions/FuncTanH.h"
#include "./neuralnet/functions/FuncSigmoid.h"
#include "./neuralnet/MultiLayerPerceptron.h"
#include "./neuralnet/algorithms/BackPropagationLearning.h"
#include <vector>

using namespace std;

static string getType(UnitType type);

int main(int argc, char** argv) {
    

    FuncSigmoid fs;
    BackPropagationLearning learning;
    MultiLayerPerceptron mlp{&fs};
    learning.setNetwork(&mlp);
    
    vector<int> n{2,3,1};
//    n.push_back(2);
//    n.push_back(3);
//    n.push_back(1);
    
    mlp.configure(n);
    cout << mlp.getLayer(0)->getNeuron(1).getId().getValue() << endl;
    
    int **matrix;
    int row = 5;
    int col = 10;
    //dynamically allocate an array
    matrix = new int *[row];
    for(int count = 0; count < row; count++){
        matrix[count] = new int[col];
    }
    
    //input element for matrix
    cout << endl << "Now enter the element for the matrix...";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << endl << "Row " << (i+1) << " col " << (j+1) << " :";
            matrix[i][j] = 0;
        }
    }
    
    
    
    
//    string line;
//    ifstream myfile ("data/xor.dat");
//    
//    if(myfile.is_open()){
//        while(getline(myfile,line)){
//            
//            size_t next, last = 0;
//            string token;
//            while((next = line.find(" ",last)) != string::npos){
//                token = line.substr(last,next-last);
//                cout << token << endl;
//                last = next + 1;
//            }
//            
//            cout << line << endl;
//        }
//        myfile.close();
//    }else{
//        cout << "Unable to open file." << endl;
//    }
    
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
