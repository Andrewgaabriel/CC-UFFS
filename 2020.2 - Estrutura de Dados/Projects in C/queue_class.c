#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef char Let;

typedef struct elemFila{
  Let Elem;
  struct elemFila *next;
} ElemFila;


typedef struct {
  ElemFila *first;
  ElemFila *last;
} Fila;


void init(Fila *fila) {
  fila->first = NULL;
  fila->last = NULL;
}


void insert(Fila *fila, char c){
  ElemFila *aux;
  aux = malloc(sizeof(ElemFila));
  aux->Elem = c;
  aux->next = NULL;

  if (fila->first==NULL)
  {
    fila->first = aux;
    fila->last = aux;
  } else {
    fila->last->next=aux;
    fila->last=aux;
  }
}


void empty(Fila *fila) {
  ElemFila *aux;
  while (fila->first != NULL) {
    aux = fila->first;
    printf("%s->",aux->Elem);
    fila->first = fila->first->next;
    free(aux);
  }
  fila->last = NULL;
}


int main(){

  int i;
  char c[20];
  Fila fila;
  init(&fila);
  scanf("%s",c);

  for (i=0; i<strlen(c);i++){
    insert(&fila, c[i]);
  }
  empty(&fila);

  return 0;
}
