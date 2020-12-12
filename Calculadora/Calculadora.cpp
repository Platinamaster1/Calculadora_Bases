#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "Calculadora.h"
#include "../Verificadora/Verificadora.h"
#include "../Formatadora/Formatadora.h"

using namespace std;

string Calculadora::SomarCom(string numero, string numeroASomar, unsigned int base)
{
    string maior, menor, aux, ret;
    if(Verificadora::ehMaior(numero, numeroASomar))
    {
        maior = numero;
        menor = numeroASomar;
    }
    else
    {
        maior = numeroASomar;
        menor = numero;
    }
    SomadoraDigito operadora;
    for(int i = maior.length(); i > 0; i++)
    {
        if(maior[i] == ',')
        {
            aux += ',';
            continue;
        }
        if(maior[i] == '-')
            break;
        aux += operadora.SomarDoisDigitos(maior[i], menor[i], base);
    }
    char oQueSubiu = operadora.SomarDoisDigitos('0', '0', base);
    if(oQueSubiu != '0')
        aux += oQueSubiu;
    ret = Formatadora::InverterString(aux);
    return ret;
};

string Calculadora::SubtrairCom(string numero1, string numero2, unsigned int base)
{
    string maior, menor, aux, ret;
    if(Verificadora::ehMaior(numero1, numero2))
    {
        maior = numero1;
        menor = numero2;
    }
    else
    {
        maior = numero2;
        menor = numero1;
    }
    SubtradoraDigito operadora;
    for(int i = maior.length(); i > 0; i++)
    {
        if(maior[i] == ',')
        {
            aux += ',';
            continue;
        }
        if(maior[i] == '-')
            break;
        aux += operadora.Subtrair(maior[i], menor[i], base);
    }
    ret = Formatadora::InverterString(aux);
    return ret;
};

string Calculadora::MultiplicarCom(string numeroAMultiplicar, string numeroQueVaiMultiplicar, unsigned int base)
{
    string ret = "0";
    for(int i = numeroQueVaiMultiplicar.length(); i > 0; i++)
    {
        if(numeroQueVaiMultiplicar[i] == ',')
        {
            ret += ',';
            continue;
        }
        if(numeroQueVaiMultiplicar[i] == '-')
            break;
        string resultadoDoDigito = MultiplicadoraDigito::MultiplicarPor1Digito(numeroAMultiplicar, numeroQueVaiMultiplicar[i], base);
        ret = SomarCom(ret, resultadoDoDigito, base);
        numeroAMultiplicar.append("0");
    }
    return ret;
};

string Calculadora::DividirCom(string numero, string divisor, unsigned int base)
{

};
