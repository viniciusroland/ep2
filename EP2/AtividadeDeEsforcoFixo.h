#ifndef ATIVIDADEDEESFORCOFIXO_H
#define ATIVIDADEDEESFORCOFIXO_H

#include "Atividade.h"
#include <cmath>

class AtividadeDeEsforcoFixo : public Atividade {
    public:
        AtividadeDeEsforcoFixo(string nome, int horasNecessarias);
        virtual ~AtividadeDeEsforcoFixo();

        virtual int getHorasNecessarias();
        virtual int getDuracao();

    protected:
    private:
        int horasNecessarias;
        int horasRecursos;
        int pessoas;
};

#endif // ATIVIDADEDEESFORCOFIXO_H
