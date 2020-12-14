#include <string.h>

using namespace std;

#ifndef FORMATADORA
#define FORMATADORA

class Formatadora
{
    public:
        static string AdicionarVirgulaCasoPrecise(string v);
        static string IgualarZerosAntesVirgula   (string v, int casasAntesVirgula);
        static string IgualarZerosDpsVirgula     (string v, int casasDpsVirgula);
        static string InverterString             (string invertida);
        static string FormatarNumero             (string num);
        static string RetirarSinal               (string num);
};

#endif
