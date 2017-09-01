#include <stdio.h>
#include <stdlib.h>
#include "listaContigua.h"


int main()
{
	listaVetor lista;
	lista.tamanho = 0;
	no elemento;
	elemento.elemento = 3;
	novoElemento(&elemento, &lista);
	printf("%d\n",lista.vetor[0]);
	elemento.elemento = 5;
	novoElemento(&elemento, &lista);
	printf("%d | %d\n",lista.vetor[0], lista.vetor[1]);
	elemento.elemento = 7;
	elementoPosicao(&elemento, 0, &lista);
	printf("%d | %d | %d\n",lista.vetor[0], lista.vetor[1], lista.vetor[2]);
	apagarElementoX(1, &lista);
	printf("%d | %d\n",lista.vetor[0], lista.vetor[1]);
	elemento.elemento = 3;
	printf("%d presente %d vez(es)\n",elemento.elemento , verificaElemento(&elemento, &lista));
	elemento.elemento = 7;
	printf("%d presente %d vez(es)\n",elemento.elemento , verificaElemento(&elemento, &lista));
	printf("tamanho da lista: %d\n",qtdElementos(&lista));
	return 0;	
}
