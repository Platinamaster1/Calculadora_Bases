#include "../Digito/Digito.h"
#ifndef CALCULADORA
#define CALCULADORA

class Calculadora
{
    private:
        Digito* vetorDigitos;
    public:
        Digito* SomarCom(Digito* num);
        Digito* SubtrairCom(Digito* num);
        Digito* MultiplicarCom(Digito* num);
        Digito* DividirCom(Digito* num);
};

#endif