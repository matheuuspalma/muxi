/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
   Menu Questões
*/

#include <stdio.h>
#include "menu.h"


int main(){

    int input, feedback;


    printf("\n************** MENU MUXI **************\n"); 
    printf("Entrada -----------------  Opcao\n");
    printf(" 1      -----------------  Questao 1\n");
    printf(" 2      -----------------  Questao 2\n");
    printf(" 3      -----------------  Questao 3\n");
    printf(" 5      -----------------  Questao 5\n");
    printf(" 6      -----------------  Questao 6\n");
    printf(" 7      -----------------  SAIR \n");
    
    scanf("%d", &input);

    if(input == 1){

       feedback = questao1();

        if( feedback < 0){
            printf(" Erro ao executar funcao! \n");
        }
    }else if(input == 2){

        feedback = questao2();

        if( feedback < 0){
            printf(" Erro ao executar funcao! \n");
        }
    }else if(input == 3){

        feedback = questao3();

        if(feedback < 0){
            printf(" Erro ao executar funcao! \n");
        } 
    }else if(input == 5){

        feedback = questao5();

        if(feedback < 0){
            printf(" Erro ao executar funcao! \n");
        } 
    }else if(input == 6){

        feedback = questao6();

        if(feedback < 0){
            printf(" Erro ao executar funcao! \n");
        } 
    }else if(input == 7){  // verificando opção sair do menu
        printf(" Encerrado ! \n");
        return 0;
    }else{
        printf("Escolha uma das opcoes. Entrada Invalida!!\n");
    }

    main();

    return 0;

}

