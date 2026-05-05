#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *prox;
}TNo;

TNo *alocaNo(int k)
{
	TNo *novo = NULL;
	novo = (TNo *)malloc(sizeof(TNo));
	if(novo)
	{
		novo -> chave = k;
		novo -> prox = NULL;
	}
}

void imprimir(TNo*p)
{
	TNo *paux = p;
	if(p==NULL)
	{
		printf("Lista vazia\n");
		return;
	}
	if(paux)
	{
		do
		{
			printf("\n%d", paux -> chave);
			paux = paux -> prox;
		}while(paux!=p->prox);
	}else
	{
		printf("\n%d", paux -> chave);
	}
	
}

TNo *buscar(TNo *p, int k)
{
	TNo *paux = p;
	do
		{
			if(paux -> chave == k)
				return paux;
		}while(paux!=p->prox);
		return NULL;
}

void insereInicio(TNo **p, int k)
{
	TNo*novo = NULL;
	novo = alocaNo(k);
	if(novo)
	{
		if(*p == NULL)//lista vazia
		{
			novo -> prox = novo;
			*p = novo;
		}
		else
		{
			novo -> prox = (*p) -> prox;
			(*p) -> prox = novo; 
		}
	}
}
void removerInicio(TNo **p)
{
	TNo*paux = (*p) -> prox;
	if(*p == paux)
	{
		free(paux);
		*p = NULL;
		paux = NULL; //mas nao precisa
	}else
	{
		(*p) -> prox = paux -> prox;
		free(paux);
		paux = NULL;
	}
}

int main ()
{
	TNo *lista = NULL, *achou = NULL;
	insereInicio(&lista, 33);
	insereInicio(&lista, 34);
	imprimir(lista);
	insereInicio(&lista, 34);
	achou = buscar(lista, 13);
	if(achou)
		printf("\n %p e %d", achou, achou -> chave);
	else
		printf("Elemento nao encontrado\n");
	removerInicio(&lista);
	printf("--------------------------------------------\n");
	imprimir(lista);
	while(lista)
	{
		removerInicio(&lista);
	}

	return 0;
}