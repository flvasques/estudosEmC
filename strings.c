#include <stdio.h>
#include <stdlib.h>

void receber_string(char *var);
void limpar_buffer();
void trocar_vogais(char *var);

#define texto 255

int main(int argc, char const *argv[])
{/*
	int dia, mes, ano;
	printf("Dia: ");
	scanf("%i",&dia);
	printf("Mes: ");
	scanf("%i",&mes);
	printf("Ano: ");
	scanf("%i",&ano);
	printf("%d/%d/%d\n",dia,mes,ano );
*/
/*
	float valor_um =  7.8954, valor_dois = 3456.345;
	printf("%f \t%f\n", valor_um, valor_dois);
	printf("%.15f \t%.3f\n", valor_um, valor_dois);
	printf("%10f \t%10f\n", valor_um, valor_dois);
	printf("%10.2f \t%10.2f\n", valor_um, valor_dois);
*/
/*
	int qtd_banana = 0, qtd_uva = 0;
	float preco_banana = 0, preco_uva = 0, total_banana = 0, total_uva = 0, sub_total = 0, imposto = 0, total = 0;
	printf("Informe os seguintes dados:\n");
	printf("Preco da Banana: ");
	scanf("%f", &preco_banana);
	printf("Quantidade de Bananas: ");
	scanf("%i", &qtd_banana);
	printf("Preco da Uva: ");
	scanf("%f", &preco_uva);
	printf("Quantidade de Uvas: ");
	scanf("%i", &qtd_uva);
	total_banana = preco_banana * qtd_banana;
	total_uva = preco_uva * qtd_uva;
	sub_total = total_banana + total_uva;
	imposto = sub_total * 0.05;
	total = sub_total + imposto;

	printf("Produto |Preco Unitario | Quantidade\t|Preco Total\n");
	printf("________|_______________|_______________|___________\n");
	printf("Banana  |R$  %.2f\t|\t%i\t|R$\t %.2f\n", preco_banana, qtd_banana, total_banana);
	printf("Uva     |R$  %.2f\t|\t%i\t|R$\t %.2f\n", preco_uva, qtd_uva, total_uva);
	printf("        |               |Sub_Total\t|R$ \t %.2f\n", sub_total);
	printf("________|_______________|_______________|___________\n");	
	printf("________|Imposto ( 5%c )\t\t\t|R$ \t %.2f\n", 37,imposto);
	printf("________|_______________|_______________|___________\n");
	printf("\t\tTotal\t\t R$ \t %.2f\n",total);
*/
/*
	float lado_a = 0, lado_b = 0, lado_c = 0;
	printf("Condicao de Existencia de Tringulos\n");
	printf("Informe o primeiro lado: ");
	scanf("%f", &lado_a);
	printf("Informe o segundo lado: ");
	scanf("%f", &lado_b);
	printf("Informe o terceiro lado: ");
	scanf("%f", &lado_c);
	if( (lado_a > 0) && (lado_b > 0) && (lado_c > 0) )
	{
		if((lado_a <= (lado_b + lado_c)) && (lado_b <= (lado_a + lado_c)) && (lado_c <= (lado_b + lado_a)))
		{
			printf("Triangulo Valido.\n");
		}
		else{
			printf("Triangulo Invalido\n");
		}
	}
	else
	{
		printf("Lados Invalidos.\n");
	}
*/
/*
	int planeta = 0;
	float peso = 0;
	printf("\nConversao de Peso Escolha um Planeta\n");
	printf("1 - Mercurio\t2 - Venus\t3 - Marte\n4 - Jupter\t5 - Saturno\t6 - Urano\n");
	scanf("%i", &planeta);
	limpar_buffer();
	printf("Informe seu peso: ");
	scanf("%f", &peso);
	limpar_buffer();
	switch(planeta)
	{
		case 1:
			peso *= 0.37;
			printf("Seu peso em Mercurio %f\n", peso); 
			break;
		case 2:
			peso *= 0.88;
			printf("Seu peso em Venus %f\n", peso); 
			break;
		case 3:
			peso *= 0.38;
			printf("Seu peso em Marte %f\n", peso); 
			break;
		case 4:
			peso *= 2.64;
			printf("Seu peso em Jupiter %f\n", peso); 
			break;
		case 5:
			peso *= 1.15;
			printf("Seu peso em Saturno %f\n", peso); 
			break;
		case 6:
			peso *= 1.17;
			printf("Seu peso em Urano %f\n", peso); 
			break;
	}
*/
/*
	int anos = 0;
	float chico = 1.5, ze = 1.1, incremento_chico = 0.02, incremento_ze = 0.04;
	while(ze <= chico)
	{
		chico += incremento_chico;
		ze += incremento_ze;
		anos++;
		printf("Altura Chico: %f - Altura Ze: %f\n", chico, ze);
	}
	printf("Ze vai precisar de %i ano(s) para passar Chico em Altura", anos);
*/
/*
	int vet_um[5], vet_dois[5];
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("Valor %i do primeiro conjunto.\n", ( i + 1 ));
		scanf("%i", &vet_um[i]);
		printf("Valor %i do segundo conjunto.\n", ( i + 1 ));
		scanf("%i", &vet_dois[i]);
	}
	for(i = 0; i < 5; i++)
	{
		vet_um[i] = vet_um[i] + vet_dois[i];
		printf("[ %i ]", vet_um[i]);
	}
	printf("\n");
*/
/*
	char *primeira, *segunda;
	printf("Primeira string: ");
	receber_string(primeira);
	printf("Segunda string: ");
	receber_string(segunda);
	int i = 0;
	while(primeira[i] != '\0')
	{
		i++;
	}
	printf("Tamanho da primeira: %i\n", i);
	i = 0;
	while(primeira[i] != '\0')
	{
		i++;
	}
	printf("Tamanho da segunda: %i\n", i);
*/
	char frase[50];
	printf("Informe a frase: ");
	receber_string(frase);
	trocar_vogais(frase);
	printf("Nova frase: %s\n", frase);

	return 0;
}

void receber_string(char *var)
{
	limpar_buffer();
	fgets(var, texto,stdin);
	int i = 0;
	while(var[i] != '\0')i++;
	var[i - 1] = '\0';
	limpar_buffer();

}

void limpar_buffer()
{
	fflush ( stdin );
	//__fpurge ( stdin );
}

void trocar_vogais(char *var)
{
	int i = 0;
	while(var[i] != '\0')
	{
		if( (var[i] == 'a') || (var[i] == 'e') || (var[i] == 'i') || (var[i] == 'o') || (var[i] == 'u') ) var[i] = '*';
	}
}