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

lista_enc * nova_lista();
int eh_vazia(lista_enc *l);
int insere_no_inicio_p(lista_enc *l, no *n);
int insere_no_inicio_n(lista_enc *l, no n);
no * novo_no(int valor);

int main()
{
	lista_enc *lista = nova_lista();
	printf("%i\n", eh_vazia(lista));
	no *nodo = novo_no(1);
	insere_no_inicio_p(lista, nodo);
	nodo = novo_no(2);
	insere_no_inicio_n(lista, *nodo);
	return 0;
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

no * novo_no(int valor)
{
	no *n = malloc(sizeof(no));
	n->info = valor;
	n->prox = NULL;
	return n;
}