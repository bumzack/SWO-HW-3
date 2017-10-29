#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

#define FILENAME AdjListFile "graph.h"

typedef struct Graph Graph;

typedef struct Node {
	int target;
	double weight;
	struct Node *next;
} Node;

struct Graph {
	//Node * AdjList[MAX_VERT];
	Node *AdjList[MAX_VERT];
	int n;
};



Graph* create(int n){
	if(n<=MAX_VERT) {
		Graph *g;
		g= (Graph*)malloc(sizeof(Node)*n);
		g->n=n;
		FillMatrix(g);
		return g;
	}
	else {
		return NULL;
	}
}

void FillMatrix(Graph *g) {
	for(int i=0;i < g->n;i++) {
			g->AdjList[i]=NULL;
	}
}

void print(Graph *g)
{
	Node *temp;
	printf("\n");
	for(int i=0;i < g->n;i++) {
		printf("Edge %d:\n",i+1);
		if(g->AdjList[i]!=NULL) {
			temp=g->AdjList[i];
			while ( temp != NULL) {
				printf("%d--(%.2f)-->%d	\n",i+1,temp->weight,temp->target);
				temp=temp->next;
			}
		}
	}
	printf("\n");
}

static Node* createNode(int target, double weight) {
	Node n = (Node) malloc(sizeof(Node));
	if(n==NULL) {
		return NULL;
	}
	n->target=target;
	n->weight=weight;
	n->next=NULL;
	return n;
}
// returns -1 if edge exists and 0 if edge doesnt exist
int edgeExists(Graph *g, int source, int target) {
	int available = 0;
	
	Node *temp;
	// Point on the wished source
	temp = g->AdjList[source-1];
	if(temp != NULL ) {
		while (temp != NULL) {
			if( temp->target == target) {
				available=-1;
				printf("Edge %d --> %d already exists!\n",source,target);
			}
			temp=temp->next;
		}
	}
	return available;
}

void insertEdge(Graph *g, int source, int target, double weight){
	Node *temp;
		// Checking if source and target are inside the matrix and if edge doesent exists, otherwise it will be ignored
		if(((source<=g->n) && (target<=g->n)) && (edgeExists(g,source,target)==0)) {

			if(g->AdjList[source-1]==NULL){
				g->AdjList[source-1]=createNode(target,weight);
			} else {
				temp=g->AdjList[source-1];
				while(temp->next!=NULL) {
					temp=temp->next;
				}
				temp->next=createNode(target,weight);
			}
		}
	}

// returns the weight between two edges, in case no egdes found i return 0
double getWeight(Graph *g,int source, int target){
	Node *temp;
	
	// Point on the wished source
	temp = g->AdjList[source-1];
	if(temp != NULL ) {
		while (temp != NULL) {
			if( temp->target == target) {
				return temp->weight;
			}
			temp=temp->next;
		}
	}
	return 0;
}

void removeEdge ( Graph *g, int source, int target) {
	Node *temp;
	Node *n;

	if(edgeExists(g,source,target)==-1) {
		temp=g->AdjList[source-1];
		if(temp->next == NULL) {
			n=temp;
			free(temp);
			n=NULL;
			// das würde richtig funktionieren
			//g->AdjList[source-1]=NULL;

		} else {
			n=temp;
			while(temp->target!=target) {
				n=temp;
				temp=temp->next;
			}
			n->next=temp->next;
			free(temp);
		}

	}
}