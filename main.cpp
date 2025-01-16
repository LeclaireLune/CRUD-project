#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

class date{
    public:
        int dia;
        int mes;
        int ano;

        date(){

        }

        date(int d, int m, int a){
            dia = d;
            mes = m;
            ano = a;
        }
};

class jogo{
    public:

        string nome;
        int disponiveis;
        float valor;
        int numID;
        string desenvolvedor;
        date dataLançamento;

        jogo(){

        }

        jogo(string N, int disp, float value, int id, string dev, date lançamento){
            nome = N;
            disponiveis = disp;
            valor = value;
            numID = id;
            desenvolvedor = dev;
            dataLançamento = lançamento;
        }

        void relatorio(){
            cout << numID << "\t" << nome << "\t" << valor << "\t" << desenvolvedor << "\t" << disponiveis << "\n";
        }
};

class usuario{
    public: 
        string nome;
        string CPF;
        int numID;
        date dataCompra(); //adicionar o tempo

        usuario(string n, string cp, int id){
            nome = n;
            CPF = cp;
            numID = id;
        }
};

class funcoes{
    public:
        void adicionar(vector<jogo> &jogos, int &cadastrados){
            string Nome, Dev;
            int disponiveis, id, data, mes, ano;
            float valor;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Escreva o nome do jogo: ";
            getline(cin, Nome);

            cout << "Escreva o preço: ";
            cin >> valor;

            cout << "Escreva a quantidade disponível: ";
            cin >> disponiveis;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Escreva o nome do desenvolvedor: ";
            getline(cin, Dev);

            cout << "Escreva o dia do lançamento: ";
            cin >> data;

            cout << "Escreva o mes do lançamento: ";
            cin >> mes;

            cout << "Escreva o ano do lançamento: ";
            cin >> ano;

            id = cadastrados;
            jogo newgame(Nome, disponiveis, valor, id, Dev, date(data, mes, ano));
            jogos.push_back(newgame);
            cadastrados += 1;
        }

        void remover(){

        }

        void alterar(){

        }

        void relatorio(){

        }
};

class venda{
    
};

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


        cout << "Sistema de Controle\n";
        cout << "Escolha uma das opções\n";
        cout << "1.Inserir\n2.Realizar venda\n3.Listar todos\n4.Exibir um\n5.Alterar\n6.Remover\n7.Exibir Relatório\n8.Sair\n";
        while(!(cin >> rsp) || rsp < 1 || rsp > 7){
            cout << "Opção inválida, tente novamente\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(rsp){
            case 1:
                //Inserir
                //Jogo no estoque ou uma venda
                manager.adicionar(manager.jogos, manager.jogosCadastrados);
                break;
            case 2:
                //Realizar Venda
            case 3:
                //Listar todos
                break;
            case 4:
                //Exibir um
                break;
            case 5:
                //Alterar
                break;
            case 6:
                //Remover
                break;
            case 7:
                //Exibir relatório
                for(int i = 0; i < manager.jogos.size(); i++){
                    manager.jogos[i].relatorio();
                }
                break;
            case 8:
                //Break
                break;
        }
    }

    //Salvar as informações

    return 0;
}