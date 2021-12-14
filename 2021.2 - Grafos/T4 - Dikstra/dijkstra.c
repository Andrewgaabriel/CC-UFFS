#include <stdio.h>
#include <stdlib.h>

//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)



#define N 7




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
 * @brief -> fill the MATRIX;
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
 * @brief -> verify if the MATRIZ-GRAPH is guided
 * 
 * @param mat 
 * @param n 
 * @return int  0 if the graph is regular or 1 if the graph is Oriented.
 */
int isOriented(int mat[][N], int n) {
    int isOriented = 0; // 0 = regular; 1 = orientado(Oriented);
    for(int i = 0; i < n; i++) {
        for(int j = 0 ;j< n; j++) {
            if(mat[i][j] != mat[j][i]){
                isOriented = 1;
            }
        }
    }
    return isOriented;
}



/**
 * @brief -> print oriented GRAPHS;
 * 
 * @param mat 
 * @param n 
 */
void printOrientedGraph(int mat[][N], int n) {
    int grauSaida[n];
    fillVec(grauSaida, n,0);
    int grauEntrada[n];
    fillVec(grauEntrada, n,0);


    printf("ARESTAS: (origem,destino,valor)\n\n");
    //percorre as LINHAS;
    for(int i = 0; i < n; i++) {
        //percorre as COLUNAS
        for(int j = 0 ;j< n; j++) {
            if(mat[i][j]!=0){
                grauSaida[i]++;
                grauEntrada[j]++;
                printf("( %d , %d , %d)\n", i,j, mat[i][j]);

            }
        }
    }
    printf("\nNODOS E RESPECTIVOS GRAUS\n\n");
    for(int c = 0; c < n; c++) {
        printf("Nodo %d: grau entrada: %d grau saida: %d \n", c+1, grauEntrada[c], grauSaida[c]);
    }

    printf("\nFONTES:\n\n");
    for(int c = 0; c < n; c++) {
        if(grauEntrada[c]==0){
            printf("-> Nodo %d\n", c);
        }
    }

    printf("\nSUMIDOUROS:\n\n");
    for(int c = 0; c < n; c++) {
        if(grauSaida[c]==0){
            printf("-> Nodo %d\n", c);
        }
    }
}



/**
 * @brief -> print non-oriented GRAPHS
 * 
 * @param mat 
 * @param n 
 */
void printNonOrientedGraph(int mat[][N], int n) {

    int grau[n];
    fillVec(grau, n,0);



    printf("ARESTAS: (origem,destino,valor)\n\n");
    //percorre as LINHAS;
    for(int i = 0; i < n; i++) {
        //percorre as COLUNAS
        for(int j = 0 ;j< n; j++) {
            if(mat[i][j]!=0){
                grau[i]++;

                printf("( %d , %d , %d)\n", i,j, mat[i][j]);

            }
        }
    }

    printf("\nNODOS E RESPECTIVOS GRAUS\n\n");
    for(int c = 0; c < n; c++) {
        printf("Nodo %d: Grau: %d \n", c, grau[c]);
    }
}


void dijkstra(int mat[][N], int n, int verticeInicial) {

    int vertice  = verticeInicial;
    int jaVisitados[N];
    int valorAcumulado[N];
    int verticeAnterior[N];

    fillVec(jaVisitados, n, 1);
    fillVec(valorAcumulado, n, __INT_MAX__);
    fillVec(verticeAnterior, n, -1);

    /**
     * ! IMPLEMENTAR FUNCIONAMENTO DO DIJKSTRA
     *      * Percorrer a matriz de adjacência com um while e,
     *      * ir preenchendo os vetores de dados do Dijkstra;
     * 
     */


























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




    if(isOriented(mat, N)){
        printOrientedGraph(mat, N);

    } else {
        printNonOrientedGraph(mat, N);
    }


    printf(">>> Aplicando Dijkstra <<< \n - Defina o vertice inicial: \n");
    scanf("%d", &verticeInicial);

    dijkstra(mat, N, verticeInicial);


    return 0;
} 