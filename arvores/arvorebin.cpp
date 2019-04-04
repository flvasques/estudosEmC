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
int * No::buscar(int num){
	int retorno[2] = {0, 0};
	return buscar(retorno, num);
}
int * No::buscar(int enc, int cont, int num)
{
	cont++;
	if(this->valor == num) 
		ret[0] = 1;	
	else
	{
		if(num < this->valor)
		{
			if(this->esq == NULL)
				this->esq->buscar(ret, num);
			else
				ret[0] = 0;
		}
		else
		{
			if(this->dir == NULL)
				this->dir->buscar(ret, num);
			else
				ret[0] = 0;
		}
	}
	return ret;
}
int No::count()
{
	if(this->esq != NULL)
		return 1 + this->esq->count();
	else
		return 0;
}