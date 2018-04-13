#include <stdio.h>
#include <stdlib.h>

#define	TAM 100

typedef struct{
	int info;
}no;
typedef struct{
	no *lista;
	int max;
	int atual;
}listaCF;

listaCF * nova_listaCF();
void inserir(listaCF *l, int valor);
void inserirPOS(listaCF *l, int valor, int pos);
void remover(listaCF *l, int valor);
void excluir_listaCF(listaCF **l);

int main()
{
	/* code */
	return 0;
}

listaCF * nova_listaCF()
{
	listaCF *l = malloc(sizeof(listaCF));
	no *n = malloc(sizeof(no) * TAM);
	l->lista = n;
	l->max = TAM;
	l->atual = 0;
}

void excluir_listaCF(listaCF **l)
{
	listaCF *pl = *l;
	free(pl);
	free(l);
	*l = NULL;
}
void inserir(listaCF *l, int valor)
{
	if(l->atual <= l->max)
	{
		l->atual++;
		l->lista[l->atual].info = valor;
	}
	else
	{
		l->max += TAM; 
		realloc(l->lista, l->max);
		l->atual++;
		l->lista[l->atual].info = valor;
	}
}
