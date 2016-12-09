/*
 * File:   NetworkPotential_Test.cpp
 * Author: abel
 *
 * Created on 21/11/2016, 16:09:46
 */
#include "NetworkPotential_Test.h"
#include "../../neuralnet/Neuron.h"
#include "../../core/Edge.h"
#include "../../core/ObjectID.h"
#include "../../neuralnet/functions/FuncTanH.h"
#include "../../neuralnet/functions/FuncRectifier.h"
#include <cmath>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(NetworkPotential_Test);

NetworkPotential_Test::NetworkPotential_Test() {
}

NetworkPotential_Test::~NetworkPotential_Test() {
}

/**
 * Ajusta o ambiente para teste
 */
void NetworkPotential_Test::setUp() {
    
    //this sets the ObjectIDs of the input and hidden layer neurons
    this->x1.setId(&this->o1);
    this->x2.setId(&this->o2);
    
    this->i1.setId(&this->o3);
    this->i2.setId(&this->o4);
    this->i3.setId(&this->o5);
    
    
    //this sets the ObjectIDs of the edges
    //between the input and hidden layer
    this->ed11.setId(&this->e11);
    this->ed12.setId(&this->e12);
    this->ed13.setId(&this->e13);
    this->ed21.setId(&this->e21);
    this->ed22.setId(&this->e22);
    this->ed23.setId(&this->e23);
        
    //values of input neurons
    this->x1.setValue(1.0);
    this->x2.setValue(-1.0);
    //weights of the edges of the first neuron of the hidden layer
    this->ed11.setWeight(0.5);
    this->ed12.setWeight(0.5);
    this->ed13.setWeight(0.5);
    //weights of the edges of the second neuron of the hidden layer
    this->ed21.setWeight(0.3);
    this->ed22.setWeight(0.5);
    this->ed23.setWeight(0.2);
    
    this->i1.addEdge(&this->ed11);
    this->i1.addEdge(&this->ed21);
    this->i2.addEdge(&this->ed12);
    this->i2.addEdge(&this->ed22);
    this->i3.addEdge(&this->ed13);
    this->i3.addEdge(&this->ed23);
    

}

void NetworkPotential_Test::tearDown() {

}

/**
 * Testa o valor dos neuronios da camada de entrada.
 * Uma vez que os neuronios da camada de entrada nao possuem arestas
 * para uma camada anterior, o valor dos neuronios sera o que for setado
 * para ele.
 * 
 */
void NetworkPotential_Test::testInputNeuronValues() {
    CPPUNIT_ASSERT(this->x1.eval() == this->x1.getValue());
    CPPUNIT_ASSERT(this->x2.eval() == this->x2.getValue());
}


/**
 * Testa o valor de saida dos neuronios da camada oculta, utilizando a funcao de ativacao
 * TanH (tangente hiperbolica).
 * 
 * Considere a seguinte notacao:
 * v_{j}^{o}(n) -> potencial de ativação do neurônio {j} da camada oculta {o} no tempo discreto (t);
 * w_{ji}^{o} -> peso da aresta que conecta o neurônio de entrada {i} ao neuronio {j}
 * x_{i}(t) -> valor do neurônio {i} no tempo (t)
 * 
 * v_{j}^{o}(t) = \sum_{i=0}^{N} w_{ji}^{o}*x_{i}(t)
 * 
 * A saida do neuronio sera f(v_{j}^{o}(t)), onde f(.) sera a funcao de ativacao.
 * 
 * TanH
 * f(x) = (2/(1+exp^{-2x})) - 1
 * 
 */
void NetworkPotential_Test::testTanHFunc(){
    this->i1.setFunction(this->fTH);
    this->i2.setFunction(this->fTH);
    this->i3.setFunction(this->fTH);
    
    double vi1 = ((0.5*1.0)+(0.3*-1.0));
    vi1 = (2/(1+exp(-2*vi1)))-1;
    
    double vi2 = ((0.5*1.0)+(0.5*-1.0));
    vi2 = (2/(1+exp(-2*vi2)))-1;
    
    double vi3 = ((0.5*1.0)+(0.2*-1.0));
    vi3 = (2/(1+exp(-2*vi3)))-1;
    
    CPPUNIT_ASSERT(this->i1.eval() == vi1);
    CPPUNIT_ASSERT(this->i2.eval() == vi2);
    CPPUNIT_ASSERT(this->i3.eval() == vi3);
    
}

/**
 * Testa o valor de saida dos neuronios da camada oculta, utilizando a funcao de ativacao
 * ReLU.
 * 
 * Considere a seguinte notacao:
 * v_{j}^{o}(n) -> potencial de ativação do neurônio {j} da camada oculta {o} no tempo discreto (t);
 * w_{ji}^{o} -> peso da aresta que conecta o neurônio de entrada {i} ao neuronio {j}
 * x_{i}(t) -> valor do neurônio {i} no tempo (t)
 * 
 * v_{j}^{o}(t) = \sum_{i=0}^{N} w_{ji}^{o}*x_{i}(t)
 * 
 * A saida do neuronio sera f(v_{j}^{o}(t)), onde f(.) sera a funcao de ativacao.
 * 
 * ReLU
 * f(x) = (x < 0.0) ? 0.0 : x
 */
void NetworkPotential_Test::testRectifier(){
    this->i1.setFunction(this->fR);
    this->i2.setFunction(this->fR);
    this->i3.setFunction(this->fR);
    
    double vi1 = ((0.5*1.0)+(0.3*-1.0));
    vi1 = (vi1 < 0.0) ? 0.0 : vi1;
    
    double vi2 = ((0.5*1.0)+(0.5*-1.0));
    vi2 = (vi2 < 0.0) ? 0.0 : vi2;
    
    double vi3 = ((0.5*1.0)+(0.2*-1.0));
    vi3 = (vi3 < 0.0) ? 0.0 : vi3;
    
    CPPUNIT_ASSERT(this->i1.eval() == vi1);
    CPPUNIT_ASSERT(this->i2.eval() == vi2);
    CPPUNIT_ASSERT(this->i3.eval() == vi3);
}


