/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
   Questão 05
*/
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int questao5(){
    long int size, i;
    int *x, aux, y;
    SingleLinkedListOfIntsNode *head;

    printf(" Qual o tamanho da sua lista? \n");
    scanf("%ld", &size);

    if( size <= 0){
        printf(" O numero precisa ser positivo!\n");
        return -1;
    }

    head = malloc(sizeof(SingleLinkedListOfIntsNode));  
    x = malloc(sizeof(int)*size);
    
    printf(" Entre com os inteiros da lista: \n");

    aux = head->content;    //valor do head

    for( i = 0; i < size; i++){    
        scanf("%d", &x[i]);
        append(head, set( x[i] ), aux);
        aux = x[i];
    }
    printf("**LISTA** \n");
    printList(head);

    printf("Qual sera o valor Y\n");
    scanf("%d", &y);

    listPartition( &head, y);
    return 0;
}

SingleLinkedListOfIntsNode* set( int x){

    SingleLinkedListOfIntsNode *newContent;
    newContent = malloc(sizeof(SingleLinkedListOfIntsNode));
    newContent->content = x;
    newContent->next = NULL;
    return newContent;
}

int append( SingleLinkedListOfIntsNode *head, SingleLinkedListOfIntsNode *new, int aux){
    if(head->content == aux){           //enquanto não achar o ultimo
        head->next = new;
    }else{
        append(head->next, new, aux);
    }
    return 0;
}

int printList( SingleLinkedListOfIntsNode *head){

    SingleLinkedListOfIntsNode *list;
 
    for (list = head->next; list != NULL; list = list->next){
      printf ("* %d\n", list->content);
    }
    return 0;
}


void listPartition(SingleLinkedListOfIntsNode **head, int y){

    SingleLinkedListOfIntsNode *i;    
    for (i = (*head)->next; i != NULL; i = i->next){
        if(i->content < y){
            printf ("* %d\n", i->content);
        }
    }
    for (i = (*head)->next; i != NULL; i = i->next){
        if(i->content == y){
            printf ("* %d\n", i->content);
        }
    }
    for (i = (*head)->next; i != NULL; i = i->next){
        if(i->content > y){
            printf ("* %d\n", i->content);
        }
    }
}


    

        
    

