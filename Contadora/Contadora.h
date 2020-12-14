#include <string.h>

using namespace std;

#ifndef CONTADORA
#define CONTADORA

class Contadora
{
    public:
        static int DiferencaCasasDpsVirgula  (string v1, string v2);
        static int DiferencaCasasAntesVirgula(string v1, string v2);
        static int SomaCasasDpsVirgula       (string v1, string v2);
};

#endif
