#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include "Calculadora.h"
#include "../Verificadora/Verificadora.h"
#include "../Formatadora/Formatadora.h"

using namespace std;

string Calculadora::SomarCom(string numero, string numeroASomar, unsigned int base)
{
    string maior, menor, aux, ret;
    cout << "NUMERO: " << numero << "NUMEROASOMAR: " << numeroASomar << endl;
    if(Verificadora::ehMaior(numero, numeroASomar))
    {
        maior = numero;
        menor = numeroASomar;
    }
    else
    {
        maior = numeroASomar;
        menor = numero;
    }

    SomadoraDigito operadora;
    SubtradoraDigito operadora2;
    if(Verificadora::primeiroNumNegativo(maior, menor))
    {
        maior = Formatadora::RetirarSinal(maior);
        for(int i = menor.length()-1; i >= 0; i--)
        {
            if(maior[i] == ',')
            {
                aux += ',';
                continue;
            }
            if(maior[i] == '-')
                break;
            aux += operadora2.Subtrair(maior[i], menor[i], base);
        }
        aux.append("-");
    }
    else if(Verificadora::segundoNumNegativo(maior, menor))
    {
        menor = Formatadora::RetirarSinal(menor);
        for(int i = menor.length()-1; i >= 0; i--)
        {
            if(maior[i] == ',')
            {
                aux += ',';
                continue;
            }
            if(maior[i] == '-')
                break;
            aux += operadora2.Subtrair(maior[i], menor[i], base);
        }
    }
    // Se nenhum tiver sinal negativo ou se os dois tiverem...
    else
    {
        for(int i = menor.length()-1; i >= 0; i--)
        {
            if(maior[i] == ',')
            {
                aux += ',';
                continue;
            }
            if(maior[i] == '-')
                break;
            aux += operadora.SomarDoisDigitos(maior[i], menor[i], base);
        }
        if(Verificadora::osDoisNegativos(maior, menor))
            aux.append("-");
    }

    // Pra quando temos um número que subiu na ultima conta, ele não seria escrito, fazendo essa última conta imaginária ele aparece
    char oQueSubiu = operadora.SomarDoisDigitos('0', '0', base);
    if(oQueSubiu != '0')
        aux += oQueSubiu;

    ret = Formatadora::InverterString(aux);
    return ret;
};



string Calculadora::SubtrairCom(string numero1, string numero2, unsigned int base)
{
    // Não podemos mudar a ordem na subtração (a ordem dos fatores altera o resultado)
    // Porém, continuamos definindo para uso de seus length() (apenas do menor) para não dar erro
    string maior, menor, aux, ret;
    if(Verificadora::ehMaior(numero1, numero2))
    {
        maior = numero1;
        menor = numero2;
    }
    else
    {
        maior = numero2;
        menor = numero1;
    }
    cout << "Valor1: " << numero1 << " Valor2: " << numero2 << endl;
    cout << "Maior: " << maior << " Menor: " << menor << endl;

    SubtradoraDigito operadora;
    SomadoraDigito operadora1;
    if(Verificadora::primeiroNumNegativo(numero1, numero2))
    {
        if(menor == numero1)
            menor = Formatadora::RetirarSinal(menor);
        numero1 = Formatadora::RetirarSinal(numero1);

        for(int i = menor.length()-1; i >= 0; i--)
        {
            if(numero1[i] == ',')
            {
                aux += ',';
                continue;
            }
            if(numero1[i] == '-')
                break;

            aux += operadora1.SomarDoisDigitos(numero1[i], numero2[i], base);
        }
        aux.append("-");
    }
    else if(Verificadora::segundoNumNegativo(numero1, numero2))
    {
        if(menor == numero2)
            menor = Formatadora::RetirarSinal(menor);
        numero2 = Formatadora::RetirarSinal(numero2);

        for(int i = menor.length()-1; i >= 0; i--)
        {
            if(numero1[i] == ',')
            {
                aux += ',';
                continue;
            }
            if(numero1[i] == '-')
                break;
            aux += operadora1.SomarDoisDigitos(numero1[i], numero2[i], base);
        }
    }
    // Se nenhum tiver sinal negativo ou se os dois tiverem...
    else
    {
        for(int i = menor.length()-1; i >= 0; i--)
        {
            if(numero1[i] == ',')
            {
                aux += ',';
                continue;
            }
            if(numero1[i] == '-')
                break;
            aux += operadora.Subtrair(maior[i], menor[i], base);
        }
        if(Verificadora::numNegativo(numero1) && numero1 == maior)
            aux.append("-");
        if(!Verificadora::numNegativo(numero2) && numero2 == maior)
            aux.append("-");
    }

    ret = Formatadora::InverterString(aux);
    return ret;
};

string Calculadora::MultiplicarCom(string numeroAMultiplicar, string numeroQueVaiMultiplicar, unsigned int base)
{
    string ret = "00", aux;
    cout << "NUMERO A MULTIPLICAR: " << numeroAMultiplicar << endl;
    cout << "NUMERO QUE VAI MULTIPLICAR: " << numeroQueVaiMultiplicar << endl;
    int indiceDaVirgula = Formatadora::SomaCasasDpsVirgula(numeroAMultiplicar, numeroQueVaiMultiplicar);
    for(int i = numeroQueVaiMultiplicar.length()-1; i >= 0; i--)
    {
        if(numeroQueVaiMultiplicar[i] == ',')
        {
            //ret += ',';
            continue;
        }
        if(numeroQueVaiMultiplicar[i] == '-')
            break;
        if(numeroQueVaiMultiplicar[i] == '0')
        {
            numeroAMultiplicar.append("0");
            continue;
        }

        string resultadoDoDigito = MultiplicadoraDigito::MultiplicarPor1Digito(numeroAMultiplicar, numeroQueVaiMultiplicar[i], base);
        cout << "Resultado do digito: " << resultadoDoDigito << endl;
        cout << "Ret antes de somar: " << ret << endl;
        if(ret.length() < resultadoDoDigito.length())
            ret = Formatadora::IgualarZerosAntesVirgula(ret, resultadoDoDigito.length() - ret.length());
        ret = SomarCom(ret, resultadoDoDigito, base);
        numeroAMultiplicar.append("0");
        cout << "Ret dps de somar: " << ret << endl;
        cout << "ret: " << ret << endl;
    }

    if(Verificadora::temVirgula(numeroAMultiplicar))
    {
        cout << "aaa: " << indiceDaVirgula << endl;
        cout << "AAAA: " << ret.length() << endl;
        for(int i = 0; i < ret.length(); i++)
        {
            if(i == (ret.length() - indiceDaVirgula))
                aux.append(",");
            aux += ret[i];
        }
        ret = aux;
    }
    if((Verificadora::numNegativo(numeroAMultiplicar) || Verificadora::numNegativo(numeroQueVaiMultiplicar)) &&
       !Verificadora::osDoisNegativos(numeroAMultiplicar, numeroQueVaiMultiplicar))
    {
        ret = Formatadora::InverterString(ret);
        ret.append("-");
        ret = Formatadora::InverterString(ret);
    }
    cout << "RET: " << ret << endl;
    return ret;
};

string Calculadora::DividirCom(string numero, string divisor, unsigned int base)
{

};
