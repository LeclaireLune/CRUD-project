#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "jogo.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class save_load{
    public:
        void carregarJogos(vector<jogo> &jogos, ifstream &Arquivo){
            string linha;
        
            while(getline(Arquivo, linha)){
                stringstream l(linha);
                string data;
                jogo tempJogo;
                string dia, mes, ano, nome, disponiveis, valor, numID, desenvolvedor;

                getline(l, nome, ',');
                getline(l, disponiveis, ',');
                getline(l, valor, ',');
                getline(l, numID, ',');
                getline(l, desenvolvedor, ',');
                getline(l, dia, ',');
                getline(l, mes, ',');
                getline(l, ano, ',');

                tempJogo.nome = nome;
                tempJogo.disponiveis = stoi(disponiveis);
                tempJogo.valor = stof(valor);
                tempJogo.numID = stoi(numID);
                tempJogo.desenvolvedor = desenvolvedor;
                tempJogo.dataLançamento.dia = stoi(dia);
                tempJogo.dataLançamento.mes = stoi(mes);
                tempJogo.dataLançamento.ano = stoi(ano);

                MAXNOMEJOGO = max(MAXNOMEJOGO, (int)tempJogo.nome.size() + 2);
                MAXNOMEDEV = max(MAXNOMEDEV, (int)tempJogo.desenvolvedor.size() + 2);

                jogos.emplace_back(tempJogo);
            }
        }

        void salvarJogos(vector<jogo> &jogos, ofstream &Arquivo){
            for(int i = 0; i < jogos.size(); i++){
                Arquivo << jogos[i].nome << "," << jogos[i].disponiveis << "," << jogos[i].valor << "," << jogos[i].numID << "," << jogos[i].desenvolvedor << "," << jogos[i].dataLançamento.dia << "," << jogos[i].dataLançamento.mes << "," << jogos[i].dataLançamento.ano << "\n";
            }
        }
};

#endif