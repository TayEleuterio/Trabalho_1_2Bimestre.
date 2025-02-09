#include <iostream>
#include <vector>
#include <algorithm>
#include "neuronio.hpp"

using namespace std;

int main() {
    // Vetor de ponteiros para objetos da classe base Neuronio
    vector<Neuronio*> neuronios;

    // Criando objetos da classe NeuronioReLU com diferentes pesos e bias
    neuronios.push_back(new NeuronioReLU({0.5, -1.0, 0.8}, 0.2));
    neuronios.push_back(new NeuronioReLU({-0.2, 0.9, -0.5}, -0.3));
    neuronios.push_back(new NeuronioReLU({1.0, -0.4, 0.7}, 0.1));
    neuronios.push_back(new NeuronioReLU({0.2, 0.4}, -1.5));
    neuronios.push_back(new NeuronioReLU({0.2, 0.4}, -0.5));

    // Conjunto de entradas para testar diferentes casos
    vector<vector<double>> entradas = {
        {1.0, 2.0, 3.0},
        {0.3, 2.0}
    };

    // Calculando e exibindo as saídas para cada neurônio e conjunto de entradas
    for (size_t i = 0; i < neuronios.size(); ++i) {
        for (size_t j = 0; j < entradas.size(); ++j) {
            cout << "Saída do NeuronioReLU " << i + 1 << " para entradas " << j + 1 << ": " 
                 << neuronios[i]->predict(entradas[j]) << endl;
        }
    }

    // Liberando a memória alocada
    for (auto neuronio : neuronios) {
        delete neuronio;
    }

    return 0;
}