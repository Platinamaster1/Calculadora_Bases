#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "Calculadora.h"

string Calculadora::SomarCom(string numero, string numeroASomar, unsigned int base)
{
    unsigned int tamanho = sizeof(numeroASomar) / sizeof(numeroASomar[0]);
    SomadoraDigito sum;
    //string resultado = (string) malloc(sizeof(numeroASomar) + 1);

    int i;
    for(i = tamanho; i >= 0; i--)
    {
        //Digito resto = sum.SomarDoisDigitos(numero[i], numeroASomar[i], base);
        //resultado[i] = resto;
    }

    return "DENIS";
};

string Calculadora::SubtrairCom(string numero, string numeroASubtrair, unsigned int base)
{

};

string Calculadora::MultiplicarCom(string numero, string numeroAMultiplicar, unsigned int base)
{

};

string Calculadora::DividirCom(string numero, string divisor, unsigned int base)
{

};
