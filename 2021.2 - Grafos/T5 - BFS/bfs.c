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
  int cauda;
  int value[1000];

} Fila;




void initFila(Fila *f, int vertex) {
  f->topo = 0;
  f->cauda = 0;
  for(int i = 0; i < N; i++) {
      f->value[i] = -1;
  }
  f->value[f->topo] = vertex;
}



void addQ(Fila *f, int valor) {
  f->value[f->cauda] = valor;
  f->cauda++;
}


void removeQ(Fila *f){
    f->topo = f->topo+1
}

void initMatD(int matD[][N], int n) {
  for(int i = 0; i < n; i++) {
    matD[0][i] = MAX; // ==> distância
    matD[1][i] = 0;   // ==> vertice anterior
    matD[2][i] = 2;   // ==> cor: 0 > preto ||| 1 > cinza  ||| 2 > branco  
  }
}



void printVec(Fila *fila) {
  for(int i = 0; i < N; i++) {
      printf("[%d],", fila->value[i]);
    }
  printf("\n");
}


void printMatD(int matD[N][N], int n, int aVertex) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (matD[j][i] == MAX) {
                printf("\tNON\t|");
            }
            else {
                if (j == 2) {
                    if(matD[j][i] == 0){
                        printf("\tPreto\t|");
                    }
                    else if(matD[j][i] == 1){
                        printf("\tCinza\t|");
                    }
                    else if(matD[j][i] == 2){
                        printf("\tBranco\t|");
                    }
                }
                else if(j == 1 && matD[j][i] == -1) {
                    printf("\tnone\t|");
                }
                else {
                    printf("\t%d\t|", matD[j][i]);
                }
            }
        }
        if(i == aVertex && aVertex > -1 && aVertex < n) {
            printf(" <- visiting");
        }
        printf("\n");
    }
}


void bfs(int matD[][N], int matA[][N], Fila *fila, int n, int fVertex, int dVertex) {

    if (fVertex == dVertex) {
        printf("Voce ja encontrou o vertice procurado!\n");
        return;
    }

    int aVertex = fVertex;

    while (aVertex < n) {
        matD[2][aVertex] = 1; // torna-se cinza;

        for (int i = 0; i < n; i++) {
            if (matA[aVertex][i] != 0 && matD[2][i] == 0) { //se ele alcança outro e o outro for cinza ->
                addQ(fila, i); // adiciona na fila
                matD[2][i] = 1; // torna-se cinza
                matD[0][i] = matD[0][aVertex] + 1; // setando distancia
                matD[1][i] = aVertex; // setando vertice anterior
            }
            if (matA[aVertex][i] != 0 && i == dVertex) {
                // ! PRINTA A MATRIZ DE DADOS
                printMatD(matD, n);
                printVec(fila);
                // ! PRINTA A LISTA DE CORES
                printf("\n\n >>> Chegamos no destino! ");

                return;

            }
             if(fila->topo > fila->cauda) {
                printf("\n\n Destino nao encontrado! \n"); 
                return;
             }
        }
        matD[2][aVertex] = 0; // torna-se preto

        // ! PRINTA A MATRIZ DE DADOS
        removeQ(fila);
        printVec(fila);
        // ! PRINTA A LISTA DE CORES
        aVertex = fila->value[fila->topo]; // atualiza o vertice atual

    }
}




int main() {

    Fila fila;
    int matD[3][N]; 
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
    printf("Digite o vertice de origem: \n");
    scanf("%d", &fVertex);
    

    printf("Digite o vertice de destino: \n");
    scanf("%d", &dVertex);

    bfs(matD, mat, fila, N, fVertex, dVertex);

    return 0;
} 