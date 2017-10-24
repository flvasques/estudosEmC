#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filha.h"

char opt;
garagem *l;
garagem *p;
carro *a;

void menu();
void limparBuffer();

int main()
{	l = novaFila();
	p = novaPilha();
	system("cls");
	menu();
	return 0;
}
void limparBuffer()
{	fflush(stdin);
	//__fpurge(stdin);
}
void menu()
{
	printf("Escolha uma opcao:");
	printf("Estacionados atualmente: %d", l->tam);
	printf("\n1.Estacionar\t2.Retirar\t3.Porcurar\n");
	printf("\n4.Listar\tx.Sair\n");
	opt = getchar();
	char n[255];
	limparBuffer();
	switch (opt)
	{
		case '1':
			printf("Informe placa do Veiculo: ");
			fgets(n,255,stdin);
			limparBuffer();
			n[strlen(n)-1] = '\0';
			push(l, n);
			system("cls");
			//system("clear");
		break;
		case '2':
		
		break;
		case '3':
		
		break;
		case '4':
			
			printf("\n");
			int j = 0;
			while(l->tam > 0)
			{	a = pop(l);
				printf("%s\t",a->placa);
				pushPilhaP(p, a);
				j++;
				if(j % 4 == 0)	printf("\n");
			}
			puts("saiu");
			while(p->tam > 0)
			{	a = popPilha(p);
				pushFila(l, a);
			}
		break;
		case 'x':
			system("cls");
			//system("clear");
			printf("\t\t\tATE LOGO\n\n");
			exit(0);
		break;
	}
	//system("cls");
	menu();
}