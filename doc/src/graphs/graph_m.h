#ifndef GRAPH_M
#define GRAPH_M


#include <stdio.h>
#include <stdlib.h>

struct Graph;
typedef struct Graph { 
    int size; 
    double *edges;
 } Graph;
 

Graph* create(int n);
void destroy(Graph *g);
void insertEdge(Graph *g, int source, int target, double weight);
double getWeight(Graph *g, int source, int target);
void removeEdge(Graph *g, int source, int target);
void print(Graph *g);


Graph* create(int n){
    Graph *g;

    g =  (Graph*)malloc(sizeof(Graph));
    g->size = n;
    g->edges = (double*)malloc(sizeof(double) * n * n);
    return g;
}

void destroy(Graph *g){
    free(g->edges);
    g->edges = NULL;
    free(g);
    g = NULL;
}

void insertEdge(Graph *g, int source, int target, double weight){
    g->edges[source * g->size + target] = weight;
}

double getWeight(Graph *g, int source, int target){
    return g->edges[source * g->size + target];
}

void removeEdge(Graph *g, int source, int target){
    g->edges[source * g->size + target] = 0;
}


void print(Graph *g){
    if (g == NULL){
        printf("Graph is Empty. Please create a new one.");
        exit(1);
    }
    int matrixSize = g->size;
    printf("Adjacency Matrix:\n\n");

    /*print header*/
    for(int i = 0; i < matrixSize; i++){ 
        printf("\t%d", i);
    }
    printf("\n");

    /*print values*/
    for(int i = 0; i < matrixSize; i++){
        printf("%d", i);
        for(int j = 0; j < matrixSize; j++){
            printf("\t%.2f", g->edges[i * g->size + j] );
        }
        printf("\n");
    }
}



#endif



