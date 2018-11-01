#include <iostream>
#include <string>
#include "Atividade.h"

using namespace std;

class AtividadeDeEsforcoFixo : public Atividade {
    public:
        AtividadeDeEsforcoFixo(string nome, int horasNecessarias);
        virtual ~AtividadeDeEsforcoFixo();

        
        virtual int getHorasNecessarias();
        virtual int getDuracao();

    protected:
        int horasNecessarias;
};