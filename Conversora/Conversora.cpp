#include <string>
#include "Conversora.h"
#include "../Verificadora/Verificadora.h"

using namespace std;

int Conversora::ConverterDigitoCharParaInt(char digito)
{
    int valor = 0;
    // Caso o digito for um numérico
    if (isdigit(digito))
        valor = (int) digito - 48;
    // Caso o dígito seja uma letra
    else
        valor = (int) toupper(digito) - 55;
    return valor;
}

char Conversora::ConverterDigitoIntParaChar(int digito)
{
    // Se o digito, agora em int, é numérico
    if(digito > 9)
        return (char)(digito + 55);
    // Se o dígito virará uma letra (a partir do digito 10)
    return (char)(toupper(digito) + 48);
}
