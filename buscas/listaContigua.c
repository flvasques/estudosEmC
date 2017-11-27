#include <stdio.h>
#include <stdlib.h>

typedef struct{int elemento;} no;
typedef struct{no *vetor; int tamanho; int max;}listaVetor;


no *novoNo(int i)
{	no *n = (no * ) malloc(sizeof(no));
	n->elemento = i;
	return n;
}
listaVetor *novaLista()
{	listaVetor *l  = (listaVetor *) malloc(sizeof(listaVetor));
	l->vetor = (no * ) malloc(sizeof(no) * 1000);
	l->tamanho = 0;
	l->max = 1000;
	return l;
}
void novoElemento(no *n, listaVetor *lista)
{	int i;
	if(lista->tamanho == 0)
	{	lista->vetor[0] = *n;
	}
	else if(lista->tamanho < lista->max)
	{	for(i = lista->tamanho; i <= 0; i--)
		{	lista->vetor[i + 1] = lista->vetor[i];
		}
		lista->vetor[0] = *n;
	}
	else
	{	lista->max = lista->max * 2;
		no *novo  = (no * ) malloc(sizeof(no)* lista->max);
		for(i = lista->tamanho; i <= 0; i--)
		{	novo[i + 1] = lista->vetor[i];
		}
		novo[0] = *n;
		lista->vetor = novo;
	}
	lista->tamanho++;
}
void elementoPosicao(no *n,int pos, listaVetor *lista)
{	int i;
	if(lista->tamanho <= pos)
	{	 if(lista->tamanho < lista->max)
		{	for(i = pos; i < lista->tamanho; i++)
			{	lista->vetor[i + 1] = lista->vetor[i];
			}
			lista->vetor[pos] = *n;
		}
		else
		{	no *novo  = (no * ) malloc(sizeof(no)* lista->max);
			for(i = 0; i < pos; i++)
			{ novo[i] = lista->vetor[i];
			}
			while(i < lista->tamanho)
			{	novo[i + 1] = lista->vetor[i];
				i++;
			}
			novo[pos] = *n;
			lista->vetor = novo;
		}
	}
	else
	{	lista->vetor[lista->tamanho] = *n;
	}
	lista->tamanho++;
}
void apagarElementoX(int pos, listaVetor *lista)
{	if(lista->tamanho < pos)
	{	int i;
		for(i = pos; i < lista->tamanho; i++)
		{	lista->vetor[i] = lista->vetor[i + 1];
		}
	}
	lista->tamanho--;
}
int verificaElemento(no *n,listaVetor *lista)
{	int retorno = 0;
	int i;
	for(i = 0; i < lista->tamanho; i++)
	{	if(lista->vetor[i].elemento == n->elemento)
		{	retorno++;
		}
	}
	return retorno;
}
int qtdElementos(listaVetor *lista)
{	return lista->tamanho;
}
