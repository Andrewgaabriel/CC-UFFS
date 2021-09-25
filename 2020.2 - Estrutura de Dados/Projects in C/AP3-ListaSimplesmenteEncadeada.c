#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para usar o strcmp na hora de comparar as strings de matricula;


/*------------------------------------------*/
typedef struct{
	int dia;
	int mes;
	int ano;
} Data;
/*------------------------------------------*/



/*------------------------------------------*/
struct _aluno{
  char matricula[10];
  char nome[40];
  Data dataNasc;
  float media;
  struct _aluno *next;
};
typedef struct _aluno Aluno;
/*------------------------------------------*/


/*---------------------------------------------------------------------------*/
int Counter(Aluno *first){ //função que retorna qntd de elementos na lista;
	int cont=0;
	Aluno *aux;
	for(aux=first; aux!=NULL; aux=aux->next){
		cont += 1;
	}
	return cont;
}
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
Aluno *delAluno(Aluno *first, char *MatDel){ //função que deleta aluno dado a matricula
	Aluno *aux, *prev = NULL;
	for(aux=first; aux!=NULL; aux=aux->next){
		if ((strcmp(aux->matricula, MatDel)) == 0){
			if (aux == first){ //caso a matricula seja a primeira da lista
				first = aux->next; //encadeamento para n perder o primeiro elemento
			}else{
				prev->next = prev->next->next;
			}
			free(aux);
		}
		prev = aux;
	}
	return first;
}
/*---------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------------------------------*/
void printAlunos(Aluno *p){ //funcao que imprime os alunos q estão na lista;
	Aluno *aux;
	for (aux=p;aux!=NULL;aux=aux->next){ //percorre a lista
		printf("%s, ", aux->matricula);
		printf("%s, ", aux->nome);
		printf("%d/%d/%d, ",aux->dataNasc.dia, aux->dataNasc.mes, aux->dataNasc.ano);
		printf("%.2f\n",aux->media); //conforme percorre vai imprimindo cada elemento na ordem de inserção
	}
}
/*-------------------------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
void printAlunosInv(Aluno *p){ //função recursiva que imprime os alunos q estão na lista;
	Aluno *aux;
	if (p==NULL) return;
	aux=p;
	printAlunosInv(aux->next);
	printf("%s, ", aux->matricula);
	printf("%s, ", aux->nome);
	printf("%d/%d/%d, ",aux->dataNasc.dia, aux->dataNasc.mes, aux->dataNasc.ano);
	printf("%.2f\n",aux->media); //conforme percorre vai imprimindo cada elemento na ordem inversa
}
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
void reset(Aluno *p){ //função recursiva para resetar/desencadear a lista;
	Aluno *aux;
	if (p==NULL) return;
	aux=p;
	reset(aux->next);
	free(aux);
	printf("-");
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
Aluno *getLast(Aluno *p){
	Aluno *aux = p;
	for (aux=p; aux->next!=NULL; aux=aux->next); //percorre a lista para achar o ultimo elemento adicionado
	return aux; //retorna o ultimo elemento da lista;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
Aluno *getAluno(Aluno *first){
	Aluno *p=malloc(sizeof(Aluno));
	Aluno *aux;
	scanf("%s", p->matricula);
	scanf("%s", p->nome);
	scanf("%d/%d/%d", &p->dataNasc.dia, &p->dataNasc.mes, &p->dataNasc.ano);
	scanf("%f",&p->media);
	p->next=NULL; //aponteiramento para não perder a lista
	if (first==NULL)
	{
		first=p;
	} else {
		aux=getLast(first); //caso não seja o primeiro aq ele ja busca o ultimo pra fazer o encadeamento
		aux->next=p;
	}
	return first;
}
/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
int menu(){
	int num;
	printf("1.Insert\n2.Consulta\n3.Exit\n");
	scanf("%d",&num);
	return num;
}
/*---------------------------------------------------------------------------*/


int main(){

  int opcao, c;
	char matDel[10]; //para usar na função de deletar um aluno;
	Aluno *first=NULL;
	opcao=menu();
  while (opcao!=0)
	{
		switch (opcao)
		{
/*------------------------------------------*/
			case 1: first=getAluno(first);
							break;

/*------------------------------------------*/
			case 2: if (first==NULL){
	      printf("Lista Vazia!\n");
	      break;
	    }
			//implementa função delete;
			scanf("%s", matDel);
			first = delAluno(first, matDel);
			break;

/*------------------------------------------*/
			case 3: if (first==NULL){
	      printf("Lista Vazia!\n");
	      break;
	    }
			//implementa funcao listar elementos;
			printAlunos(first);
			break;

/*------------------------------------------*/
			case 4: if (first==NULL){
	      printf("Lista Vazia!\n");
	      break;
	    }
			//implementa funcao recursiva que imprime na ordem inversa;
			printAlunosInv(first);
			break;
/*------------------------------------------*/
			case 5: if (first==NULL){
	      printf("Lista Vazia!\n");
	      break;
	    }
			//implementa funcao que retora quantidade de elem. na lista;
			c = Counter(first);
			printf("%d\n", c);
			break;

/*------------------------------------------*/
		}
		opcao=menu(); //reeleitura do menu;
	}//fim do while
	reset(first); //função responsável por desencadear a lista;
  return 0;
}
