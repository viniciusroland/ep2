#include <iostream>
#include "Atividade.h"
#include <string>
using namespace std;

class AtividadeDePrazoFixo : public Atividade{
    public:
        AtividadeDePrazoFixo(string nome, int dias);
        virtual ~AtividadeDePrazoFixo();

        virtual int getPrazo();
    protected:
        int dias;
};