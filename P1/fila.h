#ifndef fila
#define fila

template<typename Tipo>

class Fila
{
private:
	int begin, end;
	unsigned qtd, size;
	Tipo* v;

public:
	Fila(unsigned tam)
	{
		end = -1;
		begin = 0;
		qtd = 0;
		size = tam;
		v = new Tipo[size];
	}

	~Fila()
	{
		delete[]v;
	}

	void put(Tipo x) // fun��o que insere na lista
	{
		end++;

		if (end == size)
		{
			end = 0;
		}

		v[end] = x;
		qtd++;
	}

	Tipo takeout() // fun��o que retira da lista
	{
		Tipo temp = v[begin];
		begin++;

		if (begin == size)
		{
			begin = 0;
		}

		qtd--;

		return temp;
	}

	Tipo first() // fun��o primeiro da fila
	{
		return v[begin];
	}

	bool fullist() // fun��o lista cheia
	{
		return qtd == size;
	}

	bool emptylist() // fun��o lista vazia
	{
		return qtd==0;
	}

	// as fun��es get servem pra dar acesso �s vari�veis que est�o encapsuladas

	int getEnd()
	{
		return end;
	}

	int getBegin()
	{
		return begin;
	}

	unsigned getQtd()
	{
		return qtd;
	}

	unsigned getSize()
	{
		return size;
	}

	Tipo getVal(unsigned pos)
	{
		return v[pos];
	}
};
#endif // fila
