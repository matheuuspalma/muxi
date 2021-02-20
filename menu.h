/* Matheus Lucas Palma de Oliveira  
   Processo Seletivo Muxi
         HEADER   
*/

/*********questao 1**********/

int questao1(void);

/*********questao 2**********/

int questao2(void);
int sudokuRegra(int[9][9]);
int verificar(int[9]);

/*********questao 3**********/

int questao3(void);
char** stringsplit(const char *text, char separator, int *length);

/*********questao 4**********/

//06.h

/*********questao 5 **********/

typedef struct list SingleLinkedListOfIntsNode;
struct list 
{ 
   int content;
   SingleLinkedListOfIntsNode *next;
};

int questao5(void);
void listPartition(SingleLinkedListOfIntsNode **, int );
SingleLinkedListOfIntsNode* set(int);
int printList(SingleLinkedListOfIntsNode *);
int append( SingleLinkedListOfIntsNode *, SingleLinkedListOfIntsNode *, int );


/*********questao 6 **********/

typedef enum{
   ok,
   argumentoInvalido,
}err_t;

int questao6(void);
err_t findCommon(int *, int , int *, int, int *, int );
err_t avoidingDuplicated(int *, int *);
err_t removeInList(int *, int , int );