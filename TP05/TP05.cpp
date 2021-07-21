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
	int op; // variável das opções do menu

	system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### FUNÇÕES RECURSIVAS ####\n" << endl;
	cout << "\t\t 1 - FATORIAL" << endl;
	cout << "\t\t 2 - FINOBACCI" << endl;
	cout << "\t\t 3 - MDC" << endl;
	cout << "\t\t 4 - SOMA (S)" << endl;
	cout << "\t\t 5 - SOMA (S2)" << endl;
	cout << "\t\t 6 - DÍGITO" << endl;
	cout << "\t\t 7 - POTÊNCIA" << endl;
	cout << "\t\t 9 - ENCERRAR O PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OPÇÃO: ";
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
					cout << "\n\n\t\t INSIRA O NÚMERO: ";
					cin >> n;

					if(n < 0)
					{
						SetConsoleTextAttribute(color, 12); // letra vermelha
						cout << "\n\t\t  VALOR INVÁLIDO!!!" << endl;
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
					cout << "\n\n\t\t INSIRA A POSIÇÃO DESEJADA: ";
					cin >> n;

					if (n < 0)
					{
						SetConsoleTextAttribute(color, 12); // letra vermelha
						cout << "\n\t\t  VALOR INVÁLIDO!!!" << endl;
						SetConsoleTextAttribute(color, 15); // letra branca

						Sleep(3000);

						system("cls");
					}

				} while (n < 0);

				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t POSIÇÃO " << n << " NA SEQUÊNCIA DE FIBONACCI: ";

				SetConsoleTextAttribute(color, 14); // letra amarela 
				cout << fib(n) << endl;

				Sleep(3500);

				break;

			case 3:

				cout << "\n\n\t\t INSIRA O 1º NÚMERO: ";
				cin >> m;

				cout << "\n\n\t\t INSIRA O 2º NÚMERO: ";
				cin >> n;

				SetConsoleTextAttribute(color, 11); // letra ciano
				cout << "\n\n\t\t MDC DE " << m << " E " << n << ": ";

				SetConsoleTextAttribute(color, 14); // letra amarela
				cout << mdc(m, n) << endl;

				Sleep(3500);

				break;

			case 4:

				cout << "\n\n\t\t INSIRA O 1º NÚMERO: ";
				cin >> m;

				do 
				{
					cout << "\n\n\t\t INSIRA O 2º NÚMERO: ";
					cin >> n;

					if(n < m)
					{
						SetConsoleTextAttribute(color, 14); // letra amarela
						cout << "\n\t\tO 2º NÚMERO DEVE SER MAIOR QUE O 1º!" << endl;
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

				cout << "\n\n\t\t INSIRA O 1º NÚMERO: ";
				cin >> m;

				do
				{
					cout << "\n\n\t\t INSIRA O 2º NÚMERO: ";
					cin >> n;

					if (n < m)
					{
						SetConsoleTextAttribute(color, 14); // letra amarela
						cout << "\n\t\tO 2º NÚMERO DEVE SER MAIOR QUE O 1º!" << endl;
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

				cout << "\n\n\t\t INSIRA O NÚMERO: ";
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

				cout << "\n\n\t\t INSIRA A POTÊNCIA: ";
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

				cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				cout << "\n\t\t  OPÇÃO INVÁLIDA!!!" << endl;

				Sleep(2000); // delay
		}
	}
	return 0;
}
