#include <stdio.h>
int main(){
  int vet[101], i;
  for (i=0; i<101; i++){
    vet[i] = i;
  }
  for (i=1; i<101; i++){
    if (vet[i]%2==0){
      printf("%d\n", vet[i]);
    }
  }
}
