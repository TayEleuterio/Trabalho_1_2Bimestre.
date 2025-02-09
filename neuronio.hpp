#include <vector>

using namespace std;

class Neuronio {
protected:
    vector<double> pesos;
    double bias;

public:
    Neuronio(const vector<double>& pesos, double bias) 
        : pesos(pesos), bias(bias) {}

    virtual double predict(const vector<double> entradas) const = 0;
    virtual ~Neuronio() {}
};

// Classe derivada NeuronioReLU
class NeuronioReLU : public Neuronio {
public:
    NeuronioReLU(const vector<double>& pesos, double bias) 
        : Neuronio(pesos, bias) {}

    double predict(const vector<double> entradas) const override {
        double soma = bias;
        for (int i = 0; i < entradas.size(); i++) {
            soma += entradas[i] * pesos[i];
        }
        return soma > 0 ? soma : 0;
    }
};
