#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"



int main () {
	int source = 0;
	int target = 0;
	Graph* g = create(6);

	// Adding some Edges
	insertEdge(g,1,2,2.5);
	insertEdge(g,1,6,2.00);
	insertEdge(g,2,3,1.50);
	insertEdge(g,3,4,0.25);
	insertEdge(g,3,5,3.75);
	insertEdge(g,4,5,4.25);
	insertEdge(g,5,6,3.00);

	// Adding an already  existing edge
	insertEdge(g,5,6,3.00);

	// Adding more Edges
	insertEdge(g,2,6,1.75);
	insertEdge(g,6,3,5.25);
	insertEdge(g,3,6,1.25);

	print(g);

	// Calculating weight between two edges
	source = 6;
	target = 3;
	printf("\nWeight between %d and %d is %.2f \n",source,target,getWeight(g,source,target));

	source = 4;
	target = 5;
	printf("\nWeight between %d and %d is %.2f \n",source,target,getWeight(g,source,target));

	// Calculating weight between two non-existing edges
	source = 8;
	target = 3;
	printf("\nWeight between %d and %d is %.2f \n",source,target,getWeight(g,source,target));

	// Removing an Edge
	source = 4;
	target = 5;
	removeEdge(g,source,target);

	print(g);
	// Testfaelle fuer AdjMatrix

	return 0;
}
