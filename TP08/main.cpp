/*
   ANTHONY CLINT PASTORELLO R.A.: 0050482011005  - TP 08 LISTA ORDENADA - ESTRUTURA DE DADOS

   Construa uma aplicação para uma Lista Ordenada de números inteiros que permita ao
   usuário, a partir de um menu, executar as seguintes tarefas:
   1-inserir um novo número
   2-realizar a busca de um elemento
   3-excluir um elemento
   4-exibir a lista
   9-fim
*/


#include <iostream>
#include<Windows.h>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include "lista_ordenada.h"

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int menu() // função do menu
{
   int op; // variável da opção do usuário

   system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### LISTA ORDENADA ####\n" << endl;
	cout << "\t\t 1 - INSERIR NÚMERO" << endl;
	cout << "\t\t 2 - BUSCAR ELEMENTO" << endl;
	cout << "\t\t 3 - EXCLUIR ELEMENTO" << endl;
	cout << "\t\t 4 - EXIBIR A LISTA" << endl;
	cout << "\t\t 9 - ENCERRAR PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OPÇÃO: ";
	cin >> op;

   return op; // retornando a opção para a main
}

int main()
{
    int num;
    ListaOrdenada<int> lista;
    setlocale(LC_ALL,"portuguese");

    for(;;)
    {
       switch(menu())
       {
          case 1:

             cout << "\n\t\t INFORME O Nº: ";
             cin >> num;

             lista.insere(num);

             SetConsoleTextAttribute(color, 10); // letra verde
             cout << "\n\n\t\t INSERIDO COM SUCESSO!!!\n\n\n\t\t";
             SetConsoleTextAttribute(color, 15); // letra branca

             system("pause");

             break;

          case 2:

             if(lista.listaVazia()) // se retornar NULL
             {
                SetConsoleTextAttribute(color, 14); // letra amarela
				    cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				    cout << "\n\t\t   LISTA VAZIA!!!" << endl;
				    Sleep(2000); // delay
             }
             else
             {

                cout << "\n\t\t INFORME O Nº: ";
                cin >> num;

                int y;
                y = lista.buscaElem(num);

                if(y == -1)
                {
                    SetConsoleTextAttribute(color, 14); // letra amarela
				        cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				        cout << "\n\t\tELEMENTO INEXISTENTE!!!" << endl;
				        Sleep(2000); // delay
                }
                else
                {
                    SetConsoleTextAttribute(color, 11); // letra ciano
                    cout << "\n\n\t\t Elemento encontrado no índice: ";
                    SetConsoleTextAttribute(color, 14); // letra amarela
                    cout << y << ".";
                    SetConsoleTextAttribute(color, 15); // letra branca
                    cout << "\n\n\n\t\t";
                    system("pause");
                }
             }

             break;

          case 3:

             if(lista.listaVazia()) // se retornar NULL
             {
                SetConsoleTextAttribute(color, 14); // letra amarela
				    cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				    cout << "\n\t\t   LISTA VAZIA!!!" << endl;
				    Sleep(2000); // delay
             }
             else
             {

                cout << "\n\t\t INFORME O Nº: ";
                cin >> num;

                if(lista.remover(num)) // se remover retornar 1
                {
                    SetConsoleTextAttribute(color, 10); // letra verde
                    cout << "\n\n\t\t REMOVIDO COM SUCESSO!!!\n\n\n\t\t";
                    SetConsoleTextAttribute(color, 15); // letra branca
                    Sleep(2000); // delay
                }
                else // se retornar 0
                {
                    SetConsoleTextAttribute(color, 14); // letra amarela
				        cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				        cout << "\n\t\tELEMENTO INEXISTENTE!!!" << endl;
				        SetConsoleTextAttribute(color, 15); // letra branca
				        Sleep(2000); // delay
                }
             }

             break;

         case 4:

             if(lista.listaVazia()) // se retornar NULL
             {
                SetConsoleTextAttribute(color, 14); // letra amarela
				    cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				    cout << "\n\t\t   LISTA VAZIA!!!" << endl;
				    Sleep(2000); // delay
             }
             else
             {
                SetConsoleTextAttribute(color, 11); // letra ciano
                cout << "\n\n\t\t LISTA ORDENADA: ";
                SetConsoleTextAttribute(color, 14); // letra amarela

                Node<int> *aux=lista.h;
                while (aux != NULL)
                {
                    cout << aux->info << " ";
                    aux = aux->prox;
                }

                SetConsoleTextAttribute(color, 15); // letra branca
                cout << "\n\n\n\t\t";
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
