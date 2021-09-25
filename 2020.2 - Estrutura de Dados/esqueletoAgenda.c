
/*
 Este é um esqueleto que deve ser utilizado como base para implementação da Agenda:
  - As funções não têm os parâmetros definidos e os parâmetros, caso necessários, devem ser incluídos.
  - Caso seja necessário novas funções podem ser incluídas
  - Devem ser respeitados os nomes dados para o métodos e estruturas, porém novas estruturas e funções podem ser criados, caso julgue necessário
  - Faça os includes necessários
  - A organização das funções fica a critério do programador
  - Códigos não indentados sofrerão duras penalidades
  - Não serão toleradas variáveis globais
  - Caso seja detectado plágio, os grupos envolvidos receberão nota 0.
*/

#include <stdio.h> 


#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
typedef struct {
	int day;
	int month,
	int year
} Date;


// Estrutura que contém os campos dos registros da agenda
struct MREC {
       char name[30];
       Date birth; 
       char email[40];
       char phone[15];
	 struct MREC *next;
	 struct MREC *prev;
};

// Tipo criado para instanciar variáveis do tipo agenda
typedef struct MREC Contact;

// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
    int op=EXIT+1;
    while (op!=EXIT)
    {
        printf("%d Finaliza",EXIT);
        printf("\n: ");
        scanf("%d",&op);
    }
    return op;
}

// Permite o cadastro de um contato
void insContact()
{
     return;
}
// Permite o cadastro de um contato
// deve ser passado pelo menos o email
void insContactAfter(char *email)
{
     return;
}
// Permite excluir um contato da agenda baseado no email
void delContact (char *email)
{
     return;
}

// Lista o conteúdo da agenda (todos os campos)
void listContacts ()
{
     return;
}

// Permite consultar um contato da agenda por nome
void queryContact (char *name)
{
     return;
}

// Permite a atualização dos dados de um contato da agenda
void upContact ()
{
     return;
}
// Programa principal
int main()
{
    int op=EXIT+1;
    Contact MContact;

    while (op!=EXIT)
    {
          op=menu();
          switch(op)
          {
              case 1 : insContact();
              case 2 : insContactAfter();
              case 3 : delContact();
              case 4 : upContact();
              case 5 : queryContact();
              case 6 : listContacts();
          }
    }
    freeMem(); // liberar toda a memória alocada
    return 0;
}



