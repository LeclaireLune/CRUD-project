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

        void adicionar(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int &Cadastrados, int option, int &proximoId){
            if(option == 1){
                jogo newgame = newgame.AdicionarJogo(jogos, Cadastrados, proximoId);
                jogos.push_back(newgame);
            }
            else if(option == 2){
                usuario newuser;
                newuser.adicionarUsuario(usuarios, Cadastrados, proximoId);
                usuarios.push_back(newuser);
            }
            else if(option == 3){
                venda newsale;
                newsale = newsale.adicionarVenda(jogos, usuarios, vendas, proximoId);
                if(newsale.ID == -1){
                    //Venda não pôde ser concluída
                }
                else{
                    vendas.push_back(newsale);
                }
            }
            
        }

        void remover(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int cadastrados, int option){
            if(option == 1){
                jogo newgame;
                newgame.removerJogo(jogos, cadastrados);
            }
            else if(option == 2){
                usuario newuser;
                newuser.removerUsuario(usuarios);
            }
            else if(option == 3){
                venda tempVenda;
                tempVenda.removerVenda(vendas, usuarios, jogos ,cadastrados);
            }
        }

        void alterar(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int option, int cadastrados, int proximoID){
            if(option == 1){
                jogo temp;
                temp.alterarJogo(jogos);
                return;
            }

            else if(option == 2){
                usuario temp;
                temp.adicionarUsuario(usuarios, cadastrados, proximoID);
                return;
            }

            else if(option == 3){
                venda temp;
                temp.alterarVendas(vendas, jogos, usuarios);
                return;
            }
        }

        void exibirTodos(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int option, int id){
            if(option == 1){
                jogo temp;
                temp.exibirTodosJogos(jogos);
                return;
            }

            else if(option == 2){
                usuario temp;
                temp.exibirTodosUsuario(usuarios);
                return;
            }

            else if(option == 3){
                venda temp;
                temp.exibirTodasVendas(vendas);
                return;
            }
        }

        void relatorio(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int option){
            if(option == 1){
                jogo temp;
                temp.relatorioJogo(jogos);
                return;
            }

            else if(option == 2){
                usuario temp;
                temp.relatorioUsuario(usuarios);
                return;
            }

            else if(option == 3){
                venda temp;
                temp.relatorioVendas(vendas);
                return;
            }
        }

        void exibirUm(vector<jogo> &jogos, vector<usuario> &usuarios, vector<venda> &vendas, int option, int id){
            if(option == 1){
                jogo temp;
                temp.exibirUm(jogos);
                return;
            }

            else if(option == 2){
                usuario temp;
                temp.exibirUmUsuario(usuarios, id);
                return;
            }

            else if(option == 3){
                venda temp;
                temp.exibirUmaVenda(vendas, usuarios);
                return;
            }
        }
            
};

#endif
