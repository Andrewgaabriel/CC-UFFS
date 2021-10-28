#include <stdio.h>
#include <string.h>

int main() {
    // gravacao
    FILE *arq = fopen("arq3.aul", "w+t"); // gravacao e leitura em novo arquivo
    if(arq == NULL){
        printf("Não foi possível criar o arquivo!");
        exit(1);
    }

    char c;
    for(int i = 0; i < 26; i++){
        c = 65 + i;
        fprintf(arq, "Letra %c - Codigo %d\n", c, c);
    }

    // leitura
    rewind(arq); // ou fseek(arq, 0, SEEK_SET);
    char lido;
    int cod;
    while(fscanf(arq, "Letra %c - Codigo %d\n", &lido, &cod) > 0){
        printf("%c: %d\n", lido, cod);
    }
    fclose(arq);
    return 0;
}