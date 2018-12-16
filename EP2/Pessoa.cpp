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
        recebeuValorPadrao = true;
    }
}

Pessoa::~Pessoa() {
}

double Pessoa::getValorPorHora() {
    if (recebeValorPadrao()) {
        return Pessoa::getValorPorHoraPadrao();
    }
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
    if (dias <= 0) {
        throw new invalid_argument ("Dias negativos");
    } else if (recebeValorPadrao()) {
        return dias * horasDiarias * getValorPorHoraPadrao();
    } else {
        return dias * horasDiarias * valorPorHora;
    }
}

void Pessoa::imprimir() {
    if (recebeValorPadrao()) {
        cout << "Pessoa: " << nome << " - R$" << getValorPorHoraPadrao() << " - " << horasDiarias << "h por dia" << endl;
    } else {
        cout << "Pessoa: " << nome << " - R$" << valorPorHora << " - " << horasDiarias << "h por dia" << endl;
    }
}
