#ifndef recursivas
#define recursivas

#include<cmath>

double fatR(int n) 
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fatR(n - 1);
	}
}

double fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}

int mdc(int m, int n)
{
	if (m == n)
	{
		return m;
	}
	else if (m < n)
	{
		return mdc(n, m);
	}
	else
	{
		return mdc(m - n, n); 
	}
}

int s1(int m, int n)
{
	if(n == m)
	{
		return m;
	}
	else if(m < n)
	{
		return (s1(m, n - 1) + n);
	}
}

int s2(int m, int n)
{
	if (n == m)
	{
		return m;
	}
	else if (m < n)
	{
		return (m + s2(m + 1, n));
	}
}

int dig(int n)
{
	if(abs(n) <= 9)
	{
		return 1;
	}
	else
	{
		return (1 + dig(n / 10));
	}
}

int pot(int m, int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n < 0)
	{
		return (1 / pot(m, abs(n)));
	}
	else
	{
		return (m * pot(m, n - 1));
	}
}

#endif // recursivas
