#include <stdio.h>
#include <stdlib.h>
#include "listaDupEnc.h"

lista novaPilha()
{	return novaLista();
}
no pop(lista *l)
{	no n = retiraInicio(l);
	return n;
}
no peak(lista *l)
{	no *n  = percorre(l, 1);
	return *n;
}
void push(lista *l, int i)
{	no *n = novoNo(i);
	int r = insereNoInicioP(l, n);
}