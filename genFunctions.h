#ifndef GENFUNCTIONS_H
#define GENFUNCTIONS_H

#include <iostream>
#include <limits>

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

        void LimparBuffer(){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
};

#endif
