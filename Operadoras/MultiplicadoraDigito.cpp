#include "MultiplicadoraDigito.h"
#include "../Formatadora/Formatadora.h"
#include "../Conversora/Conversora.h"
#include <string.h>

using namespace std;

string MultiplicadoraDigito::MultiplicarPor1Digito(string numero, char digito, unsigned int base)
{
    string aux, ret; 
    unsigned int subiu = 0; // declaracao de variaveis
    unsigned int valorDigito = Conversora::ConverterDigitoCharParaInt(digito); // armazena o valor numerico do digito que vai multiplicar na variavel valorDigito
    for(int i = numero.length()-1; i >= 0; i--) // enquanto nao chegar na casa 0 da string numero
    {
        if(numero[i] == ',') // caso o char na casa i de numero for ','
            continue; // continua o for
        if(numero[i] == '-') // caso o char na casa i de numero for '-'
            break; // sai do for

        unsigned int valor = Conversora::ConverterDigitoCharParaInt(numero[i]); // armazena o valor numerico do char na casa i de numero na variavel valor
        unsigned int resultadoMultiplicacao = (valor * valorDigito) + subiu; // multiplica as variaveis valor e valorDigito e depois soma com a variavel subiu,
                                                                             // armazenando o resultado na variavel resultadoMultiplicacao
        unsigned int resultado = resultadoMultiplicacao%base; // armazena o valor correspondente ao resultado da multiplicacao
        subiu = resultadoMultiplicacao/base; // armazena quantas vezes o resultado excedeu os limites da base numerica usada na variavel subiu
        aux += Conversora::ConverterDigitoIntParaChar(resultado); // converte o resultado obtido para o tipo char
    }
    aux += Conversora::ConverterDigitoIntParaChar(subiu); // converte o valor que subiu ao multiplicar o ultimo digito de numero para tipo char e armazena
    ret = Formatadora::InverterString(aux); // inverte a string aux e armazena o resultado da inversao na variavel ret
    return ret; // retorna ret
};
