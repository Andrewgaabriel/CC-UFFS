#include <stdio.h>
#include <stdlib.h>

//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)



#define N 6




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
void fillVec(int vet[N], int n) {
    for(int j = 0 ;j< n; j++) {
        vet[j] = 0;
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
    fillVec(grauSaida, n);
    int grauEntrada[n];
    fillVec(grauEntrada, n);


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

    int grauSaida[n];
    fillVec(grauSaida, n);
    int grauEntrada[n];
    fillVec(grauEntrada, n);


    printf("ARESTAS:\n\n");
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
        printf("Nodo %d: Grau: %d \n", c+1, grauEntrada[c]+grauSaida[c]);
    }
}



int main(){

    int matrizA[N][N] = {
                                 {0,1,0,1,0,0}
                                ,{1,0,0,0,1,0}
                                ,{0,0,0,0,0,0}
                                ,{1,0,0,0,0,0}
                                ,{0,1,0,0,0,0}
                                ,{0,0,0,0,0,0}
    };

    printf("\tMATRIX:\n\n");

    printMat(matrizA, N);

    printf("\n");




    if(isOriented(matrizA, N)){
        printOrientedGraph(matrizA, N);

    } else {
        printNonOrientedGraph(matrizA, N);
    }


    return 0;
} 