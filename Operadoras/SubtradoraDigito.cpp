#include "SubtradoraDigito.h"
#include "../Formatadora/Formatadora.h"

char SubtradoraDigito::Subtrair(char digito1, char digito2, unsigned int base)
{
    int valor1, valor2;
    valor1 = Formatadora::ConverterDigitoCharParaInt(digito1);
    valor2 = Formatadora::ConverterDigitoCharParaInt(digito2);
    if(this->emprestou)
    {
        valor1--;
        this->emprestou = false;
    };
    if(valor2 > valor1)
    {
        valor1 += base;
        this->emprestou = true;
    }
    unsigned int resultado = valor1 - valor2;
    return Formatadora::ConverterDigitoIntParaChar(resultado);
};
