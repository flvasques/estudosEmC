#include <stdio.h>
#include <stdlib.h>
#include "listaContigua.h"


int main()
{
	listaVetor *lista = novaLista();
	no *elemento = novoNo(3);
	novoElemento(elemento, lista);
	printf("%d\n",lista->vetor[0]);
	elemento = novoNo(7);
	elementoPosicao(elemento, 0, lista);
	printf("%d | %d\n",lista->vetor[0], lista->vetor[1]);
	elemento = novoNo(5);
	elementoPosicao(elemento, 2, lista);
	printf("%d | %d | %d\n",lista->vetor[0], lista->vetor[1], lista->vetor[2]);
	apagarElementoX(1, lista);
	printf("%d | %d\n",lista->vetor[0], lista->vetor[1]);
	elemento = novoNo(5);
	printf("%d presente %d vez(es)\n",elemento->elemento , verificaElemento(elemento, lista));
	elemento = novoNo(7);
	printf("%d presente %d vez(es)\n",elemento->elemento , verificaElemento(elemento, lista));
	printf("tamanho da lista: %d\n",qtdElementos(lista));
	return 0;	
}
