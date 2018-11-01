#include "Recurso.h"
#include <iostream>
#include <string>
using namespace std;

class Ferramenta : public Recurso {
    public:
        Ferramenta(string nome, double custoDiaria);
        virtual ~Ferramenta();
        virtual double getCustoDiario();
        virtual void imprimir();
        virtual double getCusto(int dias);
    private:
        double custoDiaria;

};