#include <iostream>
#include "Projeto.h"
#include "PersistenciaDeProjeto.h"

using namespace std;

int main() {

	double valorPadrao;
	int comandoMenu;
	PersistenciaDeProjeto* persistencia;
	Projeto* p;
	Pessoa* pessoa;
	AtividadeDeEsforcoFixo* atv1;
	AtividadeDePrazoFixo* atv2;
	bool prazoFixo = false;
	string comando_inicial;

    try {
        cout << "Deseja carregar um novo projeto (s/n)? ";
        cin >> comando_inicial;
        cout << "" << endl;
        if (comando_inicial == "s") {
            string arquivo;
            cout << "Digite o nome do arquivo: ";
            cin >> arquivo;
            p = persistencia->carregar(arquivo);
        }
        if (comando_inicial == "n") {
            string nomeProjeto;
            cout << "Digite o nome do projeto: ";
            cin >> nomeProjeto;
            p = new Projeto(nomeProjeto);
        }
        do {
            cout << "" << endl;
            cout << "1 - Adicionar recurso" << endl;
            cout << "2 - Adicionar atividade" << endl;
            cout << "3 - Terminar atividade" << endl;
            cout << "4 - Imprimir projeto" << endl;
            cout << "5 - Definir o valor por hora padrao" << endl;
            cout << "6 - Salvar" << endl;
            cout << "0 - Sair" << endl;
            cout << "Escolha a opcao: ";
            cin >> comandoMenu;
            cout << "" << endl;


            if (comandoMenu == 1) {
                cout << "Ferramenta (f) ou Pessoa (p): ";
                string comando;
                cin >> comando;
                cout << "" << endl;
                if (comando == "f") {
                    cout << "Nome: ";
                    string nome;
                    cin >> nome;
                    cout << "Custo diario: ";
                    double custoDiario;
                    cin >> custoDiario;
                    Ferramenta* f = new Ferramenta(nome, custoDiario);
                    p->adicionar(f);

                }
                if (comando == "p") {
                    cout << "Nome: ";
                    string nome;
                    cin >> nome;
                    cout << "Horas diarias: ";
                    int horasDiarias;
                    cin >> horasDiarias;
                    cout << "Valor por hora padrao (s/n)? ";
                    string comando;
                    cin >> comando;
                    if(comando == "n") {
                        cout << "Valor por hora (em R$): ";
                        int valorPorHora;
                        cin >> valorPorHora;
                        pessoa = new Pessoa(nome, valorPorHora, horasDiarias);
                    } else {
                        pessoa = new Pessoa(nome, horasDiarias);
                    }
                    p->adicionar(pessoa);
                }
            }

            else if (comandoMenu == 2) {
                cout << "Nome: ";
                string nome;
                cin >> nome;
                cout << "Prazo fixo (p) ou trabalho fixo (t)? ";
                string comando;
                cin >> comando;
                if(comando == "p") {
                    cout << "Dias necessarios: ";
                    int dias;
                    cin >> dias;
                    atv2 = new AtividadeDePrazoFixo(nome, dias);
                    p->adicionar(atv2);
                    prazoFixo = true;
                } else {
                    cout << "Horas necessarias: ";
                    int horas;
                    cin >> horas;
                    atv1 =  new AtividadeDeEsforcoFixo(nome, horas);
                    p->adicionar(atv1);
                }
                string comando1;
                do {
                    cout << "" << endl;
                    cout << "Deseja adicionar um recurso (s/n)? ";
                    cin >> comando1;
                    cout << "" << endl;
                    list<Recurso*>* recursos = p->getRecursos();
                    list<Recurso*>::iterator it = recursos->begin();

                    int j = 0;
                    if (comando1 == "s") {
                        while (it != recursos->end()) {
                            cout << j+1 << " - ";
                            (*it)->imprimir();
                            j++;
                            it++;
                        }
                        int comando;
                        cout << "Escolha um recurso ou 0 para sair: ";
                        cin >> comando;
                        if(comando != 0) {
                            it = recursos->begin();
                            int j = 0;
                            while (j != comando - 1) {
                                it++;
                                j++;
                            }
                            if (prazoFixo) {
                                try {
                                    atv2->adicionar((*it));
                                } catch (invalid_argument *e) {
                                    cout << e->what() << endl;
                                    delete e;
                                } catch (overflow_error *e) {
                                    cout << e->what() << endl;
                                    delete e;
                                }
                            } else {
                                try {
                                    atv1->adicionar((*it));
                                } catch (invalid_argument *e) {
                                    cout << e->what() << endl;
                                    delete e;
                                } catch (overflow_error *e) {
                                    cout << e->what() << endl;
                                    delete e;
                                }

                            }
                        }
                    }
                } while (comando1 != "n");
            }

            else if (comandoMenu == 3) {
                vector<Atividade*>* atvs = p->getAtividades();
                for (unsigned int i = 0; i < atvs->size(); i++) {
                    cout << i + 1 << " - " << atvs->at(i)->getNome() << endl;
                }
                cout << "Escolha uma atividade ou 0 para cancelar: ";
                int comando;
                cin >> comando;
                if (comando != 0) {
                    if (atvs->at(comando - 1)->estaTerminada()) {
                        cout << "Atividade ja terminada" << endl;

                    } else {
                        cout << "" << endl;
                        cout << "Duracao real: ";
                        int duracao;
                        cin >> duracao;
                        atvs->at(comando - 1)->terminar(duracao);
                    }
                }
            }

            else if (comandoMenu == 4) {
                p->imprimir();
            }

            else if (comandoMenu == 5) {
                cout << "Valor atual: R$" << Pessoa::getValorPorHoraPadrao() << " por hora" << endl;
                cout << "Novo valor: ";
                cin >> valorPadrao;
                Pessoa::setValorPorHoraPadrao(valorPadrao);
            }

            else if (comandoMenu == 6) {
                cout << "Nome do arquivo: ";
                string arquivo;
                cin >> arquivo;
                persistencia->salvar(p, arquivo);
            }
        } while (comandoMenu != 0);

    } catch (invalid_argument *e) {
        cout << e->what() << endl;
        return 0;
    } catch (logic_error *e) {
        cout << e->what() << endl;
        return 0;
    } catch (overflow_error *e) {
        cout << e->what() << endl;
        return 0;
    }

    delete p;
	return 0;

}

