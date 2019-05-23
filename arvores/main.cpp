#include <iostream>
#include <stdlib.h>
#include "arvorebin.h"
#ifdef __linux__ 
	#include <stdio_ext.h>
#endif

using namespace std;

void menu();
void imprime();
void limparTela();
void limparBuffer();
void buscar();

No *arvore;
char opcao;

static int contadorBinario = 0;
int main(int argc, char const *argv[])
{
	limparTela();
	arvore = new No(10);
	arvore->insere(3);
	arvore->insere(11);
	arvore->insere(4);

	menu();

	return 0;
}
void menu(){
	limparBuffer();
	cout << "1 - Buscar valor\t2 - Imprimir" << endl;
	cout << "x - Para Sair" << endl;
	cin >> opcao;
	switch (opcao){
		case '1':
			limparTela();
			buscar();
			menu();
			break;
		case '2':
			imprime();
			menu();
			break;
		case 'x':
			limparTela();
			limparBuffer();
			exit(0);
			break;
		default:
			limparTela();
			cout<< "Opcao Invalida!" << endl;
			menu();
			break;
	}
}
void imprime()
{
	arvore->imprime();
	cout<< "=====" << endl;
	arvore->imprimePos();
	cout<< "=====" << endl;
	arvore->imprimeEm();	
}
void limparTela()
{
	#ifdef __linux__ 
    	system("clear");
	#elif _WIN32
	    system("cls");
	#else

	#endif
}
void buscar()
{
	int numero = 0;
	cout << "Imforme o valor que deseja Procurar." << endl;
	cin >> numero;
	int resultado = arvore->buscar(numero);
	if(resultado == 1)
	{
		cout << "O numero: " << numero << " encontrado." << endl;
		//cout << "Em " << resultado[1] << "chamada(s)" << endl;
	}
	else
	{
		cout << "O numero:" << numero << " nao encontrado." << endl;
	}
}
void limparBuffer()
{
	#ifdef __linux__ 
    	 __fpurge(stdin);
	#elif _WIN32
	    fflush(stdin);
	#else

	#endif
}