#include <stdio.h>
#include <math.h>

double Equacao(double X){ //funcao que calcula a o valor da equacao dado o parametro;
  double f, Euler = 2.7182;
  f = pow(Euler, X) + (2*pow(X, 2))-3;
  return f;
}

void intervaloReduzido(double x1, double x2){ // funcao para reduzir o intervalo atraves do metodo de bisseção
  double pm;
  while (x2-x1>0.1){ //aqui tem se que x1<0 e x2>0;
    pm = (x2+x1)/2; //encontra o ponto medio;
    if (Equacao(pm) < 0){ // ve se pm é negativo;
      x1 = pm; // caso a condição seja verdade, pm torna se o novo x1;
    } else
      if (Equacao(pm) > 0){ //ve se pm é positivo;
        x2 = pm; // torna pm em x2;
      }
  }
  printf("======================================================\n");
  printf("O intervalo de comprimento menor que 10^-1 e: [%.2lf, %.2lf]\n", x1, x2);
  printf("======================================================\n");
}


int main() {
  //equação escolhida : e^x+2x^2-3
  //Algoritmo que aproxima a solução da equação com o comprimento do intervalo <= 0,1;
  double x1,x2;
  double f1, f2;
  printf("========== ALGORITMO SOLUCAO EM DETERMINADO INTERVALO =========\n");
  printf("================== Equacao: e^x + 2x^2 - 3 ====================\n\n\n");
  printf("Insira o intervalo.......:\n");
  scanf("%lf %lf", &x1, &x2);
  f1 = Equacao(x1);
  f2 = Equacao(x2);

  if ((f1<0 && f2<0)||(f1>0 && f2>0)) { //verifica se há ou não uma solução no intervalo
    printf("====================================================================================\n");
    printf("Nao e possivel afirmar que existe solucao neste intervalo, tente outros dois numeros\n");
    printf("====================================================================================\n");
  } else

    if (x2-x1 > 0.1){
      printf("======================================================\n");
      printf("A equacao tem pelo menos uma solucao neste intervalo\n");
      intervaloReduzido(x1, x2);
    } else {
      printf("===========================================================================================\n");
      printf("A equacao tem pelo menos uma solucao neste intervalo\n");
      printf("O intervalo que voce digitou ja esta com um comprimento menor de 10^-1, sendo ele: [%.2lf, %.2lf]\n", x1, x2);
      printf("===========================================================================================\n");
    }



  printf("\nO resultado quando X1 = %lf == %lf\n", x1, f1);
  printf("O resultado quando X2 = %lf == %lf\n", x2, f2);
  printf("Obrigado por usar :)\n");




  return 0;
}
