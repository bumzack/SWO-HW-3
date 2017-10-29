#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"
#include "graph_algs.h"


// only use functions to access data from the graph, don't expose
// data structures from gaph_m or graph_l

// e.g. instead of using g->size   use a function  getSize(g)

Graph* invert(Graph *g) {
    int n = getSize(g);
    Graph* tempGraph = create(n);
    double w; 

    // check for all possible edges and insert only in 
    // inverted graph if edge exists (w != 0)
    for (int source = 0; source < n; source++) {
        for (int target = 0; target < n; target++) {
            w = getWeight(g, source, target);
            if (w != 0.0) {
                // swap source and target
                insertEdge(tempGraph, target, source, w);
            }
        }
    }
    return tempGraph;
}

int minDegree(Graph *g) {
    int n = getSize(g);
    int min = INT_MAX;
    int degree; 
    for(int i = 0; i < n; i++){
       degree = getDegree(g, i);
        if (degree < min){
            min = degree;
        }
    }
    return min;
}

int maxDegree(Graph *g) {
    int n = getSize(g);
    int max = INT_MIN;
    int degree; 
    for(int i = 0; i < n; i++){
       degree = getDegree(g, i);
        if (degree > max){
            max = degree;
        }
    }
    return max;
}

double avgDegree(Graph *g){
    double degreeSum = 0.0;
    int n = getSize(g);

    for (int i = 0; i < n; i++) {
        degreeSum += getDegree(g, i);
    }

    return (degreeSum / (n+1));
}

void printDegreeHistogram(Graph *g){
    int n = getSize(g);
    
    // each node can have max (n) indegree and (n) outdegree
    // so 2n degrees total 
    // hmmm - can a 0->0 edge be counted twice?
    // ask Koutschan :-)

    int maxDegree = 2*n;
    int howManyGraphnodesWithThisDegree[maxDegree+1];    // only works in C 99  , better use a dynamic array
    int degree; 

    // initialize array 
    for (int i = 0; i <= maxDegree ; i++) {
        howManyGraphnodesWithThisDegree[i] = 0;
    }

    // visit every node, get the degree of each node and increment the counter for this occurence of degree
    for (int i = 0; i < n; i++) {
        degree = getDegree(g, i);
        // increment the occurence of this degree by 1
        howManyGraphnodesWithThisDegree[degree]++;
    }
    
    printf("\nDegree Histogram:\n");
    for(int i = 0; i <= maxDegree; i++){
        // degree is i+1  as u
        printf("degree  of %d\thave %d nodes \n", i, howManyGraphnodesWithThisDegree[i]);
    }
    printf("\n");
}
