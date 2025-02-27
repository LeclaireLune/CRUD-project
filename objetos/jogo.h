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
};
#endif