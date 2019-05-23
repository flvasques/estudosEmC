
#ifndef ARVOREBIN
#define ARVOREBIN
class No
{
	public:
		int valor;
		No *esq;
		No *dir;
		No(int v);
		void insere(int v);
		void imprime();
		void imprimePos();
		void imprimeEm();
		int buscar(int num);
	private:
		int count();
};
#endif