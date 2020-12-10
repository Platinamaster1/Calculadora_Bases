#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <locale>

using namespace std;

#include "Calculadora/Calculadora.h"
#include "Digito/Digito.h"

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Habilita a acentuação para o português
    Calculadora calc;
    string stringNum1, stringNum2;
    unsigned int baseNumerica;

    cout << "Digite o primeiro número: ";
    cin >> stringNum1;
    cout << "Digite o segundo número: ";
    cin >> stringNum2;
    cout << "Digite a base dos números: ";
    cin >> baseNumerica;

    for(int i = 0; i < stringNum1.length(); i++)
    {

    };
};


