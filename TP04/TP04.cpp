// ANTHONY CLINT PASTORELLO R.A.: 0050482011005 - TP 04 PILHA LIGADA CARACTERES DE EXPRESSÃO

#include<iostream>
#include<Windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include"pilhaligada.h"
#include<string> // pra função getline
#include<sstream> // pra utilizar .at(i)

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);


int menu()
{
	int op; // variável das opções do menu

	system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### VERIFICADOR DE EXPRESSÕES MATEMÁTICAS ####\n" << endl;
	cout << "\t\t 1 - INSERIR EXPRESSÃO" << endl;
	cout << "\t\t 5 - ENCERRAR O PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OPÇÃO: ";
	cin >> op;

	cin.ignore(); // igual getchar

	return op; // retornando o valor de op para que seja recebido na switch
}

int main()
{
	setlocale(LC_ALL, "portuguese");

	Pilha<char> p; 

	string expr; // String para a expressão

	char c; // variável para comparação dos caracteres ( { [ ] } )
	char s;

	int cont; // contador

	bool verify;


	for(;;) // loop infinito
	{
		switch(menu()) // chamando o menu
		{
			case 1:

				cout << "\n\n\t\t INSIRA A EXPRESSÃO A SER VERIFICADA: ";
				getline(cin, expr);
				//cin >> expr; // recebendo a string

				verify = true;

				cont = 0;

				for(int i = 0; i < expr.length(); i++)
				{
					if(expr.at(i) == '(' || expr.at(i) == '[' || expr.at(i) == '{') //  se o índice analisado for um dos caracteres
					{
						p.empilha(expr.at(i)); // então empilha

						cont++;
					}
					if(expr.at(i) == ')' || expr.at(i) == ']' || expr.at(i) == '}') // se o índice analisado for um dos caracteres
					{
						if(p.pilhavazia()) // verifica se a pilha está vazia
						{
							verify = false;
						}
						else
						{
							c = p.elementotopo(); // torna a variável c o elemento do topo da pilha

							if(c == '(' && expr.at(i) != ')' || c == '[' && expr.at(i) != ']' || c == '{' && expr.at(i) != '}') // se a variável c for igual ao índice analisado
							{
								verify = false; // então é falso
							}
							else // do contrário
							{
								p.desempilha(); // desempilha o caractere
								
								cont--;
							}
						}
					}
				}

				if(verify && p.pilhavazia()) // se a pilha tiver sido totalmente desempilhada
				{
					SetConsoleTextAttribute(color, 10); // letra verde

					cout << "\n\n\t\t EXPRESSÃO VÁLIDA!!!" << endl;

					Sleep(3000);
				}
				else // se não tiver sido desempilhada
				{
					SetConsoleTextAttribute(color, 12); // letra vermelha

					cout << "\n\n\t\t EXPRESSÃO INVÁLIDA!!!" << endl;

					Sleep(3000);
				}

				if (!p.pilhavazia()) 
				{
					for (int i = 0; i < cont; i++) 
					{
						p.desempilha();
					}
				}

				break;

			case 5:

				system("cls"); // limpa tela

				SetConsoleTextAttribute(color, 10); // letra verde

				cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

				SetConsoleTextAttribute(color, 15); // letra branca

				exit(0); // finalizador

				break;

			default:

				SetConsoleTextAttribute(color, 12); // letra vermelha

				cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				cout << "\n\t\t  OPÇÃO INVÁLIDA!!!" << endl;

				Sleep(2000); // delay
		}
	}

	return 0;
}
