#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Verificadora.h"
#include "../Formatadora/Formatadora.h"


using namespace std;

bool Verificadora::baseValida(unsigned int base)
{
    if(base < 2)
        return false;
    if(base > 36)
        return false;
    return true;
};

bool Verificadora::numeroValido(string numero, unsigned int base)
{
    unsigned int virgulas = 0;
    unsigned int menos = 0;
    for(int i = 0; i < numero.length(); i++)
    {
        if(numero[i] == '-')
        {
            menos++;
            continue;
        }
        if(numero[i] == ',' || numero[i] == '.')
        {
            virgulas++;
            continue;
        }
        if(numero[i] > 47 && numero[i] < 58)
        {
            if((numero[i] - 48) > (base - 1))
            {
                return false;
            }
        }
        else
        {
            if(numero[i] > 64 && numero[i] < 91)
            {
                if((numero[i] - 55) > (base - 1))
                {
                    return false;
                }
            }
            else
            {
                if(numero[i] > 96 && numero[i] < 123)
                {
                    if((numero[i] - 87) > (base - 1))
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if(virgulas > 1 || menos > 1)
    {
        return false;
    }
    return true;
};

bool Verificadora::operacaoValida(char opcao)
{
    string operadores = "Xx*./÷:+-sS";
    int opcaoExiste = operadores.find_first_of(opcao);
    if(opcaoExiste == -1)
        return false;
    return true;
};

bool Verificadora::temMaisCasasDpsVirgula(string valor1, string valor2)
{
    int qntsCasasDpsVirgula1 = valor1.length() - valor1.find(',');
    int qntsCasasDpsVirgula2 = valor2.length() - valor2.find(',');
    if(qntsCasasDpsVirgula1 > qntsCasasDpsVirgula2)
        return true;
    return false;
};

bool Verificadora::digitoEhMaior(char digito1, char digito2)
{
    int valor1, valor2;
    valor1 = Formatadora::ConverterDigitoCharParaInt(digito1);
    valor2 = Formatadora::ConverterDigitoCharParaInt(digito2);
    if(valor1 > valor2)
        return true;
    return false;
};

bool Verificadora::ehMaior(string numero1, string numero2)
{
    int ondeNumero2 = 0;
    bool passouVirgula1 = false, passouVirgula2 = false, numero1EhMaior = false, umNumeroFoiMaior = false;
    for(int i = 0; i < numero1.length(); i++)
    {
        if(numero1[i] == '-')
            continue;
        if(numero2[ondeNumero2] == '-')
            ondeNumero2++;
        if(numero1[i] == ',')
        {
            passouVirgula1 = true;
            continue;
        }
        if(numero2[ondeNumero2] == ',')
        {
            passouVirgula2 = true;
            ondeNumero2++;
        }
        if(passouVirgula1 && !passouVirgula2)
            return false;
        if(!passouVirgula1 && passouVirgula2)
            return true;
        if(umNumeroFoiMaior)
        {
            ondeNumero2++;
            continue;
        }
        int valor1 = Formatadora::ConverterDigitoCharParaInt(numero1[i]);
        int valor2 = Formatadora::ConverterDigitoCharParaInt(numero2[ondeNumero2]);
        if(valor1 > valor2 || valor2 > valor1)
        {
            umNumeroFoiMaior = true;
            if(valor1 > valor2)
                numero1EhMaior = true;
        }
    }
    return numero1EhMaior;
};
