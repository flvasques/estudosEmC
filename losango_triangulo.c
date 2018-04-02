#include <stdio.h>
#include <stdlib.h>

int main()
{
	int linha, coluna, qtd = 0, metade = 0;
	printf("Imprecoes repetidas de '*'\n");
	printf("Informe um numero de Linhas\n");
	scanf("%i", &qtd);
	qtd = qtd % 2 == 0 ? qtd + 1 : qtd;
	for(linha = 0; linha < qtd; linha++)
	{
		for (coluna = 0; coluna <= linha; coluna++)
		{
			printf("*");
		}

		printf("\n");
	}
	printf("\n");
	for(linha = qtd; linha > 0; linha--)
	{
		for (coluna = linha; coluna > 0; coluna--)
		{
			printf("*");
		}

		printf("\n");
	}
    metade = qtd / 2;
    printf("\n%i\n", metade);
    for(linha = 0; linha < metade + 1; linha++)
	{
		for (coluna = 0; coluna <= metade  + linha; coluna++)
		{
			if(coluna < metade - linha)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}

		printf("\n");
	}
	for(linha = 0; linha < metade; linha++)
	{
		for (coluna = 0; coluna <= metade  + linha; coluna++)
		{
			if(coluna > metade - linha)
			{
				printf("*");
			}
			else
			{
				printf("=");
			}
		}

		printf("\n");
	} 		
	return 0;
}