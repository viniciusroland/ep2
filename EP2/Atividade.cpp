#include "Atividade.h"

int const Atividade::MAX_RECURSOS = 10;

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
    if (this->getQuantidadeDeRecursos() == Atividade::MAX_RECURSOS) {
        throw new overflow_error ("Nao foi possivel adicionar recurso");
    } else {
        for (int i = 0; i < quantidadeDeRecursos; i++) {
            if (r == recursos[i]) {
                throw new invalid_argument ("Nao foi possivel adicionar recurso");
            }
        }
        this->recursos[quantidadeDeRecursos] = r;
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
    for (int i = 0; i < getQuantidadeDeRecursos(); i++) {
        custo += recursos[i]->getCusto(getDuracao());
    }
    return custo;
}

void Atividade::terminar(int duracaoReal) {
    if (duracaoReal <= 0) {
        throw new invalid_argument ("Duracao negativa");
    } else {
        this->duracao = duracaoReal;
        this->terminada = true;
    }
}

bool Atividade::estaTerminada() {
    return terminada;
}

void Atividade::imprimir() {
    cout << this->nome << " - " <<  this->getDuracao() << " dias - R$" << this->getCusto() << endl;
}
