#include <stdio.h>
typedef struct{int elemento;} no;
typedef struct{no *vetor; int tamanho;}listaVetor;

void novoElemento(no *n, listaVetor *lista)
{	lista->tamanho++;
	no *vetor = (no *) malloc(sizeof(no) * (int)lista->tamanho);
	int i;
	for(i = 0; i < lista->tamanho && lista->tamanho > 1; vetor[i] = lista->vetor[i], i++);
	vetor[lista->tamanho - 1] = *n;
	lista->vetor = vetor;
}
void elementoPosicao(no *n,int pos, listaVetor *lista)
{	if(pos >= lista->tamanho)
	{ novoElemento(n, lista);
	}
	else
	{	int i;
		lista->tamanho++;
		no *vetor = (no *) malloc(sizeof(no)*lista->tamanho);
		for(i = 0; i < pos; vetor[i] = lista->vetor[i], i++);
		for(i = pos; i < lista->tamanho; vetor[i + 1] = lista->vetor[i], i++);
		vetor[pos] = *n;
		lista->vetor = vetor;
	}
}
void apagarElementoX(int pos, listaVetor *lista)
{	int i;
	if(pos == lista->tamanho)
	{	lista->tamanho--;
	}
	else if(pos < lista->tamanho)
	{	for(i = pos; i < lista->tamanho; lista->vetor[i] = lista->vetor[i + 1], i++);
		lista->tamanho--;
	}
}
int verificaElemento(no *n,listaVetor *lista)
{	int i;
	int ret = 0; 
	for(i = 0; i < lista->tamanho; i++)
	{	if(lista->vetor[i].elemento == n->elemento) return 1;
	}
	return ret;
}
int qtdElementos(listaVetor *lista)
{	return lista->tamanho;
}
