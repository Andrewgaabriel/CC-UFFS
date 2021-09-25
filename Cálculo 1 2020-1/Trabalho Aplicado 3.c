#include <stdio.h>
#include <math.h>

double altura(double x){ //função que calcula altura;
  double euler, altura;
  euler = 2,71828182;
  altura = (pow(euler,x)) + 2.0;
  return altura;

}


int main() {
  double a,b; //intervalo;
  double n; //quantidade de faixas;
  double largura; //armazena a largura de cada faixa
  double i;//contador
  double area;//armazena a area
  printf("======= Funcao -> f(x) = e^x + 2 ========\n");
  printf("Digite seu intervalo [a,b]\nA:");
  scanf("%lf",&a);
  printf("B:");
  scanf("%lf",&b);
  printf("----------------------------------------\n");
  printf("Digite a quantidade de divisoes/faixas:");
  scanf("%lf",&n );
  largura = (b-a)/n; //largura de cada faixa;
  i = a;
  while (i<=(largura+b)){
    area += (largura*altura(i));
    i+=largura;
  };
  printf("--------------------------------\n");
  printf("Area aproximada = %lf\n", area);


  return 0;
}
