#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    //campos
    struct no *prox;
}TNo;

TNo *alocaNo(int k);
TNo *criaLista();
void insereInicio(TNo **pprim, int k);
void imprimir(TNo *paux);
void removerInicio(TNo *cabeca);

int main()
{
	TNo *cabeca=criaLista();
	//printf("\n%d", cabeca->chave);

	insereInicio(&prim, 15);
    insereInicio(&prim, 62);
    insereInicio(&prim, 46);

    imprimir(cabeca);
}

TNo *alocaNo(int k)
{
	TNo *novo=NULL;
   novo = (TNo *)malloc(sizeof(TNo));
   if(novo) //if (novo!=NULL
   {
       novo->chave = k;
       novo->prox = NULL;
   }
   return novo;
}

TNo *criaLista()
{
	TNo *novo=NULL;
   novo = (TNo *)malloc(sizeof(TNo));
   if(novo) //if (novo!=NULL
   {
       novo->chave = -1;
       novo->prox = NULL;
   }
   return novo;

}
void insereInicio(TNo *paux, int k)
{
	TNo *novo=NULL;
	novo = alocaNo(k);
    if(novo) //if(paux!=NULL)
    {
        novo->cabeca = cabeca-> prox;
        paux->prox = novo;
    }

}

void imprimir(TNo *paux)
{
	paux = paux->prox;
	while(paux)
	{
		printf("\n%d", paux->chave);
		paux = paux->prox;
	}

}

void removerInicio(TNo *cabeca)
{

}