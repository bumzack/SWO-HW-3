#include <stdio.h>
#include <stdlib.h>
#include "GRAPH_M.h"

int main(void) {
    Graph* Test1;
    Test1 = create(6);
    insertEdge(Test1, 0, 1, 1);
    insertEdge(Test1, 0, 5, 1);
    insertEdge(Test1, 1, 2, 1);
    insertEdge(Test1, 1, 5, 1);
    insertEdge(Test1, 2, 3, 1);
    insertEdge(Test1, 2, 4, 1);
    insertEdge(Test1, 3, 4, 1);
    insertEdge(Test1, 4, 5, 1);
    insertEdge(Test1, 5, 2, 1);

    print(Test1);

    return 0;
}