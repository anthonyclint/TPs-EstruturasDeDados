// ANTHONY CLINT PASTORELLO R.A.: 0050482011005  - TP 02 PÁTIO DE CONTAINER

#include<iostream>
#include<Windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include"pilhatony.h"

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

void mensagem(int x)
{
	SetConsoleTextAttribute(color, 14); // letra amarela

	if(x == 0)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\n\t\t\t PILHA INEXISTENTE!!!" << endl;
	}
	else if(x == 1)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\n\t\t\t   PILHA CHEIA!!!" << endl;
	}
	else if(x == 2)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\n\t\t TAMANHO DO CONTAINER INCOMPATÍVEL!!!" << endl;
		cout << "\n\n\t\t\t OPERAÇÃO CANCELADA!!!" << endl;
	}
	else if(x == 3)
	{
		SetConsoleTextAttribute(color, 10); // letra verde

		cout << "\n\n\t\t CONTAINER EMPILHADO COM SUCESSO!!!" << endl;
	}
	else if(x == 4)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\n\t\t\t   PILHA VAZIA!!!" << endl;
	}
	else if(x == 5)
	{
		SetConsoleTextAttribute(color, 10); // letra verde

		cout << "\n\n\t\t CONTAINER DESEMPILHADO COM SUCESSO!!!" << endl;
	}
	else
	{
		SetConsoleTextAttribute(color, 10); // letra verde

		cout << "\n\n\t\t CONTAINERS ENCONTRADOS COM SUCESSO!!!" << endl;
	}

	Sleep(4000); // delay
}

struct Container
{
	char cod[6]; // código do container
	unsigned tam; // tamanho do container
	char marca[25]; // marca do fornecedor
};

int main()
{
	int op, np;

	setlocale(LC_ALL, "portuguese");

	Pilha<Container> *p[10]; // quantidade de pilhas
	Container c; // variável da struct

	for(int i = 0; i < 10; i++)
	{
		p[i] = new Pilha<Container>(5); // quantidade de elementos das pilhas
	}

	for(;;) // loop infinito
	{
		system("cls"); // limpa a tela

		SetConsoleTextAttribute(color, 15); // letra branca

		cout << "\n\n\t\t #### PÁTIO DE CONTAINERS ####\n" << endl;
		cout << "\t\t 1 - EMPILHAR CONTAINER" << endl;
		cout << "\t\t 2 - DESEMPILHAR CONTAINER" << endl;
		cout << "\t\t 3 - EXIBIR PILHAS DE CONTAINER" << endl;
		cout << "\t\t 4 - ENCERRAR O PROGRAMA" << endl;
		cout << "\n\n\t\t SELECIONE A OPÇÃO: ";
		cin >> op;

		system("cls"); // limpa tela

		switch(op)
		{
			case 1:

				do 
				{
					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t INSIRA O NÚMERO DA PILHA: ";
					cin >> np; // recebendo o índice do vetor

					if (np < 0 || np > 9) // se o índice estiver fora do intervalo
					{
						mensagem(0); // PILHA INEXISTENTE

						system("cls"); // limpa tela
					}

				} while (np < 0 || np > 9);

				if (p[np]->fullpilha()) // se fullpilha for true
				{
					mensagem(1); // PILHA CHEIA
				}
				else
				{
					cout << "\n\n\t\t INSIRA O CÓDIGO DO CONTAINER: ";
					cin >> c.cod;
					cout << "\n\n\t\t INSIRA O TAMANHO DO CONTAINER (FT): ";
					cin >> c.tam;
					cout << "\n\n\t\t INSIRA O FORNECEDOR DO CONTAINER: ";
					cin >> c.marca;

					if(p[np]->emptypilha() != true && p[np]->elementodotopo().tam != c.tam) // se a pilha não estiver vazia e o container do topo não for do mesmo tamanho do anterior
					{
						mensagem(2); // TAMANHO INCOMPATÍVEL
					}
					else
					{

						p[np]->empilha(c);

						mensagem(3); // CONTAINER EMPILHADO																					
					}
				}
				break;

			case 2:

				do
				{
					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t INSIRA O NÚMERO DA PILHA: ";
					cin >> np; // recebendo o índice do vetor

					if (np < 0 || np > 9) // se o índice estiver fora do intervalo
					{
						mensagem(0); // PILHA INEXISTENTE

						system("cls"); // limpa a tela
					}

				} while (np < 0 || np > 9);

				if (p[np]->emptypilha())
				{
					mensagem(4); // PILHA VAZIA									
				}
				else
				{
					system("cls"); // limpa tela

					cout << "\n\n\t\t  _____________________________________________________";
					cout << "\n\t\t |       |        |         |                          |";
					cout << "\n\t\t | PILHA | CÓDIGO | TAMANHO |        FORNECEDOR        |";
					cout << "\n\t\t |_______|________|_________|__________________________|";
					cout << "\n\t\t |       |        |         |                          |";
					cout << "\n\t\t |   " << np << "   |  ";
					cout.width(5);
					cout.setf(ios::left, ios::adjustfield);
					cout << p[np]->getVal(p[np]->getTopo()).cod << " |  ";
					cout.width(2);
					cout.setf(ios::left, ios::adjustfield);
					cout << p[np]->getVal(p[np]->getTopo()).tam << " FT  | ";
					cout.width(25);
					cout.setf(ios::left, ios::adjustfield);
					cout << p[np]->desempilha().marca << "|";
					cout << "\n\t\t |_______|________|_________|__________________________|" << endl;

					cout << "\n";

					mensagem(5); // CONTAINER DESEMPILHADO									
				}
				break;

			case 3:

				do
				{
					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t INSIRA O NÚMERO DA PILHA: ";
					cin >> np; // recebendo o índice do vetor

					if (np < 0 || np > 9) // se o índice estiver fora do intervalo
					{
						mensagem(0); // PILHA INEXISTENTE

						system("cls"); // limpa a tela
					}

				} while (np < 0 || np > 9);

				if (p[np]->emptypilha()) // se emptypilha for true
				{
					mensagem(4); // PILHA VAZIA					
				}
				else
				{
					system("cls"); // limpa a tela

					cout << "\n\n\t\t PILHA: " << np << endl;;
					cout << "\n\n\t\t CONTAINERS: " << p[np]->getTopo() + 1;
					cout << "\n\n\t\t  _____________________________________________";
					cout << "\n\t\t |        |         |                          |";
					cout << "\n\t\t | CÓDIGO | TAMANHO |        FORNECEDOR        |";
					cout << "\n\t\t |________|_________|__________________________|";

					for (int i = p[np]->getTopo(); i >= 0; i--)
					{
						cout << "\n\t\t |        |         |                          |";
						cout << "\n\t\t |  ";
						cout.width(5);
						cout.setf(ios::left, ios::adjustfield);
						cout << p[np]->getVal(i).cod << " |  ";
						cout.width(2);
						cout.setf(ios::left, ios::adjustfield);
						cout << p[np]->getVal(i).tam << " FT  | ";
						cout.width(25);
						cout.setf(ios::left, ios::adjustfield);
						cout << p[np]->getVal(i).marca << "|";
						cout << "\n\t\t |________|_________|__________________________|";
					}

					cout << "\n\n"; // espaçamento

					mensagem(6); // CONTAINER ENCONTRADO

					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t"; // espaçamento para a frase do system(pause)

					system("pause"); // pausa
				}
				break;

			case 4:

				system("cls"); // limpa a tela

				SetConsoleTextAttribute(color, 15); // letra branca

				cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

				exit(0); // finalizador

				break;

			default:
				
				SetConsoleTextAttribute(color, 14); // letra amarela

				cout << "\n\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				cout << "\n\n\n\t\t  OPÇÃO INVÁLIDA!!!" << endl;

				Sleep(2000); // delay 
		}
	}

	return 0;
}