#include <stdio.h>
#include <stdlib.h>




/**
 * @brief VERTEX linked list; 
 * 
 */
struct _vertex {
    int value;
    struct _vertex *next;
};
typedef struct _vertex Vertex;



/**
 * @brief EDGE linked list;
 * 
 */
struct _edge {
    Vertex *source;
    Vertex *destiny;
    struct _edge *next;
};
typedef struct _edge Edge;




/**
 * @brief Struct for GRAPH
 * 
 */
typedef struct {
    int oriented; //  0 to non-oriented; 1 to oriented;
    Vertex *vertexes; //lista de vértices
    Edge *edges; //lista de arestas
} Graph;



/**
 * @brief function for insert a NEW VERTEX;
 * 
 * @param head -> first of the linked list;
 * @param value -> value to be added;
 * @return Vertex* 
 */
Vertex *insertVertex(Vertex *head, int value) {
    Vertex *new = malloc(sizeof(Vertex));
    new->value = value;
    new->next = head;
    return new;
}

/**
 * @brief function for print the graph;
 * 
 * @param graph 
 */
void printGraph(Graph *graph) {

    Vertex *auxV;
    Edge *auxE;

    printf("\n*********** Vertexes: ***********");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        printf("\t %d,", auxV->value);
    }


    printf("\n*********** Edges ***********");

    if(graph->edges == NULL) {
        printf("No edges!");
    } else {
        for(auxE = graph->edges; auxE!=NULL; auxE=auxE->next){
            printf("\t (%d, %d),", auxE->source->value, auxE->destiny->value);
        }
    }

}

//nao orientado: 
// -- listar todos os vertices com os respectivos graus;

//orientado: 
// -- listar os graus de entrada e saida para cada um dos vertices;
// -- listar todos os vertices que sao sumidouros e fonte;

Graph *newGraph(){
    Graph *new = malloc(sizeof(Graph));
    printf("\nOriented graph? (0 - non-oriented; 1 - oriented;)");
    scanf("%d", new->oriented);
    new->edges = NULL;
    new->vertexes = NULL;
    return new;
}

int main(){

    Graph *g1 = newGraph();

    g1->vertexes = insertVertex(g1->vertexes, 1);
    g1->vertexes = insertVertex(g1->vertexes, 1);
    g1->vertexes = insertVertex(g1->vertexes, 1);
    g1->vertexes = insertVertex(g1->vertexes, 1);
    g1->vertexes = insertVertex(g1->vertexes, 1);

    return 0;
}