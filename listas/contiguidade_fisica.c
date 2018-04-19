#include <stdio.h>
#include <stdlib.h>

#define	TAM 2

typedef struct{
	int info;
}no;
typedef struct{
	no *lista;
	int max;
	int atual;
}lista_cf;

lista_cf * nova_lista_cf();
void inserir(lista_cf *l, int valor);
void inserirPOS(lista_cf *l, int valor, int pos);
void removerPOS(lista_cf *l, int pos);
void excluir_lista_cf(lista_cf **l);
int contar_elemneto(lista_cf *l, int valor);
void imprime_lista(lista_cf *l);

int main()
{
	lista_cf *l = nova_lista_cf();
	inserir(l, 1);
	inserir(l, 2);
	inserir(l, 3);
	imprime_lista(l);
	removerPOS(l, 1);
	inserirPOS(l, 5, 0);
	imprime_lista(l);
	excluir_lista_cf(&l);
	return 0;
}

lista_cf * nova_lista_cf()
{
	lista_cf *l = malloc(sizeof(lista_cf));
	no *n = malloc(sizeof(no) * TAM);
	l->lista = n;
	l->max = TAM;
	l->atual = 0;
}

void excluir_lista_cf(lista_cf **l)
{
	lista_cf *pl = *l;
	free(pl->lista);
	free(pl);
	*l= NULL;
}

void inserirPOS(lista_cf *l, int valor, int pos)
{
	if(l->atual <= l->max)
	{
		l->max += TAM; 
		realloc(l->lista, l->max);
	}
	int i;
	for(i = l->atual; i>pos ; i--) 
	{
		l->lista[i].info = l->lista[i - 1].info;
	}
	l->lista[i].info=valor;
	l->atual++;
}

void inserir(lista_cf *l, int valor)
{
	inserirPOS(l, valor, l->atual);
}

void removerPOS(lista_cf *l, int pos)
{
	int i;
	for(i = pos; i < l->atual; i++)
	{
		l->lista[i] = l->lista[i + 1];
	}
	l->atual--;
}

int contar_elemneto(lista_cf *l, int valor)
{
	int cont = 0, i;
	for (i = 0; i < l->atual; i++)
	{
		cont += l->lista[i].info == valor ? 1 : 0;
	}
	return cont;
}
void imprime_lista(lista_cf *l)
{
	int i;
	for (i = 0;  i < l->atual; i++)
	{
		printf("[%i]", l->lista[i].info);
	}
	printf("\n");
}