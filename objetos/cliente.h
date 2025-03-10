#ifndef CLIENTE_H
#define CLIENTE_H

#include "genFunctions.h"
#include "date.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class usuario{
    public: 
        int VIP;
        string nome;
        int numID;
        float desconto;
        string CPF;
        date ultimaCompra;
        string telefone;

        usuario(){ }

        usuario(string n, string _cpf, string t, int id, int _VIP){
            nome = n;
            CPF = _cpf;
            telefone = t;
            numID = id;
            VIP = _VIP;
        }
        
        virtual void relatorioUser() {}


};

#endif
