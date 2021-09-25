#ifndef AGENDADRCHAPATIN_H
#define AGENDADRCHAPATIN_H
/* header da agenda drchapatin */


/*---------------------------------------------------------------------------*/
//Struct que representa a data.
typedef struct {
		int day;
		int month;
		int year;
}Date;
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
// Struct que contém os campos dos registros da agenda
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



/*---------------------------------------------------------------------------*/
// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
	  int op=0;
		printf("\n--- OPTIONS: \n\n");
		printf("(1) Insert Contact;\n(2) Insert positioned contact;\n");
		printf("(3) Delete Contact;\n(4) Update Contact;\n");
		printf("(5) Consult a Contact (by name);\n(6) List all Contacts;\n");
	  printf("(10) Exit\n\n");
	  printf("----- option: ");
	  scanf("%d",&op);
	  return op;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
//Verifica se ja existe um determinado email;
int verifyEmail(char *Email, Contact *head)
{
		Contact *aux = head;
		for (aux=head; aux!=NULL; aux=aux->next){
			if (strcmp(aux->email, Email) == 0)
			{
				return 0; //já existe esse email.
			}
		}
		return 1; //não existe esse email ainda;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
//Recupera o último contato da agenda/lista
Contact *getLast(Contact *head){
		Contact *aux = head;
		for (aux=head; aux->next!=NULL; aux=aux->next);
		return aux;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
// Permite o cadastro de um contato no final da lista;
Contact *insContact(Contact *head)
{
		Contact *last;
		int vEmail; //para verificacao da existencia do email;
		Contact *aux = malloc(sizeof(Contact));
		printf("\n----- INSERTING A NEW CONTACT -----\n\n");

		printf("----- Email:\n");
		scanf("%s", aux->email);

		//verificacao do Email
		if (head != NULL)
		{
			vEmail = verifyEmail(aux->email, head);
			if (vEmail == 0)
			{
				printf("This Email is already registered!\n");
				return head;
			} else {
				printf("Email OK!\n");
			}
		}

		printf("----- Name:\n");
		getchar(); //captura o enter
		fgets(aux->name, sizeof(aux->name), stdin);
		aux->name[strcspn(aux->name, "\n")] = '\0';

		printf("----- Birth date(DD/MM/YYYY):\n");
		scanf("%d/%d/%d", &aux->birth.day, &aux->birth.month, &aux->birth.year);

		printf("----- Phone number:\n");
		scanf("%s", aux->phone);

		aux->next=NULL;
		aux->prev=NULL;

		printf("\n- Successfully registered! - \n\n");

		//alocação
		if (head == NULL)
		{
			head = aux;
			return head;
		} else
		if (head != NULL)
		{
			last = getLast(head); //recupera o ultimo elemento da lista
			last->next = aux;
			aux->prev = last;
			return head;
		}
		return head;
}
/*---------------------------------------------------------------------------*/



/*------------------------------------------------------------------------*/
//Função que recupera o elemento Previous, usado na inserção de um contato
//após dado outro contato;
Contact *getPrev(char *TEmail, Contact *head){ //retorna o elemento anterior
		Contact *aux = head;
		for(aux=head; aux!=NULL; aux=aux->next){
			if ((strcmp(aux->email, TEmail)) == 0)
			{
				return aux;
			}
		}
		return NULL;
}
/*-------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
//Função que adiciona um contato após dado contato, ou no inicio da lista/agenda
Contact *insContactAfter(char *TEmail, Contact *head)
{
		Contact *aux=malloc(sizeof(Contact));
		Contact *previous;
		previous = getPrev(TEmail, head);
		int vEmail;

		printf("\n----- INSERTING A NEW CONTACT -----\n");

		printf("\n----- Email:\n");
		scanf("%s", aux->email);

		//verificacao do Email
		if (head != NULL){
			vEmail = verifyEmail(aux->email, head);
			if (vEmail == 0){
				printf("\nThis Email is already registered!\n");
				return head;
			} else {
				printf("\n...Email OK!\n\n");
			}
		}

		printf("----- Name:\n");
		getchar();
		fgets(aux->name, sizeof(aux->name), stdin);
		aux->name[strcspn(aux->name, "\n")] = '\0';

		printf("----- Birth date(DD/MM/YYYY):\n");
		scanf("%d/%d/%d", &aux->birth.day, &aux->birth.month, &aux->birth.year);

		printf("----- Phone number:\n");
		scanf("%s", aux->phone);

		aux->next=NULL;
		aux->prev=NULL;

		printf("\n- Successfully registered! - \n\n");

		if (head==NULL) //se a lista estiver vazia ele cria o head aqui;
		{
			head=aux;
			return head;
		} else
			if (previous==NULL) //ele n achou o previous
			{                   //adiciona no inicio da lista;
				aux->next=head;
				head->prev=aux;
				head = aux;
				return head;
			} else
				if (previous->next!=NULL) //se tem alguem na frente dele
				{
					aux->next=previous->next;
					previous->next->prev=aux;
					aux->prev=previous;
					previous->next = aux;
				} else {
					aux->prev=previous;
					previous->next=aux;
				}
		  return head;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
//Função que procura determinada posição dado o email;
Contact *getEmail(Contact *head, char *UpEmail)
{
		Contact *aux;
		for (aux=head; aux!=NULL; aux=aux->next){
			if ((strcmp(aux->email, UpEmail)) == 0)
			{
				return aux;
			}
		}
		return NULL;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
// Permite excluir um contato da agenda baseado no email
Contact *delContact(Contact *head, char *emailToDel, Contact *tail)
{
		Contact *aux;
		aux = getEmail(head, emailToDel);
		if (aux == NULL){
			printf("Email not found!\n");
			return head;
		}
		if (aux == head) //se o que sera excluido for o head;
		{
			if (aux->next==NULL){ //caso só tenha o head na lista
				head=NULL;
				free(aux);
				printf("\n- Contact deleted! -\n");
				return head;
			} else {
				head=aux->next;
				aux->next->prev=NULL;
			}
		} else
			if (aux == tail) //se o que sera excluido for o tail;
			{
				aux->prev->next = NULL;
			} else { //se o que sera excluido estiver no meio;
				aux->prev->next=aux->next;
				aux->next->prev=aux->prev;
			}
		free(aux);
		printf("\n- Contact deleted! -\n\n");
		return head;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
// Lista o conteúdo da agenda (todos os campos)
void listContacts (Contact *head)
{
		Contact *aux;
		for (aux=head; aux!=NULL; aux=aux->next)
		{
			printf("\n---------------------------------\n");
			printf("Name: %s\n", aux->name);
			printf("Birth date: %d/%d/%d \n",aux->birth.day, aux->birth.month, aux->birth.year);
			printf("Email: %s\n", aux->email);
			printf("Phone number: %s\n", aux->phone);
			printf("---------------------------------\n\n");
		}
    return;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
// Permite consultar um contato da agenda por nome
void queryContact(Contact *head, char *name)
{
		Contact *aux;
		int A=0;
		printf("\n---- RESULTS: \n\n");
		for(aux=head; aux!=NULL; aux=aux->next)
		{
			if ((strcmp(aux->name, name)) == 0)
			{
				printf("\n---------------------------------\n");
				printf("Nome: %s\n", aux->name);
				printf("Data de Nascimento: %d/%d/%d \n",aux->birth.day, aux->birth.month, aux->birth.year);
				printf("Email: %s\n", aux->email);
				printf("Phone: %s\n", aux->phone);
				printf("\n---------------------------------\n");
				A+=1;
			}
		}
		if(A==0)
		{
			printf("- No contact with this name was found! - \n\n");
		}
  return;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
//Função menu que retorna a opção na função de atualizar dados;
int menu2()
{
	  int op=0;
	  printf("\n----- DATA UPDATE -----\n");
	  printf("\n(1) Update name;\n(2) Update birth date;\n");
		printf("(3) Update phone number;\n(4) Exit;\n\n");
		printf("- Option: ");
	  scanf("%d",&op);
		printf("\n");
	  return op;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
// Permite a atualização dos dados de um contato da agenda
Contact *upContact (Contact *head, char *UpEmail)
{
		Contact *aux;
		int op=0;
		char Tname[30];
		char Tphone[15];
		int Tday;
		int Tmonth;
		int Tyear;
		aux = getEmail(head, UpEmail);
		if (aux==NULL)
		{
			printf("\n- Email not found!!! - \n\n");
			return head;
		}
		op=menu2();
		while (op!=4)
    {
        switch(op)
        {
/*------------------------------------------*/
            case 1 : //atualizar nome
							printf("---- Current name: %s\n\n", aux->name);
							printf("- New name:\n");
							getchar();
							fgets(Tname, sizeof(Tname), stdin);
							Tname[strcspn(Tname, "\n")] = '\0';
							strcpy(aux->name, Tname);
							printf("\n---- Name updated to: %s\n", aux->name);
							break;
/*------------------------------------------*/
            case 2 : //atualizar data de Nascimento
							printf("---- Current birth date: %d/%d/%d \n\n",aux->birth.day, aux->birth.month, aux->birth.year);
							printf("- New birth date:\n ");
							scanf("%d/%d/%d", &Tday, &Tmonth, &Tyear);
							aux->birth.day = Tday;
							aux->birth.month = Tmonth;
							aux->birth.year = Tyear;
							printf("\n---- Birth date updated to: %d/%d/%d\n",aux->birth.day, aux->birth.month, aux->birth.year);
							break;
/*------------------------------------------*/
            case 3 : //atualizar o numero de telefone
							printf("---- Current phone number: %s\n\n",aux->phone);
							printf("- New phone number:\n ");
							scanf("%s", Tphone);
							strcpy(aux->phone, Tphone);
							printf("\n---- Phone number updated to: %s\n", aux->phone);
							break;
				}
				op=menu2();
		}
		return head;
}
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
//função para desalocar/ liberar memória;
void freeMem(Contact *head)
{
		Contact *aux;
		aux=head;
		if (aux==NULL) return;
		freeMem(aux->next);
		free(aux);
		printf("*");
		return;
}
/*---------------------------------------------------------------------------*/


#endif /* AGENDADRCHAPATIN_H */
