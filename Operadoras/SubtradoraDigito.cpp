#include "SubtradoraDigito.h"
#include "../Conversora/Conversora.h"

char SubtradoraDigito::Subtrair(char digito1, char digito2, unsigned int base)
{
    int valor1, valor2; // declaracao de variaveis
    valor1 = Conversora::ConverterDigitoCharParaInt(digito1); // armazena o valor numerico de digito1 em valor1
    valor2 = Conversora::ConverterDigitoCharParaInt(digito2); // armazena o valor numerico de digito2 em valor2
    if(this->emprestou) // caso o ultimo algarismo que foi subtraido tenha emprestado
    {
        valor1--; // reduz o valor1 em 1
        this->emprestou = false; // e coloca que emprestou eh false
    };
    if(valor2 > valor1) // caso o valor2 seja maior que o valor1 e precise emprestar
    {
        valor1 += base; // o valor1 tera seu valor aumentado no mesmo numero da base
        this->emprestou = true; // e coloca emprestou como true para reduzir o proximo digito
    }
    unsigned int resultado = valor1 - valor2; // calcula o resultado da subtracao
    return Conversora::ConverterDigitoIntParaChar(resultado); // transforma o resultado em um tipo char e retorna
};

bool SubtradoraDigito::operator==(SubtradoraDigito &outra)
{
    return (this->emprestou == outra.emprestou); // se a variavel emprestou tenha o mesmo valor em ambas as instancias retorna true
};
