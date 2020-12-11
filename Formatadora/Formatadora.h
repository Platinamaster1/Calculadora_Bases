#include <string.h>

using namespace std;

#ifndef FORMATADORA
#define FORMATADORA

class Formatadora
{
    public:
        static int PegarCasasDpsVirgula(string valor1, string valor2);
        static string IgualarZeros(string valor1, int casasDpsVirgula);
        static string FormatarResultado(string resultado);
};

#endif
