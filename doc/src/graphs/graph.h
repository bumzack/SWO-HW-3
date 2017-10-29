#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

struct Graph;
typedef struct Graph Graph;
 
Graph* create(int n);
void initIndex(Graph *g);
void destroy(Graph **g);
void insertEdge(Graph *g, int source, int target, double weight);
double getWeight(Graph *g, int source, int target);
void removeEdge(Graph *g, int source, int target);
void print(Graph *g);



// for the functions in graph_alg.c to work
// we need some additonal functions here
int getSize(Graph *g);
int getDegree(Graph *g, int n);


// you dont want to expose Node here -> only use Graph struct 

//void initNextNode(Graph *g);
//void getNextNode(Graph *g);
//int edgeCounter(Graph* g, int targetNode);



#endif
