#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    
    // und wenn du in graph.h eine Funktion getNodeCount(*g) macchst, die reutnr g->size; liefert
    // dann kannst hier noch schreiben
    // int n = getNodeCount(g);
    // und brauchst überhaupt nicht mehr auf komponenten von g zgreifen
    // wenn du getNodeCount auch für die matrix implementierst, dann 
    // bist du völlig unabhänigig von graph_m und graph_l sondern brauchst nur 
    // graph.h includen 
    int n = g->size;
    tempGraph = create(n);

    double w; 

    for (int source = 0; source < g->size; source++) {
        for (int target = 0; target < g->size; target++) {
            w = getWeight(g, source, target);
            if (w != 0.0) {
                insertEdge(tempGraph, target, source, w);
            } 
        }
    }

    // Node *targetList; 

    // for (int source = 0; source < n; source++) {
    //     targetList = g->index[source].next;
    //     while (targetList != NULL) {
    //         printf("\n\n\n'invert'  found edge from source = %d to target = %d with weight = %5.2f\n", source, targetList->nodeNumber, targetList->weight);
    //         insertEdge(tempGraph, targetList->nodeNumber, source, targetList->weight);
    //         targetList = targetList->next;
    //     }
    // }
    //initIndex(tempGraph); printf("test\n");
    // initNextNode(g);
    // printf("source: %d target: %d weight: %.2f\n", g->currentNode->source, g->currentNode->target, g->currentNode->weight);
    // while(g->currentNode != NULL){
    //     printf("\n\n\n'invert'  address of g->currentNode = %p\n", (void*)g->currentNode);
    //     insertEdge(tempGraph, g->currentNode->target, g->currentNode->source, g->currentNode->weight);
    //     getNextNode(g);
    //     printf("\n\n\n'invert' AFTER getNExtNode address of g->currentNode = %p\n\n\n", (void*)g->currentNode);
    //     printf("source: %d target: %d weight: %.2f\n", g->currentNode->source, g->currentNode->target, g->currentNode->weight);
    // }
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
