#include <stdio.h>
#include <stdlib.h>

typedef struct Graph { 
    int size; 
    double *edges;
 } Graph;
 
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

int getSize(Graph *g) {
    return g->size;
}

int getDegree(Graph *g, int n) {
    int sumDegree = 0;

    // count the outdegrees - n is the source node, so check every other node if weight is != 0 
    for (int target = 0; target < g->size; target++)  {
        if (getWeight(g, n, target) != 0.0) {
            sumDegree++;
        }
    }

    // count the in degrees - n is the target node, ... {
    for (int source = 0; source < g->size; source++)  {
        if (getWeight(g, source, n) != 0.0) {
            sumDegree++;
        }
    }
    return sumDegree;
}
