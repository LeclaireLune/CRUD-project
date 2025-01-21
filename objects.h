#ifndef OBJECTS_H
#define OBJECTS_H

#include <string>

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
            cout << "Aperte enter para continuar\n";
            
            cin.get();
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
    
};
#endif