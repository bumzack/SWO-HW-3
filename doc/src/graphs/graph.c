#include <stdio.h>
#include <stdlib.h>

//#include "GRAPH_M.h"
#include "GRAPH_L.h"
/*
#define USEMATRIX
#ifdef USEMATRIX
#include "graph_m.h"
#else
 #include "graph_l.h"
#endif
*/

int main(void) {
    Graph* Test1;
    Test1 = create(6);
    insertEdge(Test1, 0, 1, 1);
    insertEdge(Test1, 0, 5, 1);
    insertEdge(Test1, 1, 2, 1);
    insertEdge(Test1, 1, 5, 1);
    insertEdge(Test1, 2, 3, 5);
    insertEdge(Test1, 2, 4, 1);
    insertEdge(Test1, 3, 4, 1);
    insertEdge(Test1, 4, 5, 1);
    insertEdge(Test1, 5, 2, 1);

    printf("weight should be 5: %.2f\n", getWeight(Test1, 2,3));
    print(Test1);

    insertEdge(Test1, 2, 3, 100.33);
    printf("weight should be 100.33: %.2f\n", getWeight(Test1, 2,3));
    print(Test1);

    removeEdge(Test1, 0, 1);
    printf("weight should not be found: %.2f\n", getWeight(Test1, 0,1));
    
    //destroy(Test1);
    
    //print(Test1);

    return 0;
}