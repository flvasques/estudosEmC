#include <stdio.h>
#include <stdlib.h>

int soma_vetor(int vet[], int tam);
int main(int argc, char *argv[])
{
	//int vetor[] = {1, 1, 1, 1, 1};
	int *vetor = malloc( ( sizeof(int) * (argc - 1) ) );
	int i;
	for(i = 1; i <= (argc - 1); i++)
	{
		vetor[i - 1] = atoi(argv[i]);
	}
	int resultado = soma_vetor(vetor, argc - 1 );
	printf("Soma: %i\n", resultado);
	
	return 0;
}
int soma_vetor(int vet[], int tam)
{
	if(tam > 1)
	{
		tam--;
		return vet[tam] + soma_vetor(vet, tam);
	}
	else
	{
		return vet[tam - 1];
	}
}