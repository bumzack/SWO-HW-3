//#include "GRAPH_M.h"
#include "graph.h"
#include "graph_algs.h"

int main(void) {
    Graph* Test1 = NULL;
    printf("creating graph\n");
    
    printf("address of test1 = %p  (should be null)\n", (void *)Test1);
    Test1 = create(6);
    printf("address of test1 = %p  (should NOT be null)\n", (void *)Test1);

    printf("insert edge 1\n"); insertEdge(Test1, 0, 1, 1);
    printf("insert edge 2\n"); insertEdge(Test1, 0, 5, 1);
    printf("insert edge 5\n"); insertEdge(Test1, 2, 3, 5);
    printf("insert edge 3\n"); insertEdge(Test1, 1, 2, 1);

    printf("insert edge 4\n"); insertEdge(Test1, 1, 5, 1);
    printf("insert edge 6\n"); insertEdge(Test1, 2, 4, 1);
    printf("insert edge 7\n"); insertEdge(Test1, 3, 4, 1);
    printf("insert edge 8\n"); insertEdge(Test1, 4, 5, 1);
    printf("insert edge 9\n"); insertEdge(Test1, 5, 2, 1);
    printf("insert edge 10\n"); insertEdge(Test1, 4, 0, 3);
    printf("insert false edge\n"); insertEdge(Test1, 6, 2, 1);
    printf("finished inserting edges\n\n");    
    
    print(Test1); 
    
    printf("This Test should fail: "); getWeight(Test1, 5, 1);
    printf("Remove edge from 2 to 3:\n"); removeEdge(Test1, 2, 3);
    printf("Remove edge from 2 to 4:\n"); removeEdge(Test1, 2, 4);
    printf("Remove edge from 6 to 2 (should create error):\n"); removeEdge(Test1, 6, 2);

    printf("Test1 statistics:\n");
    print(Test1); 
    printf("\nMinDegree: %d\tMaxDegree: %d\tAvgDegree: %.2f\n", minDegree(Test1), maxDegree(Test1), avgDegree(Test1));
    printDegreeHistogram(Test1);
    
    Graph* Test2 = invert(Test1);
    printf("\nTest2 statistics:\n");
    print(Test2); 
    printf("\nMinDegree: %d\tMaxDegree: %d\tAvgDegree: %.2f\n", minDegree(Test2), maxDegree(Test2), avgDegree(Test2));
    printDegreeHistogram(Test2);
        
    /*destroy(Test1);
    
    print(Test1); */

    return 0;
}