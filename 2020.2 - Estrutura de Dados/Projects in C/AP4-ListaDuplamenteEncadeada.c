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
	struct _aluno *prev;
};
typedef struct _aluno Aluno;
/*------------------------------------------*/



/*-------------------------------------------------------------------------------------------------*/
Aluno *delAluno(Aluno *head, char *MatDel, Aluno *tail){ //função que deleta aluno dado a matricula
	Aluno *aux;
	for(aux=head; aux!=NULL; aux=aux->next){
		if ((strcmp(aux->matricula, MatDel)) == 0){
			if (aux == head){ //caso a matricula seja a primeira da lista
				head = aux->next;
				aux->next->prev=NULL;
			} else
			if (aux==tail){
				aux->prev->next=NULL;
			} else {
				aux->prev->next=aux->next;
				aux->next->prev=aux->prev;
			}
			free(aux);
		}
	}
	return head;
}
/*--------------------------------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------------------------------*/
void printAlunos(Aluno *head){ //funcao que imprime os alunos q estão na lista;
	Aluno *aux;
	for (aux=head;aux!=NULL;aux=aux->next){ //percorre a lista
		printf("%s, ", aux->matricula);
		printf("%s, ", aux->nome);
		printf("%d/%d/%d, ",aux->dataNasc.dia, aux->dataNasc.mes, aux->dataNasc.ano);
		printf("%.2f\n",aux->media); //conforme percorre vai imprimindo cada elemento partindo do head
	}
}
/*-------------------------------------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------------------------------*/
void printAlunosInv(Aluno *tail){ //funcao que imprime os alunos q estão na lista;
	Aluno *aux;
	for (aux=tail;aux!=NULL;aux=aux->prev){ //percorre a lista
		printf("%s, ", aux->matricula);
		printf("%s, ", aux->nome);
		printf("%d/%d/%d, ",aux->dataNasc.dia, aux->dataNasc.mes, aux->dataNasc.ano);
		printf("%.2f\n",aux->media); //conforme percorre vai imprimindo cada elemento partindo do tail
	}
}
/*---------------------------------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
void reset(Aluno *head){ //função recursiva para resetar/desencadear a lista;
	Aluno *aux;
	if (head==NULL) return;
	aux=head;
	reset(aux->next);
	free(aux);
	printf("*");
}
/*---------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------------------------------------*/
Aluno *getLast(Aluno *head){
	Aluno *aux = head;
	for (aux=head; aux->next!=NULL; aux=aux->next); //percorre a lista para achar o ultimo elemento adicionado
	return aux; //retorna o ultimo elemento da lista;
}
/*-----------------------------------------------------------------------------------------------------------*/



/*------------------------------------------------------------------------*/
Aluno *getmat(char *matprev, Aluno *head){ //retorna o elemento anterior
	Aluno *aux = head;
	for(aux=head; aux!=NULL; aux=aux->next){
		if ((strcmp(aux->matricula, matprev)) == 0){
			return aux;
		}
	}
	return NULL;
}
/*-------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
Aluno *insertAluno(char *matprev, Aluno *head){
	Aluno *previous;
	previous = getmat(matprev, head);
	Aluno *p=malloc(sizeof(Aluno));
	scanf("%s", p->matricula);
	scanf("%s", p->nome);
	scanf("%d/%d/%d", &p->dataNasc.dia, &p->dataNasc.mes, &p->dataNasc.ano);
	scanf("%f",&p->media);
	p->next=NULL;
	p->prev=NULL;
	if (head==NULL) //se a lista estiver vazia ele cria o head aqui;
	{
		head=p;
		return head;
	}
	if (previous==NULL){ //adiciona no inicio da lista;
		p->next=head;
		head->prev=p;
		head = p;
		return head;
	}else
		if (previous->next!=NULL){
			p->next=previous->next;
			previous->next->prev=p;
		} else {
			p->prev=previous;
			previous->next=p;
		}

	return head;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
int menu(){
	int num;
	scanf("%d",&num);
	return num;
}
/*---------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/
int main(){

  int opcao;
	char matprev[10]; //para usar na função de adicionar um elemento;
	char matDel[10]; //para usar na função de deletar um aluno;
	Aluno *head=NULL;
	Aluno *tail=NULL;
	opcao=menu();
  while (opcao!=0)
	{
		switch (opcao)
		{
/*------------------------------------------*/
			case 1: scanf("%s", matprev); //elemento anterior ao que sera incluido;
			head = insertAluno(matprev, head);
			tail = getLast(head);
			break;

/*------------------------------------------*/
			case 2: if (head==NULL){
	      printf("Lista Vazia!\n");
	      break;
	    }
			//implementa função delete;
			scanf("%s", matDel);
			head = delAluno(head, matDel, tail);
			break;

/*------------------------------------------*/
			case 3: if (head==NULL){
	      printf("Lista Vazia!\n");
	      break;
	    }
			printAlunos(head);
			break;

/*------------------------------------------*/
			case 4: if (head==NULL){
	      printf("Lista Vazia!\n");
	      break;
	    }
			tail = getLast(head);
			printAlunosInv(tail);
			break;
/*------------------------------------------*/
		}
		opcao=menu(); //reeleitura do menu;
	}//fim do while
	reset(head);
	 //função responsável por desencadear a lista;
  return 0;
}
