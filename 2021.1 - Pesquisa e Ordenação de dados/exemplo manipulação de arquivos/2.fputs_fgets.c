#include <stdio.h>
#include <string.h>

int main() {
    
    FILE *arq = fopen("arq2.aul", "wt");
    if(arq == NULL){
        printf("Não foi possível criar o arquivo!");
        exit(1);
    }

    char c[30] = "Ciencia da Computacao\n";
    char d[30] = "UFFS\n";
    char e[30] = "Chapeco\n";
    fputs(c, arq);
    fputs(d, arq);
    fputs(e, arq);
    fclose(arq);

    FILE *arq2 = fopen("arq2.aul", "rt");
    if(arq2 == NULL){
        printf("Não foi possível ler o arquivo!");
        exit(1);
    }

    char lido[30];
    while(fgets(lido, 30, arq2)){
        printf("%s", lido);
    }
    fclose(arq2);
    return 0;
}