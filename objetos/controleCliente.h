#ifndef CONTROLECLIENTE_H
#define CONTROLECLIENTE_H

#include "cliente.h"
#include "clientevip.h"
#include "clientecomum.h"

class controleCliente{
    public: 

        int procurarCliente(vector<usuario*> &pessoas, string cpf){
            for(int i = 0; i < pessoas.size(); i++){
                if(pessoas[i]->CPF == cpf){
                    return i;
                }
            }
            return -1;
        }

        int procurarClienteId(vector<usuario*> &pessoas, int id){
            for(int i = 0; i < pessoas.size(); i++){
                if(pessoas[i]->numID == id){
                    return i;
                }
            }
            return -1;
        }

        int adicionarPolimorfico(vector<usuario*> &clientes, int &proximoID){
            int tipo, VIP;
            bool cpfExiste = false;
            string nome, CPF, telefone;
            int id = proximoID;
            usuario *tempCliente;
            system("clear");

            cout << "Qual tipo de cliente deseja adicionar?\n1.Cliente Comum\n2.Cliente Vip" << endl;
            GF.ChecarTipoErrado(tipo, 1, 2);

            cout << "Digite o nome do cliente: ";
            getline(cin, nome);
            
            do{
                cout << "Digite o CPF: ";
                getline(cin, CPF);

                if(procurarCliente(clientes, CPF) == -1){
                    cpfExiste = false;
                }
                else{
                    cpfExiste = true;
                }
            }while(cpfExiste == true);

            cout << "Digite o número de telefone: ";
            getline (cin, telefone);

            if(tipo == 1){
                tempCliente = new clienteComum(nome, CPF, telefone, proximoID, VIP);
                tempCliente->VIP = 0;
                clientes.push_back(tempCliente);
                proximoID ++;
                return proximoID - 1;
            }
            else if(tipo == 2){
                tempCliente = new clienteVIP(nome, CPF, telefone, proximoID, VIP);
                tempCliente->VIP = 1;
                clientes.push_back(tempCliente);
                proximoID ++;
                return proximoID - 1;
            }
            else{
                return -1;
            }
        }

        void removerUsuario (vector <usuario*> &pessoas){
            char rsp;
            do{
                int id;
                cout << "Qual usuário deseja remover? ";
                GF.ChecarTipoErrado(id);
                GF.LimparBuffer();

                bool idEncontrado = false;
                
                for(int i = 0; i < pessoas.size(); i++){
                    if (pessoas[i]->numID == id){
                        pessoas.erase(pessoas.begin() + i);
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
                }
            } while (rsp == 's');
        }

        void alterarUsuario(vector <usuario*> &pessoas){
            char rsp;
            do{
                int id, escolha;
                char tentativa;

                cout << "Digite o id do usuário que deseja alterar: ";
                GF.ChecarTipoErrado(id);
                GF.LimparBuffer();

                bool idEncontrado =  false;
                for(int i = 0; i < pessoas.size(); i++){

                    if (pessoas[i]->numID == id){
                        cout << "O que deseja alterar? (outro para continuar)\n1.Nome\n2.CPF\n3.Telefone" << endl;
                        
                        switch (escolha){
                            case 1:
                                cout << "Escreva o nove nome do usuário: ";
                                getline (cin, pessoas[idEncontrado]->nome);
                                break;

                            case 2:
                                cout << "Escreva o novo CPF do usuário: ";
                                getline (cin, pessoas[idEncontrado]->CPF);
                                break;

                            case 3:
                                cout << "Escreva o novo número de telefone do usuário: ";
                                getline (cin, pessoas[idEncontrado]->telefone);
                                break;
                        }

                        idEncontrado = true;
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

        void exibirTodosUsuario( vector <usuario*> &pessoas){
            if(pessoas.size() == 0){
                cout << "Não há usuários cadastrados\n";
            }
            else{
                for(int i = 0; i < pessoas.size(); i++){
                    pessoas[i]->relatorioUser();
                    cout << "\n";
                }
            }
            GF.LimparBuffer();
            GF.EnterContinue();
        }

        void relatorioUsuario(vector<usuario*> &pessoas){
            int totalCadastrados = 0;

            totalCadastrados = pessoas.size();

            if (pessoas.empty()){
                cout << "Não há usuários cadastrados...";
                GF.EnterContinue();
            }

            cout << "Total de usuários cadastrados: " << totalCadastrados << "\n";
            GF.LimparBuffer();
            GF.EnterContinue();
        }

        void exibirUmUsuario(vector <usuario*> &pessoas){
            int id;
            cout << "Digite o número de ID do usuário que deseja ver: "<< endl;
            GF.ChecarTipoErrado(id, 0, pessoas.size() - 1);

            bool idEncontrado = false;
            for(int i = 0; i < pessoas.size(); i++){
                if (pessoas[i]->numID == id){
                    pessoas[i]->relatorioUser();
                    cout << endl;

                    GF.EnterContinue();
                    idEncontrado = true;
                    break;
                }
            }

            if (!idEncontrado){
                cout << "Não foi encontrado o usuário id: " << id << "."<< endl;
                GF.EnterContinue();
            }

        }
};

#endif