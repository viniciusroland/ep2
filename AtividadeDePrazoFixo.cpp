#include <iostream>
#include <string>
#include "AtividadeDePrazoFixo.h"
#include <stdexcept>
using namespace std;

AtividadeDePrazoFixo::AtividadeDePrazoFixo(string nome, int dias) : Atividade(nome) {
    if(dias <= 0) {
        throw new invalid_argument ("Dias invalidos");
    }
    this->dias = dias;
}

int AtividadeDePrazoFixo::getPrazo() {
    return this->dias;   
}