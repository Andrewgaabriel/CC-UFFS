#include <stdio.h>
int main(){
  int vet[20], aux, i, c;
  for (i=0; i<20; i++){
    scanf("%d", &vet[i]);
  }
  for (i=0, c=19; i<10; i++, c--){
    aux = vet[i];
    vet[i] = vet[c];
    vet[c] = aux;
  }
  for (i=0; i<20; i++){
    printf("N[%d] = %d\n",i, vet[i]);
  }
  return 0;
}
