#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

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
	int colidiu;
} tabela;


pessoa* nova_pessoa();
lista nova_lista();
tabela* nova_tebela(int tamanho);
void add_pessoa(tabela *t, pessoa *p, int i);
tabela* carregar_arquivo(char *caminho, int opt);
int to_hash1(char *palavra,int max);
int to_hash2(char *palavra, int max);
void gerar_relatorio_csv(int i, int c,  char *titulo);
void menu();
void receber_string(char *var);
void limpar_buffer();
void limpar_tela();
void set_pessoa(pessoa *p);
void gerar_relatorio_js(char *titulo);
void procurar(char *nome, int pos1, int pos2);

tabela *map1 = NULL;
tabela *map2 = NULL;
pessoa *pessoaTemp = NULL;
char *temp = NULL;
int hash1[12595];
int hash2[12595];
int main()
{
	map1 = carregar_arquivo("entrada.txt", 1);
	map2 = carregar_arquivo("entrada.txt", 2);
	gerar_relatorio_js("data.js");
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
	printf("1 - Adicionar Pessoa\t2 - Buscar Pessoa\n");
	printf("3 - Apagar Pessoa\tx - Sair\n");
	opt = getchar();
	switch(opt)
	{
		case '1':
			pessoaTemp = nova_pessoa();
			set_pessoa(pessoaTemp);
			int pos = to_hash1(pessoaTemp->nome, map1->total);
			add_pessoa(map1, pessoaTemp, pos);
			menu();
			limpar_tela();
		break;
		case '2':
			receber_string(temp);
			limpar_tela();
			menu();
			int pos1 = to_hash1(temp, map1->total);
			int pos2 = to_hash2(temp, map1->total);
			procurar(temp, pos1, pos2);
		break;
		case '3':
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
	//fflush ( stdin ); //Utilizar no Windows
	__fpurge ( stdin );  //Utilizar no linux #include <stdio_ext.h>
}
void limpar_tela()
{
	system("clear"); //Utilizar no linux
	//system("cls"); //Utilizar no Windows
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
	t->colidiu = 0;
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
	t->colidiu += t->posicoes[i].total > 1 ? 1 : 0;
	t->atual++;
}

tabela* carregar_arquivo(char *caminho, int opt)
{
	char linha[TEXTO];
	FILE *arquivo;
	arquivo = fopen(caminho,"r+");
	if(arquivo == NULL) return NULL;

	pessoa *p = NULL;
	char *token = NULL;
	fgets(linha, TEXTO, arquivo);
	int tamanho = atoi(linha) + 100;
	printf("%d - tamanho\n", tamanho);
	tabela *t2 = nova_tebela(tamanho);
	printf("lendo o arquivo\n");
	while(fgets(linha, TEXTO, arquivo) != NULL)
	{
		p = nova_pessoa();
		token = strtok(linha, ";");
		strcpy(p->nome, token);
		strcpy(p->telefone	,token);
		if(opt == 1)
		{
            add_pessoa(t2, p, to_hash1(p->nome, t2->total));
            hash1[t2->atual] = t2->colidiu;
		}
		else
		{
			add_pessoa(t2, p, to_hash2(p->nome, t2->total));
			hash2[t2->atual] = t2->colidiu;
		}
		gerar_relatorio_csv(t2->atual, t2->colidiu, "ralatorio.csv");
		token = NULL;
		p = NULL;
	}
	fclose(arquivo);
	gerar_relatorio_csv(-1, -1, "ralatorio.csv");
	return t2;
}

int to_hash1(char *palavra, int max)
{
	int tamanho, primeira, segunda; 
    tamanho =  strlen(palavra);      
    primeira = (int) palavra[0];           
    segunda = (int) palavra[1];            
    int resultado = ((tamanho * primeira) + segunda) % max;
    resultado = resultado < 0 ? resultado *(-1) : resultado;
    //printf("%d\n", resultado);
    return resultado;
}

int to_hash2(char *palavra, int max)
{
     int key = 0;
      while (*palavra) {
        key = key*37 + *palavra++;
      }
    int resultado = key % max;
    resultado = resultado < 0 ? resultado *(-1) : resultado;
    return resultado;  
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

void gerar_relatorio_csv(int i, int c,  char *titulo)//ralatorio.csv
{
	FILE *arquivo = fopen(titulo, "a+"); 
	fprintf(arquivo, "%d;%d\n", i, c);
	fclose(arquivo); 
}
void gerar_relatorio_js(char *titulo)//data.js
{
	FILE *arquivo = fopen(titulo, "w+"); 
	int i;
	fprintf(arquivo, "var vetorResultado = [{\n");
	fprintf(arquivo, "data: [");
	for(i = 0; i < 999; i++)
	{
		fprintf(arquivo, ",%d", hash1[i]);
	}
	fprintf(arquivo, "],\n");
	fprintf(arquivo, "color: 'rgba(223, 83, 83, .5)',\nname: 'Colisões Hash-1',\nthreshold: null,\n},{\ndata: [");
	for(i = 0; i < 999; i++)
	{
		fprintf(arquivo, ",%d",  hash2[i]);
	}
	fprintf(arquivo, "],\ncolor: 'rgba(119, 152, 191, .5)',\nname: 'Colisões Hash-2',\n}]");
	fclose(arquivo); 
}

void procurar(char *nome, int pos1, int pos2)
{
	if(map1->posicoes[pos1].total > 1)
	{
		printf("tabela 1==============\n");
		int achou = 1;
		pessoa *aux = map1->posicoes[pos1].primeira;
		while(aux->prox != NULL && achou != 0)
		{
			achou = strcmp(aux->nome, nome);
			aux = aux->prox;
		}
		printf("Pessoa nao encontrada\n");
		printf("Nome: %s\n",aux->nome);
		printf("Telefone: %s\n",aux->telefone);
	}
	else if(map1->posicoes[pos1].total > 1)
	{
		pessoa *aux = map1->posicoes[pos1].primeira;
		printf("Pessoa nao encontrada\n");
		printf("Nome: %s\n",aux->nome);
		printf("Telefone: %s\n",aux->telefone);

	}
	else if(map1->posicoes[pos1].total > 0)
	{
		printf("Pessoa nao encontrada\n");
	}
	printf("tabela 2==============\n");
	if(map2->posicoes[pos2].total > 1)
	{
		int achou = 1;
		pessoa *aux = map2->posicoes[pos2].primeira;
		while(aux->prox != NULL && achou != 0)
		{
			achou = strcmp(aux->nome, nome);
			aux = aux->prox;
		}
		printf("Pessoa nao encontrada\n");
		printf("Nome: %s\n",aux->nome);
		printf("Telefone: %s\n",aux->telefone);
	}
	else if(map2->posicoes[pos2].total > 1)
	{
		pessoa *aux = map2->posicoes[pos1].primeira;
		printf("Pessoa nao encontrada\n");
		printf("Nome: %s\n",aux->nome);
		printf("Telefone: %s\n",aux->telefone);

	}
	else if(map2->posicoes[pos2].total > 0)
	{
		printf("Pessoa nao encontrada\n");
	}
}
                