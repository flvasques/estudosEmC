#include <stdio.h>
#include <stdlib.h>
#include "listaSimples.h"

int main()
{
	lista l = novaLista();
	no *n = novoNo(1);
	insereNoInicioP(&l, n);
	n = novoNo(1);
	insereNoInicioP(&l, n);
	n = novoNo(3);
	insereNoFim(&l, n);
	n = novoNo(2);
	insereNaPos(&l, n, 1);
	n = novoNo(5);
	insereNoFim(&l, n);
	imprime(&l);
	excluiNaPos(&l, 1);
	imprime(&l);
	return 0;
}