/*
 * File:   main.cpp
 * Author: sim
 *
 * Created on 13 de Novembro de 2016, 19:35
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "./neuralnet/MultiLayerPerceptron.h"
#include "./neuralnet/algorithms/BackPropagationLearning.h"
#include "./neuralnet/functions/FuncSigmoid.h"
#include "./core/UnitType.h"

using namespace std;

int main(int argc, char** argv) {

    // Lê dados de treino do arquivo
    vector<vector<double>> inputs;
    vector<vector<double>> targets;

    ifstream dataFile("data/xor.dat");
    if (!dataFile.is_open()) {
        cerr << "Erro: não foi possível abrir data/xor.dat" << endl;
        return 1;
    }

    string line;
    while (getline(dataFile, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        vector<double> row;
        double val;
        while (iss >> val) row.push_back(val);
        if (row.empty()) continue;
        // Última coluna é o alvo; demais são entradas
        targets.push_back({row.back()});
        row.pop_back();
        inputs.push_back(row);
    }
    dataFile.close();

    int nInputs = (int)inputs[0].size();

    FuncSigmoid fs;
    MultiLayerPerceptron mlp{&fs};

    // Arquitetura: nInputs entradas, 4 ocultos, 1 saída
    vector<int> arch{nInputs, 4, 1};
    mlp.configure(arch);

    BackPropagationLearning learning;
    learning.setNetwork(&mlp);
    learning.setLearningRate(0.5);
    learning.setIterations(10000);
    learning.setTrainingData(inputs, targets);

    cout << "Treinando rede com " << inputs.size()
         << " amostras por 10000 iterações..." << endl;
    learning.run();
    cout << "Treinamento concluído." << endl << endl;

    // Avalia cada amostra
    cout << "Resultados:" << endl;
    int nLayers = mlp.countLayers();
    for (int s = 0; s < (int)inputs.size(); s++) {
        Layer* inputLayer = mlp.getLayer(0);
        vector<AbstractNeuron*> inputNeurons = inputLayer->getNeurons();
        int idx = 0;
        for (auto &n : inputNeurons) {
            if (n->getType() == UnitType::BIAS) continue;
            n->setValue(inputs[s][idx++]);
        }
        int time = 99990 + s;
        for (int l = 1; l < nLayers; l++) {
            for (auto &n : mlp.getLayer(l)->getNeurons()) {
                if (n->getType() == UnitType::BIAS) continue;
                n->eval(time);
            }
        }
        double output = mlp.getLayer(nLayers - 1)->getNeurons()[0]->getValue();

        cout << "  XOR(";
        for (int i = 0; i < (int)inputs[s].size(); i++) {
            if (i) cout << ", ";
            cout << inputs[s][i];
        }
        cout << ") = " << output
             << "  (esperado: " << targets[s][0] << ")" << endl;
    }

    return 0;
}
