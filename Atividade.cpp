#include "Atividade.h"
#include <iostream>
#include <string>
using namespace std;

Atividade::Atividade(string nome) {
    this->nome = nome;
    recursos = new Recurso*[MAX_RECURSOS];
}

Atividade::~Atividade() {
}

string Atividade::getNome() {
    return this->nome;
}

void Atividade::adicionar(Recurso* r) {
    if (this->getQuantidadeDeRecursos >= Atividade::MAX_RECURSOS) {
        throw new overflow_error ("Sem espaco");
    } else {
        recursos[this->getQuantidadeDeRecursos()] = r;
        quantidadeDeRecursos++;
    }
}

Recurso** Atividade::getRecursos() {
    return recursos;
}

int Atividade::getQuantidadeDeRecursos() {
    return quantidadeDeRecursos;
}

double Atividade::getCusto() {
    custo = 0;

    if (getQuantidadeDeRecursos() == 0) {
        return 0;
    }
    for(int i = 0; i < getQuantidadeDeRecursos(); i++) {
        custo += recursos[i]->getCusto(duracaoReal);
    }
}

void Atividade::terminar(int duracaoReal) {
    this->duracaoReal = duracaoReal;
    this->terminada = true;
}

bool Atividade::estaTerminada() {
    return terminada;
}

void Atividade::imprimir() {
    cout << nome << " - " << this->duracaoReal << " dias - R$" << this->getCusto() << endl;
}
