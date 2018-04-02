#include <stdio.h>
#include <stdlib.h>

int fatorial(int valor);
int main(int argc, char *argv[])
{
	//int vetor[] = {1, 1, 1, 1, 1};
	int numero = atoi(argv[1]);
	long unsigned int resultado = fatorial(numero);
	printf("Fatorial de %i: %lu\n", numero, resultado);
	
	return 0;
}
int fatorial(int valor)
{
	if( valor  < 0 )
	{
		printf("Erro: Parametro negativo!\n");
		return 0;
	}
	else if( valor == 0 )
	{
		return 1;
	}
	else
	{
		return valor * fatorial(valor - 1);
	}
}