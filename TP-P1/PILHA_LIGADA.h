#ifndef PILHA_LIGADA
#define PILHA_LIGADA

template <typename Tipo>

struct Node
{
	Tipo info;
	Node<Tipo>* prox;
};

template <typename Tipo>

class Pilha_Lig
{
private:
	Node<Tipo>* topo;

public:
	Pilha_Lig()
	{
		topo = NULL;
	}

	bool empilha(Tipo x)
	{
		bool v = true;

		Node<Tipo>* aux = new Node<Tipo>; // passo 1 - alocação

		aux->info = x; // passo 2 - guardar

		aux->prox = topo; // passo 3 - aponta pra NULL

		topo = aux; // passo 4

		return v;
	}

	Tipo desempilha()
	{
		Tipo temp = topo->info; // passo 0 - guardando o elemento

		Node<Tipo>* aux = topo; // passo 1

		topo = topo->prox; // passo 2

		delete aux; // passo 3

		return temp;
	}

	Tipo elementodotopo()
	{
		return topo->info;
	}

	bool pilhavazia()
	{
		return topo == NULL;
	}

	Node<Tipo>* getopo()
	{
		return topo;
	}

};

#endif // PILHA_LIGADA

