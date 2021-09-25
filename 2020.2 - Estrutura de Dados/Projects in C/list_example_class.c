#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO 50

typedef struct{
	int dia;
	int mes;
	int ano;
} Data;

struct _funcionario{
	int id;
	Data dataNasc;
	char nome[MAX_TAMANHO];
	float salario;
	struct _funcionario *proximo; //elemento da lista
};
typedef struct _funcionario Funcionario;

//Adicionamos um elemento, e retornamos o primeiro da lista.
Funcionario *adicionaElemento( Funcionario *primeiro){
	Funcionario *novoElemento = malloc(sizeof(Funcionario));
	Funcionario *auxiliar;

	printf("\n -> Insira um funcionário: (id, nome,data(dd/mm/aaaa), salario)\n");
	scanf("%d\n", &novoElemento->id);
	fgets(novoElemento->nome, sizeof(novoElemento->nome), stdin); //ler um nome composto
	scanf("%d/%d/%d", &novoElemento->dataNasc.dia, &novoElemento->dataNasc.mes, &novoElemento->dataNasc.ano);
	scanf("%f", &novoElemento->salario);

	//fim da leitura dos dados
	if (primeiro == NULL){
		return novoElemento; //pois ele vai ser o primeiro elemento da lista.
	}
	//lógica para adionar mais elementos.
	auxiliar = primeiro;
	while(auxiliar->proximo != NULL){
		auxiliar = auxiliar->proximo;
	}
	//chegou aqui, o auxiliar tem o último elemento;
	auxiliar->proximo = novoElemento; //encadeando o novo elemento na última posicao.



	return primeiro; //pois se ele já esta lá, nunca vai mudar na hora de adicionar.
}


void imprimeLista(Funcionario *primeiro){
	Funcionario *auxiliar;

	printf("\n----- Imprimindo a Lista -------\n");

	auxiliar = primeiro;
	while(auxiliar != NULL){
		printf("ID: %d\n", auxiliar->id);
		printf("\t->Nome: %s", auxiliar->nome);
		printf("\t->DtNasc: %d/%d/%d\n", auxiliar->dataNasc.dia, auxiliar->dataNasc.mes,	auxiliar->dataNasc.ano);
		printf("\t->Salario: R$ %.2f\n", auxiliar->salario);

		auxiliar = auxiliar->proximo;
	}
	printf("------------\n");
}


//FUnção deleta o idDeleta e retorna o primeiro funcionario da lista
Funcionario *deletaFuncionario(Funcionario *primeiro, int idDeleta){
	Funcionario *auxiliar, *anterior = NULL;
	int deletou =0; //flag de deletar


	for(auxiliar = primeiro; auxiliar != NULL; auxiliar=auxiliar->proximo){
		if (auxiliar->id == idDeleta){
			if (primeiro == auxiliar){
				primeiro = auxiliar->proximo;
			}else{
				anterior->proximo = auxiliar->proximo;
				//anterior->proximo = anterior->proximo->proximo;
			}
			free(auxiliar);
			deletou = 1; //sinaliza que deletamos
		}
		anterior = auxiliar;
	}

	if (!deletou){
		printf("\n Não achamos o meliante!\n");
	}

	return primeiro;
}


int main() {
	Funcionario *primeiro = NULL; //cabeça da lista


	primeiro = adicionaElemento(primeiro);
	imprimeLista(primeiro);

	primeiro = adicionaElemento(primeiro);
	imprimeLista(primeiro);

	primeiro = adicionaElemento(primeiro);
	primeiro = adicionaElemento(primeiro);
	imprimeLista(primeiro);


	primeiro = deletaFuncionario(primeiro, 1);
	imprimeLista(primeiro);

	primeiro = deletaFuncionario(primeiro,3);
	imprimeLista(primeiro);

	return 0;
}




Aluno  *delAluno(Aluno *first, int key)
{
  aluno *aux=first, *prev=first;
  while (aux->id!=key && aux!=NULL)
  {
    prev=aux;
    aux=aux->next;
  }
  if (aux==NULL)
  {
    return f;
  }
  prev->next=aux->next;
  if (aux==f)
     f=aux->next;
  free(aux);
  return f;

}
