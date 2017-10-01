#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float modulo(float a, float b);
int main(){
	/*int dia, mes, ano;
	printf("dia:");
	scanf("%d",&dia);
	//_fflush(stdin);
	printf("mes:");
	scanf("%d",&mes);
	//_fflush(stdin);
	printf("ano:");
	scanf("%d",&ano);
	//_fflush(stdin);
	printf("Sua data: %d/%d/%d",dia,mes,ano);
	*/
	//=============
	/*float x = 7.8954, y = 3456.345;
	printf("%f \t%f\n",x,y);
	printf("%.15f \t%.3f\n",x,y);
	printf("%10f \t%10f\n",x,y);
	printf("%10.2f \t%10.2f\n",x,y);
	*/
	//===============
	/*char c1,c2;
	scanf("%c",&c1);
	//__fpurge(stdin); //comente essa linha
	scanf("%c",&c2);
	printf("(%c)(%c)",c1,c2);
	*/
	//=============
	/* //CALCULANDO UMA TABELINHA
	int qtdBanana, qtdUva;
	float precoBanana, precoUva, totalBanana, totalUva, subTotal,imp, total;
	printf("Informe a quantidade de bananas: ");
	scanf("%i", &qtdBanana);
	printf("Informe o preco das bananas: ");
	scanf("%f",&precoBanana);
	printf("Informe a quantidade de uvas: ");
	scanf("%i",&qtdUva);
	printf("Informe o preco das uvas: ");
	scanf("%f",&precoUva);
	totalBanana = precoBanana * qtdBanana;
	totalUva = precoUva * qtdUva;
	subTotal = totalBanana + totalUva;
	imp = subTotal * 0.05;
	total = imp + subTotal;
	
	printf("____________________________________________________\n");
	printf("Produto |Preco Unitario  |Quantidade |Preco Total \n");
	printf("____________________________________________________\n");
	printf("Banana  |R$ %.2f\t |%10i |R$ %10.2f\n", precoBanana, qtdBanana, totalBanana);
	printf("Uva     |R$ %.2f\t |%10i |R$ %10.2f\n", precoUva, qtdUva, totalUva);
	printf("\t|\t\t |Sub_Total  |R$ %10.2f\n", subTotal);
	printf("____________________________________________________\n");
	printf("\t|Imposto (5\%)\t\t     |R$ %10.2f\n", total);
	printf("____________________________________________________\n");
	printf("\t\t\t\t    R$ %10.2f\n",total);
	
	//===============
	//TRINAGULO
	float a, b, c;
	printf("Primeiro Lado: ");
	scanf("%d",&a);
	printf("Segundo Lado: ");
	scanf("%d",&b);
	printf("Terceiro Lado: ");
	scanf("%d",&c);
	if(((modulo(a, b) < c) && (c < (a + b))) && ((modulo(b, c) < a) && (a < (b + c))) &&((modulo(a, c) < b) && (b < (a + a))))
	{
		printf("Trinagulo Possivel.");
	}
	else
	{
		printf("Nao forma triangulo.");
	}
	//===========
	//Switch
	float peso;
	int seletor;
	printf("Informe seu peso na terra: ");
	scanf("%f",&peso);
	printf("\t ECOLHA O PALNETA\n");
	printf("1-Mercurio\t2-Venus \t3-Marte\n4-Jutiper\t5-Saturno\t6-Urano\n");
	scanf("%i",&seletor);
	switch(seletor){
		case 1:
			peso *= 0.37;
			printf("%f",peso);
		break;
		case 2:
			peso *= 0.88;
			printf("%f",peso);
		break;
		case 3:
			peso *= 0.38;
			printf("%f",peso);
		break;
		case 4:
			peso *= 2.64;
			printf("%f",peso);
		break;
		case 5:
			peso *= 1.15;
			printf("%f",peso);
		break;
		case 6:
			peso *= 1.17;
			printf("%f",peso);
		break;
		
	}
	*/
	float ze = 1.5, chico = 1.1;
	int i = 0;
	while(ze >= chico){
		ze += 0.02;
		chico += 0.04;
		i++;
	}
	printf("\nChico sera mais alto em %i anos",i);
	return 0;
}
float modulo(float a, float b)
{
	float v = a - b;
	if(v < 0.0)
	{
		return (v * -1.0);
	}
	else
	{
		return v;
	}
	
	printf("dia:");
	scanf("%d",&dia);
	//_fflush(stdin);
	printf("mes:");
	scanf("%d",&mes);
	//_fflush(stdin);
	printf("ano:");
	scanf("%d",&ano);
	//_fflush(stdin);
	printf("Sua data: %d/%d/%d",dia,mes,ano);
	return 0.0;
}
