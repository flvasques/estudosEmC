#include <stdio.h>
#include <stdlib.h>

#define texto 5000

typedef struct node{
	int info;
	struct node *prox;
	struct node *ant;
}no;

typedef struct {
	no *primeiro;
	int tam;
}lista_enc;

no * novo_no(int valor);
lista_enc * nova_lista();

void receber_string(char *var);
void limpar_buffer();
void limpar_tela();

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
	fflush ( stdin ); //Utilizar no Windows
	//__fpurge ( stdin ); #include <stdio_ext.h> //Utilizar no linux
}
void limpar_tela()
{
	//system("clear"); //Utilizar no linux
	system("cls"); //Utilizar no Windows
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
	l->tam = 0;

	return l;
}
