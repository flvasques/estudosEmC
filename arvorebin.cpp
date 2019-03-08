#include <iostream>

class No
{
	public:
		int valor = 0;
		No *esq = NULL;
		No *dir = NULL;
		No(int v);
		void insere(int v);
		void imprime();
		void imprimePos();
		void imprimeEm();
	private:
		int count();
};


using namespace std;

int main(int argc, char const *argv[])
{
	No *arvore = new No(10);
	arvore->insere(3);
	arvore->insere(11);
	arvore->insere(4);
	arvore->imprime();
	cout<< "=====" << endl;
	arvore->imprimePos();
	cout<< "=====" << endl;
	arvore->imprimeEm();
	return 0;
}

No::No(int v)
{
	this->valor = v;
}
void No::insere(int v)
{
	if(v < this-> valor)
	{
		if(this->esq == NULL)
			this->esq = new No(v);
		else
			this->esq->insere(v);
	}
	else
	{
		if(this->dir == NULL)
			this->dir = new No(v);
		else
			this->dir->insere(v);
	}
}
void No::imprime()
{
	cout << this->valor << endl;
	if(this->esq != NULL)
		this->esq->imprime();
	if(this->dir != NULL)
		this->dir->imprime();
}
void No::imprimePos()
{
	if(this->esq != NULL)
		this->esq->imprime();
	if(this->dir != NULL)
		this->dir->imprime();
	cout << this->valor << endl;
}
void No::imprimeEm()
{
	if(this->esq != NULL)
		this->esq->imprime();
		cout << this->valor << endl;
	if(this->dir != NULL)
		this->dir->imprime();
}
int No::count()
{
	if(this->esq != NULL)
		return 1 + this->esq->count();
	else
		return 0;
}
