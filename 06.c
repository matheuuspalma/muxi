/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
   Questão 06
*/
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int questao6(){

    int numElem1, numElem2, i, resultSize = 0;
    int *list1, *list2, *result;
    err_t feedback;

    printf("Entre com o numero de elementos da primeira lista: ");
    scanf("%d", &numElem1);

    printf("Entre com os elementos da primeira lista : \n");
    list1 = malloc(sizeof(int)*numElem1);   
    for( i = 0; i < numElem1; i++){
        scanf("%d", &list1[i]);
    }
    printf("Lista 1 preenchida com sucesso!\n");

    printf("Entre com o numero de elementos da segunda lista: ");
    scanf("%d", &numElem2);

    printf("Entre com os elementos da primeira lista : \n");
    list2 = malloc(sizeof(int)*numElem2);   
    for( i = 0; i < numElem2; i++){
        scanf("%d", &list2[i]);
    }
    printf("Lista 2 preenchida com sucesso!\n");

    if(numElem1 >= numElem2){
        result = malloc(sizeof(int)*numElem1); 
    }else{
        result = malloc(sizeof(int)*numElem2); 
    }
    
    return feedback = findCommon( list1, numElem1, list2, numElem2, result, resultSize);
}

err_t findCommon(int *list1, int numElem1, int *list2, int numElem2, int *result, int resultSize){

    int i, j;
    if(list1 == NULL || list2 == NULL || result == NULL){
        return argumentoInvalido;       
    }
    for( i = 0; i < numElem1; i++){
        for( j = 0; j < numElem2; j++){
            if(list1[i] == list2[j]){
                result[resultSize] = list1[i]; 
                resultSize++;
                break;
            }
        }
    }
    avoidingDuplicated( result, &resultSize);

    printf("Os elementos em comum sao : \n");
    for(i = 0; i < resultSize; i++){
        printf("* %d\n", result[i]);
    }
    
    return ok;
}

err_t avoidingDuplicated(int *result, int *resultSize ){

    int size;

    size = resultSize[0];

    if(result == NULL){
        return argumentoInvalido;
    }

    int i,j;

    for(i = 0; i < size; i++){
        for(j = i + 1; j < size; j++){
            if(result[i] == result[j]){
                removeInList( result, j, size);
                size--;
            }
        }
    }

    resultSize[0] = size;
    return ok;
}

err_t removeInList(int *result, int i, int size){

    if(result == NULL){
        return argumentoInvalido;
    }
    int j;
    for( j = i; j < size - 1; j++){
        result[j] = result[j + 1];
    }
    return ok;
}