#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include "Recurso.h"
#include <stdexcept>

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

#endif // FERRAMENTA_H

