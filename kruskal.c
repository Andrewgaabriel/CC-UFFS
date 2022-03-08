#include <stdio.h>
#include <stdlib.h>



#define N 8




struct vertex_list
{
    int peso;
    int origem;
    int destino;
    struct vertex_list *next;
};
typedef struct vertex_list lVertex;



lVertex *getlast(lVertex *first){
    lVertex *aux = first;
    for (aux=first; aux->next!=NULL; aux=aux->next);
    return aux;
}



lVertex *insertVertex(int p, int o, int d, lVertex *first){

    lVertex *aux = malloc(sizeof(lVertex));
    lVertex *last;

    aux->peso = p;
    aux->origem = o;
    aux->destino = d;
    aux->next = NULL;


    /*IMPLEMENTAR INSERTION SORT AQUI PARA FACILITAR INVÉS DE CRIAR UM METODO SÓ PARA ORDENAÇÃO*/
    
    if (first == NULL) {
        first = aux;
    } else {
        last = getlast(first);
        last->next = aux;
    }

    return first;
}





lVertex *init(int mat[N][N], lVertex *first) {
    lVertex result;
    
    

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(mat[i][j] != 0){
                first = insertVertex(mat[i][j], i, j, first);
            }
        }
    }
    return first;
}



void printVertexList(lVertex *first){
    lVertex *aux;
    for (aux=first; aux!= NULL; aux=aux->next){
        printf("-------------------------------------\n");
        printf("Peso: %d\n", aux->peso);
        printf("Origem: %d\n", aux->origem);
        printf("Destino: %d\n", aux->destino);
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


    lVertex *first = NULL;
    first = init(mat, first);
    printVertexList(first);





    /*
        1 - Matriz de adjacência -> Lista Encadeada de Arestas;
        2 - Ordenar arestas por pesos;
        3 - Implementar Estrutura para a Floresta (aquela que cria as subarvores, grava vértice + o pai)
        4 - Implementar metodo subArvore( ) que retorna o pai dado vertice;
        5 - Merge de duas subarvores. ???
        6 - resultado deve ser impresso como uma lista de arestas;
    */




}