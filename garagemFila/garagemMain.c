#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaPilha.h"

char opt;
garagem *l;
garagem *p;
carro *a;

void menu();
void limparBuffer();
void limparTela();
int main()
{	l = novaFila();
	p = novaPilha();
	limparTela();	
	menu();
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
void menu()
{	limparBuffer();
	printf("Escolha uma opcao:");
	printf("\n1.Estacionar\t2.Procurar Veiculo\t3.Procurar e Retirar\n");
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
			enqueue(l, n, m);
			limparTela();
		break;
		case '2':
		printf("Informe a placa do Veiculo: ");
			fgets(n,255,stdin);
			limparBuffer();
			achou = 0;
			while(l->tam > 0 && achou == 0)
			{	a = pop(l);
				if(strcmp(n, a->placa))
				{	achou = 1;
				}
				enqueueP(p, a);
				j++;
				if(j % 4 == 0)	printf("\n");
			}
			while(p->tam > 0)
			{	a = pop(p);
				enqueueP(l, a);
			}
			limparTela();
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
			{	a = dequeue(l);
				printf("%d: %s, %s\t",a->id, a->placa, a->modelo);
				enqueueP(p, a);
				j++;
				if(j % 4 == 0)	printf("\n");
			}
			while(p->tam > 0)
			{	a = pop(p);
				pushP(l, a);
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
				{ pushP(p, a);
				}
				j++;
				if(j % 4 == 0)	printf("\n");
			}
			while(p->tam > 0)
			{	a = pop(p);
				enqueueP(l, a);
			}
			limparTela();
			if (achou == 0)
			{	printf("Veiculo nao encontrado\n");
			}
			else
			{	printf("Veiculo retirado\n");
			}
		break;
		case 'x':
			limparTela();
			printf("\t\t\tATE LOGO\n\n");
			exit(0);
		break;
	}
	menu();
}