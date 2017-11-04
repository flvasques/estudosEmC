#include <stdio.h>
#include <stdlib.h>

typedef struct{int elemento; 
			   struct no *proximo;
			   struct no *anterior;} no;
typedef struct{no *primeiro; 
			   int tam;}lista;

int ehVazia(lista *l){
	return (l->tam == 0)? 0 : 1;
}

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
	return n;
}

lista novaLista()
{	lista *l  = (lista *)malloc(sizeof(lista));
	l->primeiro = NULL;
	l->tam = 0;
	return  *l;
}

int insereNoInicioP(lista *l,no *n)
{	if(l->tam == 0)
	{	l->primeiro = n;
		l->tam++;
	}
	else
	{	
		n->proximo = (l->primeiro);
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
{	no *aux = l->primeiro;
	no *ant;
	int i = 0;
	while(i < p && aux->proximo != NULL)
	{	ant = aux;
		aux = aux->proximo;
		i++;
	}
	ant->proximo = n;
	n->proximo = aux;
	l->tam++;
	return 0;
}

int insereNoFim(lista *l, no *n)
{	no *aux = l->primeiro;
	int i = 0;
	while(i < l->tam - 1 && aux->proximo != NULL)
	{	aux = aux->proximo;
		i++;
	}
	aux->proximo = n;
	l->tam++;
}

int excluiNaPos(lista *l, int pos)
{	no *aux = l->primeiro;
	no *ant;
	int i = 0;
	while(i < pos && aux->proximo != NULL)
	{	ant = aux;
		aux = aux->proximo;
		i++;
	}
	ant->proximo = aux->proximo;
	free(aux);
	l->tam--;
	return 0;
}

int excluiNoFim(lista *l)
{	return excluiNaPos(l, (l->tam -1));
}

int excluiNoInicio(lista *l)
{	no *aux = l->primeiro;
	l->primeiro = aux->proximo;
	free(aux);
	return 0;
}

int ehIgual(lista *l1, lista *l2)
{	int igual = 0;
	no *aux1 = l1->primeiro;
	no *aux2 = l2->primeiro;
	int i = 0;
	if(l1->tam == l2->tam)
	{	while(i < l1->tam - 1)
		{	aux1 = aux1->proximo;
			aux2 = aux2->proximo;
			igual += (aux1->elemento != aux2->elemento) ? 1 : 0;
		}
	}else
	{
		return -1;
	}
	
	return igual;
}

int imprimeNodo(lista *l, int pos)
{	no *aux = l->primeiro;
	int i = 0;
	while(i < pos && aux->proximo != NULL)
	{	aux = aux->proximo;
		i++;
	}
	printf("[%d]\n",aux->elemento);
	return (pos <= l->tam)? 0 : 1;
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

int tamanho(lista *l)
{ return l->tam;
}

void deleteLista(lista **l)
{	lista *aux = *l;
	free(aux);
}