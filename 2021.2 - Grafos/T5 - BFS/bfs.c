#include <stdio.h>
#include <stdlib.h>


//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)


#define N 4
#define MAX 2147483647


/**
 * @brief define the queue struct;
 * 
 */
typedef struct queue{

  int head;
  int tail;
  int value[1000];

} Queue;



/**
 * @brief init the queue
 * 
 * @param f -> the queue
 * @param vertex -> the first element of the queue
 */
void initQueue(Queue *f, int vertex) {
  f->head = 0;
  f->tail = 0;
  for(int i = 0; i < N; i++) {
      f->value[i] = -1;
  }
  f->value[f->head] = vertex;
}



/**
 * @brief add some element in the queue
 * 
 * @param f -> the queue
 * @param valor -> value to be added
 */
void addQ(Queue *f, int valor) {
  f->value[f->tail] = valor;
  f->tail++;
}



/**
 * @brief remove some element from queue
 * 
 * @param f 
 */
void removeQ(Queue *f){
    f->head = f->head+1;
}



/**
 * @brief init the BFS matrix, this matrix stores the data
 * 
 * @param matD -> the matrix
 * @param n -> lenght of the matrix
 */
void initMatD(int matD[N][4], int n) {
  for(int i = 0; i < n; i++) {
    matD[i][0] = i+1;     //nomeação;
    matD[i][1] = 0;   //distancia;
    matD[i][2] = -1;    //vertice anterior;
    matD[i][3] = 2;     //cor: 0 > preto ||| 1 > cinza  ||| 2 > branco  
  }
}



/**
 * @brief print the queue
 * 
 * @param queue -> the queue
 */
void printVec(Queue *queue) {
    printf("\n");
    for(int i = 0; i < N; i++) {
        printf("[%d],", queue->value[i]+1);
        }
    printf("\n");
}



/**
 * @brief print the data matrix;
 * 
 * @param matD -> the matrix
 * @param n -> lenght of the matrix
 * @param aVertex -> vertex being visited
 */
void printMatD(int matD[N][4], int n, int aVertex) {

    printf("\tNOME\t|\tDIST.\t|\tV.ANT.\t|\tCOR\t|\t\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {

            if (matD[i][j] == MAX) {
                printf("\tN/A\t|");
            } else {
                if (j == 3) {
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
void printColors(int matD[N][4]) {

    printf("Nodos brancos: ");
    for(int i = 0; i < N; i++){
        if(matD[i][3] == 2){
            printf("[%d] ", i+1);
        }
    }
    printf("\n");


    printf("Nodos cinzas: ");
    for(int i = 0; i < N; i++){
        if(matD[i][3] == 1){
            printf("[%d] ", i+1);
        }
    }
    printf("\n");

    printf("Nodos pretos: ");
    for(int i = 0; i < N; i++){
        if(matD[i][3] == 0){
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
void bfs(int matD[N][4], int matA[N][N], Queue *queue, int n, int fVertex, int dVertex) {

    if (fVertex == dVertex) {
        printf("Voce ja encontrou o vertice procurado!\n");
        return;
    }

    int aVertex = fVertex; //vertice atual

    while (aVertex < n) {
        matD[aVertex][3] = 1; // torna-se cinza;
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

    Queue queue;
    int matD[N][4]; 
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

    initQueue(&queue, fVertex);

    bfs(matD, mat, &queue, N, fVertex-1, dVertex-1);

    return 0;
} 