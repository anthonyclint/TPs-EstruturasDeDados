#ifndef tree_search
#define tree_search

//Anthony Clint Pastorello R.A.: 0050482011005 - TP 07 Árvore Binária de Busca

using namespace std;
template <typename Tipo>

struct Node
{
   Tipo info;
   Node<Tipo> *pEsq;
   Node<Tipo> *pDir;
};

template <typename Tipo>

struct Bst
{
   Node<Tipo> *pRaiz;
   Bst()
   {
      pRaiz = NULL;
   }

   void insere(Node<Tipo> *&t, Tipo x)
   {
      if(t == NULL)
         {
            t = new Node<Tipo>;

            t->info = x;

            t->pEsq = NULL;

            t->pDir = NULL;
         }
      else
         {
            if(x < t->info)
            {
                  insere(t->pEsq,x);
            }
            else
            {
                insere(t->pDir,x);
            }
         }
   }

    bool bstvazia()
	 {
       return pRaiz == NULL;
	 }

   void PreOrdem(Node<Tipo> *t)
   {
      if(t != NULL)
         {
            cout << t->info << " ";
            PreOrdem(t->pEsq);
            PreOrdem(t->pDir);
         }
   }

   void PosOrdem(Node<Tipo> *t)
   {
      if(t != NULL)
         {
            PosOrdem(t->pEsq);
            PosOrdem(t->pDir);
            cout << t->info << " ";
         }
   }

    void EmOrdem(Node<Tipo> *t)
   {
      if(t != NULL)
         {
            EmOrdem(t->pEsq);
            cout << t->info << " ";
            EmOrdem(t->pDir);
         }
   }

   Tipo Min(Node<Tipo> *t)//E-E-E-X
   {
        if(t != NULL)
        {
            if (Min(t->pEsq) != NULL)
                return Min(t->pEsq);
            else
                return t->info;
        }

        return NULL;
    }

    Tipo Max(Node<Tipo> *t) //D-D-D-X
    {
        if(t != NULL)
        {
            if (Max(t->pDir) != NULL)
                return Max(t->pDir);
            else
                return t->info;
        }

        return NULL;
    }

    void remover(Node<Tipo> *&t, Tipo v)
    {
        if (t != NULL)
        {
           if (t->info > v)
           {
              remover(t->pEsq, v);
           }
           else if (t->info < v)
           {
              remover(t->pDir, v);
           }
           else
           {
              if (t->pEsq == NULL && t->pDir == NULL)//delete t;
              {
                 Node<Tipo> *aux = t;
                 t = t->pEsq;
                 delete aux;
              }
              else if (t->pEsq == NULL)
              {
                 Node <Tipo> *aux = t;
                 t = t->pDir;
                 delete aux;
              }
              else if (t->pDir == NULL)
              {
                 Node<Tipo> *aux = t;
                 t = t->pEsq;
                 delete aux;
              }
              else
              {
                 Node<Tipo> *aux = t->pEsq;

                 while (aux->pDir != NULL)
                 {
                    aux = aux->pDir;
                 }

                 t->info = aux->info;
                 aux->info = v;
                 remover(t->pEsq, v);
              }
           }
        }
    }
};

#endif // tree_search
