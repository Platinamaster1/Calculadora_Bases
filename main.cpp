#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <locale.h>

using namespace std;

#include "Calculadora/Calculadora.h"
#include "Verificadora/Verificadora.h"
#include "Formatadora/Formatadora.h"
#include "Contadora/Contadora.h"


// BRUNO ARNONE FRANCHI    - 19164
// ENZO FUREGATTI SPINELLA - 19168
int main()
{
    Calculadora calc;
    string stringNum1, stringNum2;
    unsigned int baseNumerica = 0;

    cout << " __________________________________________________________________________ " << endl;
    cout << "|                                                                          |" << endl;
    cout << "|  Sejam bem-vindos ao nosso aplicativo de operacoes com bases numericas!  |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|                     Trabalho desenvolvido em C++ por:                    |" << endl;
    cout << "|                      Bruno Arnone Franchi    - 19164                     |" << endl;
    cout << "|                      Enzo Furegatti Spinella - 19168                     |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|__________________________________________________________________________|" << endl << endl;

    char opcao = ' ';
    do
    {
        cout << "           Escolha a sua operacao!           " << endl;
        cout << " ___________________________________________ " << endl;
        cout << "|                                           |" << endl;
        cout << "|             '+' para Adicao               |" << endl;
        cout << "|            '-' para Subtracao             |" << endl;
        cout << "|  'X', 'x', '*' ou '.' para Multiplicacao  |" << endl;
        cout << "|          '/' ou ':' para Divisao          |" << endl;
        cout << "|            'S' ou 's' para Sair           |" << endl;
        cout << "|___________________________________________|" << endl << endl;

        cout << "\tOperacao: ";
        cin >> opcao;
        cout << "\tOperacao Escolhida: ";
        switch(opcao)
        {
            case '+':
                cout << "Adicao!" << endl;
                break;
            case '-':
                cout << "Subtracao!" << endl;
                break;
            case 'X':
            case 'x':
            case '.':
            case '*':
                cout << "Multiplicacao!" << endl;
                break;
            case '/':
            case ':':
                cout << "Divisao!" << endl;
                cout << "\tPena que nao deu tempo ;-;" << endl;
                break;
            case 'S':
            case 's':
                cout << "NENHUMA HAHAHA" << endl;
                cout << "\t...Saindo..." << endl;
                break;
        }
        // Valida a opção...
        while(!Verificadora::operacaoValida(opcao))
        {
            cout << "O simbolo digitado eh invalido! Exemplos de simbolos validos: (X x * . / : + - s S) Digite novamente: ";
            cin >> opcao;
        };
        cout << endl;

        if(opcao == 'S' || opcao == 's' || opcao == '/' || opcao == ':')
            return 0;

        cout << "Digite a base dos numeros: ";
        cin >> baseNumerica;
        // Valida a base numérica...
        while(!Verificadora::baseValida(baseNumerica))
        {
            cout << "A base digitada eh invalida! Digite uma valida: ";
            cin >> baseNumerica;
        };

        cout << "Digite o primeiro numero: ";
        cin >> stringNum1;
        // Valida o primeiro número escrito...
        while(!Verificadora::numeroValido(stringNum1, baseNumerica))
        {
            cout << "O numero digitado eh invalido! Digite o primeiro numero novamente: ";
            cin >> stringNum1;
        };
        stringNum1 = Formatadora::FormatarNumero(stringNum1);


        cout << "Digite o segundo numero: ";
        cin >> stringNum2;
        // Valida o segundo número escrito...
        while(!Verificadora::numeroValido(stringNum2, baseNumerica))
        {
            cout << "O numero digitado eh invalido! Digite o segundo numero novamente: ";
            cin >> stringNum2;
        };
        stringNum2 = Formatadora::FormatarNumero(stringNum2);

        // Transforma os eventuais pontos existentes no número escrito pelo usuário em vírgulas para facilitar na hora da conta
        if(Verificadora::temVirgula(stringNum1))
            stringNum1[stringNum1.find_first_of(".,")] = ',';
        if(Verificadora::temVirgula(stringNum2))
            stringNum2[stringNum2.find_first_of(".,")] = ',';

        // Iguala os zeros, tanto antes quanto depois da vírgula, das duas strings para facilitar as contas como feitas no passo a passo aprendido em aula
        if(Verificadora::temVirgula(stringNum1) || Verificadora::temVirgula(stringNum2))
        {
            // Adiciona a vírgula caso algum deles não tenha, para o funcionamento das operações
            stringNum1 = Formatadora::AdicionarVirgulaCasoPrecise(stringNum1);
            stringNum2 = Formatadora::AdicionarVirgulaCasoPrecise(stringNum2);

            // Iguala as casas dps da vírgula
            if(Verificadora::temMaisCasasDpsVirgula(stringNum1, stringNum2))
                stringNum2 = Formatadora::IgualarZerosDpsVirgula(stringNum2, Contadora::DiferencaCasasDpsVirgula(stringNum1, stringNum2));
            else
                stringNum1 = Formatadora::IgualarZerosDpsVirgula(stringNum1, Contadora::DiferencaCasasDpsVirgula(stringNum1, stringNum2));
        }

        // Iguala as casas antes da vírgula, ou as casas apenas
        if(Verificadora::temMaisCasasAntesVirgula(stringNum1, stringNum2))
                stringNum2 = Formatadora::IgualarZerosAntesVirgula(stringNum2, Contadora::DiferencaCasasAntesVirgula(stringNum1, stringNum2));
            else
                stringNum1 = Formatadora::IgualarZerosAntesVirgula(stringNum1, Contadora::DiferencaCasasAntesVirgula(stringNum1, stringNum2));

        string resultadoOperacao = "";
        switch(opcao)
        {
            case '+':
                resultadoOperacao = calc.SomarCom(stringNum1, stringNum2, baseNumerica);
                break;
            case '-':
                resultadoOperacao = calc.SubtrairCom(stringNum1, stringNum2, baseNumerica);
                break;
            case 'X':
            case 'x':
            case '.':
            case '*':
                resultadoOperacao = calc.MultiplicarCom(stringNum1, stringNum2, baseNumerica);
                break;
            case '/':
            case ':':
                //resultadoOperacao = calc.DividirCom(stringNum1, stringNum2, baseNumerica);
                break;
        }
        resultadoOperacao = Formatadora::FormatarNumero(resultadoOperacao);
        cout << endl << "\t\t| Resultado: " << resultadoOperacao << " |" << endl << endl;
    }
    while (opcao != 'S' && opcao != 's');

    return 0;
};


