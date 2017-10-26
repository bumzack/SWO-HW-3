#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "graph_algs.h"

struct Node;
typedef struct Node {
    int nodeNumber;
    double weight;
    struct Node *next;
} Node;

struct Graph { 
    int size; 
    struct Node *index;
    struct nodeInfo *currentNode; // added for algs
};


Graph* invert(Graph *g){
    Graph* tempGraph = create(g->size);
    initIndex(tempGraph);
    initNextNode(g);
    while(g->currentNode != NULL){
        insertEdge(tempGraph, g->currentNode->target, g->currentNode->source, g->currentNode->weight);
        getNextNode(g);
    } 
}

int minDegree(Graph *g){
    int min = INT_MAX;
    for(int i = 0; i < g->size; i++){
        if (edgeCounter(g,i) < min){
            min = edgeCounter(g,i);
        }
    }
    return min;
}
int maxDegree(Graph *g){
    int max = INT_MIN;
    for(int i = 0; i < g->size; i++){
        if (edgeCounter(g,i) < max){
            max = edgeCounter(g,i);
        }
    }
    return max;
}

double avgDegree(Graph *g){
    double weightSum = 0;
    int nodeCounter = 0;
    initNextNode(g);
    while(g->currentNode != NULL){
        weightSum += g->currentNode->weight;
        nodeCounter++;
        getNextNode(g);
    }
    return (weightSum / nodeCounter);
}

void printDegreeHistogram(Graph *g){
    printf("'Degree Histogram'");
    int *grade[g->size] = {0};
    initNextNode(g);
    while(g->currentNode != NULL){
        (*grade[g->currentNode->source])++;
        getNextNode(g);
    }
    printf("\nSum:\t\t");
    for(int i = 0; i < sizeof(grade); i++){
        printf("%d\t", grade[i]);
    }
    for(int i = 0; i < sizeof(grade); i++){
        printf("----"\n);
    }  
    printf("\nGrades:\t\t");
    for(int i = 0; i < sizeof(grade); i++){
        printf("%d\t", i);
    }
    printf("\n")
}