#ifndef tonyteatro
#define tonyteatro

template<typename Tipo>

class Poltronas
{
	private:
		int lugar;
		int linha;
		int coluna;
		Tipo* a;

	public:
		Poltronas(int i, int j)
		{
			linha = i;
			coluna = j;
			lugar = linha * coluna;
			a = new Tipo[lugar];

			for(i = 0; i < linha; i++)
			{
				for(j = 0; j < coluna; j++)
				{
					a[i * coluna + j] = '-';
				}
			}
		}

		~Poltronas()
		{
			delete[]a;
		}

		void buy(int i, int j) // fun��o da compra de poltronas
		{
			a[i * coluna + j] = 'X';
		}

		void cancel(int i, int j) // fun��o do cancelamento de compra
		{
			a[i * coluna + j] = '-';
		}

		void change(int i, int j, int x, int y) // fun��o da troca de poltronas
		{
			a[i * coluna + j] = '-';
			a[x * coluna + y] = 'X';
		}

		Tipo getD() // fun��o de disponibilidade
		{
			int count = 0;

			for(int i = 0; i < linha; i++)
			{
				for(int j = 0; j < coluna; j++)
				{
					if(a[i * coluna + j] == '-') // se o elemento na posi��o ij for tra�o
					{
						count++; // contador acresce (count = poltronas livres)
					}
				}
			}

			return count;
		}

		Tipo getVal(int i, int j)
		{
			return a[i * coluna + j]; // retorna o elemento da posi��o ij, tra�o ou X
		}
};
#endif // tonyteatro
