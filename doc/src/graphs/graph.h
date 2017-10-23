#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

struct Graph;
typedef struct Graph Graph;
 
Graph* create(int n);
void initIndex(Graph *g);
void destroy(Graph *g);
void insertEdge(Graph *g, int source, int target, double weight);
double getWeight(Graph *g, int source, int target);
void removeEdge(Graph *g, int source, int target);
void print(Graph *g);

#endif
