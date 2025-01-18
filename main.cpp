#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>

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
        void ChecarTipoErrado(auto &var){
            while(!(cin >> var)){
                cout << "Opção inválida, tente novamente\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return;
        }

        void LimparBuffer(){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int ProcurarIdJogo(vector<jogo> jogos, string Nome){
            int idEncontrado = -1;

            for (jogo n : jogos){
                if(n.nome == Nome){
                        idEncontrado = n.numID;
                }
            }

            return idEncontrado;
        }

        void adicionarJogos(vector<jogo> &jogos, int &cadastrados){
            string Nome, Dev;
            int disponiveis, id, data, mes, ano;
            float valor;

            cout << "Escreva o nome do jogo: ";
            LimparBuffer();
            getline(cin, Nome);

            cout << "Escreva o preço: ";
            ChecarTipoErrado(valor);

            cout << "Escreva a quantidade disponível: ";
            ChecarTipoErrado(disponiveis);

            cout << "Escreva o nome do desenvolvedor: ";
            LimparBuffer();
            getline(cin, Dev);

            cout << "Escreva o dia do lançamento: ";
            while(!(cin >> data) || data < 1 || data > 31){
                cout << "Opção inválida, tente novamente\n";
                LimparBuffer();
            }

            cout << "Escreva o mes do lançamento: ";
            while(!(cin >> mes) || mes < 1 || mes > 12){
                cout << "Opção inválida, tente novamente\n";
                LimparBuffer();
            }

            cout << "Escreva o ano do lançamento: ";
            while(!(cin >> ano) || ano < 1900){
                cout << "Opção inválida, tente novamente\n";
                LimparBuffer();
            }

            id = cadastrados;
            jogo newgame(Nome, disponiveis, valor, id, Dev, date(data, mes, ano));
            jogos.push_back(newgame);
            cadastrados += 1;
        }

        void remover(){

        }

        void alterarJogos(vector<jogo> &jogos){
            while(1){

                string Nome;
                int rsp, idEncontrado;
                char tentarDenovo, alterarMais;

                cout << "Qual o nome do jogo a ser alterado?\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, Nome);

                idEncontrado = ProcurarIdJogo(jogos, Nome);

                if(idEncontrado == -1){
                    cout << "Não foi encontrado, tentar novamente? (s/n)\n";
                    cin >> tentarDenovo;
                    if(tentarDenovo == 's'){
                        alterarJogos(jogos);
                        return;
                    }

                    return;
                }

                cout << "O que deseja alterar?\n1.Nome\n2.Preço\n3.Disponiveis\n4.Desenvolvedor\n5.Data de lançamento\n";
                cin >> rsp;

                switch (rsp){
                case 1:
                    cout << "Escreva o novo nome: ";
                    LimparBuffer();
                    getline(cin,jogos[idEncontrado].nome);
                    break;
                
                case 2:
                    cout << "Escreva o novo preço: ";
                    ChecarTipoErrado(jogos[idEncontrado].valor);
                    break;
                
                case 3:
                    cout << "Escreva a nova quantidade disponível: ";
                    ChecarTipoErrado(jogos[idEncontrado].disponiveis);
                    break;
                
                case 4:
                    cout << "Escreva o novo desenvolvedor: ";
                    LimparBuffer();
                    getline(cin, jogos[idEncontrado].desenvolvedor);
                    break;

                case 5:
                    cout << "Escreva o novo dia: ";
                    while(!(cin >> jogos[idEncontrado].dataLançamento.dia) || jogos[idEncontrado].dataLançamento.dia < 1 || jogos[idEncontrado].dataLançamento.dia > 31){
                        cout << "Opção inválida, tente novamente\n";
                        LimparBuffer();
                    }

                    cout << "Escreva o novo mês: ";
                    while(!(cin >> jogos[idEncontrado].dataLançamento.mes) || jogos[idEncontrado].dataLançamento.mes < 1 || jogos[idEncontrado].dataLançamento.mes > 31){
                        cout << "Opção inválida, tente novamente\n";
                        LimparBuffer();
                    }

                    cout << "Escreva o novo ano: ";
                    while(!(cin >> jogos[idEncontrado].dataLançamento.ano) || jogos[idEncontrado].dataLançamento.ano < 1 || jogos[idEncontrado].dataLançamento.ano > 31){
                        cout << "Opção inválida, tente novamente\n";
                        LimparBuffer();
                    }
                    break;
                }

                cout << "Deseja alterar mais alguma coisa? (s/n)\n";
                LimparBuffer();
                cin >> alterarMais;
                
                if(alterarMais == 's'){

                }
                else{
                    break;
                }
            }

            return;
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
                manager.adicionarJogos(manager.jogos, manager.jogosCadastrados);
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
                manager.alterarJogos(manager.jogos);
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