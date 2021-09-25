#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*------------------------------------------*/
typedef struct elem_stack{
  char w_adress[60];
  struct elem_stack *next;
} Elem_Stack;
/*------------------------------------------*/


/*------------------------------------------*/
typedef struct{
  Elem_Stack *top;
} web_stack;
/*------------------------------------------*/

/*------------------------------------------*/
void initStack(web_stack *Stack){
  Stack->top = NULL;
  return;
};
/*------------------------------------------*/


/*------------------------------------------*/
void push(web_stack *w_stack, char *op){
  Elem_Stack *aux;

  aux=malloc(sizeof(Elem_Stack));
  strcpy(aux->w_adress, op);
  //aux->w_adress == op;

  aux->next = w_stack->top;
  w_stack->top = aux;
};
/*------------------------------------------*/


/*------------------------------------------*/
void popStack(web_stack *stack){
  Elem_Stack *aux;
  aux = stack->top;
  stack->top = stack->top->next;

  free(aux);
}
/*------------------------------------------*/


/*------------------------------------------*/
void releaseStack(web_stack *stack){
  Elem_Stack *aux;
  while (stack->top != NULL){
    aux=stack->top;
    stack->top = stack->top->next;
    printf("@\n");
    free(aux);
  }
}
/*------------------------------------------*/




/*------------------------------------------*/
int main(){
  char op[60];
  web_stack *stack = (web_stack *) malloc(sizeof(web_stack));
  initStack(stack);
  scanf("%s", op);
  while (strcmp(op, "E")!=0)
  {
    if (strcmp(op, "B")==0)
    {
      if (stack->top==NULL)
      { //verificar se a lista tem elementos, se não tiver imprimir: "Vazio"
        printf("Vazio\n");
      } else {
        printf("%s\n", stack->top->w_adress);
        popStack(stack); //função back do navegador
      }
    } else {
      push(stack, op);
    }
    scanf("%s", op);
  }
  if (stack->top==NULL)
  {
    printf("!");
  } else {
    releaseStack(stack); //função resetar/limpar/desencadear pilha e imprimir "@"
  }


  return 0;
}
