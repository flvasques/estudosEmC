#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "filaPilha.h"

char opt;
garagem *l;
garagem *p;
carro *a;

void menu();
void limparBuffer();

int main()
{	l = novaFila();
	p = novaPilha();
	//system("cls");
	system("clear");
	menu();
	return 0;
}
void limparBuffer()
{	//fflush(stdin);
	__fpurge(stdin);
}
void menu()
{	limparBuffer();
	printf("Escolha uma opcao:");
	printf("\n1.Estacionar\t2.Retirar próximo\t3.Porcurar e Retirar\n");
	printf("\nx.Sair\n");
	opt = getchar();
	char n[255];
	char m[255];
	int i;
	int j = 0;
	int achou = 0;
	limparBuffer();
	switch (opt)
	{
		case '1':
			printf("Informe a placa do Veiculo: ");
			fgets(n,255,stdin);
			limparBuffer();
			n[strlen(n)-1] = '\0';
			printf("Informe o modelo do Veiculo: ");
			fgets(m,255,stdin);
			limparBuffer();
			m[strlen(m)-1] = '\0';
			push(l, n, m);
			//system("cls");
			system("clear");
		break;
		case '2':
		printf("Informe a placa do Veiculo: ");
			fgets(n,255,stdin);
			limparBuffer();
			while(l->tam > 0 && achou == 0)
			{	a = pop(l);
				if(strcmp(n, a->placa))
				{	achou = 1;
					free(a);
				}
				else
				{ pushPilhaP(p, a);
				}
				j++;
				if(j % 4 == 0)	printf("\n");
			}
			while(p->tam > 0)
			{	a = popPilha(p);
				pushFila(l, a);
			}
			if (achou == 0)
			{	printf("Veiculo nao encontrado\n");
			}
			else
			{	printf("Veiculo estacionado na vaga %d\n", j);
			}
		break;
		case '3':
			printf("Estacionados atualmente: %d\n", l->tam);
			printf("\n");
			j = 0;
			while(l->tam > 0)
			{	a = pop(l);
				printf("%d: %s, %s\t",a->id, a->placa, a->modelo);
				pushPilhaP(p, a);
				j++;
				if(j % 4 == 0)	printf("\n");
			}
			while(p->tam > 0)
			{	a = popPilha(p);
				pushFila(l, a);
			}
			limparBuffer();
			printf("\nInforme o id do Veiculo: ");
			scanf("%d",&i);
			while(l->tam > 0 && achou == 0)
			{	a = pop(l);
				if(a->id == i)
				{	achou = 1;
					free(a);
				}
				else
				{ pushPilhaP(p, a);
				}
				j++;
				if(j % 4 == 0)	printf("\n");
			}
			while(p->tam > 0)
			{	a = popPilha(p);
				pushFila(l, a);
			}
			if (achou == 0)
			{	printf("Veiculo nao encontrado\n");
			}
			else
			{	printf("Veiculo retirado\n");
			}
		break;
		case 'x':
			//system("cls");
			system("clear");
			printf("\t\t\tATE LOGO\n\n");
			exit(0);
		break;
	}
	//system("cls");
	menu();
}