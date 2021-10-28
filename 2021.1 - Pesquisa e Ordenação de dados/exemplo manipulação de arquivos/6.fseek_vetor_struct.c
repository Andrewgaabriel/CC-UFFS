#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    int idade;
    float altura;
} Pessoa;

int main() {
    //gravacao
    Pessoa p[5] = {
        {"Maria", 59, 1.67},
        {"Ana", 22, 1.58},
        {"Jose", 30, 1.80},
        {"Luiz", 39, 1.92},
        {"Joaozinho", 5, 1.10},
    };

    FILE *arq = fopen("arq6.aul", "wb");
    if(arq == NULL){
        printf("Não foi possível criar o arquivo!");
        exit(1);
    }
    fwrite(p, sizeof(Pessoa), 5, arq);
    fclose(arq);

    // leitura e alteracao
    FILE *arq2 = fopen("arq6.aul", "r+b");
    if(arq2 == NULL){
        printf("Não foi possível ler o arquivo!");
        exit(1);
    }

    Pessoa p2;
    // ultimo
    fseek(arq, -(sizeof(Pessoa)), SEEK_END);
    fread(&p2, sizeof(Pessoa), 1, arq2);
    printf("Nome: %s - Idade: %d - Altura: %.2f\n", p2.nome, p2.idade, p2.altura);

    // segundo
    fseek(arq, sizeof(Pessoa), SEEK_SET);
    fread(&p2, sizeof(Pessoa), 1, arq2);
    printf("Nome: %s - Idade: %d - Altura: %.2f\n", p2.nome, p2.idade, p2.altura);

    // primeiro
    fseek(arq, 0, SEEK_SET);
    fread(&p2, sizeof(Pessoa), 1, arq2);
    printf("Nome: %s - Idade: %d - Altura: %.2f\n", p2.nome, p2.idade, p2.altura);

   // pula 2 registros
    fseek(arq, 2*sizeof(Pessoa), SEEK_CUR);
    fread(&p2, sizeof(Pessoa), 1, arq2);
    printf("Nome: %s - Idade: %d - Altura: %.2f\n", p2.nome, p2.idade, p2.altura);

    // alterar um registro
    fseek(arq, -(sizeof(Pessoa)), SEEK_END);
    fread(&p2, sizeof(Pessoa), 1, arq2);
    strcpy(p2.nome, "Joao Pedro");
    fseek(arq, -(sizeof(Pessoa)), SEEK_END);
    fwrite(&p2, sizeof(Pessoa), 1, arq2); // grava alteracao
    fseek(arq, -(sizeof(Pessoa)), SEEK_END); // volta
    fread(&p2, sizeof(Pessoa), 1, arq2); // lê novamente
    printf("Nome: %s - Idade: %d - Altura: %.2f\n", p2.nome, p2.idade, p2.altura);

    fclose(arq2); 
    return 0;
}