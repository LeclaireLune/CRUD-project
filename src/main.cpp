//Variáveis globais para formatação das tabelas
int MAXNOMEJOGO = 15;
int MAXNOMEDEV = 15;
int MAXCLIENTEID = 30;

//Variáveis globais para controlar os id's
int proximoIdVenda = 0;
int proximoIdJogos = 0;
int proximoIdPessoas = 0;

#include "../objetos/manager.h"
#include "../objetos/save_load.h"
#include <iostream>

using namespace std;


int main(){
    //Carregar as informações salvas se tiver
    Manager manager;
    save_load sl;

    if(sl.carregarGeral(manager) == -1){
        return 0;
    }

    while(1){
        int rsp;

        system("clear");
        cout << "Sistema de Controle de Vendas\n";
        cout << "Escolha uma das opções\n";
        cout << "1.Realizar venda\n2.Controle Estoque\n3.Controle Clientes\n4.Listar todas\n5.Exibir uma\n6.Alterar\n7.Remover\n8.Exibir Relatório\n9.Sair\n";
        GF.ChecarTipoErrado(rsp, 1, 9);

        switch(rsp){
            case 1:
                //Realizar venda
                manager.FC.adicionar(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;
            case 2:
                //Controle Estoque
                manager.EstoqueMenu(manager);
                break;

            case 3:
                manager.clienteMenu(manager);
                break;

            case 4:
                //Listar todas
                manager.FC.exibirTodos(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;

            case 5:
                //Exibir uma
                manager.FC.exibirUm(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;
            case 6:
                //Alterar
                manager.FC.alterar(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;
            case 7:
                //Remover
                manager.FC.remover(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;
            case 8:
                //Exibir relatório
                manager.FC.relatorio(manager.jogos, manager.pessoas, manager.vendas, 3);
                break;
            case 9:
                //Salvar
                if(sl.salvarGeral(manager) == -1){
                    continue;
                }
                return 0;
        }
    }

    return 0;
}