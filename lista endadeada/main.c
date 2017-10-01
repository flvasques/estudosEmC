#include <stdio.h>
#include <stdlib.h>
#include "listaDupEnc.h"

int main(int argc, char *argv[])
{	lista l = novaLista();
	no n = *novoNo(2);
	insereNoInicioP(&l, &n);
	insereNoInicoI(&l, 3);
	printLista(&l);
	
	return 0;
}

