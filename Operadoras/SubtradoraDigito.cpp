#include "SubtradoraDigito.h"

Digito SubtradoraDigito::SubtrairDoisDigitos(Digito primeiro, Digito segundo, unsigned int base, bool emprestou)
{
    int valorPrimeiro = primeiro.GetValor();
    if(emprestou)
    {
        valorPrimeiro += base - 1;
    };
    int resultado = valorPrimeiro - segundo.GetValor();
    Digito ret;
    ret.SetValor(resultado);
    return ret;
};
bool EhMenor(Digito primeiro, Digito segundo)
{
    if(primeiro.GetValor() < segundo.GetValor())
    {
        return true;
    };
    return false;
};