#include <stdlib.h>
#include <stdio.h>

struct Node;
typedef struct Node {
    int nodeNumber;
    double weight;
    struct Node *next;
} Node;

typedef struct Graph {
    int size;
    struct Node *index;
} Graph;

// int currentSolution() {

//     int n = 6;

//     // create()
//     Graph *g;

//     g =  (Graph*)malloc(sizeof(Graph));
//     g->size = n;
//     g->index = (Node*)malloc(sizeof(Node) * n);

//     // initIndex
//     for(int i = 0; i < g->size; i++){
//         g->index[i].nodeNumber = i;
//         g->index[i].weight = 0;
//         g->index[i].next = NULL;
//     }

//     // show index
//     for(int i = 0; i < g->size; i++){
//         printf("address of g->index[%d] = %p\n", i, (void *)(g->index[i]));

//         printf("g->index[%d].nodeNumber = %d\n", i,  g->index[i].nodeNumber);
//         printf("g->index[%d].weight = %5.2f\n", i,  g->index[i].weight);
//         printf("g->index[%d].next = %p\n", i,  (void *)(g->index[i].next));
//     }
// }

typedef struct Graph2 {
    int size;
    struct Node *index[]; // <<---- [] hinterm *index
} Graph2;

int newSolution() {

    int n = 6;

    // create()
    Graph2 *g;

    printf("g malloc   sizeof(Graph2)= %lu\n", sizeof(Graph2));
    g = (Graph2 *)malloc(sizeof(Graph2));
    g->size = n;
    printf("g->index malloc\n");
    printf("g malloc   sizeof(Node) * n= %lu\n", sizeof(Node) * n);
    *(g->index) = (Node *)malloc(sizeof(Node) * n);

    // initIndex
    for (int i = 0; i < g->size; i++) {
        g->index[i] = NULL;
        printf("address of g->index[%d] = %p\n", i, (void *)(g->index[i]));
    }

    // hier wird  für jedes array element der speicher für den knoten reserviert - also der erste Knoten in der liste
    for (int i = 0; i < g->size; i++) {
        // g->index[i] ist das erste Knoten in der Liste und owurde ben mit NULL initialisert
        g->index[i] = malloc(sizeof(Node));
        g->index[i]->nodeNumber = i;
        g->index[i]->weight = i * 2.0;
        g->index[i]->next = NULL;
    }

    // show index
    for (int i = 0; i < g->size; i++) {
        printf("address of g->index[%d] = %p\n", i, (void *)(g->index[i]));
        printf("g->index[%d].nodeNumber = %d\n", i, g->index[i]->nodeNumber);
        printf("g->index[%d].weight = %5.2f\n", i, g->index[i]->weight);
        printf("g->index[%d].next = %p\n", i, (void *)(g->index[i]->next));
    }
}

int main() {
    newSolution();
}
