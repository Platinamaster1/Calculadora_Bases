#include <string.h>
#include <stdlib.h>
#include "Calculadora.h"
#include "../Verificadora/Verificadora.h"
#include "../Formatadora/Formatadora.h"
#include "../Contadora/Contadora.h"

using namespace std;

string Calculadora::SomarCom(string numero, string numeroASomar, unsigned int base)
{
    string maior, menor, aux, ret;
    // Define o maior e o menor n�mero...
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

    // Inicializa as duas Operadoras para englobar todos os tipos de soma
    SomadoraDigito operadora;
    SubtradoraDigito operadora2;
    // Caso o primeiro n�mero for negativo (no caso, o maior)
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
            // Subtrai os d�gitos, pois s�o de sinais diferentes
            aux += operadora2.Subtrair(maior[i], menor[i], base);
        }
        // Adiciona um sinal porque o maior n�mero q eh o negativo e sempre vai dar negativo
        aux.append("-");
    }
    // Caso o segundo n�mero for negativo (no caso, o menor)
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
            // Subtrai os d�gitos, pois s�o de sinais diferentes
            aux += operadora2.Subtrair(maior[i], menor[i], base);
        }
        //N�o colocamos o sinal no final pois o menor eh negativo e sempre vai ser positivo...
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
            // Soma os d�gitos
            aux += operadora.SomarDoisDigitos(maior[i], menor[i], base);
        }
        // Caso os dois sejam negativos, eh certeza de que o resultado tamb�m ser�
        if(Verificadora::osDoisNegativos(maior, menor))
            aux.append("-");
    }

    // Pra quando temos um n�mero que subiu na ultima conta, ele n�o seria escrito, fazendo essa �ltima conta imagin�ria ele aparece
    char oQueSubiu = operadora.SomarDoisDigitos('0', '0', base);
    if(oQueSubiu != '0')
        aux += oQueSubiu;


    // Inverte a string pois na l�gica fazemos o aux receber os �ltimos d�gitos do n�mero primeiro.
    ret = Formatadora::InverterString(aux);
    return ret;
};



string Calculadora::SubtrairCom(string numero1, string numero2, unsigned int base)
{
    // N�o podemos mudar a ordem na subtra��o (a ordem dos fatores altera o resultado)
    // Por�m, continuamos definindo para uso de seus length() e para a l�gica de quando os dois n�meros possuem sinal igual para n�o dar erro
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

    // Inicializa as duas Operadoras para englobar todos os tipos de subtra��o
    SubtradoraDigito operadora;
    SomadoraDigito operadora1;

    // Caso o primeiro n�mero escrito seja negativo...
    if(Verificadora::primeiroNumNegativo(numero1, numero2))
    {
        // Se o menor for o negativo tamb�m, � retirado o sinal para o menor.length() do for funcionar
        if(menor == numero1)
            menor = Formatadora::RetirarSinal(menor);
        // J� o n�mero negativo vai ter sempre o sinal retirado para o aux receber dps
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
        // Sempre recebe o sinal pois o resultado vai ser sempre negativo
        aux.append("-");
    }
    // Caso o segundo n�mero seja negativo...
    else if(Verificadora::segundoNumNegativo(numero1, numero2))
    {
        // Se o menor for o negativo tamb�m, � retirado o sinal para o menor.length() do for funcionar
        if(menor == numero2)
            menor = Formatadora::RetirarSinal(menor);
        // J� o n�mero negativo vai ter sempre o sinal retirado para o aux receber dps
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
        // N�o recebe sinal negativo pois esse caso vai dar sempre um n�mero positivo
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
        // Se algum n�mero for negativo (verifica somente um pois os dois tem o mesmo sinal neste caso) e, ao
        // mesmo tempo, o primeiro n�mero � o maior, o resultado � negativo
        if(Verificadora::numNegativo(numero1) && numero1 == maior)
            aux.append("-");
        // Se algum n�mero for negativo (verifica somente um pois os dois tem o mesmo sinal neste caso) e, ao
        // mesmo tempo, o segundo n�mero � o maior, o resultado � negativo
        if(!Verificadora::numNegativo(numero2) && numero2 == maior)
            aux.append("-");
    }

    // Inverte a string...
    ret = Formatadora::InverterString(aux);
    return ret;
};

string Calculadora::MultiplicarCom(string numeroAMultiplicar, string numeroQueVaiMultiplicar, unsigned int base)
{
    string ret = "00", aux;
    // Descobre em que casa do resultado deveremos colocar a virgula no final...
    int indiceDaVirgula = Contadora::SomaCasasDpsVirgula(numeroAMultiplicar, numeroQueVaiMultiplicar);
    for(int i = numeroQueVaiMultiplicar.length()-1; i >= 0; i--)
    {
        if(numeroQueVaiMultiplicar[i] == ',')
            continue;
        if(numeroQueVaiMultiplicar[i] == '-')
            break;
        // Se o n�mero � zero n�o precisamos fazer conta, � s� adicionar um zero no resultado
        if(numeroQueVaiMultiplicar[i] == '0')
        {
            numeroAMultiplicar.append("0");
            continue;
        }

        string resultadoDoDigito = MultiplicadoraDigito::MultiplicarPor1Digito(numeroAMultiplicar, numeroQueVaiMultiplicar[i], base);
        // Iguala os zeros para a soma funcionar caso o ret tiver menos digitos q o n�mero multiplicado
        if(ret.length() < resultadoDoDigito.length())
            ret = Formatadora::IgualarZerosAntesVirgula(ret, resultadoDoDigito.length() - ret.length());
        ret = SomarCom(ret, resultadoDoDigito, base);
        // Adicionamos um zero para deixar o numero a multiplicar com uma casa a mais, para simular uma multiplica��o a m�o.
        numeroAMultiplicar.append("0");
    }

    // Adiciona a v�rgula quando algum dos n�meros da multiplica��o tiver
    if(Verificadora::temVirgula(numeroAMultiplicar))
    {
        for(int i = 0; i < ret.length(); i++)
        {
            // Usa o indice calculado acima...
            if(i == (ret.length() - indiceDaVirgula))
                aux.append(",");
            aux += ret[i];
        }
        ret = aux;
    }
    // Aqui faz as verifica��es de quando o resultado fica negativo, isto �, apenas quando um � negativo
    if((Verificadora::numNegativo(numeroAMultiplicar) || Verificadora::numNegativo(numeroQueVaiMultiplicar)) &&
       !Verificadora::osDoisNegativos(numeroAMultiplicar, numeroQueVaiMultiplicar))
    {
        // Inverte
        ret = Formatadora::InverterString(ret);
        // adicionamos um zero no final
        ret.append("-");
        // Invertemos para o zero ficar no in�cio
        ret = Formatadora::InverterString(ret);
    }
    return ret;
};
/*
string Calculadora::DividirCom(string numero, string divisor, unsigned int base)
{

}; N�o fizemos pelo tempo */
