// ANTHONY CLINT PASTORELLO R.A.: 0050482011005 - TP DA P1

#include<iostream>
#include "PILHA_P1.h"
#include "FILA_P1.h"
#include "PILHA_LIGADA.h"
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h> // pra usar rand
#include<string>
#include<sstream>

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

#define ex8 

#ifdef ex6

/*
   6.	Utilizando as implementações de uma estrutura de dados pilha,
      elabore um programa que converta um número decimal em número binário.

*/

Pilha<int> p(16);

void bina(int deci)
{
    if(deci == 0)
    {
        p.empilha(0);
    }
    else
    {
        while (deci != 0)
        {
            if (deci % 2 == 0)
            {
                p.empilha(0);
            }
            else
            {
                p.empilha(1);
            }

            deci /= 2;
        }
    }
}

void exibe(int deci)
{
    cout << "\n\n\t\tNúmero decimal: " << deci << endl;
    cout << "\t\tNúmero em binário: ";

    for (int i = p.getTopo(); i >= 0; i--)
    {
        cout << p.getVal(i) << " ";
    }
    cout << "\n\n";
}

int main()
{
    int deci; 
    char resp;

    setlocale(LC_ALL, "portuguese");
    do 
    {
        do
        {
            SetConsoleTextAttribute(color, 15); // letra branca

            cout << "\n\n\t\tCONVERSÃO DE DECIMAL PARA BINÁRIO\n" << endl;

            cout << "\n\t\tINFORME UM NÚMERO DECIMAL: ";
            cin >> deci; 

            if (deci < 0)
            {
                SetConsoleTextAttribute(color, 12); // letra vermelha

                cout << "\n\n\t\t VALOR INVÁLIDO!!!" << endl;

                Sleep(2000); 

                system("cls"); 
            }

        } while (deci < 0);

        bina(deci);

        exibe(deci);

        cout << "\n\n\t\tDESEJA INFORMAR OUTRO NÚMERO?(S/N): ";
        cin >> resp;

       
        if(resp == 's' || resp == 'S')
        {
            while(!p.emptypilha())
            {
                p.desempilha(); 
            }
            system("cls");
        }
        else
        {

            system("cls");
            cout << "\n\n\t\t>>> PROGRAMA FINALIZADO <<<\n\n\n" << endl;
        }

    } while (resp == 's' || resp == 'S');

    return 0;
}

#endif // ex6

#ifdef ex7

/*
   7.	Considerando uma pilha e uma fila, de números inteiros, construa uma aplicação que:
      a) define uma pilha e uma fila de tamanho 20.
      b) carrega a fila com números aleatórios compreendidos entre 35 e 78
      c) exibe a fila
      d) transfere todos os elementos da fila para a pilha
      e) exibe a pilha
*/

Pilha<int> p(20); // a)
Fila<int> f(20);  //a)

int main()
{
    char resp;
    setlocale(LC_ALL, "portuguese");

    do 
    {
        system("cls");

        srand(time(NULL));

        for (int i = 0; i < 20; i++)
        {
            f.put(35 + rand() % 44); // b)
        }

        SetConsoleTextAttribute(color, 15); // letra branca

        cout << "\n\n\t\tFILA: "; 

        SetConsoleTextAttribute(color, 14); // letra amarela

        if (f.getBegin() > f.getEnd()) // c)
        {
            for (int i = f.getBegin(); i < f.getSize(); i++)
            {
                cout << f.getVal(i) << " ";
            }
            for (int i = 0; i <= f.getEnd(); i++) 
            {
                cout << f.getVal(i) << " ";
            }
        }
        else
        {
            for (int i = f.getBegin(); i <= f.getEnd(); i++)
            {
                cout << f.getVal(i) << " ";
            }
        }

        cout << "\n\n";

        for (int i = 0; i < 20; i++)
        {
            p.empilha(f.getVal(i)); // d)
        }

        SetConsoleTextAttribute(color, 15); // letra branca

        cout << "\n\n\t\tPILHA: ";

        SetConsoleTextAttribute(color, 14); // letra amarela
        
        for (int i = p.getTopo(); i >= 0; i--) // e)
        {
            cout << p.getVal(i) << " ";
        }
        cout << "\n\n";

        SetConsoleTextAttribute(color, 15); // letra branca

        cout << "\n\n\t\tDESEJA REPETIR?(S/N): ";
        cin >> resp;

        if (resp == 's' || resp == 'S')
        {
            while (!p.emptypilha())
            {
                p.desempilha();
            }
            system("cls");
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n\n\n\n\n" << endl;
        }
    
    } while (resp == 's' || resp == 'S');

    return 0;
}

#endif // ex7

#ifdef ex8

/*
   8.	Um pangrama é uma frase que contém pelo menos uma vez cada uma das 26 letras do novo alfabeto Português.
      Um exemplo de pangrama é: “UM PEQUENO JABUTI XERETA CHAMADO KYA VIU DEZ CEGONHAS FELIZES E GRITOU IWUP, IWUP!”
      Construa uma aplicação que recebe uma frase e verifica se ela é pangrama (utilize os conceitos de listas e strings da linguagem C++).
      Frases para teste:
      •	jackdawf loves my big quartz sphinx
      •	abcdefghijklmnopqrstuvwxyz
      •	the quick brown fox jumps over a lazy dog
      •	jackdaws loves my big sphinx of quartz
      •	hello world
      •	esta frase es muy larga y contiene todas las letras  abc def ghij klmnopqr stu vw x y zzzzz
      •	supercalifragilistico espialidoso
      •	alfa beta gamma delta epsilon iotta kappa lambda
*/


int main()
{
    setlocale(LC_ALL, "Portuguese");

    Pilha_Lig<char> p;
    string frase;
    char c;

    do
    {
        system("cls");

        SetConsoleTextAttribute(color, 15); // letra branca

        cout << "\n\n\t\t VERIFICADOR DE PANGRAMA" << endl;

        cout << "\n\n\t\t INSIRA A FRASE A SER VERIFICADA: ";
        getline(cin, frase);

        unsigned i = 0;

        int M = 65; // A
        int m = 97; // a

        for (i; i < frase.length(); i++)
        {
            c = frase.at(i);

            if (M != 91) // [ --> primeiro simbolo depois do Z
            {
                if (c == M || c == m)
                {
                    p.empilha(c);

                    M++;
                    m++;

                    i = -1;
                }
            }
            else
            {
                i = frase.length();
            }
        }

        if (p.elementodotopo() == 'z' || p.elementodotopo() == 'Z')
        {
            SetConsoleTextAttribute(color, 10); // letra verde

            cout << "\n\n\t\t A FRASE É UM PANGRAMA!!!" << endl;
        }
        else
        {
            SetConsoleTextAttribute(color, 12); // letra vermelha

            cout << "\n\n\t\t A FRASE NÃO É UM PANGRAMA!!!" << endl;
        }

        SetConsoleTextAttribute(color, 15); // letra branca

        cout << "\n\n\t\t DESEJA VERIFICAR OUTRA FRASE?(S/N):  ";
        cin >> c;
        cin.ignore();

        if (c != 's' && c != 'S')
        {
            system("cls");

            SetConsoleTextAttribute(color, 10); // letra verde

            cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

            SetConsoleTextAttribute(color, 15); // letra branca
        }
        else
        {
            while (!p.pilhavazia())
            {
                p.desempilha();
            }
        }

    } while (c == 's' || c == 'S');

    return 0;
}
#endif // ex8
