#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    int idade;
    float altura;
} Pessoa;

int main() {

    Pessoa p = {"Maria", 59, 1.67};

    FILE *arq = fopen("arq4.aul", "wb");
    if(arq == NULL){
        printf("Não foi possível criar o arquivo!");
        exit(1);
    }
    fwrite(&p, sizeof(Pessoa), 1, arq);
    fclose(arq);

    FILE *arq2 = fopen("arq4.aul", "rb");
    if(arq2 == NULL){
        printf("Não foi possível ler o arquivo!");
        exit(1);
    }

    Pessoa pessoaLida;
    fread(&pessoaLida, sizeof(Pessoa), 1, arq2);
    printf("Nome: %s - Idade: %d - Altura: %.2f\n", pessoaLida.nome, pessoaLida.idade, pessoaLida.altura);
    fclose(arq2); 
    return 0;
}