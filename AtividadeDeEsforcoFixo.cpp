#include <iostream>
#include <string>
#include "AtividadeDeEsforcoFixo.h"
#include "Pessoa.h"
using namespace std;

AtividadeDeEsforcoFixo::AtividadeDeEsforcoFixo(string nome,
                                                int horasNecessarias)
                                                : Atividade(nome){
    this->horasNecessarias = horasNecessarias;
                                               
}

int AtividadeDeEsforcoFixo::getHorasNecessarias() {
    return this->getHorasNecessarias;
}

int AtividadeDeEsforcoFixo::getDuracao() {
    int horas = this->getHorasNecessarias();
    int horasRecursos = 0;
    for (int i = 0; i < this->getQuantidadeDeRecursos - 1; i++) {
        // try {
        //     horasRecursos += this->recursos[i]->getHorasDiarias();
        // } catch (logic_error *e){
        //     throw new logic_error ("fudeu")
        // }
    }
}