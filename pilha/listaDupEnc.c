#include <stdio.h>
#include <stdlib.h>

typedef struct{int elemento; 
			   struct no *proximo;
			   struct no *anterior;} no;
typedef struct{no *primeiro; 
			   int tam;}lista;

no *percorre(lista *l, int j)
{	no *saida = l->primeiro;
	int i = 0;
	while(i < j - 1 && saida->proximo != NULL)
	{	saida = saida->proximo;
		i++;
	}
	return saida;
}
no *novoNo(int i)
{	no *n = (no *)malloc(sizeof(no));
	n->elemento = i;
	n->proximo = NULL;
	n->anterior = NULL;
	return n;
}
lista novaLista()
{	lista *l  = (lista *)malloc(sizeof(lista));
	l->primeiro = NULL;
	l->tam = 0;
	return  *l;
}
int ehVazia(lista *l){
	if(l->primeiro == NULL)
	{	return 0;
	}
	else
	{ return 1;
	}
}
int insereNoInicioP(lista *l,no *n)
{	if(l->tam == 0)
	{	l->primeiro = n;
		l->tam++;
	}
	else
	{	
		n->proximo = l->primeiro;
		l->primeiro->anterior = n;
		l->primeiro = n;
		l->tam++;
	}
	return 0;
}
int insereNoInicioN(lista *l,no n)
{	 return insereNoInicioP(l,&n);
}
int insereNoInicoI(lista *l, int i)
{	no *n = novoNo(i);
	return insereNoInicioP(l,n);
}
int insereNaPos(lista *l, no *n, int p)
{	no *aux;
	if(p >= l->tam)
	{	aux = percorre(l, l->tam);
		aux->proximo = n;
		n->anterior = aux;
	}
	else
	{	aux = percorre(l, p);
		n->proximo = aux->proximo;
		n->anterior = aux;
		aux->proximo = n;
	}
	l->tam++;
	return 0;
}
int insereNoFim(lista *l, no *n)
{	return insereNaPos(l, n, l->tam);
}

int exculiNaPos(lista *l, int pos)
{	puts("nao implementado");
	return 1;
}

void printLista(lista *l)
{	no *aux = l->primeiro;
	printf("(%d)-",l->tam);
	//printf("[%d] ",aux->elemento);
	int i = 0;
	while(i < l->tam)
	{	printf("[%d]\t",aux->elemento);
		if(aux->proximo != NULL) aux = aux->proximo;
		i++;
	}
	printf("\n");
}
no retiraInicio(lista *l)
{	no *aux = l->primeiro;
	l->primeiro = aux->proximo;
	l->tam--;
	return *aux;
}
