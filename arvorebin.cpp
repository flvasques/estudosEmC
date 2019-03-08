#include <iostream>

class No
{
	public:
		int valor = 0;
		No *esq = NULL;
		No *dir = NULL;
		No(int v);
		insere(int v);
		imprime();
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
	return 0;
}

No::No(int v)
{
	this->valor = v;
}
No::insere(int v)
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
No::imprime()
{	
	cout << this->valor << endl;
	if(this->esq != NULL)
		cout << "esq ";
		this->esq->imprime();
	if(this->dir != NULL)
		cout << "dir ";
		this->dir->imprime();
}
No::count()
{
	if(this->esq != NULL)
		return 1 + this->esq->count();
	else
		return 0;
}