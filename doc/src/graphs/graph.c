//#include "GRAPH_M.h"
#include "graph.h"
#include "graph_algs.h"

int main(void) {
    printf("creating graph\n");
    
    Graph* node1FullyConnectedGraph = NULL;
    node1FullyConnectedGraph = create(3);

    // node 0 is connected to all other nodes as source
    insertEdge(node1FullyConnectedGraph, 0, 0, 1);
    insertEdge(node1FullyConnectedGraph, 0, 1, 2);
    insertEdge(node1FullyConnectedGraph, 0, 2, 3);
    // node 0 is connected to all other nodes as target
    // 0->0 already added above 
    insertEdge(node1FullyConnectedGraph, 1, 0, 4);
    insertEdge(node1FullyConnectedGraph, 2, 0, 5);

    // random edge 
    insertEdge(node1FullyConnectedGraph, 1, 2, 6);

    printf("finished inserting edges\n\n");    
    
    print(node1FullyConnectedGraph); 
    printf("\nMinDegree: %d\tMaxDegree: %d\tAvgDegree: %.2f\n", minDegree(node1FullyConnectedGraph), maxDegree(node1FullyConnectedGraph), avgDegree(node1FullyConnectedGraph));    
    printDegreeHistogram(node1FullyConnectedGraph);
    
    Graph* invGraph = invert(node1FullyConnectedGraph);
    printf("\nstatistics for inverted graph should be equal to the values of the original graph:\n\n\n");
    
    printf("\ninverted graph statistics:\n");
    print(invGraph); 
    printf("\nMinDegree: %d\tMaxDegree: %d\tAvgDegree: %.2f\n", minDegree(invGraph), maxDegree(invGraph), avgDegree(invGraph));
    printDegreeHistogram(invGraph);
        
    /*destroy(Test1);
    
    print(Test1); */

    return 0;
}
