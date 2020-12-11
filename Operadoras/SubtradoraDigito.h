#include "../Digito/Digito.h"
#ifndef SUBTRADORA
#define SUBTRADORA

class SubtradoraDigito
{
    private:
        int subiu;
    public:
        char Subtrair(char primeiro, char segundo, unsigned int base, bool emprestou, bool foiEmprestado);
};

#endif