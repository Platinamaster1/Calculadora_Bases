#ifndef DIGITO
#define DIGITO

class Digito
{
    private:
        char digito;
    
    public:
        void SetDigito(char d);      // Seta o valor do digito a partir de um char
        char GetDigito();            // Retorna o digito
        int  GetValor();           // Transforma o valor do digito em int e retorna para o usuario
        void SetValor(int valor);    // Transforma um valor int em char e armazena na variavel 
        bool DigitoValido(int base); // Verifica se o digito esta na base numerica correta
};

#endif
