//ANTHONY CLINT PASTORELLO R.A.: 0050482011005  - TP da P2

#ifndef pilha_mt
#define pilha_mt

int MT(int a, int b)
{
   if(b == 1)
   {
      return a;
   }
   else if(b > 1)
   {
      return (MT(a,(b-1)))+1;
   }
}
#endif // pilha_mt
