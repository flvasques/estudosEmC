#include <stdio.h>
#include <stdlib.h>
typedef struct
{	char *nome;
	int idade;
	char *estadoCivil;
	struct
	{
		struct perfil *lista;
		int tam;
	}seguindo;
	struct
	{
		struct perfil *lista;
		int tam;
	}seguidores;

} perfil;

typedef struct
{	perfil *perfis;
	int tam;
} usuarios;



void listarSeguidores(perfil *p)
{	int i = 0;
	while(i < p->seguidores.tam)
	{	struct perfil *pa = (perfil *)p->seguidores.lista[i];
		printf("%d - %s\t",i,pa->nome);
		if(i%3 == 0) printf("\n");
		i++;
	}
}

void listarSeguindo(perfil *p)
{	int i = 0;
	while(i < p->seguindo.tam)
	{ 	struct perfil *pa = (perfil *)p->seguindo.lista[i];
		printf("%d - %s\t",i,pa->nome);
		if(i%3 == 0) printf("\n");
		i++;
	}
}

perfil *addPerfil(char *nome, int idade, char *eC)
{
	perfil *p = (perfil *)malloc(sizeof(perfil));
	p->nome = nome;
	p->idade = idade;
	p->estadoCivil = eC;
	p->seguindo.lista = (perfil *)malloc(sizeof(perfil) * 100);
	p->seguindo.tam = 0;
	p->seguidores.lista = (perfil *)malloc(sizeof(perfil) * 100);
	p->seguidores.tam = 0;
	return p;
}
void addUsuario(usuarios *u, perfil p)
{	u->tam++;
	u->perfis[u->tam-1] = p;
}

void seguir(perfil *meu, perfil *alvo)
{	
	meu->seguindo.lista[meu->seguindo.tam] = alvo;
	meu->seguindo.tam++;
	alvo->seguidores.lista[alvo->seguidores.tam] = meu;
	alvo->seguidores.tam++;
}

void desSeguir(perfil *meu, perfil *alvo)
{	
}

perfil getUsuario(int i)
{
	perfil p;
	return p;
}
void listar(usuarios *u)
{	int i = 0;
	perfil aux;
	while(i < u->tam)
	{	aux = u->perfis[i];
		printf("%d - %s\t",i,aux.nome);
		if(i%3 == 0) printf("\n");
		i++;
	}
}

usuarios loadUsuarios()
{	usuarios *retorno = (usuarios *)malloc(sizeof(usuarios) * 100);
	retorno->tam = 0;
	perfil *a = addPerfil("Joao", 18, "Solteiro");
	addUsuario(retorno, *a);
	perfil *b = addPerfil("Jose", 19, "Solteiro");
	addUsuario(retorno, *b);
	perfil *c = addPerfil("Juca", 20, "Solteiro");
	addUsuario(retorno, *c);
	perfil *d = addPerfil("Jopo", 21, "Solteiro");
	addUsuario(retorno, *d);
	return *retorno;
}
