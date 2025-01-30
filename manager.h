#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <iostream>

#include "functions.h"

using namespace std;

class Manager : public funcoes{
    public:
        vector<jogo> jogos;
        vector<venda> vendas;
        vector<usuario> pessoas;
        int jogosCadastrados = 0;
        int vendasCadastradas = 0;
        int pessoasCadastradas = 0;

    void EstoqueMenu(Manager &manager){
        while(1){

            int rsp;
            system("clear");
            cout << "Sistema de Controle do Estoque\n";
            cout << "Escolha uma das opções\n";
            cout << "1.Inserir\n2.Listar todos\n3.Exibir um\n4.Alterar\n5.Remover\n6.Exibir Relatório\n7.Sair\n";

            while(!(cin >> rsp) || rsp < 1 || rsp > 7){
                cout << "Opção inválida, tente novamente\n";
                manager.LimparBuffer();
            }

            switch(rsp){
                case 1:
                    manager.adicionar(manager.jogos, manager.pessoas, manager.vendas, manager.vendasCadastradas, 1);
                    break;
                
                case 2:
                    manager.exibirTodos(manager.jogos);
                    break;

                
                case 3:
                    manager.ExibirUm(manager.jogos);
                    break;

                
                case 4:
                    manager.alterarJogos(manager.jogos);
                    break;

                
                case 5:
                    break;

                
                case 6:
                    manager.relatorioJogo(manager.jogos);
                    break;

                
                case 7:
                    return;
            }
        }
    }
};

#endif