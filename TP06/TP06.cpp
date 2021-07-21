// ANTHONY CLINT PASTORELLO R.A.: 0050482011005   - TP 06 RECURSIVAS

#include<iostream>
#include<Windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include "recursivas.h"

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);


int menu()
{
	int op; // vari�vel das op��es do menu

	system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### FUN��ES RECURSIVAS ####\n" << endl;
	cout << "\t\t 1 - FATORIAL" << endl;
	cout << "\t\t 2 - FINOBACCI" << endl;
	cout << "\t\t 3 - MDC" << endl;
	cout << "\t\t 4 - SOMA (S)" << endl;
	cout << "\t\t 5 - SOMA (S2)" << endl;
	cout << "\t\t 6 - D�GITO" << endl;
	cout << "\t\t 7 - POT�NCIA" << endl;
	cout << "\t\t 9 - ENCERRAR O PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OP��O: ";
	cin >> op;

	cin.ignore(); // igual getchar

	return op; // retornando o valor de op para que seja recebido na switch
}

int main()
{
	setlocale(LC_ALL, "portuguese");

	int n, m;

	for(;;)
	{
		switch(menu())
		{
			case 1:

				do 
				{
					cout << "\n\n\t\t INSIRA O N�MERO: ";
					cin >> n;

					if(n < 0)
					{
						SetConsoleTextAttribute(color, 12); // letra vermelha
						cout << "\n\t\t  VALOR INV�LIDO!!!" << endl;
						SetConsoleTextAttribute(color, 15); // letra branca

						Sleep(3000);

						system("cls");
					}

				} while (n < 0);
				
				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t FATORIAL DE " << n << "!: ";

				SetConsoleTextAttribute(color, 14); // letra amarela
				cout << fatR(n) << endl;

				Sleep(3500);

				break;

			case 2:

				do
				{
					cout << "\n\n\t\t INSIRA A POSI��O DESEJADA: ";
					cin >> n;

					if (n < 0)
					{
						SetConsoleTextAttribute(color, 12); // letra vermelha
						cout << "\n\t\t  VALOR INV�LIDO!!!" << endl;
						SetConsoleTextAttribute(color, 15); // letra branca

						Sleep(3000);

						system("cls");
					}

				} while (n < 0);

				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t POSI��O " << n << " NA SEQU�NCIA DE FIBONACCI: ";

				SetConsoleTextAttribute(color, 14); // letra amarela 
				cout << fib(n) << endl;

				Sleep(3500);

				break;

			case 3:

				cout << "\n\n\t\t INSIRA O 1� N�MERO: ";
				cin >> m;

				cout << "\n\n\t\t INSIRA O 2� N�MERO: ";
				cin >> n;

				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t MDC DE " << m << " E " << n << ": ";

				SetConsoleTextAttribute(color, 14); // letra amarela
				cout << mdc(m, n) << endl;

				Sleep(3500);

				break;

			case 4:

				cout << "\n\n\t\t INSIRA O 1� N�MERO: ";
				cin >> m;

				do 
				{
					cout << "\n\n\t\t INSIRA O 2� N�MERO: ";
					cin >> n;

					if(n < m)
					{
						SetConsoleTextAttribute(color, 14); // letra amarela
						cout << "\n\t\tO 2� N�MERO DEVE SER MAIOR QUE O 1�!" << endl;
						SetConsoleTextAttribute(color, 15); // letra branca

						Sleep(3000);

						system("cls");
					}
				} while (n < m);
				

				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t S(" << m << ", " << n << "): ";

				SetConsoleTextAttribute(color, 14); // letra amarela
				cout << s1(m, n) << endl;

				Sleep(3500);

				break;

			case 5:

				cout << "\n\n\t\t INSIRA O 1� N�MERO: ";
				cin >> m;

				do
				{
					cout << "\n\n\t\t INSIRA O 2� N�MERO: ";
					cin >> n;

					if (n < m)
					{
						SetConsoleTextAttribute(color, 14); // letra amarela
						cout << "\n\t\tO 2� N�MERO DEVE SER MAIOR QUE O 1�!" << endl;
						SetConsoleTextAttribute(color, 15); // letra branca

						Sleep(3000);

						system("cls");
					}
				} while (n < m);

				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t S2(" << m << ", " << n << "): ";

				SetConsoleTextAttribute(color, 14); // letra amarela
				cout << s2(m, n) << endl;

				Sleep(3500);

				break;

			case 6:

				cout << "\n\n\t\t INSIRA O N�MERO: ";
				cin >> n;

				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t DIG(" << n << "): ";

				SetConsoleTextAttribute(color, 14); // letra amarela
				cout << dig(n) << endl;

				Sleep(3500);

				break;

			case 7:

				cout << "\n\n\t\t INSIRA A BASE: ";
				cin >> m;

				cout << "\n\n\t\t INSIRA A POT�NCIA: ";
				cin >> n;

				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t POT(" << m << ", " << n << "): ";

				SetConsoleTextAttribute(color, 14); // letra amarela 
				cout << pot(m, n) << endl;

				Sleep(3500);

				break;

			case 9:

				system("cls"); // limpa tela

				SetConsoleTextAttribute(color, 10); // letra verde

				cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

				SetConsoleTextAttribute(color, 15); // letra branca

				exit(0); // finalizador

			default:

				SetConsoleTextAttribute(color, 12); // letra vermelha

				cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
				cout << "\n\t\t  OP��O INV�LIDA!!!" << endl;

				Sleep(2000); // delay
		}
	}
	return 0;
}
