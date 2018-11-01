#include "Pessoa.h"

double Pessoa::valorPorHoraPadrao = 10;

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias) : Recurso(nome) {
    this->nome = nome;
    if (valorPorHora <= 0 || horasDiarias <= 0) {
        throw new invalid_argument ("Dados invalidos");
    } else {
        this->valorPorHora = valorPorHora;
        this->horasDiarias = horasDiarias;
    }
}

Pessoa::Pessoa(string nome, int horasDiarias) : Recurso(nome) {
    this->nome = nome;
    if (horasDiarias <= 0) {
        throw new invalid_argument ("Dados invalidos");
    } else {
        this->horasDiarias = horasDiarias;
        this->valorPorHora = Pessoa::valorPorHoraPadrao;
        recebeuValorPadrao = true;
    }
}

Pessoa::~Pessoa() {
}

double Pessoa::getValorPorHora() {
    return this->valorPorHora;
}

int Pessoa::getHorasDiarias() {
    return this->horasDiarias;
}

bool Pessoa::recebeValorPadrao() {
    return recebeuValorPadrao;
}

void Pessoa::setValorPorHoraPadrao(double valor) {
    if (valor <= 0) {
        throw new invalid_argument ("Dado invalido");
    } else {
        Pessoa::valorPorHoraPadrao = valor;
    }
}

double Pessoa::getValorPorHoraPadrao() {
    return Pessoa::valorPorHoraPadrao;
}

double Pessoa::getCusto(int dias) {
    return dias * horasDiarias * valorPorHora;
}

void Pessoa::imprimir() {
    cout << "Pessoa: " << nome << " - R$" << valorPorHora << " - " << horasDiarias << "h por dia" << endl;
}
