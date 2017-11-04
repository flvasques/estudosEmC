typedef struct{ int id;
				char* placa;
				char *modelo;
				struct carro *proximo;
				struct carro * anterior;}carro;
typedef struct {carro *primeiro;
				carro *ultimo;
				int tam;} garagem;
carro *novoNo(char *p, char *m);
garagem *novaFila();

void enqueue(garagem *g, char *p, char *m);
void enqueueP(garagem *g, carro *c);
carro *peak(garagem *l);
carro *dequeue(garagem *l);

garagem *novaPilha();
garagem *pop(garagem *l);
carro peakPilha(garagem *l);
void push(garagem *l,char *p, char *m);

void pushP(garagem *l, carro *c);