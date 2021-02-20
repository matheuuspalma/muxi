/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
         HEADER  04
*/

typedef struct stack
{
   int content;
   Stack *next;
} Stack;

Stack *stackNew (void);       //criar nova pilha
void stackFree (Stack *);     //  pilha cheia?
void stackPush (Stack *, int ); // inserir elemento da pilha 

int stackPop (Stack *);     // tirar elemento da pilha     
int stackEmpty (Stack *);        //pilha vazia?

void stackRemoveEven (Stack *);


