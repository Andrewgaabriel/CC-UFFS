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


Edge *insertEdge(Graph *graph, int v_source, int v_destiny){
    Vertex *auxV;
    int s_flag = 0;
    int d_flag = 0;

    for(auxV = graph->vertexes; auxV != NULL; auxV = auxV->next) {
        /*verify if v_source exist*/
        if(auxV->value == v_source) {
            s_flag = 1;
        }
    }

    for(auxV = graph->vertexes; auxV != NULL; auxV = auxV->next) {
        /*verify if v_destiny exist*/
        if(auxV->value == v_destiny) {
            d_flag = 1;
        }
    }
    
    if(s_flag == 1 && d_flag == 1){
            Edge *new = malloc(sizeof(Edge));
            new->source = v_source;
            new->destiny = v_destiny;
            new->next = graph->edges; // o primeiro vira o segundo;
            return new; // o new vira o primeiro
    } else {
        if(s_flag == 0) {
            printf("non-existent source value!!");
        }
        if(d_flag == 0) {
            printf("non-existent destiny value!!");
        } 
        return NULL;
        
    }
}
    // Buescar a Origem e o Destino na lista de Vértices. 
       //Devem ser os mesmo que estão na lista de vértices, não podem ser criados.


/**
 * @brief function for print a non-oriented GRAPH;
 * 
 * @param graph 
 */
void printNonOrientedGraph(Graph *graph) {

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
    g1->vertexes = insertVertex(g1->vertexes, 2);
    g1->vertexes = insertVertex(g1->vertexes, 3);
    g1->vertexes = insertVertex(g1->vertexes, 4);
    g1->vertexes = insertVertex(g1->vertexes, 5);

    g1->edges = insertEdge(g1,5,1);

    return 0;
}













//nao orientado: 
// -- listar todos os vertices com os respectivos graus;

//orientado: 
// -- listar os graus de entrada e saida para cada um dos vertices;
// -- listar todos os vertices que sao sumidouros e fonte;








