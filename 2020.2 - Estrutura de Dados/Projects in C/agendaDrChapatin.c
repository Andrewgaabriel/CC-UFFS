#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agendaDrchapatin.h" //Biblioteca que contém as funções e structs da agenda;

#define EXIT 10  // valor fixo para a opção que finaliza a aplicação


/*---------------------------------------------------------------------------*/
// Programa principal
int main()
{
  int op=EXIT+1; //11
	Contact *head = NULL;
	Contact *tail = NULL;
	char PrevEmail[40];//  Variáveis auxiliáres
	char DelEmail[40];//	 para implementação
	char UpEmail[40];//    das funções
	char Cname[30];//
	printf("----- Welcome Dr. Chapatin! -----\n");
	op=menu();
  while (op!=EXIT) //exit = 10
  {
    switch(op)
    {
/*------------------------------------------*/
      case 1: //Inserção de contato no fim da lista;
				head = insContact(head);
				tail = getLast(head);
				break;
/*------------------------------------------*/
      case 2: //Inserção de contato após dado email ou no inicio da lista;
			  printf("\n---- Previous Email: \n");
				scanf("%s", PrevEmail);
				head = insContactAfter(PrevEmail, head);
				tail = getLast(head);
				break;
/*------------------------------------------*/
      case 3: //Remoção de um contato da lista;
				if (head==NULL)
				{
					printf("\n- Empty agenda! -\n");
					break;
				}
				printf("\n---- Enter the contact email to delete:\n");
				scanf("%s", DelEmail);
				head = delContact(head, DelEmail, tail);
				if (head==NULL)
				{
					break;
				}
				tail = getLast(head);
				break;
/*------------------------------------------*/
      case 4: //atualização de determinado contato na lista;
				if (head==NULL)
				{
					printf("\n- Empty agenda! -\n");
					break;
				}
				printf("\n---- Enter the contact email to edit:\n");
				scanf("%s", UpEmail);
				head = upContact(head, UpEmail);
				break;
/*------------------------------------------*/
      case 5: //Listagem de determinado contato dado o nome;
				if (head==NULL)
				{
					printf("\n- Empty agenda! -\n");
					break;
				}

				printf("\n----- Enter contact name:\n");
				getchar();
				fgets(Cname, sizeof(Cname), stdin);
				Cname[strcspn(Cname, "\n")] = '\0';

				queryContact(head, Cname);
				break;
/*------------------------------------------*/
      case 6: //Listagem de todos os contatos;
				if (head==NULL)
				{
					printf("\n- Empty agenda! -\n");
					break;
				}
				listContacts(head);
				break;
/*------------------------------------------*/
    }
		op=menu(); //releitura do menu
  }
  freeMem(head); // liberar toda a memória alocada
	printf("\n\n- Memory freed!! -\n");
  return 0;
}
/*---------------------------------------------------------------------------*/
