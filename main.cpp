#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "../Calculadora/Calculadora.h"
#include "../Digito/Digito.h"

using namespace std;

int main()
{
    Calculadora calc;
    char* charNum1, charNum2;
    unsigned int baseNumerica;
    printf("Digite o primeiro número:  ");
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
    fflush(stdin);
    
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
    };

    Digito* resultadoSoma = calc.SomarCom(num1, num2, baseNumerica);
    cout << resultadoSoma;
};