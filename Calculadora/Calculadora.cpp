#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "Calculadora.h"

Digito* Calculadora::SomarCom(Digito* numero, Digito* numeroASomar, unsigned int base)
{
    unsigned int tamanho = sizeof(numeroASomar) / sizeof(numeroASomar[0]);
    SomadoraDigito sum;
    Digito* resultado = (Digito*) malloc(sizeof(numeroASomar) + 1);

    int i;
    for(i = tamanho; i >= 0; i--)
    {
        Digito resto = sum.SomarDoisDigitos(numero[i], numeroASomar[i], base);
        resultado[i] = resto;
    }
    
    return resultado;
};

Digito* Calculadora::SubtrairCom(Digito* numero, Digito* numeroASubtrair, unsigned int base)
{

};

Digito* Calculadora::MultiplicarCom(Digito* numero, Digito* numeroAMultiplicar, unsigned int base)
{

};

Digito* Calculadora::DividirCom(Digito* numero, Digito* divisor, unsigned int base)
{
    
};