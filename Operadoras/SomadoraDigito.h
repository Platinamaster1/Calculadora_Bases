#include "../Digito/Digito.h"
#ifndef SOMADORA
#define SOMADORA

class SomadoraDigito
{
    private:
        int subiu;
    public:
        Digito SomarDoisDigitos(Digito primeiro, Digito segundo, unsigned int base);
};


#endif