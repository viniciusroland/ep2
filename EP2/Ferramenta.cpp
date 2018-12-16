#include "Ferramenta.h"

Ferramenta::Ferramenta(string nome, double custoDiaria) : Recurso(nome) {
    this->nome = nome;
    if (custoDiaria < 0) {
        throw new invalid_argument ("Custo negativo");
    } else {
        this->custoDiaria = custoDiaria;
    }
}

Ferramenta::~Ferramenta() {
}

double Ferramenta::getCustoDiario() {
    return this->custoDiaria;
}

void Ferramenta::imprimir() {
    cout << "Ferramenta: " << this->getNome() << " - " << "R$" << this->custoDiaria << " por dia" << endl;
}

double Ferramenta::getCusto(int dias) {
    if (dias <= 0) {
        throw new invalid_argument ("Dias negativos");
    } else {
        return this->custoDiaria * dias;
    }
}
