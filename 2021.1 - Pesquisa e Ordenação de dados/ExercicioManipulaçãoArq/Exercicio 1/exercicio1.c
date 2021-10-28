#include <stdio.h>
#include <stdlib.h>


int main() {

    //abertura
    FILE *arquivo = fopen("exercicio1.txt", "rt");
    if (arquivo == NULL) {
        printf("Erro na leitura do arquivo!");
        exit(1);
    }

    //contadores:
    int espaco = 0;
    int quebra = 0;
    int caractere = 0;


    char c;
    while(!feof(arquivo)){
        c = fgetc(arquivo);
        switch (c)
        {
        case 32:
            espaco++;
            break;
        case 10:
            quebra++;
            break;
        default:
            caractere++;
            break;
        }
    }

    printf("Espacos: %d\n", espaco);
    printf("Quebras: %d\n", quebra);
    printf("Caracteres: %d\n", caractere-1);
}