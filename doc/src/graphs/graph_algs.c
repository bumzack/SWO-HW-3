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

struct nodeInfo;
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

Graph* invert(Graph *g){
    printf("'Invert'\n");
    Graph* tempGraph = NULL;
    int n = g->size;
    tempGraph = create(n);
    //initIndex(tempGraph); printf("test\n");
    initNextNode(g);
    printf("source: %d target: %d weight: %.2f\n", g->currentNode->source, g->currentNode->target, g->currentNode->weight);
    while(g->currentNode != NULL){
        insertEdge(tempGraph, g->currentNode->target, g->currentNode->source, g->currentNode->weight);
        getNextNode(g);
        printf("source: %d target: %d weight: %.2f\n", g->currentNode->source, g->currentNode->target, g->currentNode->weight);
    }
    return tempGraph;
}

int minDegree(Graph *g){
    int min = INT_MAX;
    for(int i = 0; i < g->size; i++){
        int degree = edgeCounter(g, i);
        if (degree < min) {
            min = degree;
        }
    }
    return min;
}
int maxDegree(Graph *g){
    int max = INT_MIN;
    for(int i = 0; i < g->size; i++){
        int degree = edgeCounter(g, i);
        if (degree > max) {
            max = degree;
        }
    }
    return max;
}

double avgDegree(Graph *g){
    double degreeSum = 0;
    for(int i = 0; i < g->size; i++){
        degreeSum += edgeCounter(g, i);
    }
    return (degreeSum / g->size);
}

void printDegreeHistogram(Graph *g){
    printf("'Degree Histogram'");
    int gradeSize = g->size;
    int grade[gradeSize];
    for(int i = 0; i < gradeSize; i++){
        grade[i] = 0;
    }
    for(int i = 0; i < g->size; i++){
        grade[i] = edgeCounter(g, i);
    }

    printf("\nSum:\t");
    for(int i = 0; i < gradeSize; i++){
        printf("%d\t", grade[i]);
    }
    printf("\nGrades:\t");
    for(int i = 0; i < gradeSize; i++){
        printf("%d\t", i);
    }
    printf("\n");
}