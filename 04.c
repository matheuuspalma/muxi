/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
   Questão 04
*/

#include <stdio.h>
#include <stdlib.h>
#include "04.h"

void stackRemoveEven( Stack *p){

    Stack *last, *aux;

    if( p == NULL){
        return -1;
    }

    while( p->next != NULL ){
        last = p;
        p = p->next;
        if(p->content % 2 == 0){ 
            last = p->next;
            aux = p;
            p = last->next;
            stackPop(aux);
        }        
    }
}
