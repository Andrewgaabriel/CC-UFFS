#include <stdio.h>
#include <string.h>

int main() {
    
    FILE *arq = fopen("arq1.aul", "wt");
    if(arq == NULL){
        printf("Não foi possível criar o arquivo!");
        exit(1);
    }

    char c;
    for(int i = 0; i < 26; i++){
        c = 65 + i;
        fputc(c, arq);
        fputc('\n', arq);
    }
    fclose(arq);

    FILE *arq2 = fopen("arq1.aul", "rt");
    if(arq2 == NULL){
        printf("Não foi possível ler o arquivo!");
        exit(1);
    }

    while(!feof(arq2)){
        c = fgetc(arq2);
        printf("%c", c);
    }
    fclose(arq2);
    return 0;
}