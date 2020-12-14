#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Verificadora.h"
#include "../Formatadora/Formatadora.h"
#include "../Conversora/Conversora.h"


using namespace std;

bool Verificadora::baseValida(unsigned int base)
{
    // Não existe base menor que a base 2
    if(base < 2)
        return false;
    // Não existe, com a possibilidade de representação, bases maiores que a base 36
    if(base > 36)
        return false;
    return true;
};

bool Verificadora::numeroValido(string numero, unsigned int base)
{
    unsigned int virgulas = 0; // variavel que armazenara o numero de ',' ou '.' no numero
    unsigned int menos = 0; // variavel que armazenara o numero de '-' no numero
    for(int i = 0; i < numero.length(); i++) // para cada char no numero
    {
        if(numero[i] == '-') // se numero[i] for igual a '-'
        {
            menos++; // menos recebe menos + 1
            continue; // continua o for
        }
        if(numero[i] == ',' || numero[i] == '.') // se numero[i] for igual a ',' ou '.'
        {
            virgulas++; // virgulas recebe virgulas + 1
            continue; // continua o for
        }
        if(numero[i] > 47 && numero[i] < 58) // se numero[i], que eh um char, valer entre 47 e 58, equivalente aos algarismos de 0(48) a 9(57)
        {
            if((numero[i] - 48) > (base - 1)) // se o valor numerico de numero[i] for maior que a base numerica - 1
            {
                return false; // retorna falso
            }
        }
        else
        {
            if(numero[i] > 64 && numero[i] < 91) // se numero[i], que eh um char, valer entre 64 e 91, equivalente as letras de A(65) a Z(90)
            {
                if((numero[i] - 55) > (base - 1)) // se o valor numerico de numero[i] for maior que a base numerica - 1
                {
                    return false; // retorna falso
                }
            }
            else
            {
                if(numero[i] > 96 && numero[i] < 123) // se numero[i], que eh um char, valer entre 96 e 123, equivalente as letras de a(97) a z(122)
                {
                    if((numero[i] - 87) > (base - 1)) // se o valor numerico de numero[i] for maior que a base numerica - 1
                    {
                        return false; // retorna falso
                    }
                }
                else
                {
                    return false; // caso o char em numero[i] nao seja ',', '.', '-', um numero de '0' a '9', 
                                  // uma letra de 'A' a 'Z' ou uma letra de 'a' a 'z', retorna falso
                }
            }
        }
    }
    if(virgulas > 1 || menos > 1) // caso o numero de virgulas ou de menos seja superior a 1
    {
        return false; // retorna false
    }
    return true; // caso nenhuma irregularidade seja encontrada, retorna verdadeiro
};

bool Verificadora::temVirgula(string numero)
{
    // Usa o find_first_of para achar se há no número um '.' ou uma ',', indicadores de casas decimais
    int tem = numero.find_first_of(",.");
    // Caso não tenha, retorna false
    if(tem == -1)
        return false;
    return true;
}

bool Verificadora::operacaoValida(char opcao)
{
    // String com todos os caracteres que podem ser usados no programa
    string operadores = "Xx*./:+-sS";
    // Verifica se a opcao do parâmetro é uma dessas da string operadores
    int opcaoExiste = operadores.find_first_of(opcao);
    // Caso não seja uma operação válida retorna false
    if(opcaoExiste == -1)
        return false;
    return true;
};

bool Verificadora::temMaisCasasAntesVirgula(string valor1, string valor2)
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

    // Retorna true caso o valor1 tenha mais casas e o contrário caso tenha menos
    if(qntsCasasAntesVirgula1 > qntsCasasAntesVirgula2)
        return true;
    return false;
}

bool Verificadora::temMaisCasasDpsVirgula(string valor1, string valor2)
{
    // Tira do length o indice da ',' + 1 para conseguir a quantidade de casas depois da vírgula de cada valor
    int qntsCasasDpsVirgula1 = valor1.length() - valor1.find(',') + 1;
    int qntsCasasDpsVirgula2 = valor2.length() - valor2.find(',') + 1;
    
    // Retorna true caso o valor1 tenha mais casa e false caso contrário
    if(qntsCasasDpsVirgula1 > qntsCasasDpsVirgula2)
        return true;
    return false;
};

bool Verificadora::digitoEhMaior(char digito1, char digito2)
{
    int valor1, valor2;
    // Converte os digitos em char para os respectivos dígitos em código ascii
    valor1 = Conversora::ConverterDigitoCharParaInt(digito1);
    valor2 = Conversora::ConverterDigitoCharParaInt(digito2);

    // Verifica qual é maior, caso o valor1 seja maior retorna true, caso contrário retorna false
    if(valor1 > valor2)
        return true;
    return false;
};

bool Verificadora::ehMaior(string numero1, string numero2)
{
    int ondeNumero2 = 0; // indice do numero2
    bool passouVirgula1 = false; // variavel que controla se ja passou pela ',' do numero1
    bool passouVirgula2 = false; // variavel que controla se ja passou pela ',' do numero2
    bool numero1EhMaior = false; // variavel que verifica se algum digito do numero1 foi maior que do numero2
    bool umNumeroFoiMaior = false; // variavel que verifica caso algum digito de um dos numeros foi maior que seu correspondente no outro numero
    for(int i = 0; i < numero1.length(); i++) // para cada char dentro do numero1, sendo i o indice de numero1
    {
        if(numero1[i] == '-') // caso numero1[i] seja igual a '-'
            continue; // continua o for, aumentando o valor do indice de numero1, que eh o i, em 1
        if(numero2[ondeNumero2] == '-') // caso numero2[ondeNumero2] seja igual a '-'
            ondeNumero2++; // aumenta o indice do numero2 em 1
        if(numero1[i] == ',') // caso numero1[i] seja igual a ','
        {
            passouVirgula1 = true; // passouVirgula1 recebe verdadeiro
            continue; // continua o for, aumentando o valor do indice de numero1, que eh o i, em 1
        }
        if(numero2[ondeNumero2] == ',') // caso numero2[ondeNumero2] seja igual a ','
        {
            passouVirgula2 = true; // passouVirgula2 recebe verdadeiro
            ondeNumero2++; // aumenta o indice do numero2 em 1
        }
        if(passouVirgula1 && !passouVirgula2) // caso passou pela virgula de numero1 e nao passou pela virgula de numero2
            return false; // retorna falso pois numero2 eh maior que numero1
        if(!passouVirgula1 && passouVirgula2) // caso passou pela virgula de numero2 e nao passou pela virgula de numero1
            return true; // retorna verdadeiro pois numero1 eh maior que numero2
        if(umNumeroFoiMaior) // se o digito de um dos numeros foi maior que seu correspondente no outro numero
        {
            ondeNumero2++; // aumenta o indice do numero2 em 1
            continue; // continua o for, aumentando o valor do indice de numero1, que eh o i, em 1
        }
        int valor1 = Conversora::ConverterDigitoCharParaInt(numero1[i]); // pega o valor numerico do char em numero1[i]
        int valor2 = Conversora::ConverterDigitoCharParaInt(numero2[ondeNumero2]); // pega o valor numerico do char em numero2[ondeNumero2]
        if(valor1 > valor2) // se o valor1 for maior que o valor2
        {
            umNumeroFoiMaior = true; // umNumeroFoiMaior recebe verdadeiro
            numero1EhMaior = true; // numero1EhMaior recebe verdadeiro
            ondeNumero2++; // aumenta o indice do numero2 em 1
            continue; // continua o for, aumentando o valor do indice de numero1, que eh o i, em 1
        }
        if(valor2 > valor1) // se o valor2 for maior que o valor1
        {
            umNumeroFoiMaior = true; // umNumeroFoiMaior recebe verdadeiro
            numero1EhMaior = false; // numero1EhMaior recebe falso
            ondeNumero2++; // aumenta o indice do numero2 em 1
            continue; // continua o for, aumentando o valor do indice de numero1, que eh o i, em 1
        }
    }
    return numero1EhMaior; // retorna verdadeiro caso numero1 for maior e falso caso nao seja
};

bool Verificadora::primeiroNumNegativo(string v1, string v2)
{
    // Verifica se o v1 é negativo e o v2 não
    if(v1.at(0) == '-' && v2.at(0) != '-')
        return true;
    return false;
}

bool Verificadora::segundoNumNegativo(string v1, string v2)
{
    // Verifica se o v1 não é negativo e se o v2 é
    if(v1.at(0) != '-' && v2.at(0) == '-')
        return true;
    return false;
}

bool Verificadora::numNegativo(string num)
{
    // Verifica se o número passado é negativo ou não
    if(num.at(0) == '-')
        return true;
    return false;
}

bool Verificadora::osDoisNegativos(string v1, string v2)
{
    // Verifica se ambos, v1 e v2, são negativos
    if(v1.at(0) == '-' && v2.at(0) == '-')
        return true;
    return false;
}
