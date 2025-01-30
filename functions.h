#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>
#include <vector>
#include <string>

#include "objects.h"
#include "genFunctions.h"
#include "manager.h"

using namespace std;

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

        void adicionar(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int &Cadastrados, int option){
            if(option == 1){
                jogo newgame = newgame.AdicionarJogo(jogos, Cadastrados);
                jogos.push_back(newgame);
                Cadastrados += 1;
            }
            else if(option == 2){
                //Criar usuario
            }
            else if(option == 3){
                //Criar venda
            }
            
        }

        void remover(){

        }

        void alterarJogos(vector<jogo> &jogos){
            while(1){
                string Nome;
                int rsp, idEncontrado;
                char tentarDenovo, alterarMais;

                if(jogos.size() != 0){
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
                else{
                    cout << "Não há jogos cadastrados\n";
                    cout << "Aperte enter para continuar\n";
                    LimparBuffer();
                    cin.get();
                    return;
                }

                cout << "O que deseja alterar?\n1.Nome\n2.Preço\n3.Disponiveis\n4.Desenvolvedor\n5.Data de lançamento\n";
                ChecarTipoErrado(rsp);

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
                    while(!(cin >> jogos[idEncontrado].dataLançamento.ano) || jogos[idEncontrado].dataLançamento.ano < 1900){
                        cout << "Opção inválida, tente novamente\n";
                        LimparBuffer();
                    }
                    break;
                }

                cout << "Deseja alterar mais algum jogo? (s/n)\n";
                ChecarTipoErrado(alterarMais);
                
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

            if(jogos.size() != 0){
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
            else{
                cout << "Não há jogos cadastrados\n";
            }

            cout << "Aperte enter para continuar\n";
            LimparBuffer();
            cin.get();
        }

        void exibirTodos(vector<jogo> jogos){
            if(jogos.size() == 0){
                cout << "Não há jogos cadastrados\n";
            }
            else{
                for (jogo n : jogos){
                    n.relatorio();
                }
            }

            cout << "Aperte enter para continuar";
            LimparBuffer();
            cin.get();
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

            if(cadastrados <= 1){
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

#endif