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


Graph* invert(Graph *g){}
int minDegree(Graph *g){}
int maxDegree(Graph *g){}
double avgDegree(Graph *g){}

void printDegreeHistogram(Graph *g){}