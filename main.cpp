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
    setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
    Calculadora calc;
    string stringNum1, stringNum2;
    unsigned int baseNumerica;
    /*printf("Digite o primeiro número:  ");
    fflush(stdout);
    scanf("%s", charNum1);
    fflush(stdin);
    printf("Digite o segundo número:   ");
    fflush(stdout);
    scanf("%s", charNum2);
    fflush(stdin);
    printf("Digite a base dos números: ");
    fflush(stdout);
    scanf("%u", baseNumerica);
    fflush(stdin);*/
    cout << "Digite o primeiro número: ";
    cin >> stringNum1;
    cout << "Digite o segundo número: ";
    cin >> stringNum2;
    cout << "Digite a base dos números: ";
    cin >> baseNumerica;

    vector<Digito> vetor;

    unsigned int tamanho = sizeof(charNum1) / sizeof(charNum1[0]);
    Digito* num1 = (Digito*) malloc(tamanho);
    Digito* num2 = (Digito*) malloc(tamanho);
    int i;
    for(i = 0; i < tamanho; i++)
    {

        Digito digito1, digito2;
        digito1.SetDigito(charNum1[i]);
        digito2.SetDigito(charNum2[i]);
        num1[i] = digito1;
        num2[i] = digito2;
        cout << digito1 << endl;
        cout << digito2 << endl;

    };

    Digito* resultadoSoma = calc.SomarCom(num1, num2, baseNumerica);
    // cout << resultadoSoma;
};


