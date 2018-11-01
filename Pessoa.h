#ifndef PESSOA_H
#define PESSOA_H

#include "Recurso.h"
#include <exception>

class Pessoa : public Recurso {
    public:
        Pessoa(string nome, double valorPorHora, int horasDiarias);
        Pessoa(string nome, int horasDiarias);
        virtual ~Pessoa();

        virtual double getValorPorHora();
        virtual int getHorasDiarias();
        virtual bool recebeValorPadrao();

        static void setValorPorHoraPadrao(double valor);
        static double getValorPorHoraPadrao();

        double getCusto(int dias);
        void imprimir();
    protected:
    private:
        double valorPorHora;
        int horasDiarias;
        static double valorPorHoraPadrao;
        bool recebeuValorPadrao = false;
};

#endif // PESSOA_H
