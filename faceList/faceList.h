typedef struct
{	char *nome;
	int idade;
	char *estadoCivil;
	struct
	{	struct perfil *lista;
		int tam;
	}seguindo;
	struct
	{	struct perfil *lista;
		int tam;
	}seguidores;

} perfil;

typedef struct
{	perfil *perfis;
	int tam;
} usuarios;




void listarSeguidores(perfil *p);

void listarSeguindo(perfil *p);

perfil *addPerfil(char *nome, int idade, char *eC);

void addUsuario(usuarios *u, perfil *p);

void seguir(perfil *meu, perfil *alvo);

void desSeguir(perfil *meu, perfil *alvo);

perfil getUsuario(int i);

void listar(usuarios *u);

usuarios *laodUsuarios();



