#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define tam 101

typedef struct string
{
	char palavra[tam];
	struct no *prox;
} no;

typedef struct lista
{
	no *primeiro;
} pilha;



no *novo(char *valor);
void receber_string(char *var);
void percore(pilha *p);

pilha *criaPilha();
int push(pilha *p, char *valor);
int pop(pilha *p, char *valor);
void invertePilha(pilha *p);

int main()
{
	pilha *p1 = criaPilha();
	
	char escreva[tam];
	int i;
	for(i = 0; i < 4; i++)
	{
		receber_string(escreva);
		push(p1, escreva);
	}
	printf("Pilha\n");
	percore(p1);
	invertePilha(p1);
	printf("Pilha Invertida\n");
	percore(p1);

	return 0;
}

void limpar_buffer()
{
	//fflush ( stdin );
	__fpurge ( stdin );
}


pilha *criaPilha()
{
	pilha *p = malloc(sizeof(pilha));
	p->primeiro = NULL;
	return p;
}

int push(pilha *p, char *valor)
{
	no *node = novo(valor);
	node->prox = p->primeiro;
	p->primeiro = node; 
	return 1;
}

int pop(pilha *p, char *valor)
{	 
	if(p->primeiro == NULL)
	{
		return 0;
	}
	else
	{
		no *aux = p->primeiro;
		p->primeiro = aux->prox;
		int i = 0;
		while(aux->palavra[i] != '\0')
		{
			valor[i] = aux->palavra[i];
			i++;
		}
		valor[i] = '\0';
		aux->prox = NULL;
		free(aux->palavra);
	}

	return 1;
}

void invertePilha(pilha *p)
{
	char val[tam];
	int cont = 1;
	pilha *nova = criaPilha();
	pilha *aux = criaPilha();
	while(cont == 1)
	{
		cont = pop(p, val);
		if(cont == 1)
		{
			push(nova, val);
		}	
	}
	cont = 1;
	while(cont == 1)
	{
		cont = pop(nova, val);	
		if(cont == 1)
		{
			push(aux, val);
		}
	}
	cont = 1;
	while(cont == 1)
	{
		cont = pop(aux, val);	
		if(cont == 1)
		{
			push(p, val);
		}
	}
}

no *novo(char *valor)
{
	no *n = malloc(sizeof(no));
	int i = 0;
	while(valor[i] != '\0')
	{
	  n->palavra[i] = valor[i];
	  i++;
	}
	n->palavra[i] = '\0';
	n->prox = NULL;
	return n;
}

void receber_string(char *var)
{
	printf("Informe sua palavra!\n");
	limpar_buffer();
	fgets(var, tam,stdin);
	int i = 0;
	while(var[i] != '\0')i++;
	var[i - 1] = '\0';
	limpar_buffer();
}

void percore(pilha *p)
{
	char retorno[tam];
	pilha *nova = criaPilha();
	printf("==================\n");
	if(p->primeiro == NULL){
		printf("vazio\n");
	}
	else
	{
		while(p->primeiro != NULL)
		{
			pop(p, retorno);
			printf("%s\n", retorno);
			push(nova, retorno);
		}
		while(nova->primeiro != NULL)
		{
			pop(nova, retorno);
			push(p, retorno);
		}
	}	
	
	printf("==================\n");
		
}