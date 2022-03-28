#include <stdio.h>
#include <stdlib.h>

// andrew.gabrielgomes@gmail.com
// Algoritmo de Kruskal

#define N 8 // tamanho do grafo



/**
 * @brief Estrutura de dados que armazena uma aresta (edge).
 * 
 */
struct edge
{
    int peso;
    int origem;
    int destino;
    struct edge *next;
};
typedef struct edge Edge;



/**
 * @brief Estrutura de dados vetor de controle
 * 
 */
struct vetor_de_controle_de_dados
{
    int vet[N];
    Edge *arestas; //arestas do caminho criado
};
typedef struct vetor_de_controle_de_dados vDados;



/**
 * @brief Função que inicia o vetor de controle
 * 
 * @return vDados* 
 */
vDados *initV(){
    vDados *dados = malloc(sizeof(vDados));
    for (int i = 0; i < N; i++)
    {
        dados->vet[i] = -1;
    }
    dados->arestas = NULL;
    return dados;
}



/**
 * @brief Função que retorna o último elemento da lista de arestas
 * 
 * @param first 
 * @return Edge* 
 */
Edge *getlast(Edge *first){
    Edge *aux = first;
    for (aux=first; aux->next!=NULL; aux=aux->next);
    return aux;
}



/**
 * @brief Função que imprime a lista de dados
 * 
 * @param dados 
 */
void printVetorControle(vDados *controle) {

	printf("Indice -> |");

	for (int i = 0; i < N; i++) {
		printf(" %d \t|", i);
	}
	printf("\n");


	printf("Raiz   -> |  ");

	for (int c = 0; c < N; c++) {
		printf(" %d \t|", controle->vet[c]);
	}
	printf("\n\n");
}



/**
 * @brief Função que imprime o caminho da solução
 * 
 * @param first 
 */
void printCaminho(vDados *controle) {

	Edge *aux;
	printf("Caminho ate agora: ");


    for (aux=controle->arestas; aux->next!=NULL; aux=aux->next){
        printf("(%d, %d), ", aux->origem, aux->destino);
    }
    printf("\n\n");
}



/**
 * @brief Função que insere uma aresta na lista de arestas
 * 
 * @param p 
 * @param o 
 * @param d 
 * @param first 
 * @return Edge* 
 */
Edge *insertEdge(int p, int o, int d, Edge *first){

    Edge *new = malloc(sizeof(Edge));
    Edge *aux, *ant = NULL;
    aux = first;
    new->peso = p;
    new->origem = o;
    new->destino = d;
    new->next = NULL;

	while ( aux != NULL && aux->peso <= p ) {
		ant = aux;
		aux = aux->next;
	}

	if (ant == NULL) {
		new->next = first;
		first = new;

	} else {
		new->next = ant->next;
		ant->next = new;
	}
    return first;
}



/**
 * @brief Função que monta a lista de arestas a partir de uma matriz de adjacência
 * 
 * @param mat 
 * @param first 
 * @return Edge* 
 */
Edge *init(int mat[N][N], Edge *first) {    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(mat[i][j] != 0){
                first = insertEdge(mat[i][j], i, j, first);
            }
        }
    }
    return first;
}



/**
 * @brief Função que imprime a lista de arestas;
 * 
 * @param first 
 */
void printEdgeList(Edge *first){
    Edge *aux;
    for (aux=first; aux!= NULL; aux=aux->next){
        printf("-------------------------------------\n");
        printf("Peso: %d\n", aux->peso);
        printf("Origem: %d\n", aux->origem);
        printf("Destino: %d\n", aux->destino);
    }
}



/**
 * @brief Insere uma aresta no vetor de controle;
 * 
 * @param controle 
 * @param add 
 * @return vDados* 
 */
vDados *insertEdgeControle(vDados *controle, Edge *add){
    Edge *new = malloc(sizeof(Edge));
    Edge *aux = NULL;

    new->destino = add->destino;
    new->origem = add->origem;
    new->peso = add->peso;
    new->next = NULL;
    
    if(controle->arestas == NULL){ // é o primeiro
        controle->arestas = new;
        controle->arestas->next = NULL;
    } else {
        aux = getlast(controle->arestas);
        aux->next = new; // ultimo
        new->next = NULL;
    }

    return controle;
}



/**
 * @brief Função que implementa o algoritmo de Kruskal
 * 
 * @param first 
 * @param controle 
 */
void kruskal(Edge *first, vDados *controle){

    int auxO, auxD;
    Edge *aux = first;

    while (aux != NULL)
    {
        printf("\n----------> Estado Atual <----------\n");
        auxO = aux->origem;
        auxD = aux->destino;

        if (controle->vet[auxO] >= 0)
        {
            auxO = controle->vet[auxO];
        }
        if (controle->vet[auxD] >= 0)
        {
            auxD = controle->vet[auxD];
        }

        printf("Visitando a aresta: (%d)- %d -(%d)\n\n", aux->origem, aux->peso, aux->destino);

        if (auxO != auxD)
        {
            if(controle->vet[auxO] < controle->vet[auxD]) {
                controle->vet[auxO] += controle->vet[auxD];
                controle->vet[auxD] = auxO; 
            } else {
                controle->vet[auxD] += controle->vet[auxO]; //o destino vira raiz/pai
                controle->vet[auxO] = auxD;
            }
            controle = insertEdgeControle(controle, aux);
        }
        
        printVetorControle(controle);
        printCaminho(controle);
        aux = aux->next;
    }
    
}

int main() {

    int mat[N][N] = {               /* 0 1 2 3 4 5 6 7 */
                            /*0*/     {0,1,0,3,0,0,0,0}
                            /*1*/    ,{0,0,0,0,0,7,7,0}
                            /*2*/    ,{0,0,0,0,3,7,0,0}
                            /*3*/    ,{0,0,0,0,0,0,0,0}
                            /*4*/    ,{0,0,0,0,0,0,0,1}
                            /*5*/    ,{0,0,0,0,0,0,3,8}
                            /*6*/    ,{0,0,0,0,0,0,0,0}
                            /*7*/    ,{0,0,0,0,0,0,0,0}             
    };


    Edge *edges = NULL;
    edges = init(mat, edges);
    vDados *controle = initV();

    printEdgeList(edges);
    kruskal(edges, controle);

}