#include <stdio.h>
#include <stdlib.h>
#include "listaDupEnc.h"

int main(int argc, char *argv[])
{	lista l = novaLista();
	no n = *novoNo(2);
	insereNoInicioP(&l, &n);
	printLista(&l);
	insereNoInicoI(&l, 7);
	printLista(&l);
	no ni = *novoNo(5);
	insereNaPos(&l, &ni, 1);
	printLista(&l);
	no *ne  = novoNo(1);
	insereNoFim(&l, ne);
	printLista(&l);
	exculiNaPos(&l, 1);
	printLista(&l);
	return 0;
}

