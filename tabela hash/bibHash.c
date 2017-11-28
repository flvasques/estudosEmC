#include <stdio.h>
#include <stdlib.h>



typedef struct{char *nome; char *telefone; struct no *proximo;} no;
typedef struct{no *primeiro; int tam;}lista;


no *novoNo(char *n, char *t)
{	no *node = (no *)malloc(sizeof(no));
	node->nome = n;
	node->telefone = t;
	node->proximo = NULL;
	return n;
}

lista novaLista()
{	lista *l  = (lista *)malloc(sizeof(lista));
	l->primeiro = NULL;
	l->tam = 0;
	return  *l;
}

int hash(char *n)
{   int p = n[0] % 26;
	printf("%s %d %d\n", n, n[0], p);
	return p;
}


void inserir(char *n, char *t, lista *l)
{	int j = hash(n);
	no *node = novoNo(n, t);
	if(l[j].tam > 0)
	{	no *aux = l[j].primeiro;
		int i = 0;
		while(i < l->tam - 1 && aux->proximo != NULL)
		{	aux = aux->proximo;
			i++;
		}
		aux->proximo = node;
		l[i].tam++;
	} 
	else 
	{	l[j].primeiro = node;
		l[j].tam++;
	}
}

void imprime(lista *l)
{	no *aux = l->primeiro;
	printf("(%d)-",l->tam);
	//printf("[%d] ",aux->elemento);
	int i = 0;
	while(i < l->tam)
	{	printf("Nome: %s\t fone: %s\n",aux->nome, aux->telefone);
		if(aux->proximo != NULL) aux = aux->proximo;
		i++;
	}
	printf("\n");
}


