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
            ofstream saveFile("estoque.crud");
            if(!saveFile){
                cout << "Problema ao abrir arquivo de estoque\n";
                manager.FC.EnterContinue();
                return -1;
            }
            else{
                cout << "Salvando as informações...\n";

                salvarJogos(manager.jogos, saveFile);
                saveFile.close();

                cout << "Dados salvos\n";
                return 1;
            }
        }

        //Chamar todas as funções de carregar
        int carregarGeral(Manager &manager){
            ifstream LoadFile("estoque.crud");

            if(!LoadFile){
                cout << "Problema ao abrir arquivo de estoque\n";
                manager.FC.EnterContinue();
                return -1;
            }
            else{
                carregarJogos(manager.jogos, LoadFile);
                LoadFile.close();
                return 1;
            }
        }

        //Salva variáveis quaisquer
        void salvarMisc(){

        }

        //Carrega informações sobre os jogos
        void carregarJogos(vector<jogo> &jogos, ifstream &Arquivo){
            string linha;
        
            while(getline(Arquivo, linha)){
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
            //Loop para escrever as informaçções de cada jogo no arquivo
            for(int i = 0; i < jogos.size(); i++){
                Arquivo << jogos[i].nome << "," << jogos[i].disponiveis << "," << jogos[i].valor << "," << jogos[i].numID << "," << jogos[i].desenvolvedor << "," << jogos[i].dataLançamento.dia << "," << jogos[i].dataLançamento.mes << "," << jogos[i].dataLançamento.ano << "\n";
            }
        }
};

#endif