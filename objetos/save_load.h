#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "manager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class save_load{
    public:
        //Chamar todas as funções de salvar
        int salvarGeral(Manager &manager){
            ofstream jogosSaveFile("estoque.crud");
            ofstream vendasSaveFile("vendas.crud");

            if(!jogosSaveFile || !vendasSaveFile){
                cout << "Problema ao abrir arquivo para salvar dados\n";
                manager.FC.EnterContinue();
                return -1;
            }
            else{
                cout << "Salvando as informações...\n";

                salvarJogos(manager.jogos, jogosSaveFile);
                jogosSaveFile.close();
                salvarVendas(manager.vendas, vendasSaveFile);
                vendasSaveFile.close();

                cout << "Dados salvos\n";
                return 1;
            }
        }

        //Chamar todas as funções de carregar
        int carregarGeral(Manager &manager){
            ifstream jogosLoadFile("estoque.crud");
            ifstream vendasLoadFile("vendas.crud");

            if(!jogosLoadFile){
                cout << "Problema ao abrir arquivo de dados salvos\n";
                manager.FC.EnterContinue();
                return -1;
            }
            else{
                carregarJogos(manager.jogos, jogosLoadFile);
                jogosLoadFile.close();
                carregarVendas(manager.vendas, vendasLoadFile);
                vendasLoadFile.close();
                return 1;
            }
        }

        //Salva variáveis quaisquer
        void salvarMisc(){

        }

        //Carrega informações sobre os jogos
        void carregarJogos(vector<jogo> &jogos, ifstream &Arquivo){
            string linha;
            int quant;
            Arquivo >> quant;
            getline(Arquivo, linha);

            for(int i = 0; i < quant; i++){
                getline(Arquivo, linha);
                stringstream l(linha);
                string data;
                jogo tempJogo;
                string dia, mes, ano, nome, disponiveis, valor, numID, desenvolvedor;

                //Pega a linha lida, lê até chegar na ',' e armazena na variável correspondente
                getline(l, nome, ',');
                getline(l, disponiveis, ',');
                getline(l, valor, ',');
                getline(l, numID, ',');
                getline(l, desenvolvedor, ',');
                getline(l, dia, ',');
                getline(l, mes, ',');
                getline(l, ano, ',');

                //Atribui o que foi lido no campo correspondente do objeto
                tempJogo.nome = nome;
                tempJogo.disponiveis = stoi(disponiveis);
                tempJogo.valor = stof(valor);
                tempJogo.numID = stoi(numID);
                tempJogo.desenvolvedor = desenvolvedor;
                tempJogo.dataLançamento.dia = stoi(dia);
                tempJogo.dataLançamento.mes = stoi(mes);
                tempJogo.dataLançamento.ano = stoi(ano);

                //Controle da maior string para formatação da exibição
                MAXNOMEJOGO = max(MAXNOMEJOGO, (int)tempJogo.nome.size() + 2);
                MAXNOMEDEV = max(MAXNOMEDEV, (int)tempJogo.desenvolvedor.size() + 2);

                jogos.emplace_back(tempJogo);
            }
        }

        //Salva informações sobre os jogos
        void salvarJogos(vector<jogo> &jogos, ofstream &Arquivo){
            //Loop para escrever as informações de cada jogo no arquivo
            Arquivo << jogos.size() << endl;
            for(int i = 0; i < jogos.size(); i++){
                Arquivo << jogos[i].nome << "," << jogos[i].disponiveis << "," << jogos[i].valor << "," << jogos[i].numID << "," << jogos[i].desenvolvedor << "," << jogos[i].dataLançamento.dia << "," << jogos[i].dataLançamento.mes << "," << jogos[i].dataLançamento.ano << "\n";
            }
        }

        void carregarVendas(vector<venda> &vendas, ifstream &Arquivo){
            string linha;

            while(getline(Arquivo, linha)){
                stringstream l (linha);
                string data;
                string ID, IdComprador, dia, mes, ano, valorTotal;
                vector<jogo> itens;
                venda tempVenda;

                getline(l, ID, ',');
                getline(l, IdComprador, ',');
                getline(l, valorTotal, ',');
                getline(l, dia, ',');
                getline(l, mes, ',');
                getline(l, ano, ',');
                carregarJogos(itens, Arquivo);

                tempVenda.ID = stoi(ID);
                tempVenda.IDComprador = stoi(IdComprador);
                tempVenda.valorTotal = stof(valorTotal);
                tempVenda.dataCompra.dia = stoi(dia);
                tempVenda.dataCompra.mes = stoi(mes);
                tempVenda.dataCompra.ano = stoi(ano);
                tempVenda.itens = itens;

                vendas.push_back(tempVenda);
            }
        }

        void salvarVendas(vector<venda> &vendas, ofstream &Arquivo){
            for(int i = 0; i < vendas.size(); i++){
                Arquivo << vendas[i].ID << "," << vendas[i].IDComprador << "," << vendas[i].valorTotal << "," << vendas[i].dataCompra.dia << "," << vendas[i].dataCompra.mes << "," << vendas[i].dataCompra.ano << endl;

                salvarJogos(vendas[i].itens, Arquivo);
            }
        }
};

#endif