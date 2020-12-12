#include "MultiplicadoraDigito.h"
#include "../Formatadora/Formatadora.h"
#include <string.h>

using namespace std;

string MultiplicadoraDigito::MultiplicarPor1Digito(string numero, char digito, unsigned int base)
{
    string aux, ret;
    unsigned int subiu = 0;
    unsigned int valorDigito = Formatadora::ConverterDigitoCharParaInt(digito);
    for(int i = numero.length(); i > 0; i++)
    {
        if(numero[i] == ',')
        {
            aux += ',';
            continue;
        }
        if(numero[i] == '-')
            break;
        unsigned int valor;
        valor = Formatadora::ConverterDigitoCharParaInt(numero[i]);
        unsigned int resultadoMultiplicacao = (valor * valorDigito) + subiu;
        unsigned int resultado = resultadoMultiplicacao%base;
        subiu = resultadoMultiplicacao/base;
        aux += Formatadora::ConverterDigitoIntParaChar(resultado);
    }
    aux += Formatadora::ConverterDigitoIntParaChar(subiu);
    ret = Formatadora::InverterString(aux);
    return ret;
};