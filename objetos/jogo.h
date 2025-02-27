#ifndef JOGO_H
#define JOGO_H

#include "genFunctions.h"
#include "date.h"
#include <vector>

GeneralFunctions GF;

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
            cout << numID << "\t" << nome << "\t" << valor << "\t" << desenvolvedor << "\t" << disponiveis << "\t";
            dataLançamento.Exibir();
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

        void exibirUm(vector<jogo> jogos){
            int idEncontrado;
            string Nome;
            char tentarDenovo;

            if(jogos.size() != 0){
                cout << "Qual o nome do jogo a ser exibido? ";
                GF.LimparBuffer();
                getline(cin, Nome);

                idEncontrado = ProcurarIdJogo(jogos, Nome);

                if(idEncontrado == -1){
                    cout << "Não foi encontrado, tentar novamente(s/n)? ";
                    cin >> tentarDenovo;
                    if(tentarDenovo == 's'){
                        exibirUm(jogos);
                        return;
                    }

                    return;
                }

                jogos[idEncontrado].relatorio();  
            }
            else{
                cout << "Não há jogos cadastrados\n";
            }

            cout << "Aperte enter para continuar\n";
            GF.LimparBuffer();
            cin.get();
        }

        void exibirTodosJogos(vector<jogo> jogos){
            if(jogos.size() == 0){
                cout << "Não há jogos cadastrados\n";
            }
            else{
                for (jogo n : jogos){
                    n.relatorio();
                }
            }

            cout << "Aperte enter para continuar";
            GF.LimparBuffer();
            cin.get();
        }

        jogo AdicionarJogo(vector<jogo> &jogos, int cadastrados){
            string Nome, Dev;
            int disponiveis, id, data, mes, ano;
            float valor;

            cout << "Escreva o nome do jogo: ";
        
            GF.LimparBuffer();
            getline(cin, Nome);

            cout << "Escreva o preço: ";
            GF.ChecarTipoErrado(valor);

            cout << "Escreva a quantidade disponível: ";
            GF.ChecarTipoErrado(disponiveis);

            cout << "Escreva o nome do desenvolvedor: ";
            GF.LimparBuffer();
            getline(cin, Dev);

            cout << "Escreva o dia do lançamento: ";
            while(!(cin >> data) || data < 1 || data > 31){
                cout << "Opção inválida, tente novamente\n";
                GF.LimparBuffer();
            }

            cout << "Escreva o mes do lançamento: ";
            while(!(cin >> mes) || mes < 1 || mes > 12){
                cout << "Opção inválida, tente novamente\n";
                GF.LimparBuffer();
            }

            cout << "Escreva o ano do lançamento: ";
            while(!(cin >> ano) || ano < 1900){
                cout << "Opção inválida, tente novamente\n";
                GF.LimparBuffer();
            }

            id = cadastrados;
            jogo newgame(Nome, disponiveis, valor, id, Dev, date(data, mes, ano));
            return newgame;
        }

        void alterarJogo(vector<jogo> &jogos){
            while(1){
                string Nome;
                int rsp, idEncontrado;
                char tentarDenovo, alterarMais;

                if(jogos.size() != 0){
                    cout << "Qual o nome do jogo a ser alterado? ";
                    GF.LimparBuffer();
                    getline(cin, Nome);

                    idEncontrado = ProcurarIdJogo(jogos, Nome);

                    if(idEncontrado == -1){
                        cout << "Não foi encontrado, tentar novamente(s/n)? ";
                        cin >> tentarDenovo;
                        if(tentarDenovo == 's'){
                            exibirUm(jogos);
                            return;
                        }

                        return;
                    }

                    jogos[idEncontrado].relatorio();  
                }
                else{
                    cout << "Não há jogos cadastrados\n";
                    cout << "Aperte enter para continuar\n";
                    GF.LimparBuffer();
                    cin.get();
                    return;
                }

                cout << "O que deseja alterar?\n1.Nome\n2.Preço\n3.Disponiveis\n4.Desenvolvedor\n5.Data de lançamento\n";
                GF.ChecarTipoErrado(rsp);

                switch (rsp){
                    case 1:
                        cout << "Escreva o novo nome: ";
                        GF.LimparBuffer();
                        getline(cin,jogos[idEncontrado].nome);
                        break;
                    
                    case 2:
                        cout << "Escreva o novo preço: ";
                        GF.ChecarTipoErrado(jogos[idEncontrado].valor);
                        break;
                    
                    case 3:
                        cout << "Escreva a nova quantidade disponível: ";
                        GF.ChecarTipoErrado(jogos[idEncontrado].disponiveis);
                        break;
                    
                    case 4:
                        cout << "Escreva o novo desenvolvedor: ";
                        GF.LimparBuffer();
                        getline(cin, jogos[idEncontrado].desenvolvedor);
                        break;

                    case 5:
                        cout << "Escreva o novo dia: ";
                        while(!(cin >> jogos[idEncontrado].dataLançamento.dia) || jogos[idEncontrado].dataLançamento.dia < 1 || jogos[idEncontrado].dataLançamento.dia > 31){
                            cout << "Opção inválida, tente novamente\n";
                            GF.LimparBuffer();
                        }

                        cout << "Escreva o novo mês: ";
                        while(!(cin >> jogos[idEncontrado].dataLançamento.mes) || jogos[idEncontrado].dataLançamento.mes < 1 || jogos[idEncontrado].dataLançamento.mes > 31){
                            cout << "Opção inválida, tente novamente\n";
                            GF.LimparBuffer();
                        }

                        cout << "Escreva o novo ano: ";
                        while(!(cin >> jogos[idEncontrado].dataLançamento.ano) || jogos[idEncontrado].dataLançamento.ano < 1900){
                            cout << "Opção inválida, tente novamente\n";
                            GF.LimparBuffer();
                        }
                        break;
                }

                cout << "Deseja alterar mais algum jogo? (s/n)\n";
                GF.ChecarTipoErrado(alterarMais);
                
                if(alterarMais == 's'){

                }
                else{
                    break;
                }
            }
        }

        void relatorioJogo(vector<jogo> &jogos){
            //Quantidade jogos cadastrados, Quantidade total, valor total do estoque
            int cadastrados, quantidadeTotal = 0;
            float valorTotal = 0;

            cadastrados = jogos.size();

            for (jogo n : jogos){
                valorTotal += n.valor * n.disponiveis;
                quantidadeTotal += n.disponiveis;
            }

            if(cadastrados <= 1){
                cout << cadastrados << " Jogo |\t" << quantidadeTotal << " Quantidade Total |\t" << valorTotal << " Valor total\n";
            }
            else{
                cout << cadastrados << " Jogos diferentes |\t" << quantidadeTotal << " Quantidade Total |\t" << valorTotal << " Valor total\n";

            }

            cout << "Aperte enter para continuar\n";
            GF.LimparBuffer();
            cin.get();
        }
};
#endif