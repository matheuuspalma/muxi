/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
   Questão 01
*/

#include <stdio.h>
#include <string.h>
#include "menu.h"

int questao1(){
    
    int size, i;
    char string[100], newString[100]; 
    const char *quit = "q";
    
    printf("\nEntre com uma palavra: \nOBS: Caso queira voltar ao menu, entrar com a letra \"q\".\n");
    scanf( "%s", string);

    if(strcmp(string,quit) == 0){  // comparando a entrada com a string "quit". Caso verdadeiro encerrar
        printf("Encerrado! \n");
        return 0;
    }

    size = strlen(string);

    for(i = 0; i < size; i++){
        newString[i] = string[size - 1 -i];
    }

    if( strlen(newString) != size){ //verificando se não há lixo no betor
       newString[size] = '\0';
    }

    printf("\n%s\n ", newString);

    questao1();

    return 0;
}