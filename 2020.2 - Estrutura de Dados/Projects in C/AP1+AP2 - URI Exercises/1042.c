#include <stdio.h>
int main(){
  int vet[3], vet2[3], aux, i;
  scanf("%d %d %d", &vet[0], &vet[1], &vet[2]);
  for (i=0; i<3; i++){
    vet2[i] = vet[i];
  }
  if (vet[0]<vet[1])
  {
    aux = vet[0];
    vet[0] = vet[1];
    vet[1] = aux;
  }
  if (vet[1]<vet[2])
  {
    aux = vet[1];
    vet[1] = vet[2];
    vet[2] = aux;
  }
  if (vet[0]<vet[1])
  {
    aux = vet[0];
    vet[0] = vet[1];
    vet[1] = aux;
  }
  printf("%d \n%d \n%d\n", vet[2], vet[1], vet[0]);
  printf("\n%d \n%d \n%d", vet2[0], vet2[1], vet2[2]);
  return 0;
}
