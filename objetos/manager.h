#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <iostream>

#include "functions.h"

using namespace std;

class Manager{
    public:
        vector<jogo> jogos;
        vector<venda> vendas;
        vector<usuario> pessoas;

        int jogosCadastrados = 0;
        int vendasCadastradas = 0;
        int pessoasCadastradas = 0;

        int proximoIdVenda = 0;
        int proximoIdJogos = 0;
        int proximoIdPessoas = 0;

        int tamMaxNome = 15;
        funcoes FC;

    void EstoqueMenu(Manager &manager){
        while(1){

            int rsp;
            system("clear");
            cout << "Sistema de Controle do Estoque\n";
            cout << "Escolha uma das opções\n";
            cout << "1.Inserir\n2.Listar todos\n3.Exibir um\n4.Alterar\n5.Remover\n6.Exibir Relatório\n7.Sair\n";

            while(!(cin >> rsp) || rsp < 1 || rsp > 7){
                cout << "Opção inválida, tente novamente\n";
                FC.LimparBuffer();
            }

            switch(rsp){
                case 1:
                    FC.adicionar(manager.jogos, manager.pessoas, manager.vendas, manager.jogosCadastrados, 1, manager.proximoIdJogos);
                    break;
                
                case 2:
                    FC.exibirTodos(manager.jogos, manager.pessoas, manager.vendas, 1);
                    break;

                
                case 3:
                    FC.exibirUm(manager.jogos, manager.pessoas, manager.vendas, 1);
                    break;

                
                case 4:
                    FC.alterar(manager.jogos, manager.pessoas, manager.vendas, 1);
                    break;

                case 5:
                    FC.remover(manager.jogos, manager.pessoas, manager.vendas, jogosCadastrados, 1);
                    break;

                
                case 6:
                    FC.relatorio(manager.jogos, manager.pessoas, manager.vendas, 1);
                    break;

                
                case 7:
                    //Salvar;
                    return;
            }
        }
    }
};

#endif