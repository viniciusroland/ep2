#include "Projeto.h"

Projeto::Projeto(string nome) {
    this->nome = nome;
    atividades = new vector<Atividade*>();
    recursos = new list<Recurso*>();
}

Projeto::~Projeto() {

}

string Projeto::getNome() {
    return this->nome;
}

void Projeto::adicionar(Atividade* a) {
    atividades->push_back(a);
}

vector<Atividade*>* Projeto::getAtividades() {
    return atividades;
}

void Projeto::adicionar(Recurso* r) {

    if (recursos->size() > 0) {
        list<Recurso*>::iterator i;
        i = find (recursos->begin(), recursos->end(), r);
        if (i != recursos->end()) {
            throw new invalid_argument ("Nao foi possivel adicionar recurso");
        }
    }
    recursos->push_back(r);
}

list<Recurso*>* Projeto::getRecursos() {
    return recursos;
}

int Projeto::getDuracao() {
    duracao = 0;

    for (unsigned int i = 0; i < atividades->size(); i++) {
        duracao += atividades->at(i)->getDuracao();
    }
    return duracao;
}

int Projeto::getDuracao(bool terminadas) {
    duracao = 0;

    for (unsigned int i = 0; i < atividades->size(); i++) {
        if (terminadas == true) {
            if (atividades->at(i)->estaTerminada() == true) {
                this->duracao += atividades->at(i)->getDuracao();
            }
        } else {
            if (atividades->at(i)->estaTerminada() == false) {
                this->duracao += atividades->at(i)->getDuracao();
            }
        }
    }
    return duracao;
}

double Projeto::getCusto() {
    custo = 0;

    for (unsigned int i = 0; i < atividades->size(); i++) {
        custo += atividades->at(i)->getCusto();
    }

    return custo;
}

void Projeto::imprimir() {
    cout << getNome() << " - R$" << getCusto() << endl;
    cout << "Duracao:" << endl;
    cout << "- Feito " << this->getDuracao(true) << " dias" << endl;
    cout << "- Falta " << this->getDuracao(false) << " dias" << endl;
    cout << "- Total " << this->getDuracao() << " dias" << endl;
    cout << "----" << endl;

    for (unsigned int i = 0; i < atividades->size(); i++) {
        atividades->at(i)->imprimir();
    }
}
