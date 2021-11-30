#include <stdio.h>
#include <stdlib.h>

//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)


#define Nlinhas 6
#define Ncolunas 6



/**
 * @brief -> fill the MATRIX;
 * 
 * @param mat 
 * @param nLinhas 
 * @param nColunas 
 */
void fillMat(int mat[][Ncolunas], int nLinhas, int nColunas) {
    for(int i = 0; i < nLinhas; i++) {
        for(int j = 0 ;j< nColunas; j++) {
            mat[i][j] = 0;
        }
    }
}



/**
 * @brief -> fill the MATRIX;
 * 
 * 
 * @param mat 
 * @param nLinhas 
 * @param nColunas 
 */
void fillVec(int vet[Ncolunas], int N) {
    for(int j = 0 ;j< N; j++) {
        vet[j] = 0;
    }
}



/**
 * @brief -> print the MATRIX
 * 
 * @param mat 
 * @param nLinhas 
 * @param nColunas 
 */
void printMat(int mat[][Ncolunas], int nLinhas, int nColunas) {
    for(int i = 0; i < nLinhas; i++) {
        for(int j = 0 ;j< nColunas; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}



/**
 * @brief -> verify if the MATRIZ-GRAPH is guided
 * 
 * @param mat 
 * @param nLinhas 
 * @param nColunas 
 * @return int  0 if the graph is regular or 1 if the graph is Oriented.
 */
int isOriented(int mat[][Ncolunas], int nLinhas, int nColunas) {
    int isOriented = 0; // 0 = regular; 1 = orientado(Oriented);
    for(int i = 0; i < nLinhas; i++) {
        for(int j = 0 ;j< nColunas; j++) {
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
 * @param nLinhas 
 * @param nColunas 
 */
void printOrientedGraph(int mat[][Ncolunas], int nLinhas, int nColunas) {
    int grauSaida[nLinhas];
    fillVec(grauSaida, nLinhas);
    int grauEntrada[nLinhas];
    fillVec(grauEntrada, nLinhas);


    printf("ARESTAS: (origem,destino,valor)\n\n");
    //percorre as LINHAS;
    for(int i = 0; i < nLinhas; i++) {
        //percorre as COLUNAS
        for(int j = 0 ;j< nColunas; j++) {
            if(mat[i][j]!=0){
                grauSaida[i]++;
                grauEntrada[j]++;
                printf("( %d , %d , %d)\n", i,j, mat[i][j]);

            }
        }
    }
    printf("\nNODOS E RESPECTIVOS GRAUS\n\n");
    for(int c = 0; c < nLinhas; c++) {
        printf("Nodo %d: grau entrada: %d grau saida: %d \n", c+1, grauEntrada[c], grauSaida[c]);
    }

    printf("\nFONTES:\n\n");
    for(int c = 0; c < nLinhas; c++) {
        if(grauEntrada[c]==0){
            printf("-> Nodo %d\n", c);
        }
    }

    printf("\nSUMIDOUROS:\n\n");
    for(int c = 0; c < nLinhas; c++) {
        if(grauSaida[c]==0){
            printf("-> Nodo %d\n", c);
        }
    }
}



/**
 * @brief -> print non-oriented GRAPHS
 * 
 * @param mat 
 * @param nLinhas 
 * @param nColunas 
 */
void printNonOrientedGraph(int mat[][Ncolunas], int nLinhas, int nColunas) {

    int grauSaida[nLinhas];
    fillVec(grauSaida, nLinhas);
    int grauEntrada[nLinhas];
    fillVec(grauEntrada, nLinhas);


    printf("ARESTAS:\n\n");
    //percorre as LINHAS;
    for(int i = 0; i < nLinhas; i++) {
        //percorre as COLUNAS
        for(int j = 0 ;j< nColunas; j++) {
            if(mat[i][j]!=0){
                grauSaida[i]++;
                grauEntrada[j]++;
                printf("( %d , %d , %d)\n", i,j, mat[i][j]);

            }
        }
    }
    printf("\nNODOS E RESPECTIVOS GRAUS\n\n");
    for(int c = 0; c < nLinhas; c++) {
        printf("Nodo %d: Grau: %d \n", c+1, grauEntrada[c]+grauSaida[c]);
    }
}



int main(){

    int matrizA[Nlinhas][Ncolunas] = {
                                 {0,1,0,1,0,0}
                                ,{1,0,0,0,1,0}
                                ,{0,0,0,0,0,0}
                                ,{1,0,0,0,0,0}
                                ,{0,1,0,0,0,0}
                                ,{0,0,0,0,0,0}
    };

    printf("\tMATRIX:\n\n");

    printMat(matrizA, Nlinhas, Ncolunas);

    printf("\n");




    if(isOriented(matrizA, Nlinhas, Ncolunas)){
        printOrientedGraph(matrizA, Nlinhas, Ncolunas);

    } else {
        printNonOrientedGraph(matrizA, Nlinhas, Ncolunas);
    }


    return 0;
} 
