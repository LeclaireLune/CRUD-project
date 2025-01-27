#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <string>
#include <vector>
#include "genFunctions.h"

using namespace std;

GeneralFunctions GF;

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

        string Exibir(){
            string data;

            cout << dia << "/" << mes << "/" << ano;

            return data;
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
            cout << numID << "\t" << nome << "\t" << valor << "\t" << desenvolvedor << "\t" << disponiveis << "\t" << dataLançamento.Exibir() << "\n";
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

class venda{
    public:
        int ID;
        int IDComprador;
        float valorTotal;
        date dataCompra;
        vector<jogo> jogosComprados;

        venda(){

        }

        venda(int _ID, int _IDComprador, float _valorTotal, date _dataCompra, vector<jogo> _jogosComprados){
            ID = _ID;
            IDComprador = _IDComprador;
            valorTotal = _valorTotal;
            dataCompra = _dataCompra;
            jogosComprados = _jogosComprados;
        }

        void relatorioSimples(){
            cout << ID << "\t" << IDComprador << "\t" << valorTotal << "\t" << dataCompra.Exibir() << "\t" << jogosComprados.size() << "\n";

        }

        void relatorioCompleto(){
            int quantidade = 0;
            cout << ID << "\t" << IDComprador << "\t" << valorTotal << "\t" << dataCompra.Exibir() << "\t" << jogosComprados.size() << "\n";
            for(jogo n : jogosComprados){
                cout << quantidade + 1 << "\." << "\t";

                n.relatorio();
            }
        }

};

#endif