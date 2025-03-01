#ifndef VENDA_H
#define VENDA_H

#include "date.h"
#include "jogo.h"
#include <vector>
#include <string>

using namespace std;

class venda{
    public:
        int ID;
        int IDComprador;
        float valorTotal;
        date dataCompra;
        vector<jogo> jogosComprados;

        venda(){

        }

        venda(int _ID, int _IDComprador, float _valorTotal, date _dataCompra, vector<jogo> _jogosComprados){
            ID = _ID;
            IDComprador = _IDComprador;
            valorTotal = _valorTotal;
            dataCompra = _dataCompra;
            jogosComprados = _jogosComprados;
        }

        float calValorTotal (vector<jogo> &precojogo, vector<int> jogosComprados){
            valorTotal = 0.0;

            for (int n : jogosComprados){
                valorTotal += precojogo[jogosComprados[n]].valor;
            }
            
            return valorTotal;
        }

        void adicionarVenda(){
            cout << "Digite o ID da venda: \n";
            cin >> ID;
            cout << "Digite o ID do comprador: \n";
            cin >> IDComprador;
            
            cout << "Digite o valor total da compra: \n";
            
            
            cout << "Digite a data da compra: \n";
            cin >> dataCompra.dia >> dataCompra.mes >> dataCompra.ano;
            

        }

        void relatorioSimples(){ 
            cout << ID << "\t" << IDComprador << "\t" << valorTotal << "\t" << dataCompra.Exibir() << "\t" << jogosComprados.size() << "\n";

        }

        void relatorioCompleto(){
            int quantidade = 0;
            cout << ID << "\t" << IDComprador << "\t" << valorTotal << "\t" << dataCompra.Exibir() << "\t" << jogosComprados.size() << "\n";
            for(jogo n : jogosComprados){
                cout << quantidade + 1 << "- " << "\t";

                n.relatorio();
            }
        }

};

#endif