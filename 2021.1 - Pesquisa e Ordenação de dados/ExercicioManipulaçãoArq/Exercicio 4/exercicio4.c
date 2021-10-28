#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[51];
    float n1, n2;

} Aluno;




int main() {


    FILE *arquivo = fopen("arquivo.txt", "rt");
    if (arquivo == NULL) {
        printf("Erro na leitura do arquivo!");
        exit(1);
    }

    int n;
    fscanf(arquivo, "%d\n", &n);
    Aluno aluno[n]; //define o tamanho da array;
    int i = 0;


    while(fscanf(arquivo, "%[A-Z ]\n%f\n%f\n", aluno[i].nome, &aluno[i].n1, &aluno[i].n2) > 0){
        i++;
    }
    fclose(arquivo);



    FILE *arquivo2 = fopen("arquivo2.txt", "w+b");
    if (arquivo2 == NULL) {
        printf("Erro na leitura do arquivo!");
        exit(1);
    }

    fwrite(aluno, sizeof(Aluno), n, arquivo2);

    rewind(arquivo2);

    Aluno alunosLidos[n];
    fread(alunosLidos, sizeof(Aluno), n, arquivo2);
    for(int i=0; i < n; i++)
        printf("Nome aluno: %s \t- Nota 1: %.2f \t- Nota 2: %.2f\n", alunosLidos[i].nome, alunosLidos[i].n1, alunosLidos[i].n2);
    fclose(arquivo2);














    return 0;
}