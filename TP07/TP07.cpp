/*
   Anthony Clint Pastorello R.A.: 0050482011005 - TP 07 Árvore Binária de Busca

   Construa uma aplicação para uma Árvore Binária de Busca(BST)
   de números inteiros que permita ao usuário, a partir de um
   menu, executar as seguintes tarefas:
   1-inserir um novo número
   2-exibir a árvore na pré-ordem
   3-exibir a árvore ná pós-ordem
   4-exibir a árvore ná em ordem
   5-exibir o máximo dos números
   6-exibir o mínimo dos números
   7-excluir um elemento da árvore
   9-fim

*/


#include <iostream> // para using namespace
#include<Windows.h> // para cores das letras
#include<locale.h> // para o setlocale
#include<stdio.h>
#include<stdlib.h>
#include "tree_search.h" // header da árvore

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int menu() // função do menu
{
   int op; // variável da opção do usuário

   system("cls"); // limpa a tela

	SetConsoleTextAttribute(color, 15); // letra branca

	cout << "\n\n\t\t #### ÁRVORE DE BUSCA ####\n" << endl;
	cout << "\t\t 1 - INSERIR NA ÁRVORE" << endl;
	cout << "\t\t 2 - EXIBIR PRÉ-ORDEM" << endl;
	cout << "\t\t 3 - EXIBIR PÓS-ORDEM" << endl;
	cout << "\t\t 4 - EXIBIR EM ORDEM" << endl;
	cout << "\t\t 5 - EXIBIR O Nº MÁXIMO" << endl;
	cout << "\t\t 6 - EXIBIR O Nº MÍNIMO" << endl;
	cout << "\t\t 7 - EXCLUIR ELEMENTO" << endl;
	cout << "\t\t 9 - ENCERRAR PROGRAMA" << endl;
	cout << "\n\n\t\t SELECIONE A OPÇÃO: ";
	cin >> op;

   return op; // retornando a opção para a main
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

            cout << "\n\t\t INFORME O Nº: ";
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
				   cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				   cout << "\n\t\t   ÁRVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << "\n\n\t\t PRÉ-ORDEM: ";
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
				   cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				   cout << "\n\t\t   ÁRVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << "\n\n\t\t PÓS-ORDEM: ";
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
				   cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				   cout << "\n\t\t   ÁRVORE VAZIA!!!" << endl;
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
				   cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				   cout << "\n\t\t   ÁRVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               cout << "\n\n\t\t Número máximo: ";
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
				   cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				   cout << "\n\t\t   ÁRVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               cout << "\n\n\t\t Número mínimo: ";
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
				   cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				   cout << "\n\t\t   ÁRVORE VAZIA!!!" << endl;
				   Sleep(2000); // delay
            }
            else
            {
               int num;
               SetConsoleTextAttribute(color, 11); // letra ciano
               cout << "\n\n\t\t EM ORDEM: ";
               SetConsoleTextAttribute(color, 15); // letra branca
               t1.EmOrdem(t1.pRaiz);

               cout << "\n\n\t\t Informe o Nº a remover: ";
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
				cout << "\n\n\t\t  >>>> ATENÇÃO <<<<" << endl;
				cout << "\n\t\t  OPÇÃO INVÁLIDA!!!" << endl;
				Sleep(2000); // delay

      }

   }

    return 0;
}
