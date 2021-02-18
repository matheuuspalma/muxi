/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
   Questão 02
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#define EOS '\0' //end of string


int questao3(){

    char *string; 
    char separator[2];  //separetor + end of line
    int lenght, i;
    char **substring;
    

    printf("Entre com o separador que sera usado! \n");
    scanf("%s", separator);
    printf(" Entre com o tamanho total da string. \n");
    scanf("%d", &lenght);
    
    printf(" Entre com a string composta por substrings, dividas pelo um separador especificado! \n");
    
    string = malloc(lenght*sizeof( char *));

    scanf("%s", &string[0]);

  

    substring = stringsplit(string, separator[0], &lenght);

    if(substring == NULL){
        return -1;
    }else{
        printf("\nSubstrings: \n");
        for( i = 0; i < lenght; i++){
            printf(" * %s \n", substring[i]);
        }
    }

    free(substring);

    return 0;
}

    

char** stringsplit(const char *string, char separator, int *length){
    if( string == NULL || length == NULL){
        return NULL;
    }

    int size,i,j,k, cont;
    char **substring; 

    k = 1;
    size = length[0];
    for(i = 0; i < size; i++){
        if( i != 0 && i != size - 1 && string[i] == separator){
            k++;
        }
    }

    substring = malloc(k * sizeof(char **));              
    
    j = 0;
    k = 0;
    i = 0;

    if(string[i] == separator){
        cont = 0;
        while( string[cont] != separator){
                cont++;
        }
        substring[j] = malloc((cont) * sizeof( char *));    // number of elements + OES * size of to alloc de memory   cont = eos + elements
        i = 1;
    }else{
        cont = 1;
        while( string[cont] != separator){
                cont++;
        }
        substring[j] = malloc((cont) * sizeof( char *));
    }
    
    while(  i < size ){
        if(string[i] != separator  && i + 1 != size){                  
            substring[j][k] = string[i];
            k++;
        
        }else if( string[i] == separator){ 
            substring[j][k] = EOS;                          
            k = 0;                                          
            j++;
            cont = 0;
            while( string[cont] != separator && i != size - 1){        //allocating memory to the next substring        //number of elements + OES * size of to alloc de memory
                cont++;                                                //the second condition does exist cause if the separator is in the last position,is to avoid loop
            }
            if(i != size - 1){
                substring[j] = malloc((cont + 1) * sizeof( char *));   //if the separator is the last one, wont alloc memory                                                                                                                                      
            }
        }else if( string[i] != separator && i + 1 == size){             //if doesn't exist the separator in the end of the string
            substring[j][k] = string[i];                                
            k++;
            substring[j][k] = EOS;  
            j++;
        }
        i++;
    }
    length[0] = j;

    return substring;
}
