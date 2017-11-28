typedef struct{char *nome; char telefone; struct no *proximo;} no;
typedef struct{no *primeiro; int tam;}lista;

no *novoNo(char *n, char *t);
int hash(char *n);
void inserir(char *n, char *t, lista *l);
lista novaLista();
void imprime(lista *l);