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
        vector<usuario*> pessoas;

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
                    FC.adicionar(jogos, pessoas, vendas, jogosCadastrados, 1, proximoIdJogos, pessoasCadastradas, proximoIdPessoas);
                    break;
                
                case 2:
                    FC.exibirTodos(jogos, pessoas, vendas, 1);
                    break;

                
                case 3:
                    FC.exibirUm(jogos, pessoas, vendas, 1);
                    break;

                
                case 4:
                    FC.alterar(jogos, pessoas, vendas, 1);
                    break;

                case 5:
                    FC.remover(jogos, pessoas, vendas, jogosCadastrados, 1);
                    break;

                
                case 6:
                    FC.relatorio(jogos, pessoas, vendas, 1);
                    break;

                
                case 7:
                    return;
            }
        }
    }

    void clienteMenu(Manager &manager){
        while(1){

            int rsp;
            system("clear");
            cout << "Sistema de Controle de Clientes\n";
            cout << "Escolha uma das opções\n";
            cout << "1.Inserir\n2.Listar todos\n3.Exibir um\n4.Alterar\n5.Remover\n6.Exibir Relatório\n7.Sair\n";

            while(!(cin >> rsp) || rsp < 1 || rsp > 7){
                cout << "Opção inválida, tente novamente\n";
                FC.LimparBuffer();
            }

            switch(rsp){
                case 1:
                    FC.adicionar(jogos, pessoas, vendas, pessoasCadastradas, 2, proximoIdPessoas, pessoasCadastradas, proximoIdPessoas);
                    break;
                
                case 2:
                    FC.exibirTodos(jogos, pessoas, vendas, 2);
                    break;

                
                case 3:
                    FC.exibirUm(jogos, pessoas, vendas, 2);
                    break;

                
                case 4:
                    FC.alterar(jogos, pessoas, vendas, 2);
                    break;

                case 5:
                    FC.remover(jogos, pessoas, vendas, pessoasCadastradas, 2);
                    break;

                
                case 6:
                    FC.relatorio(jogos, pessoas, vendas, 2);
                    break;

                
                case 7:
                    return;
            }
        }
    }
};

#endif