#include <stdio.h>
#include <stdlib.h>

//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)


#define Nlinhas 5
#define Ncolunas 5




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
 * @brief -> fill the VECTOR;
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
            printf("\t%d", mat[i][j]);
        }
        printf("\n");
    }
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
                printf("( %d , %d , %d)\n", i+1,j+1, mat[i][j]);

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
            printf("-> Nodo %d\n", c+1);
        }
    }

    printf("\nSUMIDOUROS:\n\n");
    for(int c = 0; c < nLinhas; c++) {
        if(grauSaida[c]==0){
            printf("-> Nodo %d\n", c+1);
        }
    }
}




int vCaminhos(int mat[][Ncolunas], int valorOrigem, int nLinhas, int valorDestino) {
    int c = 0;

    printf("\n----> Caminhos disponíveis: ----\n");
    for(int i = 0; i < nLinhas; i++) {
        if (mat[valorOrigem][i] > 0) {
            printf("Vertice: %d, Custo: %d\n", i+1, mat[valorOrigem][i]);
            c++;
        }        
    }

    if (mat[valorOrigem][valorDestino] > 0){
        return 1;
    } 

    if (c == 0) {
        printf("Chegamos no sumidouro! Impossível com guloso.");
        return 0;
    }
    return -1;
}


int qMenor(int mat[][Ncolunas], int i, int n){
    int menor = 2147483647;;
    for(int j=0; j < n; j++){
        if(mat[i][j] < menor && mat[i][j] != 0 && j != i){ 
            menor = mat[i][j];
        }
    }
    return menor;
}


void guloso(int mat[][Ncolunas], int nLinhas, int valorOrigem, int valorDestino){
    int valOrigem = valorOrigem;
    int custo = 0;
    int counter = 0;

    while(valOrigem < nLinhas){
        if (counter > nLinhas) {
            printf("Cansei! Impossível com guloso! \n"); //fora loop
            return;
        }
        int op = vCaminhos(mat, valorOrigem, nLinhas, valorDestino);
        if (op == 1) {
            printf("----> Caminhos escolhido! \n");
            custo += mat[valOrigem][valorDestino];
            printf("Vamos para o vertice %d, custo total: %d\n", valorDestino+1, custo);
            printf("....Chegamos!!\n");
            return;
        }
        if (op == 0){
            return;
        }
        
        for(int j = 0; j < nLinhas; j++) {
            if(mat[valOrigem][j] == qMenor(mat,valOrigem, nLinhas)) {
                printf("----> Caminho escolhido! \n");
                custo += mat[valOrigem][j];
                printf("Vamos para o vertice %d, custo: %d\n", j+1, custo);
                printf("....Chegamos!!\n");
                valOrigem = j;
                break;
            }
        }
        counter++;
    }
}


int main(){

    int origem = 0;
    int destino = 0;
    int matrizA[Nlinhas][Ncolunas] = {
                                 {0,50,30,10,100}
                                ,{0,0,0,0,0}
                                ,{0,5,0,50,0}
                                ,{0,20,0,0,0}
                                ,{0,0,0,10,0}

    };

    printf("\tMATRIX:\n\n");

    printMat(matrizA, Nlinhas, Ncolunas);

    printf("\n");

    printOrientedGraph(matrizA, Nlinhas, Ncolunas);

    printf("\n");

    printf("Digite sua origem: ");
    scanf("%d", &origem);

    printf("Digite seu destino: ");
    scanf("%d", &destino);


    guloso(matrizA, Nlinhas, origem-1, destino-1);



    return 0;
}