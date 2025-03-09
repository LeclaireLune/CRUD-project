#ifndef JOGO_H
#define JOGO_H

#include "genFunctions.h"
#include "date.h"
#include <vector>
#include <algorithm>
#include <iomanip>

//Macros da formatação da tabela
#define W_NOME 30
#define W_DISP 15
#define W_VALOR 10
#define W_ID 10
#define W_DEV 15
#define W_DATA 15

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

        //Print do cabeçalho da tabela
        void cabecalhoRelatorio(int maiorNome, int maiorDev){
            cout << left << setw(W_ID) << "ID" << setw(maiorNome) << "Nome" << setw(W_VALOR) << "Valor" << setw(maiorDev) << "Desenvolvedor" << setw(W_DISP) << "Disponiveis" <<  setw(W_DATA) << "Lançamento" << endl;
        }

        //Print da informação de cada jogo
        void relatorio(int maiorNome, int maiorDev){
            cout << left << setw(W_ID) << numID << setw(maiorNome) << nome << setw(W_VALOR) << fixed << setprecision(2) << valor << setw(maiorDev) << desenvolvedor << setw(W_DISP) << disponiveis;
            
            dataLançamento.Exibir();
        }

        int iterarIdJogo(vector<jogo> &jogos, string Nome){
            int idEncontrado = -1, i = 0, encontrados = 0, idEscolhido;
            vector<int> Ids;

            int maiorNome = MAXNOMEJOGO;
            int maiorDev = MAXNOMEDEV;

            for (jogo n : jogos){
                if(n.nome == Nome){
                    Ids.push_back(i);
                    encontrados += 1;
                    maiorNome = max(maiorNome, (int)n.nome.size() + 2);
                    maiorDev = max(maiorDev, (int)n.desenvolvedor.size() + 2);
                }
                i++;
            }

            if(encontrados > 1){
                int z = 0;
                cout << "Foi encontrado mais de um item com esse nome, selecione o desejado pelo seu numero\n" << endl;
                cout << "    ";
                cabecalhoRelatorio(maiorNome, maiorDev);

                for(int j : Ids){
                    cout << z << " | ";
                    jogos[j].relatorio(maiorNome, maiorDev);
                    z++;
                }

                GF.ChecarTipoErrado(idEscolhido, 0, z);
                idEncontrado = Ids[idEscolhido];
                return idEncontrado;
            }
            else if (encontrados == 1){
                idEncontrado = Ids[0];
                return idEncontrado;
            }
            return idEncontrado;
        }

        //Retorna o id de um jogo com o mesmo nome, se encontrado
        int ProcurarIdJogo(vector<jogo> &jogos){
            int idEncontrado = -1, i = 0;
            string Nome;
            char tentarDenovo;

            cout << "Qual o nome do jogo?" << endl;
            GF.LimparBuffer();
            getline(cin, Nome);
            idEncontrado = iterarIdJogo(jogos, Nome);

            while(idEncontrado == -1){
                cout << "Não foi encontrado, tentar novamente(s/n)? ";
                cin >> tentarDenovo;
                if(tentarDenovo == 's'){
                    cout << "Qual o nome do jogo? ";
                    GF.LimparBuffer();
                    getline(cin, Nome);
                    idEncontrado = iterarIdJogo(jogos, Nome);
                }
                else{
                    return -1;
                }
            }

            system("clear");

            return idEncontrado;
        }

        //Exibe apenas um jogo de acordo com seu nome
        void exibirUm(vector<jogo> &jogos){
            int idEncontrado;
            string Nome;
            char tentarDenovo;

            if(jogos.size() != 0){
                idEncontrado = ProcurarIdJogo(jogos);

                if(idEncontrado == -1){
                    return;
                }

                int maiorNome = max(MAXNOMEJOGO, (int)jogos[idEncontrado].nome.size() + 2);
                int maiorDev = max(MAXNOMEDEV, (int)jogos[idEncontrado].desenvolvedor.size() + 2);

                cabecalhoRelatorio(maiorNome, maiorDev);
                jogos[idEncontrado].relatorio(maiorNome, maiorDev);  
            }
            else{
                cout << "Não há jogos cadastrados\n";
            }

            GF.EnterContinue();
        }

        //Exibir todos os jogos presente no vetor
        void exibirTodosJogos(vector<jogo> &jogos){
            if(jogos.size() == 0){
                cout << "Não há jogos cadastrados\n";
            }
            else{
                cabecalhoRelatorio(MAXNOMEJOGO, MAXNOMEDEV);
                for (jogo n : jogos){
                    n.relatorio(MAXNOMEJOGO, MAXNOMEDEV);
                }
            }

            GF.EnterContinue();
        }


        //Adiciona um jogo no vetor
        jogo AdicionarJogo(vector<jogo> &jogos, int &cadastrados, int &proximoId){
            string Nome, Dev;
            int disponiveis, id, dia, mes, ano, diaMax;
            float valor;
            date newDate;

            //Perguntas das informações do objeto
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

            cout << "Escreva o ano do lançamento: ";
            GF.ChecarTipoErrado(ano, 1900);

            cout << "Escreva o mes do lançamento: ";
            GF.ChecarTipoErrado(mes, 1, 12);

            diaMax = newDate.diaMax(mes);

            cout << "Escreva o dia do lançamento: ";
            GF.ChecarTipoErrado(dia, 1, diaMax);

            id = proximoId;

            proximoId += 1;
            cadastrados += 1;
            MAXNOMEJOGO = max(MAXNOMEJOGO, (int)Nome.size() + 2);
            MAXNOMEDEV = max(MAXNOMEDEV, (int)Dev.size() + 2);

            jogo newgame(Nome, disponiveis, valor, id, Dev, date(dia, mes, ano));
            return newgame;
        }

        //Remove um jogo do vetor
        void removerJogo(vector<jogo> &jogos, int cadastrados){
            while(1){
                string Nome;
                int rsp, idEncontrado;
                char tentarDenovo, removerMais, correto;
    
                //Logica para procurar o id do jogo a ser removido
                if(jogos.size() != 0){
                    idEncontrado = ProcurarIdJogo(jogos);

                    if(idEncontrado == -1){
                        return;
                    }

                int maiorNome = max(MAXNOMEJOGO, (int)jogos[idEncontrado].nome.size() + 2);
                int maiorDev = max(MAXNOMEDEV, (int)jogos[idEncontrado].desenvolvedor.size() + 2);

                    cabecalhoRelatorio(maiorNome, maiorDev);
                    jogos[idEncontrado].relatorio(maiorNome, maiorDev);
                }
                else{
                    cout << "Não há jogos cadastrados\n";
                    GF.EnterContinue();
                    return;
                }

                //Verificação se está correto a escolha
                cout << "É o jogo correto? (s/n) ";
                GF.ChecarTipoErrado(correto);

                if(correto == 's'){
                    jogos.erase(jogos.begin() + idEncontrado);
                    cout << "Jogo deletado com sucesso!\n";
                    cadastrados -= 1;
                }

                cout << "Deseja deletar outro? (s/n) ";
                cin >> removerMais;
                if(removerMais == 's'){
                    system("clear");
                    continue;
                }
                else{
                    break;
                }
            }
        }

        //Alterar um jogo presente no vetor
        void alterarJogo(vector<jogo> &jogos){
            while(1){
                string Nome;
                int rsp, idEncontrado;
                char tentarDenovo, alterarMais;

                //logica para procurar o id do jogo
                if(jogos.size() != 0){
                    idEncontrado = ProcurarIdJogo(jogos);

                    if(idEncontrado == -1){
                        return;
                    }

                    int maiorNome = max(MAXNOMEJOGO, (int)jogos[idEncontrado].nome.size() + 2);
                    int maiorDev = max(MAXNOMEDEV, (int)jogos[idEncontrado].desenvolvedor.size() + 2);
                    
                    cabecalhoRelatorio(maiorNome, maiorDev);
                    jogos[idEncontrado].relatorio(maiorNome, maiorDev);  
                }
                else{
                    cout << "Não há jogos cadastrados\n";
                    GF.EnterContinue();
                    return;
                }

                //Pergunta oque deseja alterar
                cout << "O que deseja alterar?\n1.Nome\n2.Preço\n3.Disponiveis\n4.Desenvolvedor\n5.Data de lançamento\n (Outro para cancelar) ";
                GF.ChecarTipoErrado(rsp);

                //Direciona para a lógica de alterar uma informação específica de acordo com a resposta
                switch (rsp){
                    case 1:
                        cout << "Escreva o novo nome: ";
                        GF.LimparBuffer();
                        getline(cin,jogos[idEncontrado].nome);
                        MAXNOMEJOGO = max(MAXNOMEJOGO, (int)jogos[idEncontrado].nome.size() + 2);
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
                        MAXNOMEDEV = max(MAXNOMEDEV, (int)jogos[idEncontrado].desenvolvedor.size() + 2);
                        break;

                    case 5:
                        int max = 0;

                        cout << "Escreva o novo ano: ";
                        GF.ChecarTipoErrado(jogos[idEncontrado].dataLançamento.ano, 1900);

                        cout << "Escreva o novo mês: ";
                        GF.ChecarTipoErrado(jogos[idEncontrado].dataLançamento.mes, 1, 12);

                        max = jogos[idEncontrado].dataLançamento.diaMax(jogos[idEncontrado].dataLançamento.mes);

                        cout << "Escreva o novo dia: ";
                        GF.ChecarTipoErrado(jogos[idEncontrado].dataLançamento.dia, 1, max);
                        break;     
                }

                cout << "Deseja alterar mais algum jogo? (s/n)\n";
                GF.ChecarTipoErrado(alterarMais);
                
                if(alterarMais == 's'){
                    system("clear");
                    continue;
                }
                else{
                    break;
                }
            }
        }

        //Cria um relatório sobre o estoque
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

            GF.EnterContinue();
        }
};
#endif