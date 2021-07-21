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
	5.Considerando uma pilha e uma fila, de números inteiros,
	  construa uma aplicação que permita aos usuários as seguintes opções,
	  apresentadas no formato de menu:
	a)	Inserção de dados na fila.
	b)	Exibir a fila
	c)	Remove TODOS os elementos da fila; sendo que a cada remoção,
	    caso seja um número par, insire-o na pilha.
	d)	Exibir a pilha
*/

void mensagem(int x)
{
	if (x == 0)
	{
		SetConsoleTextAttribute(color, 14); // letra amarela

		cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
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

		cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
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

		cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\t\t   PILHA VAZIA!!!" << endl;
	}
	else
	{
		SetConsoleTextAttribute(color, 14); // letra amarela

		cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\t\t   PILHA CHEIA!!!" << endl;
	}

	Sleep(2500); // delay
}

int menu()
{
	int op; // variável das opções do menu

	system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### FILA E PILHA ####\n" << endl;
	cout << "\t\t 1 - INSERIR NÚMERO NA FILA" << endl;
	cout << "\t\t 2 - EXIBIR A FILA" << endl;
	cout << "\t\t 3 - REMOVER ELEMENTOS DA FILA" << endl;
	cout << "\t\t 4 - EXIBIR A PILHA" << endl;
	cout << "\t\t 9 - ENCERRAR O PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OPÇÃO: ";
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
					cout << "\n\n\t\t INSIRA O NÚMERO: ";
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

				cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				cout << "\n\t\t  OPÇÃO INVÁLIDA!!!" << endl;

				Sleep(2000); // delay
		}
	}

	return 0;
}


#endif // ex5

#ifdef ex6
/*
	a)	Construa a estrutura Triângulo com seus atributos a, b, c e a função e área.
	b)	Construa uma aplicação que utilize uma pilha e apresente um menu permitindo
	    ao usuário as opções de  inserir, remover  triângulos na pilha e, também
		exibir  os lados e a área de cada triângulo pertencente à pilha.
		Observe que somente poderemos inserir o novo triângulo se atender à condição de existência.
*/



int menu()
{
	int op; // variável das opções do menu

	system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### PILHA DE TRIÂNGULOS ####\n" << endl;
	cout << "\t\t 1 - INSERIR TRIÂNGULO" << endl;
	cout << "\t\t 2 - REMOVER TRIÂNGULO" << endl;
	cout << "\t\t 3 - EXIBIR DADOS" << endl;
	cout << "\t\t 9 - ENCERRAR O PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OPÇÃO: ";
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

	p = new Pilha<Tri>(5); // o user pode inserir 5 triângulos na pilha

	Tri t; // variável da struct

	float sp;

	for(;;)
	{
		switch(menu())
		{
			case 1: // INSERIR

				if(p->fullpilha())
				{
					SetConsoleTextAttribute(color, 14); // letra amarela

					cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
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

							cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
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

					cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
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

					cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
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
						cout << "\n\n\t\tTriângulo:\n\n\t\t";
						cout << "LADO A: "<< p->getVal(i).a << endl;
						cout << "\t\t";
						cout << "LADO B: " << p->getVal(i).b << endl;
						cout << "\t\t";
						cout << "LADO C: " << p->getVal(i).c << endl;
						cout << "\t\t";
						cout << "ÁREA: " << p->getVal(i).area << endl;
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

				cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				cout << "\n\t\t  OPÇÃO INVÁLIDA!!!" << endl;

				Sleep(2000); // delay
		}
	}

	return 0;
}
#endif // ex6