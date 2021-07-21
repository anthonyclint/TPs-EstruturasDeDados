#ifndef pilhatony
#define pilhatony

template<typename Tipo>

class Pilha
{
	private:
		Tipo* v;
		unsigned tamanho;
		int topo;

	public:
		Pilha(unsigned tam)
		{
			tamanho = tam;
			v = new Tipo[tamanho];
			topo = -1;
		}

		~Pilha()
		{
			delete []v;
		}

		void empilha(Tipo x)
		{
			topo++;

			v[topo] = x;
		}

		Tipo desempilha()
		{
			Tipo temp = v[topo];

			topo--;

			return temp;
		}

		Tipo elementodotopo()
		{
			return v[topo];
		}

		bool fullpilha()
		{
			return topo == (tamanho - 1);
		}

		bool emptypilha()
		{
			return topo == -1;
		}

		unsigned getTopo()
		{
			return topo;
		}

		unsigned getTamanho()
		{
			return tamanho;
		}

		Tipo getVal(unsigned posicao)
		{
			return v[posicao];
		}
};

#endif // pilhatony