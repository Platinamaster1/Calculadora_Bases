#ifndef SUBTRADORA
#define SUBTRADORA

class SubtradoraDigito
{
    private:
        bool emprestou = false;
    public:
        char Subtrair(char primeiro, char segundo, unsigned int base);
        bool operator==(SubtradoraDigito &outra);
};

#endif
