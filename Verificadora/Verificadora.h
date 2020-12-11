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
};

#endif
