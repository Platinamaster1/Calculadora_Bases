#include <string>
#include "Formatadora.h"

using namespace std;

int Formatadora::DiferencaCasasDpsVirgula(string valor1, string valor2)
{
    int qntsCasasDpsVirgula1 = valor1.length() - valor1.find(',') + 1;
    int qntsCasasDpsVirgula2 = valor2.length() - valor2.find(',') + 1;

    if(qntsCasasDpsVirgula1 > qntsCasasDpsVirgula2)
        return qntsCasasDpsVirgula1 - qntsCasasDpsVirgula2;

    return qntsCasasDpsVirgula2 - qntsCasasDpsVirgula1;
};

int Formatadora::ConverterDigitoCharParaInt(char digito)
{
    int valor = 0;
    if (isdigit(digito))
    {
        valor = (int) digito - 48;
    } 
    else
    {
        valor = (int) toupper(digito) - 55;
    }
    return valor;
}

char Formatadora::ConverterDigitoIntParaChar(int digito)
{
    if(digito > 9)
        return (char)(digito + 55);
    return (char)(toupper(digito) + 48);
}

string Formatadora::IgualarZerosDpsVirgula(string valor, int diferencaCasasDpsVirgula)
{
    for(int i = 0; i < diferencaCasasDpsVirgula; i++)
        valor.append("0");

    return valor;
};

string Formatadora::FormatarResultado(string resultado)
{
    // Parte antes da vírgula...
    for(int i = 0; i < resultado.length(); i++)
    {
        if(resultado.at(i) != '0')
        {
            resultado.erase(0, i);
            break; 
        }
    }
    // Parte depois da vírgula...
    for(int i = resultado.length()-1; i > 0; i--)
    {
        if(resultado.at(i) != '0')
        {
            resultado.erase(resultado.begin()+i+1, resultado.end());
            break;
        }
    }
    return resultado;
}

string Formatadora::InverterString(string invertida)
{
    string ret;
    for(int i = invertida.length(); i > 0; i--)
        ret.append(invertida[i] + "");
    return ret;
}

