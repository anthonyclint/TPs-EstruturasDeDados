#ifndef lista_ordenada
#define lista_ordenada

template <typename Tipo>
struct Node
{
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
struct ListaOrdenada
    {
       Node<Tipo> *h;

       ListaOrdenada()
       {
          h=NULL;
       }

       ~ListaOrdenada()
       {
           Node<Tipo> *aux = new Node<Tipo>;

           while(h != NULL)
           {
               aux = h;
               h = h->prox;
               delete aux;
           }
       }

       bool listaVazia()
       {
          return h==NULL;
       }

       void insere(Tipo x)
       {
          Node<Tipo> *aux2;
          Node<Tipo> *aux=new Node<Tipo>;
          aux->info=x;

          if(h==NULL || x < h->info)
          {
              aux->prox=h;
              h = aux;
          }
          else
          {
              aux2 = h;

              while(aux2->prox!=NULL && x > aux2->prox->info)
              {
                  aux2 = aux2->prox;
              }

              aux->prox = aux2->prox;
              aux2->prox = aux;
          }
      }

      bool remover(Tipo x)
      {
          Node<Tipo> *aux = new Node<Tipo>;
          aux = h;

          if(h->info == x)
          {
              h = h->prox;
              delete aux;
              return 1; // retorna 1 após deletar o elemento
          }

          while (aux->prox != NULL && aux->prox->info <= x)
          {
              if(aux->prox->info == x)
              {
                  Node<Tipo> *aux2 = new Node<Tipo>;
                  aux2 = aux->prox;
                  aux->prox = aux->prox->prox;

                  delete aux2;

                  return 1; // retorna 1 após deletar o elemento
              }

              aux = aux->prox;
          }

          return 0; // caso não exista o elemento
      }

      int buscaElem(Tipo x)
      {
          Node<Tipo> *aux = h;
          int indice = 0;

          while (aux != NULL && aux->info <= x)
          {
              indice++; // caso não encontre o elemento incrementa

              if(aux->info == x)
              {
                  return indice; // retornar o índice do elemento encontrado
              }

              aux = aux->prox;
          }

          return -1; // caso não exista o elemento
      }

      Tipo *getRaiz()
      {
          return h;
      }
   };

#endif // lista_ordenada
