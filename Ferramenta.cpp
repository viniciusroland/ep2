#include "Ferramenta.h"
#include <iostream>
#include <string>
using namespace std;

Ferramenta::Ferramenta(string nome, double custoDiaria) : Recurso(nome) {
    this->custoDiaria = custoDiaria;
}
Ferramenta::~Ferramenta() {
    cout << "Ferramenta destruída" << endl;
}

double Ferramenta::getCustoDiario() {
    return this->custoDiaria;
}

void Ferramenta::imprimir() {
    cout << "Ferramenta: " << this->getNome() << " - " << "R$" << this->custoDiaria << " por dia" << endl; 
}

double Ferramenta::getCusto(int dias) {
    return this->custoDiaria * dias;
}