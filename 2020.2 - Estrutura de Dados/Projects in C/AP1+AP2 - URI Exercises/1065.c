#include <stdio.h>

int main(){
  int qntP=0, vet[5], i;
  for (i=0; i<5; i++){
    scanf("%d", &vet[i]);
    if (vet[i]%2==0){
      qntP+=1;
    }
  }
  printf("%d valores pares\n", qntP);
  return 0;
}
