#ifndef SOMADORA
#define SOMADORA

class SomadoraDigito
{
    private:
        int subiu = 0;
    public:
        char SomarDoisDigitos(char primeiro, char segundo, unsigned int base);
        bool operator==      (const SomadoraDigito &outra);
};


#endif
