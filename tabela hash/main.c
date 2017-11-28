#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>
#include "bibHash.h"

#define SIZE 26
char opt;

void loadFile();
void limparBuffer();
void limparTela();
void menu();

int main()
{	setlocale(LC_CTYPE,"Portuguese");
	limparBuffer();
	
	lista *tabela = (lista *)malloc(sizeof(lista) * SIZE);

	int cont;
	for(cont = 0; cont < SIZE; cont++)
	{	tabela[cont] = novaLista();
	}
	inserir("Fernando", "1234", tabela);
	for(cont = 0; cont < SIZE; cont++)printf("%d\n", tabela[cont].tam);
	return 0;
}

void limparBuffer()
{	fflush(stdin);
	//__fpurge(stdin);
}
void limparTela()
{
	system("cls");
	//system("clear");
}
void loadFile()
{	FILE *arquivo;
	char linha[151];

	int n = 0;
	arquivo = fopen("entrada.txt", "r");
	if(arquivo == NULL)
	{
		puts("Arquivo não encontrado");
	}

	while(fgets(linha, 150, arquivo) != NULL)
	{
		printf("%s\n", linha);
	}
}	//system("clear");
void menu()
{	limparBuffer();
	printf("Escolha uma opcao:");
	printf("\n1. \t2. \t3. \n");
	printf("\nx.Sair\n");
	opt = getchar();

	limparBuffer();
	switch (opt)
	{	case '1':
			
		break;
		case '2':
		
		break;
		case '3':
			
		break;
		case 'x':
			limparTela();
			printf("\t\t\tATE LOGO\n\n");
			exit(0);
		break;
	}
	menu();
}