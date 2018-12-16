#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include <string>
#include <iostream>
#include "Pessoa.h"
#include "Ferramenta.h"
#include <stdexcept>

using namespace std;

class Atividade
{
    public:
        Atividade(string nome);
        virtual ~Atividade();

        virtual string getNome();

        virtual void adicionar(Recurso* r);
        virtual Recurso** getRecursos();
        virtual int getQuantidadeDeRecursos ();

        virtual int getDuracao() = 0;
        virtual double getCusto();

        virtual void terminar(int duracaoReal);
        virtual bool estaTerminada();

        virtual void imprimir();

        static const int MAX_RECURSOS;
    protected:
        string nome;
        int quantidadeDeRecursos = 0;
        Recurso** recursos;
        double custo;
        double duracao;
        bool terminada = false;
    private:
};

#endif // ATIVIDADE_H
