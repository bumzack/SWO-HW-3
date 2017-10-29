#ifndef GRAPH_ALGS_H
#define GRAPH_ALGS_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct Graph;
typedef struct Graph Graph;

Graph* invert(Graph *g);
int minDegree(Graph *g);
int maxDegree(Graph *g);
double avgDegree(Graph *g);

void printDegreeHistogram(Graph *g);
#endif
