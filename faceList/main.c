#include <stdio.h>
#include <stdlib.h>
#include "faceList.h"

void menu();
int main()
{

	usuarios *users = loadUsuarios();
	listar(users);
	return 0;
}
void menu(){

}