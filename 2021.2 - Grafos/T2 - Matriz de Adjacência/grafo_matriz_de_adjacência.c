#include <stdio.h>
#include <stdlib.h>

//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)


#define Nlinhas 10
#define Ncolunas 10


/**
 * @brief -> fill the MATRIX;
 * 
 * @param mat 
 * @param nLinhas 
 * @param nColunas 
 */
void *fillMat(int mat[][Ncolunas], int nLinhas, int nColunas) {
    for(int i = 0; i < nLinhas; i++) {
        for(int j = 0 ;j< nColunas; j++) {
            mat[i][j] = 0;
        }
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



int main(){

    int matrizA[Nlinhas][Ncolunas];
    fillMat(matrizA, Nlinhas, Ncolunas);
    printMat(matrizA, Nlinhas, Ncolunas);

    printf("\n");

    for(int i = 0; i < Nlinhas; i++) {
        matrizA[i][i] = 5;
    }
    printMat(matrizA, Nlinhas, Ncolunas);


    return 0;
} 
