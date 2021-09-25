#include <stdio.h>

int main(){
  int qnt, pos, men, i;
  scanf("%d", &qnt);
  int vet[qnt];
  for (i=0; i<qnt; i++){
    scanf("%d", &vet[i]);
  }
  men = vet[0];
  for (i=1; i<qnt; i++){
    if (men>vet[i]){
      men = vet[i];
      pos = i;
    }
  }
  printf("Menor valor: %d\nPosicao: %d\n",men, pos);
}
