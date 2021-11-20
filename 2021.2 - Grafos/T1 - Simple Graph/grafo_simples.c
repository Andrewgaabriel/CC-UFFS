#include <stdio.h>
#include <stdlib.h>

//Andrew Gabriel Gomes (andrew.gabrielgomes@gmail.com)

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
 * @brief insert a NEW EDGE;
 * 
 * @param graph 
 * @param v_source 
 * @param v_destiny 
 * @return Edge* 
 */
Edge *insertEdge(Graph *graph, int v_source, int v_destiny){
    Vertex *auxV;
    int s_flag = 0;
    Vertex *s_temp;
    int d_flag = 0;
    Vertex *d_temp;

    for(auxV = graph->vertexes; auxV != NULL; auxV = auxV->next) {
        /*verify if v_source exist*/
        if(auxV->value == v_source) {
            s_flag = 1;
            s_temp = auxV;
        }
    }

    for(auxV = graph->vertexes; auxV != NULL; auxV = auxV->next) {
        /*verify if v_destiny exist*/
        if(auxV->value == v_destiny) {
            d_flag = 1;
            d_temp = auxV;
        }
    }
    
    if(s_flag == 1 && d_flag == 1){
            Edge *new = malloc(sizeof(Edge));
            new->source = s_temp;
            new->destiny = d_temp;
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



/**
 * @brief calculates the degree of the unoriented GRAPH;
 * 
 * @param graph 
 * @param auxV 
 * @return int 
 */
int calculateG(Graph *graph, Vertex *auxV){
    //auxV->value = vertice a ser achado o valor;
    Edge *auxE;
    int degree = 0;
    for(auxE = graph->edges; auxE!=NULL; auxE = auxE->next) {
        if (auxE->destiny->value == auxV->value) {
            degree++;
        }
        if (auxE->source->value == auxV->value){
            degree++;
        }
    }
    return degree;   
}



/**
 * @brief function for print a unoriented GRAPH;
 * 
 * @param graph 
 */
void printNonOrientedGraph(Graph *graph) {

    Vertex *auxV;
    Edge *auxE;

    printf("\n*********** Vertexes: ***********\n\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        int g = calculateG(graph, auxV);
        printf("\t Graph: %d - Degree: %d\n", auxV->value, g);
        
    }


    printf("\n*********** Edges ***********\n\n");

    if(graph->edges == NULL) {
        printf("No edges!");
    } else {
        for(auxE = graph->edges; auxE!=NULL; auxE=auxE->next){
            printf("\t (%d, %d)\n", auxE->source->value, auxE->destiny->value);
        }
    }
}



/**
 * @brief calculates the output degree of the VERTEX;
 * 
 * @param graph 
 * @param auxV 
 * @return int 
 */
int calculateOutputDegree(Graph *graph, Vertex *auxV){
    //auxV->value = vertice a ser achado o valor do grau de saida/source;
    Edge *auxE;
    int outputDegree = 0;
    for(auxE = graph->edges; auxE!=NULL; auxE = auxE->next) {
        if (auxE->source->value == auxV->value){
            outputDegree++;
        }
    }
    return outputDegree;   
}



/**
 * @brief calculates the input degree of the VERTEX;
 * 
 * @param graph 
 * @param auxV 
 * @return int 
 */
int calculateInputDegree(Graph *graph, Vertex *auxV){
    //auxV->value = vertice a ser achado o valor do grau de entrada/destiny;
    Edge *auxE;
    int inputDegree = 0;
    for(auxE = graph->edges; auxE!=NULL; auxE = auxE->next) {
        if (auxE->destiny->value == auxV->value){
            inputDegree++;
        }
    }
    return inputDegree;   
}



/**
 * @brief function for print the founts and holes of the GRAPH;
 * 
 * @param graph 
 */
void printFonteSumidouro(Graph *graph) {
    Vertex *auxV;
    Edge *auxE;

    printf("\n*********** Fontes: ***********\n\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        int OutDegree = calculateOutputDegree(graph, auxV);
        int InDegree = calculateInputDegree(graph, auxV);
        if (InDegree == 0) {
            printf("\t Graph: %d - In degree: %d - Out degree: %d \n", auxV->value, InDegree, OutDegree);
        }
    }
    printf("\n*********** Sumidouros: ***********\n\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        int OutDegree = calculateOutputDegree(graph, auxV);
        int InDegree = calculateInputDegree(graph, auxV);
        if (OutDegree == 0) {
            printf("\t Graph: %d - In degree: %d - Out degree: %d \n", auxV->value, InDegree, OutDegree);
        }
    }

}



/**
 * @brief function for print a oriented GRAPH;
 * 
 * @param graph 
 */
void printOrientedGraph(Graph *graph) {
    Vertex *auxV;
    Edge *auxE;

    printf("\n*********** Vertexes: ***********\n\n");
    for (auxV = graph->vertexes; auxV!=NULL; auxV=auxV->next) {
        int OutDegree = calculateOutputDegree(graph, auxV);
        int InDegree = calculateInputDegree(graph, auxV);
        printf("\t Graph: %d - In degree: %d - Out degree: %d \n", auxV->value, InDegree, OutDegree);
    }


    printf("\n*********** Edges ***********\n\n");

    if(graph->edges == NULL) {
        printf("No edges!");
    } else {
        for(auxE = graph->edges; auxE!=NULL; auxE=auxE->next){
            printf("\t (%d, %d)\n", auxE->source->value, auxE->destiny->value);
        }
    }
    printFonteSumidouro(graph);
}



/**
 * @brief Create a new Graph;
 * 
 * @return Graph* 
 */
Graph *newGraph(){
    Graph *new = malloc(sizeof(Graph));
    printf("\nOriented graph? (0 - no; 1 - yes;)");
    scanf("%d", &new->oriented);
    new->edges = NULL;
    new->vertexes = NULL;
    return new;
}



/**
 * @brief -> Imprime menu e retorna opção escolhida;
 * 
 * @return int 
 */
int menu()
{
    int op = 0;
    printf("\t>>>>> MENU <<<<<\n\n");
    printf(">> ( 1 ) for create a new vertex.\n");
    printf(">> ( 2 ) for create a new edge.\n");
    printf(">> ( 3 ) for print the graph.\n");
    printf(">> ( 4 ) exit :(\n");
    printf(">> OPTION: ");
    printf("\n: ");
    scanf("%d",&op);

    return op;
}


int main(){

    Graph *g1 = newGraph();
    int op = 0;
    int s_value;
    int d_value;
    int value;


// A SIMPLE IMPLEMENTATION <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/*     g1->vertexes = insertVertex(g1->vertexes, 1);
    g1->vertexes = insertVertex(g1->vertexes, 2);
    g1->vertexes = insertVertex(g1->vertexes, 3);
    g1->vertexes = insertVertex(g1->vertexes, 4);
    g1->vertexes = insertVertex(g1->vertexes, 5);

    g1->edges = insertEdge(g1,5,1);
    g1->edges = insertEdge(g1,3,1);
    //g1->edges = insertEdge(g1,4,2);
    g1->edges = insertEdge(g1,2,4);
    g1->edges = insertEdge(g1,1,4);
    //g1->edges = insertEdge(g1,4,1);

    if(g1->oriented == 0) {
        printNonOrientedGraph(g1);
    } else {
        printOrientedGraph(g1);
    } */

    op = menu();
    while (op != 4)
    {
        switch (op)
        {
        case 1:
            printf("\n\nInsert the VERTEX value: ");
            scanf("%d", &value);
            g1->vertexes = insertVertex(g1->vertexes,value);
            printf("VERTEX inserted! \n\n");
            break;
        case 2:
            printf("\n\nInsert the EDGE values:\nSource value: ");
            scanf("%d", &s_value);
            printf("Destiny value:");
            scanf("%d", &d_value);
            g1->edges = insertEdge(g1, s_value, d_value);
            printf("EDGE inserted! \n\n");
            break;
        case 3:
            if(g1->oriented == 0) {
                printNonOrientedGraph(g1);
            } else {
                printOrientedGraph(g1);
            }
            break;
        }
        op = menu();
    }
    
    return 0;
}
