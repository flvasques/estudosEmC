typedef struct 
{
	char *nome;
	int idade;
	char *estadoCivil
} pessoa;
typedef struct
{
	pessoa info;
	struct
	{
		struct perfil *lista;
		int tam
	}seguindo;
	struct
	{
		struct perfil *lista;
		int tam
	} seguidores

} perfil;

typedef struct
{
	perfil *perfis;
	int tam
} usuarios;

void listarUsuarios(usuarios *u);

void listarSeguidores(perfil *p);

void listarSeguindo(perfil *p);

perfil addUsuario(char *nome, int idade, char *eC);

void addPerfil(usuarios *u, perfil *p);

void seguir(perfil *p);

void desSeguir(perfil *p);

perfil getUsuario(int i);





