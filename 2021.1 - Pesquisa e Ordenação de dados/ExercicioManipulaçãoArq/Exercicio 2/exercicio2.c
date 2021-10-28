#include <stdio.h>
#include <stdlib.h>


void selection_sort(int vetor[], int n){
    int k, j, aux, men;

    for (k=0; k<n-1; k++)
    {
        men = k;
        for (j=k+1; j<n; j++)
        {
            if (vetor[men] > vetor[j])
            {
                men = j;
            }
        }
        aux = vetor[k];
        vetor[k] = vetor[men];
        vetor[men] = aux;
    }
}

int main() {

    //abertura
    FILE *arquivo = fopen("numeros.txt", "rt");
    if (arquivo == NULL) {
        printf("Erro na leitura do arquivo!");
        exit(1);
    }


    char virgula;
    int numero;
    int num[20];
    int i = 0;

    while(fscanf(arquivo, "%d%c", &numero, &virgula) > 0){
        num[i] = numero;
        i++;
    }
    fclose(arquivo);

    for (int c = 0; c<20; c++) {
        printf("%d ", num[c]);
    }

    selection_sort(num, 20);


    FILE *arquivo2 = fopen("numeros_ord.txt", "wt");
    if (arquivo2 == NULL) {
        printf("Erro na escrita do arquivo!");
        exit(1);
    }


    char c;
    for(int i = 0; i < 20; i++){
        fprintf(arquivo2, "%d\n", num[i]);
    }
    fclose(arquivo2);
    

}