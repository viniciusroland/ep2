#include "AtividadeDeEsforcoFixo.h"

AtividadeDeEsforcoFixo::AtividadeDeEsforcoFixo(string nome, int horasNecessarias) : Atividade(nome){
    this->horasNecessarias = horasNecessarias;
}

AtividadeDeEsforcoFixo::~AtividadeDeEsforcoFixo() {

}

int AtividadeDeEsforcoFixo::getHorasNecessarias() {
    return this->horasNecessarias;
}

int AtividadeDeEsforcoFixo::getDuracao() {
    if (terminada == true) {
        return duracao;
    } else {
        horasRecursos = 0;

        for (int i = 0; i < this->getQuantidadeDeRecursos(); i++) {
            Pessoa* r = dynamic_cast<Pessoa*>(recursos[i]);
            if (r != NULL) {
                horasRecursos += r->getHorasDiarias();
                pessoas++;
            }
        }
        if (pessoas == 0) {
            throw new logic_error ("Nao ha pessoas");
        }
        return ceil((double)horasNecessarias/horasRecursos);
    }
}
