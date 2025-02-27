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