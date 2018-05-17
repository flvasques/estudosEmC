#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_de.h"





// Funções de Nodo
nodo* nod_nov(nodo *anterior, nodo *proximo, int val)
{
	nodo *n = (nodo*)malloc(sizeof(nodo));

	if (anterior != NULL)
	{
		anterior->proximo = n;
		n->anterior = anterior;
	}
	else n->anterior = NULL;

	if (proximo != NULL)
	{
		n->proximo = proximo;
		proximo->anterior = n;
	}
	else n->proximo = NULL;

	n->valor = val;
	return n;
}

void nod_setval(nodo* n, int val)
{
	n->valor = val;
}

int nod_val(nodo* n)
{
	if (n == NULL) return 0;
	return n->valor;
}

void nod_imp(nodo* n)
{
	if (n == NULL) printf("Nodo inválido.");
	else
	{
		if (nod_ant(n) != NULL)
			printf("%3d <- ", nod_val(nod_ant(n)));
		else
			printf("--- <- ");
		printf("%3d", nod_val(n), nod_val(nod_pro(n)));
		if (nod_pro(n) != NULL)
			printf(" -> %3d", nod_val(nod_pro(n)));
		else
			printf(" -> ---");
	}
}

nodo* nod_pro(nodo* n)
{
	if (n == NULL) return NULL;
	return n->proximo;
}

nodo* nod_ant(nodo* n)
{
	if (n == NULL) return NULL;
	return n->anterior;
}

void nod_des(nodo** n)
{
	if (n == NULL) return;
	nodo* nod = *n;

	nodo* nant = nod->anterior;
	if (nant != NULL)
	{
		nant->proximo = nod->proximo;
	}
	nodo* npro = nod->proximo;
	if (npro != NULL)
	{
		npro->anterior = nod->anterior;
	}

	free(nod);
	nod = NULL;
}








// Funções de Lista
lista* lst_nov()
{
	//alocando a lista
	lista *l = (lista*)malloc(sizeof(lista));

	// inicializando valores
	l->tamanho=0;
	l->primeiro = NULL;
	l->ultimo = NULL;
	return l;
}

int lst_ins(lista *l, int val, int posicao)
{
	if (posicao > l->tamanho) return err_pos;
	if (posicao < 0) return err_pos;

	if (posicao == 0) return lst_ins_ini(l, val);
	if (posicao == l->tamanho) return lst_ins_fim(l, val);

	nodo* naux = l->primeiro;
	if (naux == NULL)
	{
		return err_nul;
	}
	else
	{
		nodo* nant = NULL;
		for(int i = 0; i < posicao; ++i)
		{
			if (naux == NULL) return err_pos;
			nant = naux;
			naux = nod_pro(naux);
		}
		nodo* n = nod_nov(nant, naux, val);
	}
	l->tamanho++;
	return err_nen;
}

int lst_ins_ini(lista *l, int valor)
{
	if(l->tamanho < 1) return lst_ins_fim(l, valor);

	if (l->ultimo == NULL) l->ultimo = l->primeiro;

	l->primeiro = nod_nov(NULL, l->primeiro, valor);

	l->tamanho++;
	return err_nen;
}

int lst_ins_fim(lista *l, int valor)
{
	nodo* n = nod_nov(l->ultimo, NULL, valor);
	l->ultimo = n;
	if (l->primeiro == NULL) l->primeiro = n;

	l->tamanho++;
	return err_nen;
}

int lst_exc(lista *l, int pos)
{
	if (pos >= l->tamanho) return err_pos;
	if (pos < 0) return err_pos;

	nodo* n = l->primeiro;
	nodo* nant = NULL;

	for (int i = 0; i < pos; ++i)
	{
		if (n == NULL) return err_pos;

		nant = n;
		n = nod_pro(n);
	}

	if (n->anterior == NULL)
	{
		l->primeiro = nod_pro(l->primeiro);
	}
	if (n->proximo == NULL)
	{
		l->ultimo = nod_ant(l->ultimo);
	}

	nod_des(&n);
	
	l->tamanho--;
	return err_nen;
}

void lst_imp(lista *l)
{
	if (l->tamanho < 1)
	{
		puts("Lista vazia.");
	}
	else
	{
		nodo* n = l->ultimo;
		printf("Lista de %d elementos:\n", l->tamanho);
		while(n != NULL)
		{
			nod_imp(n);
			printf("\n");
			n = nod_ant(n);
		}
	}
}

int lst_tam(lista *l)
{
	return l->tamanho;
}

int lst_cmp(lista* l1, lista* l2)
{
	if (lst_tam(l1) > lst_tam(l2)) return 1;
	if (lst_tam(l1) > lst_tam(l2)) return -1;

	nodo* n1 = lst_pri(l1);
	nodo* n2 = lst_pri(l2);
	while(n1 != NULL && n2 != NULL)
	{
		if (nod_val(n1) > nod_val(n2)) return 1;
		if (nod_val(n1) < nod_val(n2)) return -1;
		n1 = nod_pro(n1);
		n2 = nod_pro(n2);
	}
	return 0;
}

nodo* lst_pri(lista *l)
{
	if (l->tamanho < 1) return NULL;
	return l->primeiro;
}

void lst_setpri(lista* l, nodo* n)
{
	l->primeiro = n;
}

nodo* lst_ult(lista* l)
{
	if (l->tamanho < 1) return NULL;
	return l->ultimo;
}

void lst_setult(lista* l, nodo* n)
{
	l->ultimo = n;
}

nodo* lst_get(lista* l, int pos)
{
	if (pos >= l->tamanho) return NULL;
	if (pos < 0) return NULL;

	if (pos == 0) return lst_pri(l);
	if (pos == l->tamanho - 1) return lst_ult(l);


	nodo* n = l->primeiro;
	for(int i = 0; i < pos; ++i)
	{
		if (n == NULL) return n;
		n = nod_pro(n);
	}
	return n;
	return NULL;
}

void lst_des(lista **pl)
{
	lista *l = *pl;
	nodo *n = l->primeiro;
	while(n != NULL)
	{
		nodo *nant = n;
		n = nod_pro(n);
		free(nant);
	}
	free(l);
	l = NULL;
	pl = NULL;
}








// Funções de Calculadora
void clc_imp_num(lista *l)
{
	if (lst_tam(l) < 1)
	{
		printf("0");
	}
	else
	{
		nodo* n = lst_pri(l);
		while(n != NULL)
		{
			if (n->valor > 99 || n == lst_pri(l))
				printf("%d", nod_val(n));
			else
			{
				if (n->valor > 9)
					printf("0%d", nod_val(n));
				else if (nod_val(n) > 0)
					printf("00%d", nod_val(n));
				else 
					printf("000");
			}
			n = nod_pro(n);
			if (n != NULL)
				printf(".");
		}
		puts("");
	}
}

void clc_fill(lista* l, char* str)
{
	char* n = (char*)malloc(sizeof(char) * MAX_DIG);
	strcpy(n, str);
	int neg = n[0] == '-';

	if (neg)
	{
		n[0] = '0';
	}

	for (int i = strlen(n) - 1; i >= 0; i -= 3)
	{
		char num[3];
		num[0] = i > 1? n[i-2] : '0';
		num[1] = i > 0? n[i-1] : '0';
		num[2] = n[i];
			
		lst_ins_ini(l, atoi(num));
	}
	// Remover zeros a esquerda
	nodo* nod = l->primeiro;
	while(nod != NULL)
	{
		if (nod_val(nod) == 0)
			lst_exc(l, 0);
		else break;
		nod = nod_pro(nod);
	}

	// Definir ou não a lista como negativa
	if (neg > 0)
	{
		nod = l->primeiro;
		nod_setval(nod, nod_val(nod) * -1);
	}
	free(n);
}

int clc_cmpmod(lista* l1, lista* l2)
{
	if (lst_tam(l1) > lst_tam(l2)) return 1;
	if (lst_tam(l1) > lst_tam(l2)) return -1;

	int l1neg = clc_isneg(l1);
	int l2neg = clc_isneg(l2);
	if (l1neg) clc_neglst(l1);
	if (l2neg) clc_neglst(l2);

	int cmp = lst_cmp(l1, l2);

	if (l1neg) clc_neglst(l1);
	if (l2neg) clc_neglst(l2);
	return cmp;
}

lista* clc_neglst(lista* l)
{
	nodo* n = lst_pri(l);
	nod_setval(n, nod_val(n) * -1);
	lst_setpri(l, n);
	return l;
}

int clc_isneg(lista* l)
{
	return nod_val(lst_pri(l)) < 0;
}

void clc_som_nod(lista *lr, nodo* n1, nodo* n2, int sobra)
{
	if (sobra == 0 && n1 == NULL && n2 == NULL) return;

	int val1 = n1 != NULL ? nod_val(n1) : 0;
	int val2 = n2 != NULL ? nod_val(n2) : 0;

	int soma = val1 + val2 + sobra;
	printf("%d + %d + %d = %d\n", val1, val2, sobra, soma);
	sobra = soma != 0 ? soma/1000 : 0;
	soma = soma % 1000;
	lst_ins_ini(lr, soma);
	clc_som_nod(lr, nod_ant(n1), nod_ant(n2), sobra);
}

void clc_sub_nod(lista *lr, nodo* n1, nodo* n2, int debt)
{
	if (n1 == NULL && n2 == NULL) return;

	int val1 = nod_val(n1);
	int val2 = nod_val(n2);
	if (val1 < 0) val1 *= -1;
	if (val2 < 0) val2 *= -1;

	int subt = val1 - val2 - debt;
	printf("%d - %d - %d = %d", val1, val2, debt, subt);
	if (subt < 0 && nod_ant(n2) != NULL)
	{
		debt = 1;
		subt += 1000;
	}
	else
	{
		debt = 0;
	}
	printf(" -> %d vai %d\n", subt, debt);
	lst_ins_ini(lr, subt);
	clc_sub_nod(lr, nod_ant(n1), nod_ant(n2), debt);
}














// Funções de Menu
lista *men_som(lista* l1, lista* l2)
{
	nodo* n1 = lst_ult(l1);
	nodo* n2 = lst_ult(l2);
	lista* lr = lst_nov();

	if (clc_isneg(l1) == clc_isneg(l2))
		clc_som_nod(lr, n1, n2, 0);
	else
	{
		if (clc_cmpmod(l1, l2) > 0)
		{
			clc_sub_nod(lr, n1, n2, 0);
		}
		else
		{
			clc_sub_nod(lr, n2, n1, 0);
		}
	}

	// Remover zeros a esquerda
	nodo* nod = lr->primeiro;
	while(nod != NULL)
	{
		if (nod_val(nod) == 0)
			lst_exc(lr, 0);
		else break;
		nod = nod_pro(nod);
	}
	return lr;
}

lista *men_sub(lista* l1, lista* l2)
{
	lista* lr;

	if(clc_cmpmod(l1, l2) > 0)
	{
		l2 = clc_neglst(l2);
		lr = men_som(l1, l2);
		l2 = clc_neglst(l2);
	}
	else
	{
		l1 = clc_neglst(l1);
		lr = men_som(l2, l1);
		l1 = clc_neglst(l1);
	}

	// Remover zeros a esquerda
	nodo* nod = lr->primeiro;
	while(nod != NULL)
	{
		if (nod_val(nod) == 0)
			lst_exc(lr, 0);
		else break;
		nod = nod_pro(nod);
	}
	return lr;
}

lista *men_set()
{
	char n[MAX_DIG];

	printf("Digite um numero: ");

	fgets(n, MAX_DIG, stdin);
	n[strlen(n) - 1] = '\0';

	for (int i = 0; i < strlen(n); ++i)
	{
		if (!strchr("0123456789", n[i]))
		{
			if (i == 0 && n[i] == '-') continue;
			lista* l = lst_nov();
			clc_fill(l, "0");
			return l;
		}
	}

	lista* l = lst_nov();
	clc_fill(l, n);

	return l;
}
