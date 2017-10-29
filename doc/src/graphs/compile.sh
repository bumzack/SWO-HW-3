#/bin/sh

gcc -pedantic -Wall -Wextra -std=c11 -ggdb -o graph_matrix graph.c graph_m.c graph_algs.c
gcc -pedantic -Wall -Wextra -std=c11 -ggdb -o graph_list graph.c graph_l.c graph_algs.c
