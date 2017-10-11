typedef struct{int elemento; 
			   struct no *proximo;
			   struct no *anterior;} no;
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

int exculiNaPos(lista *l, int pos);

void printLista(lista *l);
no retiraInicio(lista *l);
