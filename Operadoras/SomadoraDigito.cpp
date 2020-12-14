#include "SomadoraDigito.h"
#include "../Conversora/Conversora.h"

char SomadoraDigito::SomarDoisDigitos(char v1, char v2, unsigned int base)
{
    unsigned int primeiro = 0, segundo = 0; // variaveis onde serao armazenados os valores numericos dos valores passados
    primeiro = Conversora::ConverterDigitoCharParaInt(v1); // armazenamento do valor numerico de v1 em primeiro
    segundo = Conversora::ConverterDigitoCharParaInt(v2); // armazenamento do valor numerico de v2 em segundo

    unsigned int resultado = primeiro + segundo + this->subiu; // soma os valores passados com a variavel subiu, que eh o valor que passou o 
                                                               // limite da base na ultima soma realizada por uma instancia da classe somadora
    unsigned int resto = resultado%base; // calcula o numero que sera retornado ao usuario
    this->subiu = resultado/base; // numero que passou o limite da base e sera armazenado para somar na proxima adicao
    char ret = Conversora::ConverterDigitoIntParaChar(resto); // converte numero que representa o valor numerico do resultado para o tipo char
    return ret; // retorna o resultado obtido
};

bool SomadoraDigito::operator== (const SomadoraDigito &outra)
{
    return (this->subiu == outra.subiu); // retorna true caso ambas as instancias possuam o mesmo dado armazenado em subiu
};
