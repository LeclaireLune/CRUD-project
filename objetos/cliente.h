#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "date.h"

using namespace std;

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

#endif