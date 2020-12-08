#include "../Digito/Digito.h"
#ifndef SUBTRADORA
#define SUBTRADORA

class SubtradoraDigito
{
    private:
        int subiu;
    public:
        Digito SubtrairDoisDigitos(Digito primeiro, Digito segundo, unsigned int base);
};

#endif