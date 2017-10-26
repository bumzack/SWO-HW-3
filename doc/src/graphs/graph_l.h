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
void destroy(Graph **g);
void insertEdge(Graph *g, int source, int target, double weight);
double getWeight(Graph *g, int source, int target);
void removeEdge(Graph *g, int source, int target);
void print(Graph *g);

void initNextNode(Graph *g);
void getNextNode(Graph *g);


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
  /*  free(*(g->index));
    *(g->index) = NULL;
    free(g);
    *g = NULL;*/
}

Node* findSource(Graph *g, int source){
    return g->index[source].next;
    
    /*for(int i = 0; i < g->size; i++){
        if(g->index[i].nodeNumber == source ){
            return g->index[i].next; /////////////////// why?
        }
    }    
    if(g->index[i].nodeNumber != source){
        return NULL;
    }*/
}

Node* createNode(int value, double weight){
    Node* n = NULL;
    n->nodeNumber = value;
    n->weight = weight;
    n->next = NULL;
    return n;
}


Node* findNode(Graph *g, int source, int target){
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
    Node* n = NULL;
    n = createNode(target, weight);
    
    //insert target
    Node* help = g->index[source].next;
    Node* pHelp = NULL;
    while(help != NULL && help->nodeNumber <= target){
        pHelp = help;
        help = help->next;
    }
    if(help == NULL){
        help->next = n; 
    } else if(help->nodeNumber < target){
        pHelp->next = n;
        n->next = help->next;
    } else if(help->nodeNumber == target){
        help->weight = weight;        
    }
}

double getWeight(Graph *g, int source, int target){
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
        printf("Graph is Empty. Please create a new one.");
        exit(1);
    }
    int graphSize = g->size;
    printf("Adjacency List:\n\n");

    /*print values*/
    for(int i = 0; i < graphSize; i++){
        printf("%d |", i);

        Node* help = g->index[i].next;
        while(help != NULL){
            printf("\t%d, %.2f", help->nodeNumber, help->weight);
        }
        printf("\n");
    }
}

#endif



