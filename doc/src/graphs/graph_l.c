#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

struct Node;
typedef struct Node {
    int nodeNumber;
    double weight;
    struct Node *next;
} Node;

struct Graph { 
    int size; 
    struct Node *index;
};

Graph* create(int n){
    Graph *g;

    g =  (Graph*)malloc(sizeof(Graph));
    g->size = n;
    g->index = (Node*)malloc(sizeof(Node) * n);
    initIndex(g);
    return g;
}

void initIndex(Graph *g){
    for(int i = 0; i < g->size; i++){
        g->index[i].nodeNumber = i;
        g->index[i].weight = 0;
        g->index[i].next = NULL;
    }
}

void destroy(Graph **g){
    free((*g)->index);
    (*g)->index = NULL;
    free(g);
    *g = NULL;
}

Node* findSource(Graph *g, int source){
    if(source > 0 || source < g->size){
        return g->index[source].next;
    } else {
        printf("Error:\tSource node not part of graph.\n");
        return NULL;
    }
}

Node* createNode(int value, double weight){
    Node* n = NULL;
    n = (Node *) malloc(sizeof(Node));
    if (n == NULL) {
        printf("out of memory -> aborting\n");
        exit (-1);
    }
    n->nodeNumber = value;
    n->weight = weight;
    n->next = NULL;
    return n;
}

void valueCheck(Graph *g, int source, int target){
    if(source < 0) { printf("Error:\tSource node not part of graph.\n"); exit(1); }
    if(source > g->size-1) { printf("Error:\tSource node not part of graph.\n"); exit(2); }
    if(target < 0) { printf("Error:\tSource node not part of graph.\n"); exit(3); }
    if(target > g->size-1) { printf("Error:\tTarget node not part of graph.\n"); exit(4);}
}

Node* findNode(Graph *g, int source, int target){
    printf("finding Node\n");
    valueCheck(g, source, target);

    Node* help = g->index[source].next;

    while(help != NULL && help->nodeNumber != target){
        help = help->next;
    }
    if(help->nodeNumber == target){
        return help;
    } else {
        return NULL;
    }
}



void insertEdge(Graph *g, int source, int target, double weight){
    printf("'insertEdge  HALLO'\n");
   // printf("address of g = %p\n", (void *)g);
    valueCheck(g, source, target);
    //if (source > g->size-1) {printf("whats wrong with you\?");exit(1);}
    
    Node* n = createNode(target, weight);
    Node* help = g->index[source].next;
    Node* pHelp = &(g->index[source]); // wie kann ich hier auf g->index[source] zeigen und nicht auf das nächste element?
    
    printf("address of g = %p\n", (void *)g);
    printf("address of g->index = %p\n", (void *)(g->index));

    for (int i = 0; i <= g->size; i++) {
        printf("address of g->index[%d] = %p\n", i, (void *)(&(g->index[i])));    
    }
    printf("address of help = %p\n", (void *)help);
    printf("address of pHelp = %p    ---  should be equal to %p\n", (void *)pHelp, (void *)(&(g->index[source])));


    if(help == NULL) {
        g->index[source].next = n; 
    } else {
        while(help != NULL && help->nodeNumber < target) {
            pHelp = help;
            help = help->next;
        }
        if(help == NULL){
            pHelp->next = n; 
        } else if(help->nodeNumber == target){  //overwrite existing weight
            help->weight = weight;        
        } else if(help->nodeNumber < target){
            pHelp->next = n;
            n->next = help->next;
        }
    }
}

double getWeight(Graph *g, int source, int target){
    valueCheck(g, source, target);
    Node* n;
    n = findNode(g,source,target);
    if(n != NULL){
        return n->weight;
    } else {
        printf("There is no edge from %d to %d\n", source, target);
        return 0;
    }
}


void removeEdge(Graph *g, int source, int target){
    valueCheck(g, source, target);
    Node* pHelp = findSource(g, source); 
    Node* help = pHelp->next;   
    while(help != NULL && help->nodeNumber != target){
        pHelp = help;
        help = help->next;
    }
    if(help == NULL){
        printf("There is no edge from %d to %d\n", source, target);
    } else {
        pHelp->next = help->next;
        help->next = NULL;
        free(help);
        help = NULL;
        printf("Removed edge from %d to %d\n", source, target);
    }
}


void print(Graph *g){
    if (g == NULL){
        printf("Graph is Empty. Please create a new one.\n");
        exit(1);
    }
    int graphSize = g->size;
    printf("Adjacency List:\n");

    /*print values*/
    for(int i = 0; i < graphSize; i++){
        printf("%d | ", i);

        Node* help = g->index[i].next;
        while(help != NULL){
            printf("%d/%.1f\t", help->nodeNumber, help->weight);
            help = help->next;
        }
        printf("\n");
    }
}
