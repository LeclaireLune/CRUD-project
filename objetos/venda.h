#ifndef VENDA_H
#define VENDA_H

#include "date.h"
#include "jogo.h"
#include "cliente.h"
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class venda{
    public:
        int ID;
        int IDComprador;
        vector<jogo> itens;
        float valorTotal;
        date dataCompra;

        venda(){
            //construtor obrigatorio
        }

        venda(int _ID, int _IDComprador, float _valorTotal, date _dataCompra, vector<jogo> _itens){
            ID = _ID;
            IDComprador = _IDComprador;
            valorTotal = _valorTotal;
            dataCompra = _dataCompra;
            itens = _itens;
        }

        float calValorTotal (vector<jogo> &jogosComprados){
            float valorTotal = 0.0;

            for (jogo n : jogosComprados){
                valorTotal += n.valor;
            }
            
            return valorTotal;
        }

        void criarListaJogos(vector<jogo> &jogosComprados, vector<jogo> &jogos){
            string tempJogoComprado;
            char tempRsp;
            int id_jogo;
            jogo tempJogo;

            while(1){
                cout << "Digite o nome do produto a comprar: ";
                cin.ignore();
                GF.LimparBuffer();
                getline(cin, tempJogoComprado);
                id_jogo = tempJogo.ProcurarIdJogo(jogos, tempJogoComprado);

                while(id_jogo == -1){
                    cout << "Jogo não encontrado, tentar novamente? (s/n): ";
                    GF.ChecarTipoErrado(tempRsp);
                    if(tempRsp == 's'){
                        cout << "Qual o nome do produto a comprar: ";
                        GF.LimparBuffer();
                        getline(cin, tempJogoComprado);
                        id_jogo = tempJogo.ProcurarIdJogo(jogos, tempJogoComprado);
                    }
                    else{
                        break;
                    }
                }
                
                if(id_jogo != -1){
                    jogosComprados.push_back(jogos[id_jogo]);
                    jogos[id_jogo].disponiveis -= 1;
                }
                
                while(1){

                    cout << "Deseja adicionar mais um item, remover ou continuar? (a/r/c): ";
                    GF.ChecarTipoErrado(tempRsp);

                    if(tempRsp == 'a'){
                        break;
                    }
                    else if(tempRsp == 'r'){
                        int id_remover, i = 0;
                        for(jogo n : jogosComprados){
                            cout << i << " | ";
                            n.relatorio();
                            i++;
                        }
    
                        cout << "digite o id de qual deseja remover: ";
                        GF.ChecarTipoErrado(id_remover, 0, jogosComprados.size());
                        jogosComprados.erase(jogosComprados.begin() + id_remover);
                    }
                    else{
                        break;
                    }
                }
                if(tempRsp == 'c'){                
                    break;
                }
            }
        }
        
        void relatorioSimples(){
            cout << ID << "\t" << IDComprador << "\t" << valorTotal << "\t" << dataCompra.Exibir() << "\n";
        }

        void relatorioCompleto(){
            int quantidade = 0;
            cout << ID << "\t" << IDComprador << "\t" << valorTotal << "\t" << dataCompra.Exibir() << "Itens: " << itens.size() << "\n";
    
            for(jogo n : itens){
                cout << quantidade + 1 << " | ";
                cout << n.nome << "\t" << n.valor << "\n";
            } 
        }

        venda adicionarVenda(vector<jogo> &jogos, vector<usuario> &clientes, vector<venda> &vendas, int &proximoId){
            char tempRsp;
            string nomeComprador, tempJogoComprado;
            vector<jogo> jogosComprados;
            jogo tempJogo;
            usuario *tempUsuario;
            int id_jogo, id_venda, id_comprador;

            id_venda = proximoId;

            if(jogos.size() == 0){
                cout << "Não há produtos cadastrados no estoque\n";
                cout << "Aperte enter para continuar";
                cin.get();
                venda vendaCancelada;
                vendaCancelada.ID = -1;
                return vendaCancelada;
            }

            cout << "Digite o nome do comprador: \n";
            GF.LimparBuffer();
            getline(cin, nomeComprador);

            //Logica de procurar o comprador
            usuario tempUsuario2;
            id_comprador = tempUsuario2.procurarCliente(clientes, nomeComprador);
            if(id_comprador == -1){
                //tempUsuario.adicionarUsuario();
                tempUsuario = new usuario("Claudio", "000.000.000-00", 0);
                clientes.push_back(*tempUsuario);
                id_comprador = 0;
            }

            //adicionar jogos ao vetor de jogos comprados
            criarListaJogos(jogosComprados, jogos);

            valorTotal = calValorTotal(jogosComprados);

            //Data da compra
            time_t now = time(0);
            tm* local_time = localtime(&now);
            date tempData(local_time->tm_mday, (local_time->tm_mon + 1), local_time->tm_year + 1900);
            
            venda tempVenda(id_venda, id_comprador, valorTotal, tempData, jogosComprados);

            cout << "Id\tId_cliente\tValor total\tData da venda\n";
            tempVenda.relatorioCompleto();

            cout << "As informações estão corretas? (s/n): ";
            GF.ChecarTipoErrado(tempRsp);
            if(tempRsp == 's'){
                proximoId += 1;
                clientes[id_comprador].ultimaCompra = tempData;
                return tempVenda;
            }
            else{

            }
        }

        void alterarUmaVenda(vector<venda> &vendas){
            int idEncontrado = -1, id;
            char tentarDenovo;

            if(vendas.size() != 0){
                cout << "Qual o id da venda a ser alterada? ";
                cin >> id;
                cin.ignore();

                for(venda n : vendas){
                    if(n.ID == id){
                        idEncontrado = id;
                    }
                }
                
                while(idEncontrado == -1){
                    cout << "Não foi encontrado, tentar novamente(s/n)? ";
                    cin >> tentarDenovo;
                    if(tentarDenovo == 's'){
                        cout << "Qual o id da venda a ser alterada? ";
                        GF.LimparBuffer();
                        cin >> id;
                        cin.ignore();
        
                        for(venda n : vendas){
                            if(n.ID == id){
                                idEncontrado = id;
                            }
                        }
                    }
                    else{
                        return;
                    }
                }

                
            }

            else{
                cout << "Não há vendas cadastradas\n";
                cout << "Aperte enter para continuar\n";
                GF.LimparBuffer();
                cin.get();
            }
                
        }

        void exibirTodasVendas(vector<venda> &vendas){
            if(vendas.size() == 0){
                cout << "Não há vendas cadastrados\n";
            }
            else{
                for (venda n : vendas){
                    n.relatorioSimples();
                }
            }

            cout << "Aperte enter para continuar";
            GF.LimparBuffer();
            cin.get();
        }

        void exibirUmaVenda(vector<venda> &vendas){
            int idEncontrado = -1, id, quantidade = 0;
            char tentarDenovo;

            if(vendas.size() != 0){
                cout << "Qual o id da venda a ser exibida? ";
                cin >> id;
                cin.ignore();

                for(venda n : vendas){
                    if(n.ID == id){
                        idEncontrado = id;
                    }
                }
                
                while(idEncontrado == -1){
                    cout << "Não foi encontrado, tentar novamente(s/n)? ";
                    cin >> tentarDenovo;
                    if(tentarDenovo == 's'){
                        cout << "Qual o id da venda a ser exibida? ";
                        GF.LimparBuffer();
                        cin >> id;
                        cin.ignore();
        
                        for(venda n : vendas){
                            if(n.ID == id){
                                idEncontrado = id;
                            }
                        }
                    }
                    else{
                        return;
                    }
                }

                vendas[idEncontrado].relatorioCompleto();
                cout << "Aperte enter para continuar\n";
                GF.LimparBuffer();
                cin.get();
            }
            else{
                cout << "Não há vendas cadastradas\n";
                cout << "Aperte enter para continuar\n";
                GF.LimparBuffer();
                cin.get();
            }
        }

        void relatorioVendas(vector<venda> &vendas){
            int quantidade = 0, QuantidadeProdutos = 0;
            float valorTotal = 0;

            for(venda n : vendas){
                quantidade += 1;
                QuantidadeProdutos += n.itens.size();
                valorTotal += n.valorTotal;
            }
        }

};

#endif