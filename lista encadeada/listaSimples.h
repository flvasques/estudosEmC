typedef struct{int elemento; 
			   struct no *proximo;} no;
typedef struct{no *primeiro; 
			   int tam;}lista; 

no *novoNo(int i);
lista novaLista();
int ehVazia(lista *l);

int insereNoInicioP(lista *l,no *n);
int insereNoInicioN(lista *l,no n);
int insereNoInicoI(lista *l, int i);
int insereNaPos(lista *l, no *n, int p);
int insereNoFim(lista *l, no *n);

int excluiNaPos(lista *l, int pos);
int excluiNoFim(lista *l);
int excluiNoInicio(lista *l);

int ehIgual(lista *l1, lista *l2);
int imprimeNodo(lista *l, int pos);
void imprime(lista *l);
int tamanho(lista *l);
void deleteLista(lista **l);

void ordenarLista(lista *l);
void inserirNaOrdem(lista *l, no *n);
