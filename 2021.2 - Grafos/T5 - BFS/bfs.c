#include <stdio.h>
#include <stdlib.h>

//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)



#define N 7
#define MAX 2147483647







/**
 * @brief -> fill the MATRIX;
 * 
 * @param mat 
 * @param n 
 */
void fillMat(int mat[][N], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0 ;j< n; j++) {
            mat[i][j] = 0;
        }
    }
}



/**
 * @brief -> fill the VECTOR with value;
 * 
 * 
 * @param mat 
 * @param n
 */
void fillVec(int vet[N], int n, int value) {
    for(int j = 0 ;j< n; j++) {
        vet[j] = value;
    }
}



/**
 * @brief -> print the MATRIX
 * 
 * @param mat 
 * @param n 
 */
void printMat(int mat[][N], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0 ;j< n; j++) {
            printf("\t| %d ", mat[i][j]);
        }
        printf("\n");
    }
}


/**
 * @brief -> print the MATRIX d
 * 
 * @param mat 
 * @param n 
 */
void printMatD(int matD[][N], int n) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0 ;j < n; j++) {
            if(matD[i][j] == MAX) {
                printf("\t| INF. ");
            } else {
                printf("\t| %d ", matD[i][j]);
            }
            
        }
        printf("\n");
    }
}


typedef struct fila{

  int topo;
  int c;
  int value[N];

} Fila;




void initFila(Fila *f, int vertex) {
  f->topo = 0;
  f->c = 1;
  for(int i = 0; i < N; i++) {
      f->value[i] = -1;
  }
  f->value[f->topo] = vertex;
}



void addQ(Fila *f, int valor) {
  f->value[f->c] = valor;
  f->c++;
}




void initMatD(int matD[][N], int n) {
  for(int i = 0; i < n; i++) {
    matD[0][i] = MAX;
    matD[1][i] = 0;
    matD[2][i] = 2;
  }
}



void printVec(Fila *fila) {
  for(int i = 0; i < N; i++) {
      printf("[%d],", fila->value[i]);
    }
  printf("\n");
}



void bfs(int matD[][N], int matA[][N], Filfa *fila, int n) {

}




int main()
{

    Fila fila;
    int matD[3][N]; //0-distancia; 1-vert.anterior; 2-color (0 is black, 1 is gray; 2 is white) ;

    initMatD(matD, N);
  
    int mat[N][N] = {
                                 {0,7,0,5,0,0,0}
                                ,{7,0,8,9,7,0,0}
                                ,{0,8,0,0,5,0,0}
                                ,{5,9,0,0,15,6,0}
                                ,{0,7,5,15,0,8,9}
                                ,{0,0,0,6,8,0,11}
                                ,{0,0,0,0,9,11,0}
                                
    };



    int fVertex;
    printf("Digite o primeiro a vertice a ser visitado: ");
    scanf("%d", &fVertex);
    
    initFila(&fila, fVertex);
    addQ(&fila, 10);
    printVec(&fila);

    addQ(&fila, 5);
    printVec(&fila);

    addQ(&fila, 2);
    printVec(&fila);
    printMatD(matD, N);



    







    /*


    printMatD(matD, N); -> função que imprime a matriz que armazena os dados
    addQ(&fila, 10); -> função para adicionar elemento na fila de visitas
    printVec(&fila); -> função que imprime a fila de visitas            
    
    
    */
    
    



    return 0;
} 