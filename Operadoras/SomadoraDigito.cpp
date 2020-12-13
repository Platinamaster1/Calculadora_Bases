#include "SomadoraDigito.h"
#include "../Formatadora/Formatadora.h"

char SomadoraDigito::SomarDoisDigitos(char v1, char v2, unsigned int base)
{
    int primeiro = 0, segundo = 0;
    primeiro = Formatadora::ConverterDigitoCharParaInt(v1);
    segundo = Formatadora::ConverterDigitoCharParaInt(v2);
    cout << "Primeio: " << primeiro << " Segundo: " << segundo << endl;

    unsigned int resultado = primeiro + segundo + this->subiu;
    cout << "res: " << resultado << endl;
    unsigned int resto = resultado%base;
    cout << "resto: " << resto << endl;
    this->subiu = resultado/base;

    char ret = Formatadora::ConverterDigitoIntParaChar(resto);
    return ret;
};
