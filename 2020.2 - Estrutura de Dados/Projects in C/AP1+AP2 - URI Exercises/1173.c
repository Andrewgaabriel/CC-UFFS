#include <stdio.h>
int main(){
  int vet[10],i,c;
  scanf("%d", &i);
  vet[0]=i;
  for (c=1; c<10; c++){
    vet[c]=vet[c-1]+vet[c-1];
  }
  for (c=0; c<10; c++){
    printf("N[%d] = %d\n",c, vet[c]);
  }
  return 0;
}
