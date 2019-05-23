#include <iostream>
#include "arvorebin.h"
using namespace std;
No::No(int v)
{
	this->esq = NULL;
	this->dir = NULL;
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
int No::buscar(int num){
	contadorBinario++;
	if(this->valor == num) 
		return 1;	
	else
	{
		if(num < this->valor)
		{
			if(this->esq != NULL)
				this->esq->buscar(num);
			else
				return 0;
		}
		else
		{
			if(this->dir != NULL)
				this->dir->buscar(num);
			else
				return 0;
		}
	}
}
int No::count()
{
	if(this->esq != NULL)
		return 1 + this->esq->count();
	else
		return 0;
}