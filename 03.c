/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
   Questão 02
*/

#include <stdio.h>
#include <string.h>
#include "menu.h"


int questao3(){

    char string[100];
    char *barra = "/";
    char substring[100][100];
    int size, i, j, k;

    printf(" Entre com a palavra composta por substrings separadas por \"/\" \n");

    scanf("%s", string);

    size = strlen(string);

    i = 0;
    k = 0;
    for( j = 0; j < size;j++){

        if( string[j] == barra ){
            i++;
            k = j;
        }else{
            
            substring[i][j - k] = string[j];
        }

    }

    for( j = 0; j < i; j++){
        printf(" * %s \n", substring[j]);
    }
    
    return 0;
}

    


