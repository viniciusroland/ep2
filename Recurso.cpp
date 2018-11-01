#include "Recurso.h"
#include <iostream>
#include <string>
using namespace std;

Recurso::Recurso(string nome) {
    this->nome = nome;
}
Recurso::~Recurso() {
    cout << "Recurso destruído" << endl;
}

string Recurso::getNome(){
    return this->nome;
}