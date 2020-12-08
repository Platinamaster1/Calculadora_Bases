#include "../Digito/Digito.h"
#include "../Operadoras/SomadoraDigito.h"
#include "../Operadoras/SubtradoraDigito.h"
#include "../Operadoras/MultiplicadoraDigito.h"
#include "../Operadoras/DivisoraDigito.h"
#ifndef CALCULADORA
#define CALCULADORA

class Calculadora
{
    public:
        Digito* SomarCom(Digito* num1, Digito* num2, unsigned int base); 
        Digito* SubtrairCom(Digito* num1, Digito* num2, unsigned int base); 
        Digito* MultiplicarCom(Digito* num1, Digito* num2, unsigned int base); 
        Digito* DividirCom(Digito* num1, Digito* num2, unsigned int base); 
};

#endif