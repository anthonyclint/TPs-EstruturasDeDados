// ANTHONY CLINT PASTORELLO R.A.: 0050482011005   - TP 08 TABELA HASHING.

#include <iostream>
#include<Windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include "hashing.h"

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int menu() // fun��o do menu
{
   int op; // vari�vel da op��o do usu�rio

   system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### TABELA HASHING ####\n" << endl;
	cout << "\t\t 1 - INSERIR N�MERO" << endl;
	cout << "\t\t 2 - EXCLUIR ELEMENTO" << endl;
	cout << "\t\t 3 - BUSCAR ELEMENTO" << endl;
	cout << "\t\t 4 - EXIBIR A TABELA" << endl;
	cout << "\t\t 9 - ENCERRAR PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OP��O: ";
	cin >> op;

   return op; // retornando a op��o para a main
}

int main()
{
    Hash h;
    int num;
    Node *aux;
    setlocale(LC_ALL,"portuguese");

    for(;;)
    {
        switch(menu())
        {
            case 1:

                cout << "\n\t\t INFORME O N�: ";
                cin >> num;

                h.insere(num);

                SetConsoleTextAttribute(color, 10); // letra verde
                cout << "\n\n\t\t INSERIDO COM SUCESSO!!!\n\n\n\t\t";
                SetConsoleTextAttribute(color, 15); // letra branca

                system("pause");

                break;

            case 2:

                    cout << "\n\t\t INFORME O N�: ";
                    cin >> num;

                    if (h.listavazia(h.fht(num)))
			           {
				            SetConsoleTextAttribute(color, 14); // letra amarela
                        cout << "\n\n\t\t ESSE N�MERO N�O EXISTE NA LISTA!!!" << endl;
			           }
                    else if (h.remove(num))
			           {
				            SetConsoleTextAttribute(color, 10); // letra verde
				            cout << "\n\n\t\t VALOR REMOVIDO COM SUCESSO!!!" << endl;
			           }
			           else
			           {
				            SetConsoleTextAttribute(color, 14); // letra amarela
				            cout << "\n\n\t\t ESSE N�MERO N�O EXISTE NA LISTA!!!" << endl;
			           }

			           Sleep(2000); // delay

                break;

            case 3:

                    cout << "\n\t\t INFORME O N�: ";
                    cin >> num;

                    if (h.busca(num)>0)
			           {
				            SetConsoleTextAttribute(color, 10);
				            cout << "\n\n\t\t O N�MERO " << num << " � O " << h.busca(num) << "� VALOR DA LISTA h[" << h.fht(num) << "] !!!\n\n\n\t\t ";
				            SetConsoleTextAttribute(color, 15);

				            system("pause");
			           }
			           else
			           {
				            SetConsoleTextAttribute(color, 14); // letra amarela
				            cout << "\n\n\t\t ESSE N�MERO N�O EXISTE NA LISTA!!!" << endl;
				            Sleep(3000);
			           }

                break;

            case 4:

                for (int i = 0; i < w; i++)
			       {
				        aux = h.h[i];

				        cout << "\n\t\t h[" << i << "]->";

                    if (h.listavazia(i))
				        {
					         SetConsoleTextAttribute(color, 14); // letra amarela
					         cout << " TABELA VAZIA!!!";
				        }
				        else
                    {
					         while (aux != NULL)
					         {
						          cout << aux->info << "->";
						          aux = aux->prox;
					         }
				        }

				        SetConsoleTextAttribute(color, 15);
			       }

                cout << "\n\n\t\t ";

			       system("pause");

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
