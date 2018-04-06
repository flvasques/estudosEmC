#include <stdio.h>

#include <stdlib.h>

#define texto 255

typedef struct
{
	char nome[texto];
	char matricula[texto]; 
	float media;
} aluno;

aluno *alunos;
int total = 0;
int atual = 0;
aluno* novo_aluno();
void receber_string(char *var);
void limpar_buffer();
void limpar_tela();
void set_aluno(aluno *a);
void get_alunos(aluno *a);
void menu();

int main()
{
	limpar_tela();
	limpar_buffer();
	printf("\t\tSeja Bem Vindo!\n");
	printf("Informe o tamanho da sua turma: ");
	scanf("%i", &total);
	alunos = malloc(sizeof(aluno) * total);
	limpar_tela();
	menu();
	return 0;
}
void menu()
{
	char opt;
	limpar_buffer();
	printf("\t\tSeja Bem Vindo!\n");
	printf("\tO que Deseja Fazer?\n");
	printf("1 - Inserir Aluno\t2 - Listar Alunos\tx - Sair\n");
	opt = getchar();
	switch(opt)
	{
		case '1':
			limpar_tela();
			if(atual < total)
			{
				aluno *a = novo_aluno();
				set_aluno(a);
				alunos[atual] = *a;
				atual++;
				limpar_tela();
			}
			else
			{
				puts("Desculpe turma Preenchida!");
			}
			
			menu();
		break;
		case '2':
			get_alunos(alunos);
			limpar_buffer();
			puts("Aperte qualquer tecla para continuar.");
			system('pause');
			limpar_tela();
			menu();
		break;
		case 'x':
			exit(0);
		break;
		default:
			limpar_tela();		    
			puts("Não entendi");
			menu();
		break;
	}
}
aluno* novo_aluno()
{
	aluno *a = malloc(sizeof(aluno));
	a->nome[0] = '\0';
	a->matricula[0] = '\0';
	a->media = 0;
	return a;
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
	fflush ( stdin ); //Utilizar no Windows
	//__fpurge ( stdin ); #include <stdio_ext.h> //Utilizar no linux
}
void limpar_tela()
{
	//system("clear"); //Utilizar no linux
	system("cls"); //Utilizar no Windows
}
void set_aluno(aluno *a)
{
	int j = 1;
	char controle;

	printf("Informe o nome: ");
	receber_string(a->nome);

	printf("Informe a matricula: ");
	receber_string(a->matricula);

	printf("Informe a média: ");
	float m = 0;
	scanf("%f",&m);
	a->media = m;
}

void get_alunos(aluno *a)
{
	int i;
	aluno j;
	limpar_tela();
	for(i = 0; i < atual; i++)
	{
		j = a[i];
		printf("%s - %s - %.2f\n", j.matricula, j.nome, j.media);
	}
	
}