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
                    FC.adicionar(manager.jogos, manager.pessoas, manager.vendas, manager.vendasCadastradas, 1);
                    break;
                
                case 2:
                    FC.exibirTodos(manager.jogos);
                    break;

                
                case 3:
                    FC.ExibirUm(manager.jogos);
                    break;

                
                case 4:
                    FC.alterar(manager.jogos, manager.pessoas, manager.vendas, jogosCadastrados, 1);
                    break;

                case 5:
                    break;

                
                case 6:
                    FC.relatorioJogo(manager.jogos);
                    break;

                
                case 7:
                    //FC.salvar(manager);
                    return;
            }
        }
    }
};

#endif