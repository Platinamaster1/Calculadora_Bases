#include "SubtradoraDigito.h"

char SubtradoraDigito::Subtrair(char digito1, char digito2, unsigned int base, bool emprestou, bool foiEmprestado)
{
    int valor1, valor2;
    if(digito1 > 47 && digito1 < 58)
        valor1 = digito1 - 48;
    else if(digito1 > 64 && digito1 < 91)
        valor1 = digito1 - 55;
        else if(digito1 > 96 && digito1 < 123)
            valor1 = digito1 - 87;
    if(digito2 > 47 && digito2 < 58)
        valor2 = digito2 - 48;
    else if(digito2 > 64 && digito2 < 91)
        valor2 = digito2 - 55;
        else if(digito2 > 96 && digito2 < 123)
            valor2 = digito2 - 87;
    if(emprestou)
    {
        valor1 += base - 1;
    };
    if(foiEmprestado)
    {
        valor1--;
    }
    unsigned int resultado = valor1 - valor2;
    char ret;
    if(resultado < 10)
        ret = resultado + 48;
    else if(resultado > 10 && digito1 < 36)
        ret = resultado + 55;
    return ret;
};