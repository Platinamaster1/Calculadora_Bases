#include <string>
#include "Contadora.h"
#include "../Verificadora/Verificadora.h"

using namespace std;

int Contadora::DiferencaCasasDpsVirgula(string valor1, string valor2)
{
    // Pega a quantidade de casas dps da v�rgula de cada valor
    int qntsCasasDpsVirgula1 = valor1.length() - valor1.find(',') + 1;
    int qntsCasasDpsVirgula2 = valor2.length() - valor2.find(',') + 1;

    // Verifica se o valor1 tem mais e retorna a diferen�a entre os dois
    if(qntsCasasDpsVirgula1 > qntsCasasDpsVirgula2)
        return qntsCasasDpsVirgula1 - qntsCasasDpsVirgula2;

    // Verifica se o valor2 tem mais e retorna a diferen�a entre os dois
    return qntsCasasDpsVirgula2 - qntsCasasDpsVirgula1;
};

int Contadora::DiferencaCasasAntesVirgula(string valor1, string valor2)
{
    // Inicializa as vari�veis, deste modo a deix�-las prontas pra caso os valores tenham virgula ou n�o
    int qntsCasasAntesVirgula1 = 0;
    int qntsCasasAntesVirgula2 = 0;
    int indiceVirgula1 = valor1.find(',');
    int indiceVirgula2 = valor2.find(',');

    // Se o valor1 n�o tem v�rgula, ele recebe o seu length() como a qtd de casas
    if(indiceVirgula1 == -1)
        qntsCasasAntesVirgula1 = valor1.length();
    // Se tiver v�rgula, ele recebe o �ndice da v�rgula mesmo
    else
        qntsCasasAntesVirgula1 = indiceVirgula1;

    // Se o n�mero � negativo, a casa do '-' � ignorada
    if(Verificadora::numNegativo(valor1))
        qntsCasasAntesVirgula1--;

    // Mesma coisa do valor1 pro valor2
    if(indiceVirgula2 == -1)
        qntsCasasAntesVirgula2 = valor2.length();
    else
        qntsCasasAntesVirgula2 = indiceVirgula2;

    if(Verificadora::numNegativo(valor2))
        qntsCasasAntesVirgula2--;

    // Mesma l�gica do DiferencaCasasDpsVirgula
    if(qntsCasasAntesVirgula1 > qntsCasasAntesVirgula2)
        return qntsCasasAntesVirgula1 - qntsCasasAntesVirgula2;

    return qntsCasasAntesVirgula2 - qntsCasasAntesVirgula1;
}

int Contadora::SomaCasasDpsVirgula(string valor1, string valor2)
{
    // Pega a qtd de v�rgulas atrav�s do indice dela de cada valor
    int qntsCasasDpsVirgula1 = valor1.length() - (valor1.find(',') + 1);
    int qntsCasasDpsVirgula2 = valor2.length() - (valor2.find(',') + 1);

    // .. E retorna a soma delas
    return (qntsCasasDpsVirgula1 + qntsCasasDpsVirgula2);
}
