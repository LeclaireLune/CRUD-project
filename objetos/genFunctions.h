#ifndef GENFUNCTIONS_H
#define GENFUNCTIONS_H

#include <iostream>
#include <limits>
#include <string>

using namespace std;

class GeneralFunctions{
    public:
        void ChecarTipoErrado(auto &var){
            while(!(cin >> var)){
                cout << "Opção inválida, tente novamente\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return;
        }

        void ChecarTipoErrado(auto &var, int min){
            while(!(cin >> var) || var < min){
                cout << "Opção inválida, tente novamente\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return;
        }

        void ChecarTipoErrado(auto &var, int min, int max){
            while(!(cin >> var) || var < min | var > max){
                cout << "Opção inválida, tente novamente\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return;
        }

        void LimparBuffer(){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
};

#endif