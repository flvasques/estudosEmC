typedef struct{int elemento;} no;
typedef struct{no *vetor; int tamanho;}listaVetor;
no *novoNo(int i);
listaVetor *novaLista();
void novoElemento(no *n, listaVetor *lista);
void elementoPosicao(no *n,int pos, listaVetor *lista);
void apagarElementoX(int pos, listaVetor *lista);
int verificaElemento(no *n,listaVetor *lista);
int qtdElementos(listaVetor *lista);
