#include <iostream>

#include "../objetos/manager.h"

using namespace std;

int main(){
    //Carregar as informações salvas se tiver
    Manager manager;

    while(1){
        int rsp;

        system("clear");
        cout << "Sistema de Controle\n";
        cout << "Escolha uma das opções\n";
        cout << "1.Realizar venda\n2.Controle Estoque\n3.Listar todas\n4.Exibir uma\n5.Alterar\n6.Remover\n7.Exibir Relatório\n8.Sair\n";
        while(!(cin >> rsp) || rsp < 1 || rsp > 8){
            cout << "Opção inválida, tente novamente\n";
            manager.FC.LimparBuffer();
        }

        switch(rsp){
            case 1:
                //Realizar venda
                manager.FC.adicionar(manager.jogos, manager.pessoas, manager.vendas, manager.vendasCadastradas, 3, manager.proximoIdVenda);
                break;
            case 2:
                //Controle Estoque
                manager.EstoqueMenu(manager);
                break;

            case 3:
                manager.FC.exibirTodos(manager.jogos, manager.pessoas, manager.vendas, 3);
                //Listar todas
                break;

            case 4:
                //Exibir uma
                manager.FC.exibirUm(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;
            case 5:
                //Alterar
                manager.FC.alterar(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;
            case 6:
                //Remover
                manager.FC.remover(manager.jogos, manager.pessoas, manager.vendas, manager.vendasCadastradas,  3);
                break;
            case 7:
                //Exibir relatório
                manager.FC.relatorio(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;
            case 8:
                //Break
                break;
        }
    }

    //Salvar as informações

    return 0;
}
