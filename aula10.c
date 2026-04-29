#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int chave;
    //campos
    struct no *prox;
}TNo;

TNo *alocaNo(int k);
void insereInicio(TNo **pprim, int k);
void imprimir(TNo *paux);
void removerInicio(TNo **prim);
void removerTodos(TNo **prim);
void inserirFinal(TNo **pprim, int k);
TNo* buscar(TNo *paux, int chave);
TNo* criarListaPar(TNo * paux);

int main()
{
    TNo *prim=NULL, *buscado=NULL;
    insereInicio(&prim, 15);
    insereInicio(&prim, 62);
    insereInicio(&prim, 46);
    inserirFinal(&prim,111);
    
    printf("\nBuscado 62: %p", buscar(prim, 62));
    TNo *listaPar = criarListaPar(prim);
    printf("\nLista par: ");
    imprimir(listaPar);
    printf("\nFinal lista par");
    //printf("\n%d", prim->chave);
    imprimir(prim);
    removerInicio(&prim);
    printf("\n----------------");
    imprimir(prim);
/*    while(prim)
//        removerInicio(&prim);
    removerTodos(&prim);
    printf("\n----------------");
    imprimir(prim);
//    insereInicio(&prim, 99);
//    imprimir(prim);*/

}

void removerTodos(TNo **prim)
{
    while(*prim)
        removerInicio(prim);
}

void inserirFinal(TNo **pprim, int k)
{
    TNo *paux=*pprim, *novo=NULL;
    if(*pprim==NULL) //lista vazia
    {
       insereInicio(pprim,k);
       return;
    }
    else
    {
        while(paux->prox!=NULL)
        {
           paux=paux->prox;
        }
        novo=alocaNo(k);
        if(novo)
        {
            paux->prox = novo;
        }
    }

}

void removerInicio(TNo **prim)
{
    TNo *paux=*prim;
    if(paux) //if(paux!=NULL)
    {
        *prim = (*prim)->prox;
        free(paux);
        paux=NULL;
    }
}

void imprimir(TNo *paux)
{
   if(paux == NULL)
      printf("\nLista vazia!");
   while(paux!=NULL)
   {
      printf("\n%p %d", paux, paux->chave);
      paux = paux->prox;
   }
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
void insereInicio(TNo **pprim, int k)
{
    TNo *novo=NULL;
    novo = alocaNo(k);
    if (novo == NULL) return;
    novo->prox = *pprim;
    *pprim = novo;
}

TNo* buscar(TNo *paux, int chave)
{
  while(paux!=NULL)
   {
      if(paux->chave == chave)
        return paux;
      paux = paux->prox;
   }
   return NULL;
}


TNo* criarListaPar(TNo * paux)
{
  TNo *ppar = NULL;
  while(paux)
  {
    if(paux->chave%2 == 0)
    {
      insereInicio(&ppar, paux->chave);
    }
    paux = paux->prox;
  }
  return ppar;
}