#include <stdio.h>
int main(){
  int valor, resto, vet[7]; //armazena a qnt de cada nota
  scanf("%d", &valor);
  resto = valor;
  vet[0] = resto/100;
  resto = resto-vet[0]*100;
  vet[1] = resto/50;
  resto = resto-vet[1]*50;
  vet[2] = resto/20;
  resto = resto-vet[2]*20;
  vet[3] = resto/10;
  resto = resto-vet[3]*10;
  vet[4] = resto/5;
  resto = resto-vet[4]*5;
  vet[5] = resto/2;
  resto = resto-vet[5]*2;
  vet[6] = resto/1;
  resto = resto-vet[6]*1;
  printf("%d\n", valor);
  printf("%d nota(s) de R$ 100,00\n", vet[0]);
  printf("%d nota(s) de R$ 50,00\n", vet[1]);
  printf("%d nota(s) de R$ 20,00\n", vet[2]);
  printf("%d nota(s) de R$ 10,00\n", vet[3]);
  printf("%d nota(s) de R$ 5,00\n", vet[4]);
  printf("%d nota(s) de R$ 2,00\n", vet[5]);
  printf("%d nota(s) de R$ 1,00\n", vet[6]);
  return 0;
}


//pos 0 - 100
//pos 1 - 50
//pos 2 - 20
//pos 3 - 10
//pos 4 - 5
//pos 5 - 2
//pos 6 - 1
