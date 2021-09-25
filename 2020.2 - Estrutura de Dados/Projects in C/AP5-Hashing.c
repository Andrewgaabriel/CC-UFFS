#include <stdio.h>
#include <stdlib.h>

#define MAXELE 20
#define OVERFLOW 5



typedef struct{
  int id;
  char nome[41];
  double salario;
  int idade;
} Funcionario;



int menu(){
	int num;
  printf("-------------------------------------\n");
  printf("\t1.Insert\n\t2.List Hash\n\t3.Exit\n");
  printf("-------------------------------------\n");
  printf("Op: ");
	scanf("%d",&num);
	return num;
}



void initHtable(Funcionario *h)
{
  int i;
  for (i=0; i<MAXELE+OVERFLOW; i++){
    h[i].idade = -1;
  }
}



void listHashTable(Funcionario *h)
{
  int i;

  printf("=================================\n");
  printf("=================================\n");
  printf("\tHASH TABLE:\n");
  printf("=================================\n");
  printf("=================================\n");

  for (i=0; i<MAXELE; i++)
  {
    if (h[i].idade!=-1){

      printf("-------------------------------------\n");
      printf("ID: %d\n", h[i].id);
      printf("NAME:  %s\n", h[i].nome);
      printf("SALARY: %.2lf\n", h[i].salario);
      printf("AGE:  %d\n", h[i].idade);
      printf("-------------------------------------\n");
    } else {
      printf("-1\n");
    }

  }

  printf("=================================\n");
  printf("=================================\n");
  printf("\tOVERFLOW AREA:\n");
  printf("=================================\n");
  printf("=================================\n");

  for (i=MAXELE; i<MAXELE+OVERFLOW ;i++)
  {
    if (h[i].idade!=-1){
      printf("-------------------------------------\n");
      printf("ID: %d\n", h[i].id);
      printf("NAME:  %s\n", h[i].nome);
      printf("SALARY: %.2lf\n", h[i].salario);
      printf("AGE:  %d\n", h[i].idade);
      printf("-------------------------------------\n");
    }else {
      printf("-1\n");
    }
  }
}

Funcionario getFunc(){
  Funcionario new;
  printf("-------------------------------------\n");
  printf("ID: ");
  scanf("%d", &new.id);
  printf("NAME: ");
  scanf("%s", new.nome);
  printf("SALARY: ");
  scanf("%lf", &new.salario);
  printf("AGE: ");
  scanf("%d", &new.idade);
  printf("-------------------------------------\n");

	return new;
}


int hash(int data)
{
   return data%MAXELE;
}


int main()
{
  Funcionario hTable[MAXELE+OVERFLOW];
  Funcionario data;
  int op, i, found, pos;
  initHtable(hTable);

  op=menu();
  while (op!=4)
  {
    switch (op)
    {
      case 1:
			data=getFunc();
			pos=hash(data.idade);
			if (hTable[pos].idade==-1){
        hTable[pos]=data;
        break;
      }else
				{
			    for (i=MAXELE;i<MAXELE+OVERFLOW;i++) //procura no overflow se tem "vaga"
				  	{
				     	found=0;
				     	if (hTable[i].idade==-1) // achou uma vaga :)
			    		{
				        hTable[i]=data; //guarda
				        found=1;
				        break;
			       	}
				   	}
				    if (!found)
				      printf("-->>>  Area de Overflow cheia!  <<<--\n");
				}
      break;


      case 2:
        listHashTable(hTable);
        break;
    }
    op=menu();
  }
  printf("\tThank U :)\n");
  return 0;
}
