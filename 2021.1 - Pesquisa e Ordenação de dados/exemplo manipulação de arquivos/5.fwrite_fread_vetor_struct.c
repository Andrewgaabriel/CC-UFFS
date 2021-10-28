#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    int idade;
    float altura;
} Pessoa;

int main() {

    Pessoa p[5] = {
        {"Maria", 59, 1.67},
        {"Ana", 22, 1.58},
        {"Jose", 30, 1.80},
        {"Luiz", 39, 1.92},
        {"Joaozinho", 5, 1.10},
    };

    FILE *arq = fopen("arq5.aul", "wb");
    if(arq == NULL){
        printf("Não foi possível criar o arquivo!");
        exit(1);
    }
    fwrite(p, sizeof(Pessoa), 5, arq);
    fclose(arq);

    FILE *arq2 = fopen("arq5.aul", "rb");
    if(arq2 == NULL){
        printf("Não foi possível ler o arquivo!");
        exit(1);
    }

    Pessoa pessoasLidas[5];
    fread(pessoasLidas, sizeof(Pessoa), 5, arq2);
    for(int i=0; i < 5; i++)
        printf("Nome: %s - Idade: %d - Altura: %.2f\n", pessoasLidas[i].nome, pessoasLidas[i].idade, pessoasLidas[i].altura);
    fclose(arq2); 
    return 0;
}