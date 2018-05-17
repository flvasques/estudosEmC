#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define texto 5000

typedef struct node{
	int info;
	struct node *prox;
	struct node *ant;
}no;

typedef struct {
	no *primeiro;
	no *ultimo;
	int tam;
	char sinal;
}lista_enc;

no * novo_no(int valor);
lista_enc * nova_lista();

void receber_string(char *var);
void limpar_buffer();
void limpar_tela();
void imprime_numero(lista_enc *l);
void insere_fim(lista_enc *l, int valor);
void set_valor(lista_enc *l, char *num);

void menu();

int main()
{
	char *str_1;
	limpar_tela();
	printf("\t\tSeja Bem Vindo!\n");
	printf("Informe um valor ou x para sair.\n");
	receber_string(str_1);
	menu();
	return 0;
}
void menu(){
	char *str_2;
	char opt = '\0';
	limpar_buffer();
	

	printf("Soma(+) / Subtracao(-) x para sair.\n");
	while((opt !='+') && (opt != '-') && (opt != 'x') )
	{
		opt = getchar();
		limpar_buffer();	
	}
	if(opt == 'x') exit(0);

	printf("Informe o segundo valor ou x para sair.\n");
	
	receber_string(str_2);
	menu();
}
void receber_string(char *var)
{
	limpar_buffer();
	fgets(var, texto,stdin);
	limpar_buffer();
	if(var[0] !='x')
	{
		int i = 0;
		while(var[i] != '\0')i++;
		var[i - 1] = '\0';
	}
	else
	{	limpar_tela();
		exit(0);
	}
}

void limpar_buffer()
{
	//fflush ( stdin ); //Utilizar no Windows
	__fpurge ( stdin ); //Utilizar no linux
}
void limpar_tela()
{
	system("clear"); //Utilizar no linux
	//system("cls"); //Utilizar no Windows
}

no * novo_no(int valor)
{
	no *n = malloc(sizeof(no));
	n->info = valor;
	n->prox = NULL;
	n->ant = NULL;
	return n;
}
lista_enc * nova_lista()
{
	lista_enc * l = malloc(sizeof(lista_enc));
	l->primeiro = NULL;
	l->ultimo = NULL;
	l->tam = 0;
	l->sinal ='\0';
	return l;
}
void apaga_no(no** nodo)
{
	if (nodo == NULL) return;
	no* n = *nodo;
	free(n);
	n = NULL;
}
void apaga_lista(lista_enc *l)
{
	no* n = l->ultimo;
	no* aux;
	while(n != NULL)
	{
		aux = n;
		n = n->prox;
		apaga_no(&aux);
	}
}
void insere_fim(lista_enc *l, int valor)
{
	no* n = novo_no(valor);
	n->ant = l->ultimo;
	l->ultimo = n;
	if (l->primeiro == NULL) l->primeiro = n;

	l->tam++;
}
void imprime_numero(lista_enc *l)
{
	if (l->tam < 1)
	{
		printf("0");
	}
	else
	{
		no* n = l->primeiro;
		while(n != NULL)
		{
			if (n->info > 99 || n == l->primeiro)
				printf("%d", n->info);
			else
			{
				if (n->info > 9)
					printf("0%d", n->info);
				else if (n->info > 0)
					printf("00%d", n->info);
				else 
					printf("000");
			}
			n = n->prox;
			if (n != NULL)
				printf(".");
		}
		printf("\n");
	}
}

void set_valor(lista_enc *l, char *num)
{
	l->sinal = num[0] == '-' ? '-' : '+';
	int i;
	char aux[3];
	int valor;
	for(i = strlen(num) - 1; i > 0;  i -= 3)
	{
		aux[0] = num[i - 2];
		aux[1] = num[i - 1];
		aux[2] = num[i];
		int valor = atoi(aux);
		no *n = novo_no(valor);
		n->ant = l->ultimo;
		l->ultimo->prox = n;
		if(l->primeiro = NULL) l->primeiro = n;
	}
}