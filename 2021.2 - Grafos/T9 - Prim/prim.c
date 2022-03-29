#include <stdio.h>
#include <stdlib.h>

//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)



#define N 8
#define MAX 2147483647




/**
 * @brief retorna o index do menor valor e não visitado;
 * 
 * @param valor 
 * @param visitados 
 * @return int 
 */
int next(int valor[], int visitados[]) {

	int index, menor = MAX;
	for (int i = 0; i < N; i++) {
		if ( visitados[i] == 0 && valor[i] < menor)
        {
			menor = valor[i];
			index = i;
		}
	}
	return index;
}




/**
 * @brief Função que inicia os vetores de dados
 * 
 * @param visitados 
 * @param valor 
 * @param anterior 
 */
void fillData(int *visitados, int *valor, int *anterior) {
    for (int i = 0; i < N; i++)
    {
        visitados[i] = 0;
        valor[i] = MAX;
        anterior[i] = -1;
    }
}


/**
 * @brief imprime o algoritmo de prim
 * 
 * @param mat 
 * @param visitados 
 * @param valor 
 * @param anterior 
 */
void printPrim(int mat[N][N], int *visitados, int *valor, int *anterior) {
    printf("    vertice\t|   visitados\t|    valor\t|    anterior\t|\t\n");
    for (int i = 0; i < N; i++) {
	    printf("\t%d\t|\t%d\t|\t", i, visitados[i]);
        if(valor[i] == MAX) {
            printf("MAX\t|\t%d\t|\n", anterior[i]);
        } else {
            printf("%d\t|\t%d\t|\n", visitados[i], anterior[i]);
        }

	}
}



/**
 * @brief Implementa o algoritmo de PRIM;
 * 
 */
void prim(int mat[N][N], int inicial) {

    int visitados[N];
    int valor[N];
    int anterior[N];
    fillData(visitados, valor, anterior);

    valor[inicial] = 0;
    anterior[inicial] = 0;
    int aux = inicial;

    for(int i = 0; i < N-1; i++) {
        aux = next(valor, visitados);

        printf("\n------- Estado atual -------  {\n");
        printf("\t Visitando: %d\n", aux);

        visitados[aux] = 1;

		for (int j = 0; j < N; j++) {
			if (mat[aux][j] && visitados[j] == 0 && mat[aux][j] < valor[j]) {
				anterior[j] = aux;
				valor[j] = mat[aux][j];
			}
		}
        printPrim(mat, visitados, valor, anterior);
    }
}

int main(){

    int verticeInicial;
    int mat[N][N] = {               /* 0 1 2 3 4 5 6 7 */
                            /*0*/     {0,1,0,3,0,0,0,0}
                            /*1*/    ,{0,0,0,0,0,7,7,0}
                            /*2*/    ,{0,0,0,0,3,7,0,0}
                            /*3*/    ,{0,0,0,0,0,0,0,0}
                            /*4*/    ,{0,0,0,0,0,0,0,1}
                            /*5*/    ,{0,0,0,0,0,0,3,8}
                            /*6*/    ,{0,0,0,0,0,0,0,0}
                            /*7*/    ,{0,0,0,0,0,0,0,0}             
    };


    printf(">>> Aplicando Prim <<< \n - Defina o vertice inicial: (0-%d)\n", N-1);
    scanf("%d", &verticeInicial);
    prim(mat, verticeInicial);


    return 0;
} 