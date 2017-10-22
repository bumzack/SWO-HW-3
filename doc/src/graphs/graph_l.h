#ifndef GRAPH_L
#define GRAPH_L


#include <stdio.h>
#include <stdlib.h>


struct Node;
typedef struct Node {
    int nodeNumber;
    double weight;
    struct Node *next;
} Node;

struct Graph;
typedef struct Graph { 
    int size; 
    struct Node *index;
 } Graph;
 

Graph* create(int n);
void initIndex(Graph *g);
void destroy(Graph *g);
void insertEdge(Graph *g, int source, int target, double weight);
double getWeight(Graph *g, int source, int target);
void removeEdge(Graph *g, int source, int target);
void print(Graph *g);

Graph* create(int n){
    Graph *g;

    g =  (Graph*)malloc(sizeof(Graph));
    g->size = n;
    g->index = (Node*)malloc(sizeof(Node) * n);
    initIndex(g);
    return g;
}

void initIndex(Graph *g){
    for(int i = 0; i < size; i++){
        g->index[i]->nodeNumber = i;
        g->index[i]->weight = 0;
        g->index[i]->next = NULL;
    }
}

void destroy(Graph *g){
    free(g->Index);
    g->index = NULL;
    free(g);
    g = NULL;
}
Node* findSource(Graph *g, int source){
    for(int i = 0; i < g->size; i++){
        if(g->index[i]->nodeNumber == source ){
            return g->index[i]
        }
    }    
    if(g->index[i]->nodeNumber != source){
        return NULL;
    }
}

Node* createNode(Graph *g, int value, double weight){
    Node* n;
    n->nodeNumber = value;
    n->weight = weight;
    n->next = NULL;
}

/// TODO COMPLETE FINDNOTE + INSERTNODE
Node* findNode(Graph *g, int source, int request){
    Node* help = g->index[source];

    while(help->next != NULL && help->nodeNumber != target){
        help = g->index[source]->next;
    }
    if(help->nodeNumber == target){
        return help;
    } else {
        return NULL;
    }
}

void insertNode(Graph *g, Node *n){

}

void insertEdge(Graph *g, int source, int target, double weight){
    //find sourceNode
    Node* s;
    Node* n = NULL;
    s = findSource(g, source);
    if (findNode(g,source,target) == NULL){
        n = createNode(g, target, weight);
        insertNode(g, n);
    }
    
    //insert target
    Node* help = NULL;
    while(s->next != NULL && s->next->nodeNumber < target){
        help = s->next;
    }
    
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



