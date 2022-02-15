#include <stdio.h>
#include <stdlib.h>


//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)


#define N 4
#define MAX 2147483647


/**
 * @brief define the stack struct;
 * 
 */
typedef struct stack{

  int top;
  int value[20];

} Stack;



/**
 * @brief init the stack
 * 
 * @param f -> the stack
 * @param vertex -> the first element of the stack
 */
void initStack(Stack *f, int vertex) {
  f->top = 0;
  f->value[f->top] = vertex;
}



/**
 * @brief add some element in the Stack
 * 
 * @param f -> the Stack
 * @param valor -> value to be added
 */
void addS(Stack *f, int valor) {
    f->top+=1;
    f->value[f->top] = valor;
}



/**
 * @brief remove some element from Stack
 * 
 * @param f 
 */
void removeS(Stack *f){
    f->value[f->top] = 0; //desempilha
    f->top-=1;
}



/**
 * @brief print the Stack
 * 
 * @param Stack -> the Stack
 */
void printStack(Stack *s) {
    printf("\n");
    for(int i = 0; i < N; i++) {
        printf("[%d],", s->value[i]+1);
        }
    printf("\n");
}



/**
 * @brief init the BFS matrix, this matrix stores the data
 * 
 * @param matD -> the matrix
 * @param n -> lenght of the matrix
 */
void initMatD(int matD[N][5], int n) {
  for(int i = 0; i < n; i++) {
    matD[i][0] = i+1;     //nomeação;
    matD[i][1] = 2;   //cor: 0 > preto ||| 1 > cinza  ||| 2 > branco
    matD[i][2] = -1;    //vertice anterior;
    matD[i][3] = 0;     // D - timestamp in
    matD[i][4] = 0;     // F - timestamp out
    }
}



/**
 * @brief print the data matrix;
 * 
 * @param matD -> the matrix
 * @param n -> lenght of the matrix
 * @param aVertex -> vertex being visited
 */
void printMatD(int matD[N][5], int n, int aVertex) {

    printf("\tNOME\t|\COR.\t|\tV.ANT.\t|\tD\t|\tF\t|\t\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {

            if (matD[i][j] == MAX) {
                printf("\tN/A\t|");
            } else {
                if (j == 1) {
                    if(matD[i][j] == 0){
                        printf("\tPreto\t|");
                    }
                    else if(matD[i][j] == 1){
                        printf("\tCinza\t|");
                    }
                    else if(matD[i][j] == 2){
                        printf("\tBranco\t|");
                    }
                }
                else if(j == 2 && matD[i][j] == -1) {
                    printf("\tN tem\t|");
                }
                else if(j == 2){
                    printf("\t%d\t|", matD[i][j]+1);
                }
                else {
                    printf("\t%d\t|", matD[i][j]);
                }
            }
        }
        if(i == aVertex && aVertex > -1 && aVertex < n) {
            printf(" <- Visitando.");
        }
        printf("\n");
    }
}



/**
 * @brief print the color of the vertexes
 * 
 * @param matD -> data matrix
 */
void printColors(int matD[N][5]) {

    printf("Nodos brancos: ");
    for(int i = 0; i < N; i++){
        if(matD[i][1] == 2){
            printf("[%d] ", i+1);
        }
    }
    printf("\n");


    printf("Nodos cinzas: ");
    for(int i = 0; i < N; i++){
        if(matD[i][1] == 1){
            printf("[%d] ", i+1);
        }
    }
    printf("\n");

    printf("Nodos pretos: ");
    for(int i = 0; i < N; i++){
        if(matD[i][1] == 0){
            printf("[%d] ", i+1);
        }
    }
    printf("\n");

}



/**
 * @brief perform the bfs
 * 
 * @param matD -> data matrix
 * @param matA -> adjacency matrix
 * @param queue -> the queue
 * @param n -> lenght of the matrix
 * @param fVertex -> first vertex
 * @param dVertex -> destiny
 */
void dfs(int matD[N][5], int matA[N][N], Queue *queue, int n, int fVertex, int dVertex) {

    if (fVertex == dVertex) {
        printf("Voce ja encontrou o vertice procurado!\n");
        return;
    }

    int aVertex = fVertex; //vertice atual

    while (aVertex < n) {


        printf("\n>>> Visitando o vertice %d <<<\n\n", aVertex+1);



        for (int i = 0; i < n; i++) {
            if (matA[aVertex][i] != 0 && matD[i][3] != 0) { //se ele alcança outro e o outro for branco;
                addQ(queue, i);                      // adiciona na queue
                matD[i][3] = 1;                     // torna-se cinza
                matD[i][2] = aVertex;               // setando vertice anterior
                matD[i][1] = matD[aVertex][i] + 1;  // setando a distancia
                
            }
            if (matA[aVertex][i] != 0 && i == dVertex) {
                printMatD(matD, n, aVertex);
                printVec(queue);
                printColors(matD);
                printf("\n\n >>> Chegamos no vertice %d, o seu destino!\n\n ", i+1);

                return;

            }
            if(queue->head > queue->tail) {
                printf("\n\n Destino nao encontrado! \n"); 
                return;
             }
        }
        matD[aVertex][3] = 0; // torna-se preto

        printMatD(matD, n, aVertex);
        removeQ(queue);
        printVec(queue);
        printColors(matD);
        if(queue->value[queue->head] == -1) {

        }
        aVertex = queue->value[queue->head]; // atualiza o vertice atual
    }
}




int main() {

    Stack stack;
    int matD[N][5]; 
    initMatD(matD, N);
  
    int mat[N][N] = {               /* 1 2 3 4 */
                            /*1*/     {0,1,1,0}
                            /*2*/    ,{0,0,0,1}
                            /*3*/    ,{0,1,0,0}
                            /*4*/    ,{0,0,1,0}
            
                                
    };

    int fVertex, dVertex;

    printf("Digite o vertice de origem: (1-%d)\n", N);
    scanf("%d", &fVertex);
    
    printf("Digite o vertice de destino: (1-%d)\n", N);
    scanf("%d", &dVertex);
    
    initStack(stack, fVertex);

    bfs(matD, mat, &queue, N, fVertex-1, dVertex-1);

    return 0;
} 