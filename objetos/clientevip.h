#ifndef CLIENTEVIP_H
#define CLIENTEVIP_H

#include "cliente.h"

class clienteVIP : public usuario{

    public:

        clienteVIP(){ 
        }

        clienteVIP(string n, string _cpf, string t, int id, int vip) : usuario(n, _cpf, t, id, vip){
        }

        void relatorioUser() override{
            cout << "V | " << numID << "\t" << nome << "\t" << CPF << "\t" << telefone;
        }
};

#endif