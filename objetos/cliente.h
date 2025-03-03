#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>
#include <vector>
#include "date.h"

using namespace std;

class usuario{
    public: 
        string nome;
        string CPF;
        int numID;
        date ultimaCompra; //adicionar o tempo

        usuario(){

        }

        usuario(string n, string cpf, int id){
            nome = n;
            CPF = cpf;
            numID = id;
        }

        int procurarCliente(vector<usuario> &clientes, string name){
            for(int i = 0; i < clientes.size(); i++){
                if(clientes[i].nome == name){
                    return i;
                }
            }
            return -1;
        }
        
        void relatorioUser(){
            cout << nome << "\t" << CPF << "\t" << numID;

        }
        
    void adicionarUsuario (){
        cout << "Digite o nome do usuário: \n";
        getline(cin, nome);
        
        cout << "Digite o CPF: \n";
        getline(cin, CPF);

        cout << "Digite o ID: \n";
        cin >> numID;
    }

    void removerUsuario (vector <usuario> &pessoas) {
        int id;
        cout << "Qual usuário deseja remover? ";
        cin >> id;

        bool idEncontrado = false;
        for (auto vetorUser = pessoas.begin (); (vetorUser != pessoas.end()); vetorUser++){
            
            if (vetorUser-> numID == id){
                pessoas.erase(vetorUser);
                cout << "Usuário " << id << " removido." << endl;
                idEncontrado = true;
                break;
            }

            else if (!idEncontrado){
                cout << "Não foi encontrado o usuário " << id << "." << endl;
            }
        }

    }

    void alterarUsuario(){

    }

    void exibirTodosUsuario( vector <usuario> &pessoas){
        if(pessoas.size() == 0){
            cout << "Não há jogos cadastrados\n";
        }
        else{
            for (usuario n : pessoas){
                n.relatorioUser();
            }
        }

        cout << "Aperte enter para continuar";
        cin.get();
    }

    void relatorioUsuario(){
        
    }

    void exibirUmUsuario(int id, vector <usuario> &pessoas){
        cout << "Digite o número de ID do usuário que deseja ver: "<< endl;
        cin >> id;

        bool idEncontrado = false;
        for (auto vetorUser = pessoas.begin (); vetorUser != pessoas.end(); vetorUser++){
            
            if (vetorUser-> numID == id){
                vetorUser->relatorioUser();
                break;
            }

            else if (!idEncontrado){
                cout << "Não foi encontrado o usuário " << id << "."<< endl;
            }
        }

    }

};

#endif