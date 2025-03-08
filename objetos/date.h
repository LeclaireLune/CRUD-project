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

        int diaMax(int mes){
            switch(mes){
                case 4:
                case 6:
                case 9:
                case 11:
                    return 30;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    return 31;
                case 2:
                    return 28;
                default:
                    return 31;
            }
        }

        std::string Exibir(){
            string _dia = to_string(dia);
            string _mes = to_string(mes);
            string _ano = to_string(ano);
            std::string data;

            if(dia < 10){
                _dia = "0" + _dia;
            }

            if(mes < 10){
                _mes = "0" + _mes;
            }

            std::cout << _dia << "/" << _mes << "/" << _ano << "\n";

            return data;
        }
};

#endif