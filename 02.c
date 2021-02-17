/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
   Questão 02
*/

#include <stdio.h>
#include "menu.h"


int questao2(){
    
  int m[9][9], i, j;
  int feedback;

  printf(" Entre com os valores da Matriz A 9 X 9:\nSeguindo a ordem da primeira linha ate a ultima, da esquerda para direita! \n");
    
  for (i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
     
      scanf("%d", &m[i][j]); //entrada matriz
     
      if( m[i][j] > 9 || m[i][j] < 0){ //validação entrada
        printf(" Entrar com numeros maior ou igual a 0 e  menor ou igual a 9 !!! \n");
        return -1;
      }
    }
  }  
  feedback = sudokuRegra(m);

  if( feedback < 0){
    printf("\nA matriz nao e uma solicao valida para o Sudoku!! \n ");
  }else{
    printf("\nA matriz e uma solucao valida para o Sudoku!! \n");
  }
  for (i = 0; i < 9; i++){ //print na tela da matriz
    printf("\n| ");
    for(j = 0; j < 9; j++){
      if( j == 2 || j == 5 || j == 8){
        printf(" %d | ", m[i][j]);
      }else{
        printf(" %d ", m[i][j]);
      }
    }
    if( i == 2 || i == 5 || i == 8){
      printf("\n");
    }
  }  
  return 0;
}


int sudokuRegra( int m[9][9]){

  int i,j,k; // indices 
  int cont = 3; //indice especial que varia de 3 em 3 referente as colunas
  int v[9], ok;     //variavéis que vão verificar se cada bloco, linha e coluna da matriz está de acordo com a regra

  i = 0;
  k = 0;

  /*********************************** VERIFICANDO BLOCO **********************************/
  for( j = 0; j < 9; j ++){
    for(i ; i < cont; i++){
      v[k] = m[i][j];  // atribuindo os valores do bloco a um vetor que irá verificar se há números repetidos.
      k++;
      if(j == 2 || j == 5 || j == 8){ // divisão entre os blocos, chamando a funçao verificar 
        ok = verificar(v);
        if ( ok < 0){ // caso negativo, não de acordo com as regras SUDOKU
          return -1;
        }
        k = 0;    // não necessário zerar o vetor ve verificação dos valores, pois será sobreescrito com os valores do novo bloco
      }
      if(j == 8){
        i = cont;
        cont += 3;
        j = 0;
      }

    }
  }
  /*********************************** VERIFICANDO LINHAS **********************************/
  
  for( i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      v[j] = m[i][j];  //salvando as linhas no vetor v, indice j pois indexação é ideal para a atribuicao
    }
    ok = verificar(v);
    if ( ok < 0){ // caso negativo, não de acordo com as regras SUDOKU
      return -1;
    }
  }
  /************************* VERIFICANDO COLUNAS *****************************/
  for( j = 0; j < 9; j++){
    for(i = 0; i < 9; i++){
      v[i] = m[i][j]; //salvando as linhas no vetor v, indice i pois indexação é ideal para a atribuicao
    }
    ok = verificar(v);
    if ( ok < 0){ // caso negativo, não esta de acordo com as regras SUDOKU
      return -1;
    }
  }
  return 0;
}


int verificar(int v[9]){
  int i,j;
  for( i = 0; i < 9; i++){
    for( j = i + 1; j < 9; j++){
      if(v[i] == v[j]){  //apenas verdadeiro se houver repetição
        return -1;
      }
    }
  }
  return 0;
}