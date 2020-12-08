#include "SomadoraDigito.h"

Digito SomadoraDigito::SomarDoisDigitos(Digito primeiro, Digito segundo, unsigned int base)
{
    unsigned int resultado = primeiro.GetValor() + segundo.GetValor() + this->subiu;
    unsigned int resto = resultado%base;
    this->subiu = resultado/base;
    Digito ret;
    ret.SetValor(resto);
    return ret;
};