#include <iostream>
#include <string>
#include "Recurso.h"

using namespace std;

class Atividade{
    public:
        Atividade(string nome);
        virtual ~Atividade();

        virtual string getNome();

        virtual void adicionar(Recurso * r);
        virtual Recurso** getRecursos();
        virtual int getQuantidadeDeRecursos();

        virtual int getDuracao() = 0;
        virtual double getCusto();

        virtual void terminar(int duracaoReal);
        virtual bool estaTerminada();

        virtual void imprimir()= 0;
        static const int MAX_RECURSOS = 10;
    protected:
        string nome;
        Recurso** recursos;
        static const int MAX_RECURSOS = 10;
        int quantidadeDeRecursos;
        double custo;
        double duracaoReal;
        bool terminada = false;
};