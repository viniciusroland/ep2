#ifndef PROJETO_H
#define PROJETO_H

#include "AtividadeDeEsforcoFixo.h"
#include "AtividadeDePrazoFixo.h"
#include <vector>
#include <list>
#include <algorithm>
#include <string>

class Projeto {
    public:
        Projeto(string nome);
        virtual ~Projeto();
        virtual string getNome();

        virtual void adicionar(Atividade *a);
        virtual vector<Atividade*>* getAtividades();
        virtual void adicionar(Recurso* r);
        virtual list<Recurso*>* getRecursos();

        virtual int getDuracao();
        virtual int getDuracao(bool terminadas);
        virtual double getCusto();
        virtual void imprimir();
    private:
        string nome;
        vector<Atividade*>* atividades;
        list<Recurso*>* recursos;
        double custo;
        int duracao;
};

#endif // PROJETO_H
