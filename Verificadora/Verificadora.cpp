#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Verificadora.h"


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
