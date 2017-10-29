#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

// struct Node;
typedef struct Node {
    int nodeNumber;
    double weight;
    struct Node *next;
} Node;

// struct nodeInfo;
typedef struct nodeInfo{
    int source;
    int target;
    double weight; 
} nodeInfo;

struct Graph { 
    int size; 
    struct Node *index;
    struct nodeInfo *currentNode; // added for algs
} ;

Graph* create(int n){
    Graph *g;

    g =  (Graph*)malloc(sizeof(Graph));
    g->size = n;
    g->index = (Node*)malloc(sizeof(Node) * n);
    g->currentNode = NULL;
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
    printf("Destroying\n");
    /* Delete all nodes 
    for(int i = 0; i < g->size; i++){
        Node* head = &(g->index[i]);
        Node* temp = head->next;
        while(head->next != NULL){
            printf("Del. %d temp-Node: %d\n", i, temp->nodeNumber);
            /// TO DO____FUNKTIONIERT NICHT
            
            temp = head->next;
            head->next = temp->next;
            temp->next = NULL;
            free(temp);
            temp = head->next;
        }
    }
    printf("Nodes deleted.\n");
    */

    /* Delete graph */
    
    free((*g)->index);      printf("free((*g)->index)");
    (*g)->index = NULL;     printf("(*g)->index = NULL");
    free(g);               printf("free g");
    (*g) = NULL;            printf("(*g) = NULL");
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

int valueCheck(Graph *g, int source, int target){
    int result = 1;
    if(source < 0) { printf("Error:\tSource node not part of graph.\n"); result = 0; }
    if(source > g->size-1) { printf("Error:\tSource node not part of graph.\n"); result = 0; }
    if(target < 0) { printf("Error:\tSource node not part of graph.\n"); result = 0; }
    if(target > g->size-1) { printf("Error:\tTarget node not part of graph.\n"); result = 0; }

    return result;
}

Node* findNode(Graph *g, int source, int target){
    printf("finding Node\n");
    if(valueCheck(g, source, target)){
        Node* help = g->index[source].next;
        while(help != NULL && help->nodeNumber <= target){
            help = help->next;
        }
        if(help->nodeNumber == target){
            return help;
        } else {
            return NULL;
        }
    } else {
        printf("Error while finding node.\n");
        return NULL;
    }
}


void insertEdge(Graph *g, int source, int target, double weight){
    printf("'insertEdge'\n");
   // printf("address of g = %p\n", (void *)g);
    if (valueCheck(g, source, target)){
        Node* n = createNode(target, weight);
        Node* head = &(g->index[source]);
        Node* temp = head;
        Node* temp2 = head;
        
        if( temp->next == NULL){ // List is empty
            printf("--list is empty\n");
            temp->next = n;
        } else {
            temp = temp->next;
            while(temp != NULL && temp->nodeNumber < target){
                printf("---nodeNumber %d\n", temp->nodeNumber);
                temp2 = temp;
                temp = temp->next;
            }
            if(temp == NULL){ //insert at the end;
                printf("--insert at end\n");
                temp2->next = n;
            } else {
                if(temp2 == head){ //insert at the beginning of the list
                    printf("--insert at begin\n");
                    n->next = head->next;
                    head->next = n;
                } else if (temp->nodeNumber < target){ //insert in the middle
                    printf("--insert in middle\n");
                    temp2->next = n;
                    n->next = temp;
                } else if (temp->nodeNumber == target){ //there is already an edge
                    printf("--overwriting\n");
                    temp->weight = weight;
                } else {
                    printf("--well, this was unexpected."); //should never be shown
                }
            }
        }
    } else {
        printf("Error while inserting node.\n");
    }
}

double getWeight(Graph *g, int source, int target){
    if(valueCheck(g, source, target)){
        Node* n = findNode(g,source,target);
        if(n != NULL){
            return n->weight;
        } else {
            printf("There is no edge from %d to %d\n", source, target);
            return 0;
        }
    } else {
        return 0;
    }
}


void removeEdge(Graph *g, int source, int target){
    if (valueCheck(g, source, target)){
        printf("remove check passed\n");
        Node* head = &(g->index[source]);
        Node* temp = head;
        Node* temp2 = head;
        
        if( temp->next == NULL){ // List is empty
            printf("Edge from %d to %d could not been found\n", source, target);
        } else {
            printf("bfwhile nodeNumber %d\n", temp->nodeNumber);
            while(temp != NULL && temp->nodeNumber < target){
                temp2 = temp;
                temp = temp->next;
                printf("nodeNumber %d\n", temp->nodeNumber);
            }
            if(temp == NULL){ //remove at the end;
                printf("Edge from %d to %d could not been found\n", source, target);
            } else {
                if(temp->nodeNumber < target && temp2 == head){ //remove at the beginning of the list
                    printf("remove at begin\n");
                    head->next = temp->next;
                    temp->next = NULL;
                    free(temp);
                }  
                if(temp->nodeNumber < target){ //remove in the middle
                    printf("remove in middle\n");
                    temp2->next = temp->next;
                    temp->next = NULL;
                    free(temp);
                }
                if (temp->nodeNumber == target){ //remove the node
                    printf("overwriting\n");
                    temp2->next = temp->next;
                    temp->next = NULL;
                    free(temp);
                }
            }
        }
    } else {
        printf("Error while removing node.\n");
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


void initNextNode(Graph *g){
    printf("'Initalizing getNextNode'\n");
    int graphSize = g->size;
    for(int i = 0; i < graphSize; i++){
        Node* help = g->index[i].next;
        if(help != NULL){  
            g->currentNode->source = i;
            g->currentNode->target = help->nodeNumber;
            g->currentNode->weight = help->weight;
            i = graphSize; // abort loops
        }
    }
}

void getNextNode(Graph *g){
    printf("'Getting next node'\n");
    int graphSize = g->size;

    int i = g->currentNode->source;
    Node* help = g->index[i].next;
    while(help != NULL && help->nodeNumber < g->currentNode->target){ 
        if(help->nodeNumber ==  g->currentNode->target){
            if(help->next != NULL){
                help = help->next;
                g->currentNode->source = i;
                g->currentNode->target = help->nodeNumber;
                g->currentNode->weight = help->weight; 
            } else {
                for(int j = i; j < graphSize; j++){
                    Node* help = g->index[j].next;
                    if(help != NULL){  
                        g->currentNode->source = j;
                        g->currentNode->target = help->nodeNumber;
                        g->currentNode->weight = help->weight;
                        i = graphSize; // abort loops
                    }
                }
            }
        }
    }
    if(help == NULL){
        g->currentNode = NULL;
    }
}

int edgeCounter(Graph* g, int targetNode){
    Node* temp = &(g->index[targetNode]);
    int counter = 0;
    while(temp->next != NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}

int getSize(Graph *g) {
    return g->size;
}

int getDegree(Graph *g, int n) {
    // maybe rename edgeCounter to getDegree and delete this 3 lines
    return edgeCounter(g, n);
}
