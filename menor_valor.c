#include <stdio.h>
#include <stdlib.h>

int menor_valor(int vet[], int tam);
int main()
{
	int vetor[] = {9, 4, -3, 5, 2, 1, 3, 0,10,33};
	int resultado = menor_valor(vetor, (sizeof(vetor) / sizeof(int)));
	printf("O menor valor e: %i\n", resultado);
	
	return 0;
}
int menor_valor(int vet[], int tam) 
{
	return (tam > 1 ? (vet[0] > vet[tam - 1] ? menor_valor(vet + 1, tam) : menor_valor(vet, tam-1)) : vet[0]);
	/*
	if(tam > 1)
	{
		if(vet[0] > vet[tam - 1])
		{
			return menor_valor(vet + 1, tam);
		}
		else
		{
			return menor_valor(vet, tam-1);
		}
	}
	else
	{
		return vet[0];
	}
	*/
}
