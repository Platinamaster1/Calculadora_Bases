#include "../Digito/Digito.h"
#ifndef SUBTRADORA
#define SUBTRADORA

class SubtradoraDigito
{
    private:
        bool emprestou;
    public:
        char Subtrair(char primeiro, char segundo, unsigned int base);
};

#endif