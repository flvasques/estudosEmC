#include <string.h>
#include <stdio.h>
int main(){

   char frase[64]; 
   char *token = NULL;
   strcpy( frase, "o sporting ainda vai ser campeao portugues" );
   token= strtok( frase, " " );
    while( token )
    {
        printf("%s\n",token);
        token = strtok( NULL, " " );
                                   
    }
    /* resto do prog... */
}