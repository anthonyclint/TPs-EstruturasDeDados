
// ANTHONY CLINT PASTORELLO R.A.: 0050482011005 - TP 01 - TEATRO - RESERVA DE POLTRONAS

#include<iostream>
#include<locale.h> // para utilizar o setlocale
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h> // para utilizar o HANDLE color
#include"tonyteatro.h" //incluindo o header

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

void load(int op)
{
	system("cls");

	SetConsoleTextAttribute(color, 14); // letra amarela

	if(op == 1)
	{
		cout << "\n\n\n\t\t  >>>> AGUARDE <<<<" << endl;
		cout << "\n\n\n\t\tRESERVANDO A POLTRONA...\n\n" << endl;
	}
	else if(op == 2)
	{
		cout << "\n\n\n\t\t  >>>> AGUARDE <<<<" << endl;
		cout << "\n\n\n\t\tTROCANDO AS POLTRONAS...\n\n" << endl;
	}
	else
	{
		cout << "\n\n\n\t\t  >>>> AGUARDE <<<<" << endl;
		cout << "\n\n\n\t\t CANCELANDO A RESERVA...\n\n" << endl;
	}

	Sleep(2300); // delay
}

void erro(int w)
{
	SetConsoleTextAttribute(color, 14); // letra amarela

	if(w == 1)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\n\t\t  NÃO HÁ POLTRONAS LIVRES PARA COMPRA!\n\n" << endl;
	}
	else if(w == 2)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\n\t\t    NENHUMA POLTRONA FOI COMPRADA,\n\t\t\t  IMPOSSÍVEL TROCAR!\n\n" << endl;
	}
	else if(w == 3)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\n\t\t  NÃO HÁ POLTRONAS LIVRES PARA TROCAS!\n\n" << endl;
	}
	else if(w == 4)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\n\t\t    NENHUMA POLTRONA FOI COMPRADA,\n\t\t     IMPOSSÍVEL CANCELAR COMPRA!\n\n" << endl;
	}
	else if(w == 5)
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\t\t\t POLTRONA OCUPADA!" << endl;
		cout << "\n\t\t\tOPERAÇÃO CANCELADA!!!";
	}
	else
	{
		cout << "\n\n\n\t\t\t  >>>> ATENÇÃO <<<<" << endl;
		cout << "\n\t\t\t  POLTRONA VAZIA!!!" << endl;
		cout << "\n\t\t\tOPERAÇÃO CANCELADA!!!";
	}

	Sleep(4000); // delay
}

int main()
{
	setlocale(LC_ALL, "portuguese");

	int linha = 4, coluna = 5, r1, r2, r3, r4, op, z;

	Poltronas<int> a(linha, coluna); // matriz 4x5

	for(;;) // loop infinito
	{
		system("cls");
		system("color 02"); //fundo preto e letra verde

		cout << "\n\t\t     ____________________    \n";
		cout << "\t\t    |                    |    \n";
		cout << "\t\t    |    TONY  TEATRO    |    \n";
		cout << "\t\t    |____________________|    \n";

		cout << "\n\n\t\t     1 - COMPRAR INGRESSO\n";
		cout << "\t\t     2 - TROCAR POLTRONA\n";
		cout << "\t\t     3 - CANCELAR RESERVA\n";
		cout << "\t\t     4 - SAIR\n";
		
		cout << "\n\n\t\t    POLTRONAS DISPONÍVEIS: " << a.getD() << endl;

		cout << "\n\t\t       SELECIONE A OPÇÃO: ";
		cin >> op;

		system("cls");

		if(op == 1 || op == 2 || op == 3)
		{
			cout << "\n\t\t             C O L U N A" << endl;
			cout << "\n\t\t      0     1     2     3     4";
			cout << "\n\t\t" << "    _____________________________";

			for (int i = 0; i < linha; i++)
			{
				cout << "\n\t\t" << "   |     |     |     |     |     |";
				cout << "\n\t\t" << i << "  |  ";

				for (int j = 0; j < coluna; j++)
				{
					cout << (char)a.getVal(i, j) << "  |  ";

					if (j == coluna - 1)
					{
						if (i == 1)
						{
							cout << "\n" << "    L I N H A      |_____|_____|_____|_____|_____| ";
						}
						else
						{
							cout << "\n\t\t" << "   |_____|_____|_____|_____|_____| ";
						}
					}
				}
			}

			cout << "\n\n\n\t\t        X -> POLTRONA OCUPADA" << endl;
		}

		z = a.getD(); // atribuindo o ponteiro e função do header para a variável z

		switch(op)
		{
			case 1:
				if(z == 0)
				{
					erro(1); // mensagem de erro da opção 1
				}
				else
				{
					cout << "\n\n\t\tInsira a poltrona desejada: " << endl;

					do
					{
						cout << "\n\t\tL: ";
						cin >> r1; //recebendo a fileira
					} while (r1 < 0 || r1 > 3);

					do
					{
						cout << "\t\tC: ";
						cin >> r2; //recebendo a coluna
					} while (r2 < 0 || r2 > 4);

					if ((char)a.getVal(r1, r2) == 'X')
					{
						erro(5); // POLTRONA OCUPADA
					}
					else
					{
						a.buy(r1, r2); //chamando função pelo ponteiro e enviando parâmetros

						load(op); //chamando função e enviando parâmetro
					}
				}

				break;

			case 2:
				if(z == 20)
				{
					erro(2); // mensagem de erro da opção 2 caso teatro esteja vazio
				}
				else if(z == 0)
				{
					erro(3); // mensagem de erro da opção 2 caso teatro esteja lotado
				}
				else
				{
					cout << "\n\n\t\tInsira a poltrona a ser trocada: " << endl;

					do
					{
						cout << "\n\t\tL: ";
						cin >> r1; //recebendo a fileira
					} while (r1 < 0 || r1 > 3);

					do
					{
						cout << "\t\tC: ";
						cin >> r2; //recebendo a coluna
					} while (r2 < 0 || r2 > 4);

					if ((char)a.getVal(r1, r2) == '-')
					{
						erro(6); // POLTRONA VAZIA
					}
					else
					{
						cout << "\n\n\t\tInsira a poltrona desejada: " << endl;

						do
						{
							cout << "\n\t\tL: ";
							cin >> r3; //recebendo a fileira
						} while (r3 < 0 || r3 > 3);

						do
						{
							cout << "\t\tC: ";
							cin >> r4; //recebendo a coluna
						} while (r4 < 0 || r4 > 4);

						if ((char)a.getVal(r3, r4) == 'X')
						{
							erro(5); // POLTRONA OCUPADA
						}
						else 
						{
							a.change(r1, r2, r3, r4); //chamando função pelo ponteiro e enviando parâmetros

							load(op); //chamando função e enviando parâmetro
						}
					}
				}

				break;

			case 3:
				if(z == 20)
				{
					erro(4); // mensagem de erro da opção 3
				}
				else
				{
					cout << "\n\n\t\tInsira a poltrona reservada: " << endl;

					do
					{
						cout << "\n\t\tL: ";
						cin >> r1; //recebendo a fileira
					} while (r1 < 0 || r1 > 3);

					do
					{
						cout << "\t\tC: ";
						cin >> r2; //recebendo a coluna
					} while (r2 < 0 || r2 > 4);

					if ((char)a.getVal(r1, r2) == '-')
					{
						erro(6); // POLTRONA VAZIA
					}
					else
					{
						a.cancel(r1, r2); //chamando função pelo ponteiro e enviando parâmetros

						load(op); //chamando função e enviando parâmetro
					}
				}

				break;

			case 4:
				cout << "\n\n\n\t\t     PROGRAMA FINALIZADO\n\n" << endl;

				exit(0);

				break;

			default:
				system("color 0F"); // fundo preto e letra branca
				cout << "\n\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				cout << "\n\n\n\t\t  OPÇÃO INVÁLIDA!!!" << endl;
				Sleep(2000); //delay 
		}
	}

	return 0;
}