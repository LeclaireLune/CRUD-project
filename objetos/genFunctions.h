#ifndef GENFUNCTIONS_H
#define GENFUNCTIONS_H

#include <iostream>
#include <limits>
#include <string>

using namespace std;

class GeneralFunctions{
    public:
        //Checa se o input é do tipo errado e, caso seja aplicável, overload com valor minimo e maximo
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

        //Limpa o buffer do teclado
        void LimparBuffer(){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //Apresenta o "aperte enter para continuar" para parar a execução para exibir algo
        void EnterContinue(){
            cout << "Aperte enter para continuar" << endl;
            LimparBuffer();
            cin.get();
        }
};

#endif