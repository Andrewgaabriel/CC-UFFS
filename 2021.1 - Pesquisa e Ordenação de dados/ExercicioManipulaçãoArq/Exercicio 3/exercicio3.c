#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *arquivo = fopen("arquivo.txt", "rt");
    if (arquivo == NULL) {
        printf("Erro na leitura do arquivo!");
        exit(1);
    }

    int n; //numero de registros
    fscanf(arquivo, "%d\n", &n);

    char nome[51];
    float nota1, nota2;
    

    printf("Alunos com media aritmetica > 7.0: \n");
    while(fscanf(arquivo, "%[A-Z ]\n%f\n%f\n", nome, &nota1, &nota2) > 0){
        if ((nota1+nota2)/2 > 7.0) {
            printf("Aluno: %s\n", nome);
            printf("Nota 1: %.1f\n", nota1);
            printf("Nota 2: %.1f\n", nota2);
        }
    }
    fclose(arquivo);

    return 0;
}