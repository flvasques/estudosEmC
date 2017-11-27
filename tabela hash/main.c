#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE,"Portuguese");
	FILE *arquivo;
	char linha[151];

	int n = 0;
	arquivo = fopen("entrada.txt", "r");
	if(arquivo == NULL)
	{
		puts("Arquivo não encontrado");
		return 1;
	}

	while(fgets(linha, 150, arquivo) != NULL)
	{
		printf("%s\n", linha);
	}

	return 0;
}