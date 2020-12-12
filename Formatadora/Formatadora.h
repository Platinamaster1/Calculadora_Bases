#include <string.h>

using namespace std;

#ifndef FORMATADORA
#define FORMATADORA

class Formatadora
{
    public:
        static int DiferencaCasasDpsVirgula(string v1, string v2);
        static string IgualarZerosDpsVirgula(string v, int casasDpsVirgula);
        static string FormatarResultado(string res);

        static int ConverterDigitoCharParaInt(char digito);
        static char ConverterDigitoIntParaChar(int valorDigito);

        static string InverterString(string invertida);
};

#endif
