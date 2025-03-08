#ifndef CLIENTE_H
#define CLIENTE_H

#include "genFunctions.h"
#include <string>
#include <iostream>
#include <vector>
#include "date.h"

using namespace std;

class usuario{
    public: 
        string nome;
        string CPF_CNPJ;
        int numID;
        date ultimaCompra;
        string telefone;
        int cadastrados;
        date ultimaCompra;

        usuario(){ }

        usuario(string n, string _cpf_cnpj, string t, int id){
            nome = n;
            CPF_CNPJ = _cpf_cnpj;
            telefone = t;
            numID = id;
        }

        int procurarCliente(vector<usuario> &pessoas, int id){
            for(int i = 0; i < pessoas.size(); i++){
                if(pessoas[i].numID == id){
			return i;
                }
            }
            return -1;
        }
        
        void relatorioUser( ){
            cout << nome << "\t" << CPF_CNPJ << "\t" << telefone << "\t" << numID;

        }
        
	usuario adicionarUsuario (vector<usuario> &pessoas, int &cadastrados, int &proximoID){
            string nome, CPF_CNPJ, telefone;
            int id = proximoID;

            cout << "Digite o nome do usuário: ";
            getline(cin, nome);
        
            cout << "Digite o CPF: ";
            getline(cin, CPF_CNPJ);

            cout << "Digite o número de telefone: ";
            getline (cin, telefone);

           
            cadastrados ++;
            proximoID ++;

            usuario newuser (nome, CPF_CNPJ, telefone, id);
            pessoas.push_back(newuser);
            return newuser;
	}

	void removerUsuario (vector <usuario> &pessoas) {
        char rsp;
        do{

        int id;
        cout << "Qual usuário deseja remover? ";
        GF.ChecarTipoErrado(id);
        GF.LimparBuffer();
        bool idEncontrado = false;
        for (auto vetorUser = pessoas.begin (); (vetorUser != pessoas.end()); vetorUser++){
            
            if (vetorUser-> numID == id){
                pessoas.erase(vetorUser);
                cout << "Usuário " << id << " removido." << endl;
                idEncontrado = true;
                break;
        }
     	 if (!idEncontrado){
            cout << "Não foi encontrado o usuário " << id << ".";
            GF.EnterContinue();
        }

        cout << "Deseja remover outro usuário? ";
        GF.ChecarTipoErrado(rsp);
    } while (rsp == 's');

    }

    void alterarUsuario(vector <usuario> &pessoas){
            char rsp;
            do{
                int id, escolha;
                char tentativa;

                cout << "Qual usuário deseja alterar? ";
                GF.ChecarTipoErrado(id);

                bool idEncontrado =  false;
                for (auto vetorUser = pessoas.begin(); (vetorUser != pessoas.end()); vetorUser++) {
                    if (vetorUser-> numID == id){
                        cout << "O que deseja alterar? \n1.Nome\n2.CPF/CNPJ\n3.Telefone\n4.Digite ";
                            switch (escolha){
                                case 1:
                                cout << "Escreva o nove nome do usuário: ";
                                getline (cin, pessoas[idEncontrado].nome);
                                break;
                                case 2:
                                cout << "Escreva o novo CPF/CNPJ do usuário: ";
                                getline (cin, pessoas[idEncontrado].CPF_CNPJ);
                                break;
                                case 3:
                                cout << "Escreva o novo número de telefone do usuário: ";
                                getline (cin, pessoas[idEncontrado].telefone);
                                break;
                            }
                        break;
                    }
                    else if (!idEncontrado){
                        cout << "Não foi encontrado o usuário " << id << ".";
                        GF.EnterContinue();
                    }
                }
                cout << "Deseja alterar outro usuário? ";
                GF.ChecarTipoErrado(rsp);
            } while (rsp == 's');
    }

    void exibirTodosUsuario( vector <usuario> &pessoas){
        if(pessoas.size() == 0){
            cout << "Não há usuários cadastrados\n";
        }
        else{
            for (usuario n : pessoas){
                n.relatorioUser();
	        cout << "\n";
            }
        }

        GF.EnterContinue();
    }

    void relatorioUsuario(vector<usuario> &pessoas){
        int cadastrados, totalCadastrados = 0;

        for (usuario n : pessoas){
            totalCadastrados += n.cadastrados;
        }

        if (pessoas.empty()){
            cout << "Não há usuários cadastrados...";
            GF.EnterContinue();
        }

        cout << "Total de usuários cadastrados: " << totalCadastrados << "\n";
        for (const usuario &n : pessoas) {
                cout << "Nome: " << n.nome << "\tCPF/CNPJ: " << n.CPF_CNPJ << "\tTelefone: " << n.telefone << "\tID: " << n.numID << "\n";
            }

            GF.EnterContinue();
    }

    void exibirUmUsuario(vector <usuario> &pessoas, int id){
        cout << "Digite o número de ID do usuário que deseja ver: "<< endl;
        cin >> id;

        bool idEncontrado = false;
        for (auto vetorUser = pessoas.begin (); vetorUser != pessoas.end(); vetorUser++){
            
            if (vetorUser-> numID == id){
                vetorUser->relatorioUser();
                break;
            }
	}
        if (!idEncontrado){
            cout << "Não foi encontrado o usuário " << id << "."<< endl;
            GF.EnterContinue();
        }

    }

};

#endif
