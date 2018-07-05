#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXTO 100
#define TAM 255

typedef struct node{
	char nome[TEXTO];
	char telefone[TEXTO];
	struct node *prox;
}pessoa;

typedef struct {
	pessoa* primeira;
	int total;
}lista;

typedef struct
{
	lista* posicoes;
	int atual;
	int total;
} tabela;

pessoa* nova_pessoa();
lista nova_lista();
tabela* nova_tebela(int tamanho);
void add_pessoa(tabela *t, pessoa *p, int i);
tabela* carregar_arquivo(char *arquivo);
int to_hash(char *palavra);
void gerar_relatorio();
void menu();
void receber_string(char *var);
void limpar_buffer();
void limpar_tela();
void set_pessoa(pessoa *p);

tabela *map1 = NULL;
int main()
{

	limpar_tela();
	limpar_buffer();
	menu();
	return 0;
}

void menu()
{
	char opt;
	limpar_buffer();
	printf("\t\tSeja Bem Vindo!\n");
	printf("\tO que Deseja Fazer?\n");
	printf("1 - Carregar do arquivo\t2 - Adicionar Pessoa\t3 - Buscar Pessoa\n");
	printf("4 - Apagar Pessoa\t5 - Gerar Relatorio\tx - Sair\n");
	opt = getchar();
	switch(opt)
	{
		case '1':
			map1 = carregar_arquivo("entrada.txt");
			limpar_tela();
			menu();
		break;
		case '2':
			/*pessoa *nova;
			nova = nova_pessoa();
			set_pessoa(nova);
			int pos = to_hash(nova->nome);
			add_pessoa(map1, nova, pos);*/
			menu();
			limpar_tela();
		break;
		case '3':
			menu();
			limpar_tela();
		break;
		case '4':
			menu();
			limpar_tela();
		break;
		case '5':
			menu();
			limpar_tela();
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

void receber_string(char *var)
{
	limpar_buffer();
	fgets(var, TEXTO,stdin);
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

pessoa* nova_pessoa()
{
	pessoa *p = malloc(sizeof(pessoa));
	p->nome[0] = '\0';
	p->telefone[0] = '\0';
	p->prox = NULL;
	return p;
}

lista nova_lista()
{
	lista *l = malloc(sizeof(lista));
	l->primeira = NULL;
	l->total = 0;
	return *l;
}

tabela* nova_tebela(int tamanho)
{
	tabela *t = malloc(sizeof(tabela));
	lista *vetor = (lista *) malloc(sizeof(lista) * tamanho);
	int i;
	for(i = 0; i < tamanho; i++)
	{
		vetor[i] = nova_lista();
	}
	t->posicoes = vetor;
	t->total = tamanho;
	t->atual = 0;
	return t;
}

void add_pessoa(tabela *t, pessoa *p, int i)
{
	if(t->posicoes[i].primeira == NULL)
	{
		t->posicoes[i].primeira = p;
	}
	else
	{
		pessoa *aux = t->posicoes[i].primeira;
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}
			aux->prox = p;
	}
	t->posicoes[i].total++;
	t->atual++;
}

tabela* carregar_arquivo(char *caminho)
{
	char linha[TEXTO];
	FILE *arquivo;
	arquivo = fopen(caminho,"r+");
	if(arquivo == NULL) return NULL;

	pessoa *p = NULL;
	char *token = NULL;
	fgets(linha, TEXTO, arquivo);
	int tamanho = atoi(linha);
	printf("%d - tamanho\n", tamanho);
	tabela *t2 = nova_tebela(tamanho);
	while(fgets(linha, TEXTO, arquivo) != NULL)
	{
		p = nova_pessoa();
		token = strtok(linha, ";");
		strcpy(p->nome, token);
		strcpy(p->telefone	,token);
		add_pessoa(t2, p, to_hash(p->nome));
		token = NULL;
		p = NULL;
	}
	fclose(arquivo);
	return t2;
}

int to_hash(char *palavra)
{
	int retorno = 0,i = 0;
	for(i = 0; palavra[i] != '\0'; i++)
	{
		retorno += (int) palavra[i];
	}
	return retorno;
}

void set_pessoa(pessoa *p)
{
	int j = 1;
	char controle;

	printf("Informe o nome: ");
	receber_string(p->nome);

	printf("Informe a matricula: ");
	receber_string(p->telefone);
}

void gerar_relatorio()
{
	FILE *arquivo = fopen("ralatorio.csv", "w+"); 
	int i;
	for(i = 0; i < map1->total; i++)
	{

	}
	 fclose(arquivo); 
}
