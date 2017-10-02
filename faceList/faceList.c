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
	} seguidores;

} perfil;

typedef struct
{	perfil *perfis;
	int tam;
} usuarios;



void listarSeguidores(perfil *p)
{
}

void listarSeguindo(perfil *p)
{
}

perfil *addPerfil(char *nome, int idade, char *eC)
{
	perfil *p = (perfil *)malloc(sizeof(perfil));
	p->nome = nome;
	p->idade = idade;
	p->estadoCivil = eC;
	p->seguindo.lista = (perfil *)malloc(sizeof(perfil) * 10);
	p->seguindo.tam = 0;
	p->seguidores.lista = (perfil *)malloc(sizeof(perfil) * 10);
	p->seguidores.tam = 0;
	return p;
}
void addUsuario(usuarios *u, perfil p)
{	u->tam++;
	u->perfis[u->tam-1] = p;
}

void seguir(perfil *meu, perfil alvo)
{	
}

void desSeguir(perfil *p)
{
}

perfil getUsuario(int i)
{
	perfil p;
	return p;
}
void listar(usuarios *u)
{	int i = 0;
	puts("listajem inicio");
	perfil aux;
	while(i < u->tam)
	{	aux = u->perfis[i];
		printf("%d - %s\t",i,aux.nome);
		if(i%3 == 0) printf("\n");
		i++;
	}
}

usuarios loadUsuarios()
{	usuarios *retorno = (usuarios *)malloc(sizeof(usuarios) * 10);
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
