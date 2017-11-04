#include <stdio.h>
#include <stdlib.h>

typedef struct{  int id;
				char *placa;
				char *modelo;
				struct carro *proximo;
				struct carro * anterior;}carro;
typedef struct {carro *primeiro;
				carro *ultimo;
				int tam;} garagem;

carro *novoNo(char *p, char *m)
{	carro *c = (carro *)malloc(sizeof(carro));
	c->placa = p;
	c->modelo = m;
	c->id = 0;
	c->proximo = NULL;
	c->anterior = NULL;
	return c;
}

garagem *novaFila()
{	garagem *g = (garagem *)malloc(sizeof(garagem));
	g->primeiro = NULL;
	g->ultimo = NULL;
	g->tam = 0;
	return g;
}

void enqueue(garagem *g, char *p, char *m)
{	carro  *c = novoNo(p,m);
	if(g->tam == 0)
	{	c->id = g->tam;
		g->primeiro = c;
		g->ultimo = c;
		g->tam++;
	}
	else
	{	carro *aux = g->primeiro;
		c->id = g->tam;
		c->proximo = aux;
		aux->anterior = c;
		g->primeiro = c;
		g->tam++;
	}
}

void enqueueP(garagem *g, carro *c)
{	if(g->tam == 0)
	{	c->id = g->tam;
		g->primeiro = c;
		g->ultimo = c;
		g->tam++;		
	}
	else
	{	carro *aux = g->primeiro;
		c->id = g->tam;
		c->proximo = aux;
		aux->anterior = c;
		g->primeiro = c;
		g->tam++;
	}
}

carro *peak(garagem *g)
{	if(g->tam > 0)
	{	carro *aux = g->ultimo;
		return aux;
	}
	else
	{	return NULL;
	}
}

carro *dequeue(garagem *g)
{	carro *aux = g->ultimo;
	g->ultimo = aux->anterior;
	g->tam--;
	return aux;
}

garagem *novaPilha()
{	return novaFila();
}

carro *pop(garagem *l)
{	carro *aux = l->primeiro;
	l->primeiro = aux->proximo;
	l->tam--;
	return aux;
}

carro peakPilha(garagem *l)
{	carro *n  =l->primeiro;
	return *n;
}
void push(garagem *l, char *p,  char *m)
{	carro *n = novoNo(p,m);
	if(l->tam == 0)
	{	n->id = l->tam;
		l->primeiro = n;
		l->tam++;
	}
	else
	{	n->id = l->tam;
		n->proximo = (l->primeiro);
		l->primeiro = n;
		l->tam++;
	}
}

void pushP(garagem *l, carro *c)
{	if(l->tam == 0)
	{	c->id = l->tam;
		l->primeiro = c;
		l->tam++;
	}
	else
	{	c->id = l->tam;
		c->proximo = (l->primeiro);
		l->primeiro = c;
		l->tam++;
	}
}