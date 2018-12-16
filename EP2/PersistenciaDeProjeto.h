#ifndef PERSISTENCIADEPROJETO_H
#define PERSISTENCIADEPROJETO_H

#include "Projeto.h"
#include <string>
#include <fstream>
#include "ErroDeArquivo.h"

class PersistenciaDeProjeto {
    public:
        PersistenciaDeProjeto();
        virtual ~PersistenciaDeProjeto();

        Projeto* carregar(string arquivo);
        void salvar(Projeto* p, string arquivo);
    protected:
    private:
};

#endif // PERSISTENCIADEPROJETO_H
