#ifndef pilhaligada
#define pilhaligada

template <typename Tipo>

struct Node
{
	Tipo info;
	Node<Tipo> *prox;
};

template <typename Tipo>

class Pilha
{
	private:
		Node<Tipo> *topo;

	public:
		Pilha()
		{
			topo = NULL;
		}

		bool empilha(Tipo x) 
		{
			bool v = true;

			Node<Tipo> *aux = new Node<Tipo>; // passo 1 - aloca??o

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

		Tipo elementotopo()
		{
			return topo->info;
		}

		bool pilhavazia()
		{
			return topo == NULL;
		}

		Node<Tipo> *getopo()
		{
			return topo;
		}

};

#endif // pilha ligada
