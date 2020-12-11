#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "Calculadora.h"
#include "../Verificadora/Verificadora.h"

using namespace std;

string Calculadora::SomarCom(string numero, string numeroASomar, unsigned int base)
{
    
};

string Calculadora::SubtrairCom(string numero1, string numero2, unsigned int base)
{
    string maior, menor;
    string ret;
    /*if(Verificadora::ehMaior(numero1, numero2))
    {
        maior = numero1;
        menor = numero2;
    }
    else
    {
        maior = numero2;
        menor = numero1;
    }*/
    int ondeMaior = maior.length();
    int ondeMenor = menor.length();
    for(int i = ondeMenor; i >= 0; i--)
    {
        if(maior[ondeMaior] == ',')
        {
            ret.insert(ret.begin(), ',');
            continue;
        }
        if(menor[ondeMenor] == '-')
            break;

    }

};

string Calculadora::MultiplicarCom(string numero, string numeroAMultiplicar, unsigned int base)
{

};

string Calculadora::DividirCom(string numero, string divisor, unsigned int base)
{

};
