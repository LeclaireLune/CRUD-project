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

        void relatorioSimples(){
            cout << ID << "\t" << IDComprador << "\t" << valorTotal << "\t" << dataCompra.Exibir() << "\n";
        }

        void relatorioCompleto(vector<usuario> &clientes){
            int quantidade = 0, id_cliente = -1;
            string cliente_identification;

            //Procura o cliente para identificar, caso não encontre deixa como não identificado
            for(int i = 0; i < clientes.size(); i++){
                if(IDComprador == clientes[i].numID){
                    cliente_identification = clientes[i].nome + "(" + clientes[i].CPF_CNPJ + ")";
                    id_cliente = i;
                }
            }

            if(id_cliente == -1){
                cliente_identification = "Cliente não identificado";
            }

            cout << ID << "\t" << cliente_identification << "\t" << valorTotal << "\t" << dataCompra.Exibir() << "Itens: " << itens.size() << "\n";
    
            for(jogo n : itens){
                cout << quantidade + 1 << " | ";
                cout << n.nome << "\t" << n.valor << "\n";
            } 
        }

        void alterarListaJogos(vector<jogo> &jogosAlterar, vector<jogo> &jogos){
            char tempRsp;
            string tempJogoComprado;
            int id_jogo;
            jogo tempJogo;

            while(1){
                int quantidade = 0;
                system("clear");

                for(jogo n : jogosAlterar){
                    cout << quantidade << " | ";
                    cout << n.nome << "\n";
                    quantidade++;
                }

                cout << "Deseja adicionar mais um item, remover ou continuar? (a/r/c): ";
                GF.ChecarTipoErrado(tempRsp);

                if(tempRsp == 'a'){
                    id_jogo = tempJogo.ProcurarIdJogo(jogos);

                    if(id_jogo == -1){
                        return;
                    }

                    if(id_jogo != -1){
                        cout << "Jogo adicionado: " << jogos[id_jogo].nome << "\n";
                        jogosAlterar.push_back(jogos[id_jogo]);
                        jogos[id_jogo].disponiveis -= 1;
                        GF.EnterContinue();
                    }

                    else{
                        cout << "Problema para adicionar o jogo\n";
                        GF.EnterContinue();
                    }
                }

                else if(tempRsp == 'r'){
                    int id_remover, i = 0;

                    tempJogo.cabecalhoRelatorio(MAXNOMEJOGO, MAXNOMEDEV);
                    for(jogo n : jogosAlterar){
                        cout << i << " | ";
                        n.relatorio(MAXNOMEJOGO, MAXNOMEDEV);
                        i++;
                    }

                    cout << "digite o id do item que deseja remover: ";
                    GF.ChecarTipoErrado(id_remover, 0, jogosAlterar.size() - 1);
                    for(jogo n : jogos){
                        if(jogosAlterar[id_remover].nome == n.nome){
                            n.disponiveis += 1;
                        }
                    }

                    jogosAlterar.erase(jogosAlterar.begin() + id_remover);
                }
                else{
                    break;
                }
            }
        }

        void criarListaJogos(vector<jogo> &jogosComprados, vector<jogo> &jogos){
            string tempJogoComprado;
            char tempRsp;
            int id_jogo;
            jogo tempJogo;

            id_jogo = tempJogo.ProcurarIdJogo(jogos);

            if(id_jogo == -1){
                return;
            }
            
            if(id_jogo != -1){
                cout << "Jogo adicionado: " << jogos[id_jogo].nome << "\n";
                jogosComprados.push_back(jogos[id_jogo]);
                jogos[id_jogo].disponiveis -= 1;
            }
            
            alterarListaJogos(jogosComprados, jogos);
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
                GF.EnterContinue();

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
                tempUsuario = new usuario(nomeComprador, "000.000.000-00", 0);
                clientes.push_back(*tempUsuario);
                id_comprador = 0;
            }

            //adicionar jogos ao vetor de jogos comprados
            criarListaJogos(jogosComprados, jogos);

            //Cancelar a compra caso não tenha feito uma lista
            if(jogosComprados.size() == 0){
                venda vendaCancelada;
                vendaCancelada.ID = -1;
                return vendaCancelada;
            }

            valorTotal = calValorTotal(jogosComprados);

            //Data da compra
            time_t now = time(0);
            tm* local_time = localtime(&now);
            date tempData(local_time->tm_mday, (local_time->tm_mon + 1), local_time->tm_year + 1900);
            
            venda tempVenda(id_venda, id_comprador, valorTotal, tempData, jogosComprados);

            cout << "Id\tCliente\tValor total\tData da venda\n";
            tempVenda.relatorioCompleto(clientes);

            cout << "As informações estão corretas? (s/n): ";
            GF.ChecarTipoErrado(tempRsp);
            if(tempRsp == 's'){
                proximoId += 1;
                clientes[id_comprador].ultimaCompra = tempData;
                return tempVenda;
            }
            else{
                cout << "Deseja alterar ou cancelar? (a/c)";
                GF.ChecarTipoErrado(tempRsp);
                if(tempRsp == 'a'){
                    alterarUmaVenda(tempVenda, jogos, clientes);
                    proximoId += 1;
                    return tempVenda;
                }
                else{
                    //Reestabelece o estoque
                    for(jogo i : jogosComprados){
                        for(jogo j : jogos){
                            if(j.nome == i.nome){
                                j.disponiveis += 1;
                            }
                        }
                    }
                    tempVenda.ID = -1;
                    return tempVenda;
                }
            }
        }

        void alterarUmaVenda(venda &venda, vector<jogo> &jogos, vector<usuario> &clientes){
            char alterarMais;
            int rsp;
            string cpf_cnpj;
            usuario tempUsuario;
            while(1){
                cout << "\nO que deseja alterar? (Outro para cancelar)\n1.Comprador\n2.Lista de Itens\n";
                GF.ChecarTipoErrado(rsp);

                switch (rsp){
                    case 1:
                        int id_cliente;
                        cout << "Escreva o cpf/cnpj do comprador (000.000.000-00 / 00.000.000/0000-00):";
                        GF.LimparBuffer();
                        getline(cin, cpf_cnpj);
                        id_cliente = tempUsuario.procurarCliente(clientes, cpf_cnpj);

                        if(id_cliente == -1){
                            //Criar Cliente
                        }

                        IDComprador = id_cliente;

                        break;
                    
                    case 2:
                        GF.LimparBuffer();
                        alterarListaJogos(venda.itens, jogos);
                        break;   
                }

                cout << "Deseja alterar mais alguma informação? (s/n)\n";
                GF.ChecarTipoErrado(alterarMais);
                
                if(alterarMais == 's'){
                    system("clear");
                    continue;
                }
                else{
                    venda.valorTotal = venda.calValorTotal(venda.itens);
                    break;
                }
            }
        }

        void alterarVendas(vector<venda> &vendas, vector<jogo> &jogos, vector<usuario> &clientes){
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

                alterarUmaVenda(vendas[idEncontrado], jogos, clientes);
            }

            else{
                cout << "Não há vendas cadastradas\n";
                GF.EnterContinue();
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

            GF.EnterContinue();
        }

        void exibirUmaVenda(vector<venda> &vendas, vector<usuario> &clientes){
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

                vendas[idEncontrado].relatorioCompleto(clientes);
                GF.EnterContinue();
            }
            else{
                cout << "Não há vendas cadastradas\n";
                GF.EnterContinue();
            }
        }

        void relatorioVendas(vector<venda> &vendas){
            int quantidade = 0, QuantidadeProdutos = 0;
            float valorTotal = 0.00;

            if(vendas.size() == 0){
                cout << "Não há vendas cadastradas\n";
                GF.EnterContinue();
                return;
            }

            for(venda n : vendas){
                quantidade += 1;
                QuantidadeProdutos += n.itens.size();
                valorTotal += n.valorTotal;
            }

            cout << "Quantidade de vendas: " << quantidade;
            cout << " | Quantidade de produtos vendidos: " << QuantidadeProdutos;
            cout << " | Receita Total: " << valorTotal << "\n";

            GF.EnterContinue();
        }

        void removerVenda(vector<venda> &vendas, vector<usuario> &clientes, vector<jogo> &jogos, int &cadastrados){
            while(1){
                string Nome;
                int rsp, id_escolhido, quantidade = 0;
                char tentarDenovo, removerMais, correto;

                if(vendas.size() != 0){
                    cout << "id\tid_comprador\tValor Total\tData compra";
                    for(venda n : vendas){
                        cout << quantidade << "\t";
                        n.relatorioSimples();
                        quantidade++;
                    }

                    cout << "Qual o id da venda a ser removida? ";
                    GF.ChecarTipoErrado(id_escolhido, 0, vendas.size() - 1);
    
                    vendas[id_escolhido].relatorioCompleto(clientes);
                }
                else{
                    cout << "Não há vendas cadastrados\n";
                    GF.EnterContinue();
                    return;
                }

                cout << "É a venda correta? (s/n) ";
                GF.ChecarTipoErrado(correto);

                if(correto == 's'){
                    for(jogo i : jogos){
                        for(jogo j : vendas[id_escolhido].itens){
                            if(j.nome == i.nome){
                                i.disponiveis += 1;
                            }
                        }
                    }
                    vendas.erase(vendas.begin() + id_escolhido);
                    cout << "Venda deletada com sucesso!\n";
                    cadastrados -= 1;
                }

                cout << "Deseja deletar outra? (s/n) ";
                cin >> removerMais;
                if(removerMais == 's'){
                    system("clear");
                    continue;
                }
                else{
                    break;
                }
            }
        }    

};

#endif