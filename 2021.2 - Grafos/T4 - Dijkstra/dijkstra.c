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
 * @brief print the dijkstra algorithm
 * 
 * @param n 
 * @param vis 
 * @param valor 
 * @param anterior 
 */
void printDijkstra(int n, int vis[], int valor[], int anterior[]) {
    printf("\t Estado atual\n");
    printf("\t| Vert\t| Vis\t| Valor\t| Anterior\n");
    for(int i = 0; i < n; i++) {
        printf("\t| %c ", i+65);
        printf("\t| %d ", vis[i]);

        if(valor[i] == MAX) {
            printf("\t| INF ");    
        } else {
            printf("\t| %d ", valor[i]);
        }
        printf("\t| %c ", anterior[i]+65);
        printf("\n");
    }
}



/**
 * @brief implements dijkstra algorithm
 * 
 * @param mat 
 * @param n 
 * @param verticeInicial 
 */
void dijkstra(int mat[][N], int n, int verticeInicial) {

    int verticeAtual  = verticeInicial;
    int jaVisitados[N];
    int valorAcumulado[N];
    int verticeAnterior[N];

    fillVec(jaVisitados, n, 0);
    fillVec(valorAcumulado, n, MAX);
    fillVec(verticeAnterior, n, -1);


    while(verticeAtual < n) {
        printf("\n>>> Visitando o vertice %c <<<\n\n", verticeAtual+65);
        jaVisitados[verticeAtual] = 1;

        for(int i = 0; i < n; i++) {
            if(mat[verticeAtual][i] != 0 && jaVisitados[i] != 1 && (mat[verticeAtual][i] + valorAcumulado[verticeAtual]) < valorAcumulado[i]) {
                if(valorAcumulado[verticeAtual] == MAX) {
                    valorAcumulado[i] = mat[verticeAtual][i];
                } else {
                    valorAcumulado[i] = mat[verticeAtual][i] + valorAcumulado[verticeAtual];
                }
                verticeAnterior[i] = verticeAtual;
            }
        }

        printDijkstra(n, jaVisitados, valorAcumulado, verticeAnterior);


        int menor = MAX;
        int proximoVertice;
        for(int i = 0; i < n; i++) {
            if(jaVisitados[i] != 1 && valorAcumulado[i] < menor) {
                menor = valorAcumulado[i];
                proximoVertice = i;
            }
        }
        
        if(menor == MAX || proximoVertice > n) {
            return;
        }

        verticeAtual = proximoVertice;
    }
}








int main(){
    int verticeInicial;
    int mat[N][N] = {
                                 {0,7,0,5,0,0,0}
                                ,{7,0,8,9,7,0,0}
                                ,{0,8,0,0,5,0,0}
                                ,{5,9,0,0,15,6,0}
                                ,{0,7,5,15,0,8,9}
                                ,{0,0,0,6,8,0,11}
                                ,{0,0,0,0,9,11,0}
                                
    };

    printf("\tMATRIX:\n\n");

    printMat(mat, N);

    printf("\n");


    printf(">>> Aplicando Dijkstra <<< \n - Defina o vertice inicial: (0-%d)\n", N-1);
    scanf("%d", &verticeInicial);
    printf("Vertice escolhido: %d == %c\n\n", verticeInicial, verticeInicial+65);

    dijkstra(mat, N, verticeInicial);


    return 0;
} 