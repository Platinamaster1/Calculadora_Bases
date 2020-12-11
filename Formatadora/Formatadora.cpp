#include <string>
#include "Formatadora.h"

using namespace std;

int Formatadora::PegarCasasDpsVirgula(string valor1, string valor2)
{
    int qntsCasasDpsVirgula1 = valor1.length() - valor1.find(',');
    int qntsCasasDpsVirgula2 = valor2.length() - valor2.find(',');
    if(qntsCasasDpsVirgula1 > qntsCasasDpsVirgula2)
        return qntsCasasDpsVirgula1;
    return qntsCasasDpsVirgula2;
};
string Formatadora::IgualarZeros(string valor, int casasDpsVirgula)
{
    for(int i = 0; i < casasDpsVirgula; i++)
        valor += '0';
    return valor;
};
