#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class date{
    public:
        int dia;
        int mes;
        int ano;

        date(){

        }

        date(int d, int m, int a){
            dia = d;
            mes = m;
            ano = a;
        }

        std::string Exibir(){
            std::string data;

            std::cout << dia << "/" << mes << "/" << ano << "\n";

            return data;
        }
};

#endif