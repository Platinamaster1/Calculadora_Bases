#include <string.h>

using namespace std;

#ifndef VERIFICADORA
#define VERIFICADORA

class Verificadora
{
    public:
        static bool baseValida(unsigned int baseNumerica);
        static bool numeroValido(string numero, unsigned int base);
        static bool temVirgula(string numero);
        static bool operacaoValida(char opcao);
        static bool temMaisCasasAntesVirgula(string v1, string v2);
        static bool temMaisCasasDpsVirgula(string valor1, string valor2);
        static bool digitoEhMaior(char digito1, char digito2);
        static bool ehMaior(string valor1, string valor2);

        static bool primeiroNumNegativo(string valor1, string valor2);
        static bool segundoNumNegativo(string valor1, string valor2);
        static bool osDoisNegativos(string valor1, string valor2);
        static bool numNegativo(string num);
};

#endif
