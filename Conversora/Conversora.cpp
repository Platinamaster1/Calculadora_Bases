#include <string>
#include "Conversora.h"
#include "../Verificadora/Verificadora.h"

using namespace std;

int Conversora::ConverterDigitoCharParaInt(char digito)
{
    int valor = 0;
    // Caso o digito for um num�rico
    if (isdigit(digito))
        valor = (int) digito - 48;
    // Caso o d�gito seja uma letra
    else
        valor = (int) toupper(digito) - 55;
    return valor;
}

char Conversora::ConverterDigitoIntParaChar(int digito)
{
    // Se o digito, agora em int, � num�rico
    if(digito > 9)
        return (char)(digito + 55);
    // Se o d�gito virar� uma letra (a partir do digito 10)
    return (char)(toupper(digito) + 48);
}
