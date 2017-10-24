#include <stdio.h>
#include <stdlib.h>

typedef struct{ char *placa;
				struct carro *proximo;
				struct carro * anterior;}carro;
typedef struct {carro *primeiro;
				carro *ultimo;
				int tam;} garagem;

carro *novoNo(char *p)
{	carro *c = (carro *)malloc(sizeof(carro));
	c->placa = p;
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

void push(garagem *g, char *p)
{	carro  *c = novoNo(p);
	if(g->tam == 0)
	{	g->primeiro = c;
		g->ultimo = c;
		g->tam++;
	}
	else
	{	carro *aux = g->primeiro;
		c->proximo = aux;
		aux->anterior = c;
		g->primeiro = c;
		g->tam++;
	}
}

void pushFila(garagem *g, carro *c)
{	if(g->tam == 0)
	{	g->primeiro = c;
		g->ultimo = c;
		g->tam++;
	}
	else
	{	carro *aux = g->primeiro;
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

carro *pop(garagem *g)
{	carro *aux = g->ultimo;
	g->ultimo = aux->anterior;
	g->tam--;
	return aux;
}

garagem *novaPilha()
{	return novaFila();
}

carro *popPilha(garagem *l)
{	carro *aux = l->primeiro;
	l->primeiro = aux->proximo;
	l->tam--;
	return *aux;
}

carro peakPilha(garagem *l)
{	carro *n  =l->primeiro;
	return *n;
}
void pushPilha(garagem *l,char *p)
{	carro *n = novoNo(p);
	if(l->tam == 0)
	{	l->primeiro = n;
		l->tam++;
	}
	else
	{	
		n->proximo = (l->primeiro);
		l->primeiro = n;
		l->tam++;
	}
}

void pushPilhaP(garagem *l, carro *c)
{	if(l->tam == 0)
	{	l->primeiro = c;
		l->tam++;
	}
	else
	{	
		c->proximo = (l->primeiro);
		l->primeiro = c;
		l->tam++;
	}
}