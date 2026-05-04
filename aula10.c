#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *prox;
}TNo;

typedef struct nocabeca{
	int cont;
	TNo *prim; //olha pro no cabeça
	TNo * ult;
}TNoCabeca;

void insereFinal(TNoCabeca *paux, int k)
{
	Tno *novo=NULL, *ultimo = paux->ultimo;
	novo = alocaNo(k);
	if(novo)
	{ //tb serve: paux -> ult -> prox = novo;
		ultimo -> prox=novo;
		paux->ult = novo;
		paux -> cont = paux -> cont + 1;
	}
}

TNoCabeca *criaLista(){

	TNoCabeca*novo = NULL;
	novo = (TNoCabeca *)malloc(sizeof(TNoCabeca));
	if(novo)
	{
		novo-> cont = 0;
		novo -> prim = NULL;
		novo-> ult NULL;
	}
}

void insereInicio(TNoCabeca *paux, int k)
{
	TNo *novo=NULL;
	novo = alocaNo(k);
	if(novo)
	{
		novo -> prox = paux->prim;
		if(paux->ult==NULL)
			paux->ult = novo;
		paux->cont = paux->cont + 1;
	}

}

TNo *alocaNo(int k)
{
	TNo *novo = NULL;
	novo = (TNo *)malloc(sizeof(TNo));
	if(novo)
	{
		novo -> chave;
		novo -> prox = *prox;
	}
}

void imprimir(TNoCabeca *paux)
{
	TNo *paux2 = paux->prim;
   if(paux2 == NULL)
      printf("\nLista vazia!");
   while(paux2 != NULL)
   {
      printf("\n %d"paux2->chave);
      paux2 = paux2->prim;
   }
}

int main ()
{
	TNoCabeca *prim = criaLista();
	insereInicio(prim, 7);
	insereInicio(prim, 12);
	insereInicio(prim, 46);
	insereFinal(prim, 22);
	imprimir(prim);

	return 0;
}