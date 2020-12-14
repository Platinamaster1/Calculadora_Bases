#include "MultiplicadoraDigito.h"
#include "../Formatadora/Formatadora.h"
#include <string.h>

using namespace std;

string MultiplicadoraDigito::MultiplicarPor1Digito(string numero, char digito, unsigned int base)
{
    string aux, ret;
    cout << "DIGITO: " << digito << endl;
    unsigned int subiu = 0;
    unsigned int valorDigito = Formatadora::ConverterDigitoCharParaInt(digito);
    cout << "VAlor digito: " << valorDigito << endl;
    for(int i = numero.length()-1; i >= 0; i--)
    {
        if(numero[i] == ',')
        {
            //aux += ',';
            continue;
        }
        if(numero[i] == '-')
            break;

        unsigned int valor;
        valor = Formatadora::ConverterDigitoCharParaInt(numero[i]);
        cout << "VAlor numero[i]: " << valor << endl;
        unsigned int resultadoMultiplicacao = (valor * valorDigito) + subiu;
        cout << "Resultado Multiplicacao: " << resultadoMultiplicacao << endl;
        unsigned int resultado = resultadoMultiplicacao%base;
        cout << "Resultado: " << resultado << endl;
        subiu = resultadoMultiplicacao/base;
        cout << "Subiu: " << subiu << endl;
        aux += Formatadora::ConverterDigitoIntParaChar(resultado);
        cout << "aux: " << aux << endl;
    }
    aux += Formatadora::ConverterDigitoIntParaChar(subiu);
    cout << "aux final: " << aux << endl;
    ret = Formatadora::InverterString(aux);
    cout << "aux invertida: " << ret << endl;
    return ret;
};
