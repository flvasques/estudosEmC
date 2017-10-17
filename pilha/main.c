#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char *argv[])
{	lista l = novaPilha();
	push(&l, 1);
	puts("entrou");
	no *a = peak(&l);
	printf("%d", a->elemento);
	push(&l, 2);
	a = peak(&l);
	printf("%d", a->elemento);
	push(&l, 3);
	a = peak(&l);
	printf("%d", a->elemento);
	push(&l, 4);
	a = peak(&l);
	printf("%d", a->elemento);
	push(&l, 5);
	a = peak(&l);
	printf("%d", a->elemento);
	
	return 0;
}

