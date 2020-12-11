#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "Calculadora.h"
#include "../Verificadora/Verificadora.h"

using namespace std;

string Calculadora::SomarCom(string numero, string numeroASomar, unsigned int base)
{
    string maior, menor, aux, ret;
    if(Verificadora::ehMaior(numero, numeroASomar))
    {
        maior = numero;
        menor = numeroASomar;
    }
    else
    {
        maior = numeroASomar;
        menor = numero;
    }
    SomadoraDigito operadora;
    for(int i = maior.length(); i > 0; i++)
    {
        if(maior[i] == ',')
        {
            aux += ',';
            continue;
        }
        if(maior[i] == '-')
            break;
        aux += operadora.SomarDoisDigitos(maior[i], menor[i], base);
    }
    for(int i = aux.length(); i > 0; i--)
        ret.append(aux[i] + "");
    return ret;
};

string Calculadora::SubtrairCom(string numero1, string numero2, unsigned int base)
{
    string maior, menor, aux, ret;
    if(Verificadora::ehMaior(numero1, numero2))
    {
        maior = numero1;
        menor = numero2;
    }
    else
    {
        maior = numero2;
        menor = numero1;
    }
    SubtradoraDigito operadora;
    for(int i = maior.length(); i > 0; i++)
    {
        if(maior[i] == ',')
        {
            aux += ',';
            continue;
        }
        if(maior[i] == '-')
            break;
        aux += operadora.Subtrair(maior[i], menor[i], base);
    }
    for(int i = aux.length(); i > 0; i--)
        ret.append(aux[i] + "");
    return ret;
};

string Calculadora::MultiplicarCom(string numero, string numeroAMultiplicar, unsigned int base)
{

};

string Calculadora::DividirCom(string numero, string divisor, unsigned int base)
{

};
