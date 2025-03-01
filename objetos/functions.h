#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>
#include <vector>
#include <string>

#include "jogo.h"
#include "venda.h"
#include "cliente.h"
#include "genFunctions.h"

using namespace std;

class funcoes : public GeneralFunctions{ 
    public:

        void adicionar(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int &Cadastrados, int option){
            if(option == 1){
                jogo newgame = newgame.AdicionarJogo(jogos, Cadastrados);
                jogos.push_back(newgame);
            }
            else if(option == 2){
                //Criar usuario
            }
            else if(option == 3){
                //Criar venda
                bool ();

                venda newsale = newsale;
            }
            
        }

        void remover(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int cadastrados, int option){
            if(option == 1){
                jogo newgame;
                newgame.removerJogo(jogos, cadastrados);
            }
            else if(option == 2){
                //Remover usuario
            }
            else if(option == 3){
                //Remover venda
            }
        }

        void alterar(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int option){
            if(option == 1){
                jogo temp;
                temp.alterarJogo(jogos);
                return;
            }

            else if(option == 2){
                //Alterar usuario
            }

            else if(option == 3){
                //Alterar venda
            }
        }

        void exibirTodos(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int option){
            if(option == 1){
                jogo temp;
                temp.exibirTodosJogos(jogos);
                return;
            }

            else if(option == 2){
                //Exibir usuario
            }

            else if(option == 3){
                //Exibir venda
            }
        }

        void relatorio(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int option){
            if(option == 1){
                jogo temp;
                temp.relatorioJogo(jogos);
                return;
            }

            else if(option == 2){
                //Criar usuario
            }

            else if(option == 3){
                //Criar venda
            }
        }

        void exibirUm(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int option){
            if(option == 1){
                jogo temp;
                temp.exibirUm(jogos);
                return;
            }

            else if(option == 2){
                //Criar usuario
            }

            else if(option == 3){
                //Criar venda
            }
        }
            
};

#endif