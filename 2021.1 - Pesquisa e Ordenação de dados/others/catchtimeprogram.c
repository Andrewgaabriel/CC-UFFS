#include <stdio.h>
#include <time.h>

void funcao(int i){
    for (int j=0;j < i; j++){
        printf("Aqui o i: %d\n",j);
    }
}

int main(){
    clock_t start, end;

    start = clock();

    funcao(10000);
    
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("\n\n\n\t -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo*1000);

    return 0;
}