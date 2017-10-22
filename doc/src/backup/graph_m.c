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
/*
int main(void) {
    Graph* Test1;
    Test1 = create(6);
    insertEdge(Test1, 0, 1, 1);
    insertEdge(Test1, 0, 5, 1);
    insertEdge(Test1, 1, 2, 1);
    insertEdge(Test1, 1, 5, 1);
    insertEdge(Test1, 2, 3, 1);
    insertEdge(Test1, 2, 4, 1);
    insertEdge(Test1, 3, 4, 1);
    insertEdge(Test1, 4, 5, 1);
    insertEdge(Test1, 5, 2, 1);

    print(Test1);

    return 0;
  }
*/



