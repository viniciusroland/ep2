#include "PersistenciaDeProjeto.h"

PersistenciaDeProjeto::PersistenciaDeProjeto() {

}

PersistenciaDeProjeto::~PersistenciaDeProjeto() {

}

Projeto* PersistenciaDeProjeto::carregar(string arquivo) {

    ifstream input;
    input.open(arquivo);

    if (input.fail()) {
        input.close();
        throw new ErroDeArquivo ("Arquivo nao encontrado");
    }

    string nomeProjeto;

    input >> nomeProjeto;

    if (!input) {
        input.close();
        throw new ErroDeArquivo ("Arquivo vazio");
    }

    Projeto* projeto = new Projeto(nomeProjeto);
    int quantidadeRecursos;

    input >> quantidadeRecursos;

    string tipoRecurso;

    for (int i = 0; i < quantidadeRecursos; i++) {
        input >> tipoRecurso;
        if (tipoRecurso == "F") {
            string nomeF;
            int custoDiario;
            input >> nomeF;
            input >> custoDiario;
            Ferramenta* ferramenta = new Ferramenta(nomeF, custoDiario);
            projeto->adicionar(ferramenta);
        } else {
            string nomeP;
            double valorPorHora;
            int horasDiarias;
            input >> nomeP;
            input >> valorPorHora;
            input >> horasDiarias;
            if (valorPorHora == -1) {
                Pessoa* pessoa = new Pessoa(nomeP, horasDiarias);
                projeto->adicionar(pessoa);
            } else {
                Pessoa* pessoa = new Pessoa(nomeP, valorPorHora, horasDiarias);
                projeto->adicionar(pessoa);
            }
        }
    }

    int quantidadeAtividades;
    input >> quantidadeAtividades;
    for (int i = 0; i < quantidadeAtividades; i++) {
        string tipoAtividade;
        input >> tipoAtividade;
        int numeroRecursos;
        string nomeRecursos;
        list<Recurso*>* recursos = projeto->getRecursos();
        list<Recurso*>::iterator it;

        if (tipoAtividade == "E") {
            AtividadeDeEsforcoFixo* atv;
            string nomeA;
            int horas;
            string terminou;
            input >> nomeA;
            input >> horas;
            input >> terminou;
            int duracao;
            if (terminou == "T") {
                input >> duracao;
                atv = new AtividadeDeEsforcoFixo(nomeA, horas);
                atv->terminar(duracao);
            } else {
                atv = new AtividadeDeEsforcoFixo(nomeA, horas);
            }

            input >> numeroRecursos;
            for (int j = 0; j < numeroRecursos; j++) {
                input >> nomeRecursos;
                it = recursos->begin();
                while (it != recursos->end()) {
                    if (nomeRecursos == (*it)->getNome()) {
                        atv->adicionar((*it));
                    }
                    it++;
                }
            }
            projeto->adicionar(atv);
        } else {
            AtividadeDePrazoFixo* atv;
            string nomeA;
            int prazo;
            string terminou;
            int duracao;
            input >> nomeA;
            input >> prazo;
            input >> terminou;
            if (terminou == "T") {
                input >> duracao;
                atv = new AtividadeDePrazoFixo(nomeA, prazo);
                atv->terminar(duracao);
            } else {
                atv = new AtividadeDePrazoFixo(nomeA, prazo);
            }


            input >> numeroRecursos;

            for (int j = 0; j < numeroRecursos; j++) {
                input >> nomeRecursos;
                it = recursos->begin();
                while (it != recursos->end()) {
                    if (nomeRecursos == (*it)->getNome()) {
                        atv->adicionar((*it));
                    }
                    it++;
                }
            }
            projeto->adicionar(atv);
        }
    }
    if (input.fail()) {
        throw new ErroDeArquivo ("Formatacao errada");
    }

    salvar(projeto, "teste.txt");
    input.close();


    return projeto;
}

void PersistenciaDeProjeto::salvar(Projeto* p, string arquivo) {
    ofstream output;
    output.open(arquivo, ios_base::trunc);

    if (output.fail()) {
        output.close();
        throw new ErroDeArquivo ("O arquivo nao pode ser escrito");
    }

    int i = 0;
    list<Recurso*>::iterator it = p->getRecursos()->begin();

    output << p->getNome() << endl;
    while (it != p->getRecursos()->end()) {
        i++;
        it++;
    }
    output << i << endl;

    it = p->getRecursos()->begin();
    while (it != p->getRecursos()->end()) {
        Ferramenta* ferramenta = dynamic_cast<Ferramenta*>((*it));
        if (ferramenta == NULL) {
            Pessoa* pessoa = dynamic_cast<Pessoa*>((*it));
            if (pessoa->recebeValorPadrao()){
                output << "P " << pessoa->getNome() << " " << -1 << " " << pessoa->getHorasDiarias() << endl;
            } else {
                output << "P " << pessoa->getNome() << " " << pessoa->getValorPorHora() << " " << pessoa->getHorasDiarias() << endl;
            }
        } else {
            output << "F " << ferramenta->getNome() << " " << ferramenta->getCustoDiario() << endl;
        }
        it++;
    }

    unsigned int j;
    for (j = 0; j < p->getAtividades()->size(); j++);
    output << j << endl;
    for (j = 0; j < p->getAtividades()->size(); j++) {
        AtividadeDeEsforcoFixo* atividade1 = dynamic_cast<AtividadeDeEsforcoFixo*>(p->getAtividades()->at(j));
        if (atividade1 == NULL) {
            AtividadeDePrazoFixo* atividade2 = dynamic_cast<AtividadeDePrazoFixo*>(p->getAtividades()->at(j));
            output << "P " << atividade2->getNome() << " " << atividade2->getPrazo();
            if (atividade2->estaTerminada() == true) {
                output << " T " << atividade2->getDuracao() << endl;
            } else {
                output << " N " << endl;
            }
            output << atividade2->getQuantidadeDeRecursos() << endl;
            for (int j = 0; j < atividade2->getQuantidadeDeRecursos(); j++) {
                output << atividade2->getRecursos()[j]->getNome() << " ";
            }
            output << "" << endl;
        } else {
            output << "E " << atividade1->getNome() << " " << atividade1->getHorasNecessarias();
            if (atividade1->estaTerminada() == true) {
                output << " T " << atividade1->getDuracao() << endl;
            } else {
                output << " N " << endl;
            }
            output << atividade1->getQuantidadeDeRecursos() << endl;
            for (int j = 0; j < atividade1->getQuantidadeDeRecursos(); j++) {
                output << atividade1->getRecursos()[j]->getNome() << " ";
            }
            output << "" << endl;

        }
    }
    output << "" << endl;
    output.close();

}
