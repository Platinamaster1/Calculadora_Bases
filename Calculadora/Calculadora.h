#include "../Digito/Digito.h"
#include <string>
#include "../Operadoras/SomadoraDigito.h"
#include "../Operadoras/SubtradoraDigito.h"
#include "../Operadoras/MultiplicadoraDigito.h"
#include "../Operadoras/DivisoraDigito.h"
#ifndef CALCULADORA
#define CALCULADORA

class Calculadora
{
    public:
        string SomarCom(string num1, string num2, unsigned int base);
        string SubtrairCom(string num1, string num2, unsigned int base);
        string MultiplicarCom(string num1, string num2, unsigned int base);
        string DividirCom(string num1, string num2, unsigned int base);
};

#endif
