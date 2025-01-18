#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include "objects.h"

using namespace std;

namespace std{
    class GeneralFunctions{
    public:
        void ChecarTipoErrado(auto &var){
            while(!(cin >> var)){
                cout << "Opção inválida, tente novamente\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return;
        }

        void LimparBuffer(){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
};

class funcoes : public GeneralFunctions{ 
    public:
        int ProcurarIdJogo(vector<jogo> jogos, string Nome){
            int idEncontrado = -1;

            for (jogo n : jogos){
                if(n.nome == Nome){
                        idEncontrado = n.numID;
                }
            }

            return idEncontrado;
        }

        void adicionarJogos(vector<jogo> &jogos, int &cadastrados){
            string Nome, Dev;
            int disponiveis, id, data, mes, ano;
            float valor;

            cout << "Escreva o nome do jogo: ";
            LimparBuffer();
            getline(cin, Nome);

            cout << "Escreva o preço: ";
            ChecarTipoErrado(valor);

            cout << "Escreva a quantidade disponível: ";
            ChecarTipoErrado(disponiveis);

            cout << "Escreva o nome do desenvolvedor: ";
            LimparBuffer();
            getline(cin, Dev);

            cout << "Escreva o dia do lançamento: ";
            while(!(cin >> data) || data < 1 || data > 31){
                cout << "Opção inválida, tente novamente\n";
                LimparBuffer();
            }

            cout << "Escreva o mes do lançamento: ";
            while(!(cin >> mes) || mes < 1 || mes > 12){
                cout << "Opção inválida, tente novamente\n";
                LimparBuffer();
            }

            cout << "Escreva o ano do lançamento: ";
            while(!(cin >> ano) || ano < 1900){
                cout << "Opção inválida, tente novamente\n";
                LimparBuffer();
            }

            id = cadastrados;
            jogo newgame(Nome, disponiveis, valor, id, Dev, date(data, mes, ano));
            jogos.push_back(newgame);
            cadastrados += 1;
        }

        void remover(){

        }

        void alterarJogos(vector<jogo> &jogos){
            while(1){
                string Nome;
                int rsp, idEncontrado;
                char tentarDenovo, alterarMais;

                cout << "Qual o nome do jogo a ser alterado?\n";
                LimparBuffer();
                getline(cin, Nome);

                idEncontrado = ProcurarIdJogo(jogos, Nome);

                if(idEncontrado == -1){
                    cout << "Não foi encontrado, tentar novamente? (s/n)\n";
                    cin >> tentarDenovo;
                    if(tentarDenovo == 's'){
                        alterarJogos(jogos);
                        return;
                    }

                    return;
                }

                cout << "O que deseja alterar?\n1.Nome\n2.Preço\n3.Disponiveis\n4.Desenvolvedor\n5.Data de lançamento\n";
                cin >> rsp;

                switch (rsp){
                case 1:
                    cout << "Escreva o novo nome: ";
                    LimparBuffer();
                    getline(cin,jogos[idEncontrado].nome);
                    break;
                
                case 2:
                    cout << "Escreva o novo preço: ";
                    ChecarTipoErrado(jogos[idEncontrado].valor);
                    break;
                
                case 3:
                    cout << "Escreva a nova quantidade disponível: ";
                    ChecarTipoErrado(jogos[idEncontrado].disponiveis);
                    break;
                
                case 4:
                    cout << "Escreva o novo desenvolvedor: ";
                    LimparBuffer();
                    getline(cin, jogos[idEncontrado].desenvolvedor);
                    break;

                case 5:
                    cout << "Escreva o novo dia: ";
                    while(!(cin >> jogos[idEncontrado].dataLançamento.dia) || jogos[idEncontrado].dataLançamento.dia < 1 || jogos[idEncontrado].dataLançamento.dia > 31){
                        cout << "Opção inválida, tente novamente\n";
                        LimparBuffer();
                    }

                    cout << "Escreva o novo mês: ";
                    while(!(cin >> jogos[idEncontrado].dataLançamento.mes) || jogos[idEncontrado].dataLançamento.mes < 1 || jogos[idEncontrado].dataLançamento.mes > 31){
                        cout << "Opção inválida, tente novamente\n";
                        LimparBuffer();
                    }

                    cout << "Escreva o novo ano: ";
                    while(!(cin >> jogos[idEncontrado].dataLançamento.ano) || jogos[idEncontrado].dataLançamento.ano < 1 || jogos[idEncontrado].dataLançamento.ano > 31){
                        cout << "Opção inválida, tente novamente\n";
                        LimparBuffer();
                    }
                    break;
                }

                cout << "Deseja alterar mais alguma coisa? (s/n)\n";
                LimparBuffer();
                cin >> alterarMais;
                
                if(alterarMais == 's'){

                }
                else{
                    break;
                }
            }

            return;
        }

        void ExibirUm(vector<jogo> jogos){
            int idEncontrado;
            string Nome;
            char tentarDenovo;

            cout << "Qual o nome do jogo a ser exibido? ";
            LimparBuffer();
            getline(cin, Nome);

            idEncontrado = ProcurarIdJogo(jogos, Nome);

            if(idEncontrado == -1){
                cout << "Não foi encontrado, tentar novamente(s/n)? ";
                cin >> tentarDenovo;
                if(tentarDenovo == 's'){
                    ExibirUm(jogos);
                    return;
                }

                return;
            }

            jogos[idEncontrado].relatorio();

        }

        void relatorioJogo(vector<jogo> jogos){
            //Quantidade jogos cadastrados, Quantidade total, valor total do estoque
            int cadastrados, quantidadeTotal = 0;
            float valorTotal = 0;

            cadastrados = jogos.size();

            for (jogo n : jogos){
                valorTotal += n.valor * n.disponiveis;
                quantidadeTotal += n.disponiveis;
            }

            if(cadastrados > 1){
                cout << cadastrados << " Jogo |\t" << quantidadeTotal << " Quantidade Total |\t" << valorTotal << " Valor total\n";
            }
            else{
                cout << cadastrados << " Jogos diferentes |\t" << quantidadeTotal << " Quantidade Total |\t" << valorTotal << " Valor total\n";

            }
            
            cout << "Aperte enter para continuar\n";
            LimparBuffer();
            cin.get();
        }
    };
}

#endif