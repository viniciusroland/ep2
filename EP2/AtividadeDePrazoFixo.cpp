#include "AtividadeDePrazoFixo.h"

AtividadeDePrazoFixo::AtividadeDePrazoFixo(string nome, int dias) : Atividade(nome) {
    if (dias <= 0) {
        throw new invalid_argument ("Dias invalidos SDASA");
    }
    this->dias = dias;
}

AtividadeDePrazoFixo::~AtividadeDePrazoFixo() {

}

int AtividadeDePrazoFixo::getPrazo() {
    return this->dias;
}

int AtividadeDePrazoFixo::getDuracao() {
    if (terminada == true) {
        return duracao;
    } else {
        return this->dias;
    }
}
