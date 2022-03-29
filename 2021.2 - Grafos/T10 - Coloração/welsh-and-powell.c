#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



#define N 11



/**
 * @brief Função que imprime tabela de cores
 * 
 * @param cores 
 * @param atual 
 */
void printCores(int *cores, int atual) {

    printf("\n_________________________________\n");
    printf("|\tVertice\t|\tCor\t|\n");
    printf("|<--------------><------------->|\n");
    for(int i = 0; i < N; i++){
        if(cores[i] == 0)
        {
            printf("|\t%d\t| %d - NON\t| ", i, cores[i]);
        }
        else if(cores[i] == 1)
        {
            printf("|\t%d\t| %d - VERMELHO\t| ", i, cores[i]);
        }
        else if(cores[i] == 2)
        {
            printf("|\t%d\t| %d - VERDE\t| ", i, cores[i]);
        }
        else if(cores[i] == 3)
        {
            printf("|\t%d\t| %d - AZUL\t| ", i, cores[i]);
        }
        else if(cores[i] == 4)
        {
            printf("|\t%d\t| %d - PRETO\t| ", i, cores[i]);
        }
        else if(cores[i] == 5)
        {
            printf("|\t%d\t| %d - BRANCO\t| ", i, cores[i]);
        } else {
            printf("|\t%d\t|\t%d\t| ", i, cores[i]);
        }
        if(i == atual){
            printf("<---");
        }
        printf("\n");
    }
    printf("|_______________________________|\n");
}



/**
 * @brief Função que seta os graus de cada vértice
 * 
 * @param graus 
 * @param adj 
 */
void set_degree(int *graus, int adj[N][N]) {

    for (int i = 0; i < N; i++) {
        int c = 0;
        for (int j = 0; j < N; j++) {
            if (adj[i][j] != 0) {
                c++;
            }
        }
        graus[i] = c;
    }
}



/**
 * @brief Função que ordena os vértices de acordo com o grau 
 * @param graus lista de graus
 * @param vertices lista de vértices
 */
void ordenaPorGrau(int *graus, int *vertices){
    for(int i = 0; i < N; i++){
        int maior = 0;
        int posmaior;
        for(int j = 0; j < N; j++){
            if(graus[j] > maior){
                maior = graus[j];
                posmaior = j;
            }
        }
        vertices[i] = posmaior;
        graus[posmaior] = -1;
    }
}



/**
 * @brief função que verifica se ainda há vértices não coloridos
 * 
 * @param cores 
 * @return true 
 * @return false 
 */
bool ehColorivel(int *cores) {
    for (int i = 0; i < N; i++) {
        if(cores[i] == 0){
            return false;
        }
    }
    return true;
}



/**
 * @brief Função que verifica se eu posso pintar
 * 
 * @param cores 
 * @param adj 
 * @param vertice 
 * @param cor 
 * @return true posso pintar
 * @return false não posso pintar
 */
bool possoPintar(int *cores, int adj[N][N], int vertice, int cor){
    if(cores[vertice] != 0) {
        return false;
    }

    for(int i = 0; i < N; i++){
        if(adj[vertice][i] != 0){
            if(cores[i] == cor){
                return false;
            }
        }
    }
    return true;
}



/**
 * @brief Função que implementa o algoritmo Welsh-Powell
 * 
 * @param cores 
 * @param adj 
 * @param vertices 
 * @return int numero de cores
 */
int welsh_and_powell(int *cores, int adj[N][N], int *vertices) {
    int nColor = 1;
    int i = 0;

    while(!ehColorivel(cores)){ // verifica se ainda há vértices não coloridos

        if(cores[vertices[i]] == 0){

            for(int j = 0; j < N; j++) {

                if(adj[vertices[j]][vertices[i]] == 0 && possoPintar(cores, adj, vertices[j], nColor)){

                    cores[vertices[j]] = nColor;
                    printCores(cores, vertices[j]);
                }
            }
            nColor++;
            i++;
        } else {
            i++;
        }
    }
    return nColor;
}



/**
 * @brief Função que inicia a lista de cores
 * 
 * @param cores 
 */
void initCores(int *cores){
    for(int i = 0; i < N; i++){
        cores[i] = 0;
    }
}



/**
 * @brief Função que printa a relação de vertice e seu respectivo grau
 * 
 * @param graus 
 */
void printGraus(int *graus){
    printf("\n_________________________________\n");
    printf("|\tVertice\t|\tGrau\t|\n");
    printf("|<--------------><------------->|\n");
    for (int i = 0; i < N; i++){
        printf("|\t%d\t|\t%d\t|\n", i, graus[i]);
    }
    printf("|_______________________________|\n");
}



/**
 * @brief Função que printa ordem dos vértices por grau
 * 
 * @param vertices 
 */
void printGrausOrd(int *vertices) {
    printf("\n_________________________________\n");
    printf("|\tOrdem\t|\tVertice\t|\n");
    printf("|<--------------><------------->|\n");
    for (int i = 0; i < N; i++){
            printf("|\t%d\t|\t%d\t|\n", i+1, vertices[i]);
        }
    printf("|_______________________________|\n");
}



int main() {
    

    int vertices[N];
    int graus[N];
    int cores[N];
    int qtdcores;

    initCores(cores);

    int mat[N][N] = {               /* 0 1 2 3 4 5 6 7 8 9 10*/
                            /*0*/     {0,1,0,0,0,0,0,1,0,0,0}
                            /*1*/    ,{1,0,0,1,0,0,0,0,0,0,0}
                            /*2*/    ,{0,0,0,1,0,0,0,0,0,0,0}
                            /*3*/    ,{1,1,0,0,0,0,0,0,1,0,1}
                            /*4*/    ,{0,0,0,0,0,1,0,0,0,0,1}
                            /*5*/    ,{0,0,0,0,1,0,1,0,0,0,0}
                            /*6*/    ,{0,0,0,0,0,1,0,1,0,0,1}
                            /*7*/    ,{1,0,0,0,0,0,1,0,1,1,1}
                            /*8*/    ,{0,0,0,1,0,0,0,1,0,1,0}
                            /*9*/    ,{0,0,0,0,0,0,0,1,1,0,1}
                            /*10*/   ,{0,0,0,1,1,0,1,1,0,1,0}       
    };


    set_degree(graus, mat);
    printGraus(graus);

    ordenaPorGrau(graus, vertices);
    printGrausOrd(vertices);

    qtdcores = welsh_and_powell(cores, mat, vertices);

    printf("\n________TABELA RESULTADO________");
    printCores(cores, -1);


    printf("\n__________________________________");
    printf("\n| Numero de cores: %d             |", qtdcores-1);
    printf("\n|________________________________|\n");


    return 0;
}
