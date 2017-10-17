#include <stdio.h>
#include <stdlib.h>
#include "listaDupEnc.h"

int main()
{
	lista list = novaLista();
	
	printf("vazia? %d.\n",ehVazia(&list));
	
	no *node = novoNo(2);
	
	insereNoInicioP(&list,node);
	node = novoNo(3);
	insereNoInicioP(&list,node);
	printf("vazia? %d.\n",ehVazia(&list));

	printLista(&list);
	return 0;
}