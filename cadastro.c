#include <stdio.h>
#include <stdlib.h>

#define texto 255

typedef struct 
{
	char rua[texto];
	char cep[texto];
 	char cidade[texto];
	char numero[6];
} endereco;
typedef struct
{
	char nome[texto];
	char idade[3]; 
	char telefones[5][15];
	endereco *end;
} pessoa;
typedef struct
{
	pessoa *lista;
	int total;
}listagem;

pessoa* nova_pessoa();
void receber_string(char *var);
void limpar_buffer();
void set_pessoa(pessoa *p);
void get_pessoa(pessoa *p);

int main()
{
	pessoa *p1 = nova_pessoa();
	set_pessoa(p1);
	get_pessoa(p1);
	

	return 0;
}

pessoa* nova_pessoa()
{
	pessoa *p = malloc(sizeof(pessoa));
	endereco *e = malloc(sizeof(endereco));
	p->nome[0] = '\0';
	p->idade[0] = '\0';
	p->telefones[0][0] = '\0';
	p->telefones[0][1] = '\0';
	p->telefones[0][2] = '\0';
	p->telefones[0][3] = '\0';
	p->telefones[0][4] = '\0';
	e->rua[0] = '\0';
	e->cep[0] = '\0';
	e->cidade[0] = '\0';
	e->numero[0] = '\0';
	p->end = e;
	return p;
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

void set_pessoa(pessoa *p)
{
	int j = 1;
	char controle;

	printf("Informe seu nome: ");
	receber_string(p->nome);

	printf("Informe sua idade: ");
	receber_string(p->idade);

	printf("Informe seu Primeiro telefone: ");
	receber_string(p->telefones[0]);


	printf("Outro Telefone? s/n ");
	controle = getchar();
	limpar_buffer();
	

	while(controle == 's' && j < 5)
	{
		printf("Informe seu telefone seguinte: ");
		receber_string(p->telefones[j]);
		j++;
		printf("Outro Telefone? s/n ");
		controle = getchar();
		limpar_buffer();
	}

	printf("Informe seu CEP: ");
	receber_string(p->end->cep);

	printf("Informe seu Rua: ");
	receber_string(p->end->rua);

	printf("Informe seu Cidade: ");
	receber_string(p->end->cidade);

	printf("Informe seu Numero: ");
	receber_string(p->end->numero);
}

void get_pessoa(pessoa *p)
{
	int j = 0;
	printf("Ola: %s \n", p->nome);
	printf("Sua idade: %s \n", p->idade);

	while(p->telefones[j][0] != '\0' && j < 5)
	{
		printf("Telefones[ %s ]\n", p->telefones[j]);
		j++;
	}
	printf("Seu CEP: %s \n", p->end->cep);
	printf("Seu CEP: %s \n", p->end->rua);
	printf("Seu CEP: %s \n", p->end->cidade);
	printf("Seu CEP: %s \n", p->end->numero);
}