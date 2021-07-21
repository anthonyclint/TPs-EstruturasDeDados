/*
   Anthony Clint Pastorello R.A.: 0050482011005 - TP 07 �rvore Bin�ria de Busca

   Construa uma aplica��o para uma �rvore Bin�ria de Busca(BST)
   de n�meros inteiros que permita ao usu�rio, a partir de um
   menu, executar as seguintes tarefas:
   1-inserir um novo n�mero
   2-exibir a �rvore na pr�-ordem
   3-exibir a �rvore n� p�s-ordem
   4-exibir a �rvore n� em ordem
   5-exibir o m�ximo dos n�meros
   6-exibir o m�nimo dos n�meros
   7-excluir um elemento da �rvore
   9-fim

*/


#include <iostream> // para using namespace
#include<Windows.h> // para cores das letras
#include<locale.h> // para o setlocale
#include<stdio.h>
#include<stdlib.h>
#include "tree_search.h" // header da �rvore

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int menu() // fun��o do menu
{
   int op; // vari�vel da op��o do usu�rio

   system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### �RVORE DE BUSCA ####\n" << endl;
	cout << "\t\t 1 - INSERIR NA �RVORE" << endl;
	cout << "\t\t 2 - EXIBIR PR�-ORDEM" << endl;
	cout << "\t\t 3 - EXIBIR P�S-ORDEM" << endl;
	cout << "\t\t 4 - EXIBIR EM ORDEM" << endl;
	cout << "\t\t 5 - EXIBIR O N� M�XIMO" << endl;
	cout << "\t\t 6 - EXIBIR O N� M�NIMO" << endl;
	cout << "\t\t 7 - EXCLUIR ELEMENTO" << endl;
	cout << "\t\t 9 - ENCERRAR PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OP��O: ";
	cin >> op;

   return op; // retornando a op��o para a main
}

int main()
{
   int num;
   Bst<int> t1;

   setlocale(LC_ALL,"portuguese");

   for(;;)
   {
      switch(menu())
      {
         case 1:

            cout << "\n\t\t INFORME O N�: ";
            cin >> num;

            t1.insere(t1.pRaiz,num);

            SetConsoleTextAttribute(color, 10); // letra verde
            cout << "\n\n\t\t INSERIDO COM SUCESSO!!!\n\n\n\t\t";
            SetConsoleTextAttribute(color, 15); // letra branca

            system("pause");

            break;

         case 2:

            if(t1.bstvazia())
            {
               SetConsoleTextAttribute(color, 14); // letra amarela
				   cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
				   cout << "\n\t\t   �RVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << "\n\n\t\t PR�-ORDEM: ";
               SetConsoleTextAttribute(color, 15); // letra branca
               t1.PreOrdem(t1.pRaiz);
               cout << "\n\n\n\t\t";
               system("pause");
            }

            break;

         case 3:
            if(t1.bstvazia())
            {
               SetConsoleTextAttribute(color, 14); // letra amarela
				   cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
				   cout << "\n\t\t   �RVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << "\n\n\t\t P�S-ORDEM: ";
               SetConsoleTextAttribute(color, 15); // letra branca
               t1.PosOrdem(t1.pRaiz);
               cout << "\n\n\n\t\t";
               system("pause");
            }

            break;

         case 4:

            if(t1.bstvazia())
            {
               SetConsoleTextAttribute(color, 14); // letra amarela
				   cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
				   cout << "\n\t\t   �RVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << "\n\n\t\t EM ORDEM: ";
               SetConsoleTextAttribute(color, 15); // letra branca
               t1.EmOrdem(t1.pRaiz);
               cout << "\n\n\n\t\t";
               system("pause");
            }

            break;

         case 5:

            if(t1.bstvazia())
            {
               SetConsoleTextAttribute(color, 14); // letra amarela
				   cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
				   cout << "\n\t\t   �RVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               cout << "\n\n\t\t N�mero m�ximo: ";
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << t1.Max(t1.pRaiz);
               SetConsoleTextAttribute(color, 15); // letra branca
               cout << "\n\n\n\t\t";
               system("pause");
            }

            break;

         case 6:

            if(t1.bstvazia())
            {
               SetConsoleTextAttribute(color, 14); // letra amarela
				   cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
				   cout << "\n\t\t   �RVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               cout << "\n\n\t\t N�mero m�nimo: ";
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << t1.Min(t1.pRaiz);
               SetConsoleTextAttribute(color, 15); // letra branca
               cout << "\n\n\n\t\t";
               system("pause");
            }

            break;

         case 7:

            if(t1.bstvazia())
            {
               SetConsoleTextAttribute(color, 14); // letra amarela
				   cout << "\n\n\t\t  >>>> ATEN��O <<<<" << endl;
				   cout << "\n\t\t   �RVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               int num;
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << "\n\n\t\t EM ORDEM: ";
               SetConsoleTextAttribute(color, 15); // letra branca
               t1.EmOrdem(t1.pRaiz);

               cout << "\n\n\t\t Informe o N� a remover: ";
               cin>>num;
               t1.remover(t1.pRaiz, num);

               SetConsoleTextAttribute(color, 10); // letra verde
               cout << "\n\n\t\t PROCESSANDO...\n";
               Sleep(2000);
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
