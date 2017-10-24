typedef struct{ char* placa;
				struct carro *proximo;
				struct carro * anterior;}carro;
typedef struct {carro *primeiro;
				carro *ultimo;
				int tam;} garagem;
carro *novoNo(char *p);
garagem *novaFila();

void push(garagem *g, char *p);
void pushFila(garagem *g, carro *c);
carro *peak(garagem *l);
carro *pop(garagem *l);

garagem *novaPilha();
garagem *popPilha(garagem *l);
carro peakPilha(garagem *l);
void pushPilha(garagem *l,char *p);

void pushPilhaP(garagem *l, carro *c);