#include <string>
#include <iostream>
#include "Formatadora.h"
#include "../Verificadora/Verificadora.h"

using namespace std;

int Formatadora::DiferencaCasasDpsVirgula(string valor1, string valor2)
{
    int qntsCasasDpsVirgula1 = valor1.length() - valor1.find(',') + 1;
    int qntsCasasDpsVirgula2 = valor2.length() - valor2.find(',') + 1;

    if(qntsCasasDpsVirgula1 > qntsCasasDpsVirgula2)
        return qntsCasasDpsVirgula1 - qntsCasasDpsVirgula2;

    return qntsCasasDpsVirgula2 - qntsCasasDpsVirgula1;
};

int Formatadora::DiferencaCasasAntesVirgula(string valor1, string valor2)
{
    int qntsCasasAntesVirgula1 = 0;
    int qntsCasasAntesVirgula2 = 0;
    int indiceVirgula1 = valor1.find(',');
    int indiceVirgula2 = valor2.find(',');

    if(indiceVirgula1 == -1)
        qntsCasasAntesVirgula1 = valor1.length();
    else
        qntsCasasAntesVirgula1 = indiceVirgula1;

    if(Verificadora::numNegativo(valor1))
        qntsCasasAntesVirgula1--;

    if(indiceVirgula2 == -1)
        qntsCasasAntesVirgula2 = valor2.length();
    else
        qntsCasasAntesVirgula2 = indiceVirgula2;

    if(Verificadora::numNegativo(valor2))
        qntsCasasAntesVirgula2--;

    if(qntsCasasAntesVirgula1 > qntsCasasAntesVirgula2)
        return qntsCasasAntesVirgula1 - qntsCasasAntesVirgula2;

    return qntsCasasAntesVirgula2 - qntsCasasAntesVirgula1;
}

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

string Formatadora::AdicionarVirgulaCasoPrecise(string valor)
{
    int indiceVirgula = valor.find(',');
    if(indiceVirgula == -1)
        valor.append(",");
    return valor;
}

string Formatadora::IgualarZerosAntesVirgula(string valor, int diferencaCasasAntesVirgula)
{
    cout << "Valor: " << valor << " DiferencaCAsas: " << diferencaCasasAntesVirgula << endl;
    string valorComZeros;
    if(Verificadora::numNegativo(valor))
        valorComZeros.append("-");
    for(int i = 0; i < diferencaCasasAntesVirgula; i++)
        valorComZeros.append("0");

    for(int i = 0; i < valor.length(); i++)
        if(valor[i] != '-')
            valorComZeros += valor[i];
    return valorComZeros;
}

string Formatadora::IgualarZerosDpsVirgula(string valor, int diferencaCasasDpsVirgula)
{
    for(int i = 0; i < diferencaCasasDpsVirgula; i++)
        valor.append("0");
    return valor;
};

string Formatadora::FormatarNumero(string numero)
{
    // Parte antes da vírgula...
    if(numero.length() > 1)
    {
        for(int i = 0; i < numero.length(); i++)
        {
            if(numero.at(i) != '0' && numero.at(i) != '-')
            {
                if(numero.at(0) == '-')
                    numero.erase(numero.begin()+1, numero.begin()+i);
                else
                    numero.erase(numero.begin(), numero.begin()+i);
                break;
            }
        }
        if(Verificadora::temVirgula(numero))
        {
            // Parte depois da vírgula...
            for(int i = numero.length()-1; i >= 0; i--)
            {
                if(numero.at(i) != '0')
                {
                    if(numero.at(i) == ',')
                        numero.erase(numero.begin()+i, numero.end());
                    numero.erase(numero.begin()+i+1, numero.end());
                    break;
                }
            }
        }
    }
    // Se houver um -0, muda-se para 0...
    //if(numero.length() == 2 && numero.at(1) == '0')
    //    numero.erase(0, 1);
    return numero;
}

string Formatadora::InverterString(string invertida)
{
    string ret;
    for(int i = invertida.length()-1; i >= 0; i--)
        ret += invertida[i];
    return ret;
}

string Formatadora::RetirarSinal(string n)
{
    n.erase(0, 1);
    return n;
}

