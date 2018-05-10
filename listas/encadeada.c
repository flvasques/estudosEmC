#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node *prox;
}no;

typedef struct {
	no *primeiro;
	int tam;
}lista_enc;

no * novo_no(int valor);
lista_enc * nova_lista();
int eh_vazia(lista_enc *l);
int insere_no_inicio_p(lista_enc *l, no *n);
int insere_no_inicio_n(lista_enc *l, no n);
int insere_no_inicio_i(lista_enc *l, int i);
void insere_na_pos(lista_enc *l, int pos, no *n);
void insere_no_fim(lista_enc *l, no *n);

void imprime(lista_enc *l);

int main()
{
	lista_enc *lista = nova_lista();
	printf("%i\n", eh_vazia(lista));
	no *nodo = novo_no(1);
	insere_no_inicio_p(lista, nodo);
	nodo = novo_no(2);
	insere_no_inicio_n(lista, *nodo);
	insere_no_inicio_i(lista, 3);
	nodo = novo_no(4);
	insere_na_pos(lista, 1, nodo);

	imprime(lista);

	return 0;
}

no * novo_no(int valor)
{
	no *n = malloc(sizeof(no));
	n->info = valor;
	n->prox = NULL;
	return n;
}

lista_enc * nova_lista()
{
	lista_enc * l = malloc(sizeof(lista_enc));
	l->primeiro = NULL;
	l->tam = 0;

	return l;
}

int eh_vazia(lista_enc *l)
{
	return l->tam == 0 ? 1 : 0;
}

int insere_no_inicio_p(lista_enc *l, no *n)
{
	n->prox = l->primeiro;
	l->primeiro = n;
	
	return 0;
}

int insere_no_inicio_n(lista_enc *l, no n)
{
	n.prox = l->primeiro;
	l->primeiro = &n;
	
	return 0;	
}

int insere_no_inicio_i(lista_enc *l, int i)
{
	no *n = novo_no(i);
	n->prox = l->primeiro;
	l->primeiro = n;
	
	return 0;
}
void insere_na_pos(lista_enc *l, int pos, no *n)
{
	no *aux = l->primeiro;
	int i = 0;
	if(l->primeiro != NULL)
	{
		while((aux->prox != NULL) && (i < pos))
		{
			aux = aux->prox;
			i++;
			printf("%i - ", i);
		}
		printf("\n");
		n->prox = aux->prox;
		aux->prox = n;
	}else
	{
		l->primeiro  = n;
	}

}
void insere_no_fim(lista_enc *l, no *n)
{
	no *aux = l->primeiro;
	if(l->primeiro != NULL)
	{
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}
		n->prox = aux->prox;
		aux->prox = n;
	}else
	{
		l->primeiro  = n;
	}
}

void imprime(lista_enc *l)
{
	no *aux = l->primeiro;
	if(l->primeiro != NULL)
	{
		while(aux->prox != NULL)
		{
			aux = aux->prox;
			printf("[%i]", aux->info);
			system("pause");
		}
	}else
	{
		printf("[]");
	}
	printf("\n");
}