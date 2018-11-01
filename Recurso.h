#include <iostream>
#include <string>
using namespace std;

class Recurso {
    public:
        Recurso(string nome);
        virtual ~Recurso();

        virtual string getNome();
        virtual double getCusto(int dias) = 0;
        virtual void imprimir() = 0;
    
    protected:
        string nome;
        double custo;
};