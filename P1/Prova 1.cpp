// Anthony Clint Pastorello R.A.: 0050482011005 - PROVA P1 - 30/04/2021

#include<iostream>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include"pilha.h"
#include"fila.h"

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

#define ex6

#ifdef ex5
/*
	5.Considerando uma pilha e uma fila, de n�meros inteiros,
	  construa uma aplica��o que permita aos usu�rios as seguintes op��es,
	  apresentadas no formato de menu:
	a)	Inser��o de dados na fila.
	b)	Exibir a fila
	c)	Remove TODOS os elementos da fila; sendo que a cada remo��o,
	    caso seja um n�mero par, insire-o na pilha.
	d)	Exibir a pilha
*/

void mensagem(int x)
{
	if (x == 0)
	{
		SetConsoleTextAttribute(color, 14); // letra amarela

		cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
		cout << "\n\t\t    FILA CHEIA!!!" << endl;
	}
	else if (x == 1)
	{
		SetConsoleTextAttribute(color, 10); // letra verde

		cout << "\n\n\t\t INSERIDO NA FILA COM SUCESSO!!!" << endl;
	}
	else if (x == 2)
	{
		SetConsoleTextAttribute(color, 14); // letra amarela

		cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
		cout << "\n\t\t    FILA VAZIA!!!" << endl;
	}
	else if(x == 3)
	{
		SetConsoleTextAttribute(color, 10); // letra verde

		cout << "\n\n\t\t RETIRADO DA FILA COM SUCESSO!!!" << endl;
	}
	else if(x == 4)
	{
		SetConsoleTextAttribute(color, 14); // letra amarela

		cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
		cout << "\n\t\t   PILHA VAZIA!!!" << endl;
	}
	else
	{
		SetConsoleTextAttribute(color, 14); // letra amarela

		cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
		cout << "\n\t\t   PILHA CHEIA!!!" << endl;
	}

	Sleep(2500); // delay
}

int menu()
{
	int op; // vari�vel das op��es do menu

	system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### FILA E PILHA ####\n" << endl;
	cout << "\t\t 1 - INSERIR N�MERO NA FILA" << endl;
	cout << "\t\t 2 - EXIBIR A FILA" << endl;
	cout << "\t\t 3 - REMOVER ELEMENTOS DA FILA" << endl;
	cout << "\t\t 4 - EXIBIR A PILHA" << endl;
	cout << "\t\t 9 - ENCERRAR O PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OP��O: ";
	cin >> op;

	return op; 
}


int main()
{
	setlocale(LC_ALL, "portuguese");

	Pilha<int> p(10);
	Fila<int> f(10);
	int num; // elemento da fila dado pelo user


	for(;;)
	{	
		switch(menu())
		{
			case 1: // INSERIR NA FILA

				if (f.fullist()) // se retornar true
				{
					mensagem(0); // FILA CHEIA!
				}
				else
				{
					cout << "\n\n\t\t INSIRA O N�MERO: ";
					cin >> num;

					f.put(num); // inserindo na fila

					mensagem(1); // INSERIDO COM SUCESSO!
				}

				break;

			case 2: // EXIBIR A FILA

				if (f.emptylist()) // se retornar true 
				{
					mensagem(2); // FILA VAZIA!
				}
				else 
				{
					SetConsoleTextAttribute(color, 11); // letra ciano

					cout << "\n\n\t\t";

					if (f.getBegin() > f.getEnd())
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

					cout << "\n\n\t\t";

					SetConsoleTextAttribute(color, 15); // letra branca

					system("pause");
				}

				break;

			case 3: // REMOVER DA FILA

				if (f.emptylist()) // se retornar true 
				{
					mensagem(2); // FILA VAZIA!
				}
				else 
				{
					while(!f.emptylist())
					{
						int aux;
						aux = f.takeout();

						if (aux % 2 == 0 && aux != 0)
						{
							if(p.fullpilha())
							{
								mensagem(5); // PILHA CHEIA!
							}
							else
							{
								p.empilha(aux);
							}
							
						}
					}

					mensagem(3); // RETIRADO COM SUCESSO!
				}

				break;

			case 4: // EXIBIR PILHA

				if (p.emptypilha()) // se retornar true
				{
					mensagem(4); // PILHA VAZIA!
				}
				else
				{
					SetConsoleTextAttribute(color, 11); // letra ciano

					cout << "\n\n\t\t";

					for (int i = p.getTopo(); i >= 0; i--)
					{
						cout << p.getVal(i) << " ";
					}
					
					cout << "\n\n\t\t";

					SetConsoleTextAttribute(color, 15); // letra branca

					system("pause");
				}

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


#endif // ex5

#ifdef ex6
/*
	a)	Construa a estrutura Tri�ngulo com seus atributos a, b, c e a fun��o e �rea.
	b)	Construa uma aplica��o que utilize uma pilha e apresente um menu permitindo
	    ao usu�rio as op��es de  inserir, remover  tri�ngulos na pilha e, tamb�m
		exibir  os lados e a �rea de cada tri�ngulo pertencente � pilha.
		Observe que somente poderemos inserir o novo tri�ngulo se atender � condi��o de exist�ncia.
*/



int menu()
{
	int op; // vari�vel das op��es do menu

	system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### PILHA DE TRI�NGULOS ####\n" << endl;
	cout << "\t\t 1 - INSERIR TRI�NGULO" << endl;
	cout << "\t\t 2 - REMOVER TRI�NGULO" << endl;
	cout << "\t\t 3 - EXIBIR DADOS" << endl;
	cout << "\t\t 9 - ENCERRAR O PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OP��O: ";
	cin >> op;

	return op;
}

struct Tri
{
	int a;
	int b;
	int c;
	float area;
};

int main()
{
	setlocale(LC_ALL, "portuguese");

	Pilha<Tri>* p;

	p = new Pilha<Tri>(5); // o user pode inserir 5 tri�ngulos na pilha

	Tri t; // vari�vel da struct

	float sp;

	for(;;)
	{
		switch(menu())
		{
			case 1: // INSERIR

				if(p->fullpilha())
				{
					SetConsoleTextAttribute(color, 14); // letra amarela

					cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
					cout << "\n\t\t    PILHA CHEIA!!!" << endl;

					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t";

					system("pause");
				}
				else
				{
					do
					{
						system("cls"); // limpa a tela

						cout << "\n\n\t\t INSIRA O LADO A: ";
						cin >> t.a;

						cout << "\n\n\t\t INSIRA O LADO B: ";
						cin >> t.b;

						cout << "\n\n\t\t INSIRA O LADO C: ";
						cin >> t.c;

						if(((t.b + t.c) < t.a) || ((t.a + t.c) < t.b) || ((t.a + t.b) < t.c))
						{
							SetConsoleTextAttribute(color, 14); // letra amarela

							cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
							cout << "\n\t\tTODOS OS LADOS DEVEM SER MENORES QUE A SOMA DOS DEMAIS!" << endl;

							SetConsoleTextAttribute(color, 15); // letra branca

							cout << "\n\n\t\t";

							system("pause");
						}

					} while (((t.b + t.c)<t.a) || ((t.a + t.c) < t.b) || ((t.a + t.b) < t.c));

					sp = (t.a + t.b + t.c) / 2;

					t.area = sqrt(sp * (sp - t.a) * (sp - t.b) * (sp - t.c));

					p->empilha(t);	
					
				}

				break;

			case 2: // REMOVER

				if (p->emptypilha())
				{
					SetConsoleTextAttribute(color, 14); // letra amarela

					cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
					cout << "\n\t\t    PILHA VAZIA!!!" << endl;

					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t";

					system("pause");
				}
				else
				{
					p->desempilha().area;
					
					SetConsoleTextAttribute(color, 10); // letra verde

					cout << "\n\n\t\t RETIRADO COM SUCESSO!!!" << endl;

					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t";

					system("pause");
				}

				break;

			case 3: // EXIBIR

				if (p->emptypilha())
				{
					SetConsoleTextAttribute(color, 14); // letra amarela

					cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
					cout << "\n\t\t    PILHA VAZIA!!!" << endl;

					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t";

					system("pause");
				}
				else
				{
					SetConsoleTextAttribute(color, 14); // letra amarela

					for (int i = p->getTopo(); i >= 0; i--) 
					{
						cout << "\n\n\t\tTri�ngulo:\n\n\t\t";
						cout << "LADO A: "<< p->getVal(i).a << endl;
						cout << "\t\t";
						cout << "LADO B: " << p->getVal(i).b << endl;
						cout << "\t\t";
						cout << "LADO C: " << p->getVal(i).c << endl;
						cout << "\t\t";
						cout << "�REA: " << p->getVal(i).area << endl;
					}
					cout << "\n\n";

					SetConsoleTextAttribute(color, 15); // letra branca

					cout << "\n\n\t\t";

					system("pause");
				}

				break;

			case 9:

				system("cls"); // limpa tela

				SetConsoleTextAttribute(color, 10); // letra verde

				cout << "\n\n\n\n\n\t\t\t>>>>> PROGRAMA FINALIZADO <<<<<\n\n" << endl;

				SetConsoleTextAttribute(color, 15); // letra branca

				exit(0); // finalizador

				break;

			default:

				SetConsoleTextAttribute(color, 12); // letra vermelha

				cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
				cout << "\n\t\t  OP��O INV�LIDA!!!" << endl;

				Sleep(2000); // delay
		}
	}

	return 0;
}
#endif // ex6