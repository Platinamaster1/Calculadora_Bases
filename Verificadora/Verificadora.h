#include <string.h>

using namespace std;

#ifndef VERIFICADORA
#define VERIFICADORA

class Verificadora
{
    public:
        static bool baseValida(unsigned int baseNumerica);
        static bool numeroValido(string numero, unsigned int base);
        static bool operacaoValida(char opcao);
        static bool temMaisCasasDpsVirgula(string valor1, string valor2);
        static bool digitoEhMaior(char digito1, char digito2);
        static bool ehMaior(string valor1, string valor2);
};

#endif
