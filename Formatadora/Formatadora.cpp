#include <string>
#include "Formatadora.h"
#include "../Verificadora/Verificadora.h"

using namespace std;

string Formatadora::AdicionarVirgulaCasoPrecise(string valor)
{
    // Acha o índice
    int indiceVirgula = valor.find(',');
    // Caso não tenha vírgula, adiciona
    if(indiceVirgula == -1)
        valor.append(",");
    return valor;
}

string Formatadora::IgualarZerosAntesVirgula(string valor, int diferencaCasasAntesVirgula)
{
    string valorComZeros;
    // Se o número eh negativo, a versão com zero deve ser também
    if(Verificadora::numNegativo(valor))
        valorComZeros.append("-");
    // Adiciona a qtd de casas que precisa para igualar este valor com o outro dono do qtd
    for(int i = 0; i < diferencaCasasAntesVirgula; i++)
        valorComZeros.append("0");

    // Adiciona, dps dos zeros necessários, o número em si
    for(int i = 0; i < valor.length(); i++)
        if(valor[i] != '-')
            valorComZeros += valor[i];
    return valorComZeros;
}

string Formatadora::IgualarZerosDpsVirgula(string valor, int diferencaCasasDpsVirgula)
{
    // Adiciona os zeros necessários dps da vírgula para igualar com o dono do maior valor q este está sendo igualado em casas
    for(int i = 0; i < diferencaCasasDpsVirgula; i++)
        valor.append("0");
    return valor;
};

string Formatadora::FormatarNumero(string numero)
{
    // Tira os possíveis zeros da parte antes da vírgula
    if(numero.length() > 1)
    {
        for(int i = 0; i < numero.length(); i++)
        {
            if(numero.at(i) != '0' && numero.at(i) != '-')
            {
                // Não apaga o '-' quando for negativo
                if(numero.at(0) == '-')
                    numero.erase(numero.begin()+1, numero.begin()+i);
                else
                    numero.erase(numero.begin(), numero.begin()+i);
                break;
            }
        }
        if(Verificadora::temVirgula(numero))
        {
            // Tira os possíveis zeros da parte depois da vírgula, caso o número tenha vírgula
            for(int i = numero.length()-1; i >= 0; i--)
            {
                if(numero.at(i) != '0')
                {
                    // Caso não tenha números válidos depois da vírgula, apaga ela também
                    if(numero.at(i) == ',')
                        numero.erase(numero.begin()+i, numero.end());
                    numero.erase(numero.begin()+i+1, numero.end());
                    break;
                }
            }
        }
    }
    return numero;
}

string Formatadora::InverterString(string invertida)
{
    string ret;
    // Percorre a string de trás pra frente para invertê-la
    for(int i = invertida.length()-1; i >= 0; i--)
        ret += invertida[i];
    return ret;
}

string Formatadora::RetirarSinal(string n)
{
    // Retira o primeiro caracter do n que deverá ser um -, caso o contrário dará erro
    n.erase(0, 1);
    return n;
}

