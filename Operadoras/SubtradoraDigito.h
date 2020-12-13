#include "../Digito/Digito.h"
#ifndef SUBTRADORA
#define SUBTRADORA

class SubtradoraDigito
{
    private:
        bool emprestou = false;
    public:
        char Subtrair(char primeiro, char segundo, unsigned int base);
};

#endif
