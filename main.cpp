#include <iostream>

#include "objects.h"
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
};

int main(){
    //Carregar as informações salvas se tiver
    Manager manager;
    while(1){
        int rsp;

        system("clear");
        cout << "Sistema de Controle\n";
        cout << "Escolha uma das opções\n";
        cout << "1.Inserir\n2.Realizar venda\n3.Listar todos\n4.Exibir um\n5.Alterar\n6.Remover\n7.Exibir Relatório\n8.Sair\n";
        while(!(cin >> rsp) || rsp < 1 || rsp > 7){
            cout << "Opção inválida, tente novamente\n";
            manager.LimparBuffer();
        }

        switch(rsp){
            case 1:
                //Inserir
                //Jogo no estoque ou uma venda
                manager.adicionarJogos(manager.jogos, manager.jogosCadastrados);
                break;
            case 2:
                //Realizar Venda
            case 3:
                //Listar todos
                break;
            case 4:
                //Exibir um
                manager.ExibirUm(manager.jogos);
                break;
            case 5:
                manager.alterarJogos(manager.jogos);
                //Alterar
                break;
            case 6:
                //Remover
                break;
            case 7:
                //Exibir relatório
                manager.relatorioJogo(manager.jogos);
                break;
            case 8:
                //Break
                break;
        }
    }

    //Salvar as informações

    return 0;
}