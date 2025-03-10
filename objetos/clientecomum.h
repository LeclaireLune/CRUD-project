#ifndef CLIENTECOMUM_H
#define CLIENTECOMUM_H

#include "cliente.h"

class clienteComum : public usuario{

    public:

        clienteComum(){
        }

        clienteComum(string n, string _cpf, string t, int id, int vip) : usuario(n, _cpf, t, id, vip){
        }

        void relatorioUser() override{
            cout <<"C | " << numID << "\t" << nome << "\t" << CPF << "\t" << telefone;
        }
};

#endif