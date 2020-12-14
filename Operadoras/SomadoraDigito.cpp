#include "SomadoraDigito.h"
#include "../Formatadora/Formatadora.h"

char SomadoraDigito::SomarDoisDigitos(char v1, char v2, unsigned int base)
{
    int primeiro = 0, segundo = 0;
    primeiro = Formatadora::ConverterDigitoCharParaInt(v1);
    segundo = Formatadora::ConverterDigitoCharParaInt(v2);

    unsigned int resultado = primeiro + segundo + this->subiu;
    unsigned int resto = resultado%base;
    this->subiu = resultado/base;

    char ret = Formatadora::ConverterDigitoIntParaChar(resto);
    return ret;
};
