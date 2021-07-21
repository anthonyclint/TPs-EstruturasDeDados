// ANTHONY CLINT PASTORELLO R.A.: 0050482011005  - TP 03 FILA

#include<iostream>
#include<Windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include "filarello.h"
#include<iomanip>

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

void mensagem(int x)
{
	SetConsoleTextAttribute(color, 14); // letra amarela

	if (x == 1)
	{
		cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\t\t    FILA CHEIA!!!" << endl;
	}
	else if (x == 2)
	{
		SetConsoleTextAttribute(color, 10); // letra verde

		cout << "\n\n\t\t INSERIDO NA FILA COM SUCESSO!!!" << endl;
	}
	else if (x == 3)
	{
		cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\t\t    FILA VAZIA!!!" << endl;
	}
	else
	{
		SetConsoleTextAttribute(color, 10); // letra verde

		cout << "\n\n\t\t RETIRADO DA FILA COM SUCESSO!!!" << endl;
	}

	Sleep(2500); // delay
}

int menu()
{
	int op; // variável das opções do menu

	system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### FILA DE ATENDIMENTO ####\n" << endl;
	cout << "\t\t 1 - ENTRAR NA FILA" << endl;
	cout << "\t\t 2 - SAIR DA FILA" << endl;
	cout << "\t\t 3 - EXIBIR PRIMEIRO DA FILA" << endl;
	cout << "\t\t 4 - EXIBIR A FILA" << endl;
	cout << "\t\t 5 - ENCERRAR O PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OPÇÃO: ";
	cin >> op;

	return op; // retornando o valor de op para que seja recebido na switch
}

void main()
{
	setlocale(LC_ALL, "portuguese");

	unsigned tamanho, senha=1;

	SetConsoleTextAttribute(color, 14); // letra amarela

	cout << "\n\n\t\tINFORME O TAMANHO DA FILA: ";
	cin >> tamanho;

	Fila<unsigned> w(tamanho); // enviando 'tamanho' para a header: filarello.h
	
	for(;;) // loop infinito
	{
		switch(menu())
		{
			case 1: 

				if (w.fulline()) // se fullist for true
				{
					mensagem(1); // FILA CHEIA
				}
				else
				{
					w.put(senha); // chamando função e enviando parâmetro 'senha'

					senha++; // incrementando 

					mensagem(2); // INSERIDO COM SUCESSO
				}

				break;

			case 2: 

				if(w.emptyline()) // se emptyline for true
				{
					mensagem(3); // FILA VAZIA
				}
				else
				{
					SetConsoleTextAttribute(color, 11); // letra ciano

					cout << "\n\t\t  _______________";
					cout << "\n\t\t |               |";
					cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << w.takeout() << " |"; // setw(6) reservando 6 espaços e setfill('0') define que o espaços vazios serão preenchidos por 0
					cout << "\n\t\t |_______________|";

					cout << "\n";

					mensagem(4); // RETIRADO COM SUCESSO
				}

				break;

			case 3:

				if (w.emptyline()) // se emptyline for true
				{
					mensagem(3); // FILA VAZIA
				}
				else
				{
					SetConsoleTextAttribute(color, 11); // letra ciano

					cout << "\n\t\t  _______________";
					cout << "\n\t\t |               |";
					cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << w.first() << " |"; // setw(6) reservando 6 espaços e setfill('0') define que o espaços vazios serão preenchidos por 0
					cout << "\n\t\t |_______________|";

					cout << "\n\n\n\t\t"; 

					SetConsoleTextAttribute(color, 15); // letra branca

					system("pause");
				}

				break;

			case 4:

				if (w.emptyline()) // se emptyline for true
				{
					mensagem(3); // FILA VAZIA
				}
				else
				{
					SetConsoleTextAttribute(color, 11); // letra ciano

					cout << "\n\t\t  _______________";

					if(w.getBegin() > w.getEnd())
					{
						for(int i = w.getBegin(); i < w.getSize(); i++)
						{
							cout << "\n\t\t |               |";
							cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << w.getVal(i) << " |"; 
							cout << "\n\t\t |_______________|";
						}

						for(int i = 0; i <= w.getEnd(); i++)
						{
							cout << "\n\t\t |               |";
							cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << w.getVal(i) << " |";
							cout << "\n\t\t |_______________|";
						}
					}
					else
					{
						for (int i = w.getBegin(); i <= w.getEnd(); i++)
						{
							cout << "\n\t\t |               |";
							cout << "\n\t\t | SENHA: " << setw(6) << setfill('0') << w.getVal(i) << " |";
							cout << "\n\t\t |_______________|";
						}
					}

					cout << "\n\n\n\t\t";

					SetConsoleTextAttribute(color, 15); // letra branca

					system("pause");
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
}