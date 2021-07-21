#ifndef hashing
#define hashing
#define w 5

//ANTHONY CLINT PASTORELLO R.A.: 0050482011005   - TP 08 TABELA HASHING.

struct Node
{
    int info;
    Node *prox;
};

struct Hash
{
    Node *h[w];

    Hash()
    {
        for(int i=0; i<w; i++)
        {
            h[i] = NULL;
        }
    }

    int fht(int x)
    {
        return (x % w);
    }

    bool listavazia(int lista)
    {
        return (h[lista] == NULL);
    }

    void insere(int x)
    {
        Node *aux2;
        Node *aux = new Node;
        aux->info = x;

        int p = fht(x); // qual lista

        if(h[p] == NULL || x <= h[p]->info)
        {
            aux->prox = h[p];
            h[p] = aux;
        }
        else
        {
            aux2 = h[p];

            while(aux2->prox != NULL && x > aux2->prox->info)
            {
                aux2 = aux2->prox;
            }

            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

    bool remove(int x)
    {
        int p = fht(x); // qual lista
        Node* aux = new Node;

        aux = h[p];
        if (aux != NULL)
        {
            if (x == aux->info)
            {
                h[p] = h[p]->prox;
                delete aux;

                return true;
            }
            else
            {
                while (aux->prox != NULL && aux->prox->info <= x)
                {
                    if (x == aux->prox->info)
                    {
                        Node* aux2 = new Node;
                        aux2 = aux->prox;
                        aux->prox = aux->prox->prox;
                        delete aux2;

                        return true;
                    }
                    aux = aux->prox;
                }
            }
        }

        return false;
    }

    int busca(int x)
    {
        int pos = 0;
        int p = fht(x); // qual lista
        Node* aux = h[p];

        while (aux != NULL && aux->info <= x)
        {
            pos++;

            if (x == aux->info)
            {
                return pos;
            }

            aux = aux->prox;
        }
        return 0;
    }
};

#endif // hashing
