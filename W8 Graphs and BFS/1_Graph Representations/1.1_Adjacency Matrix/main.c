#include "graph.h"
#include <stdio.h>

/*
 * 演示邻接矩阵（Adjacency Matrix）表示：建图、加边、打印矩阵。
 * 空间 Θ(n²)；Edge Query O(1)；列出一个顶点的邻居 Θ(n)。对照 ../complexity.md。
 * 用的是和 ../1.2_Adjacency List/main.c 完全一样的图，方便对比两种表示。
 */
int main(void) {
    /* 有向图：0->1, 0->2, 1->2, 2->0, 2->3 */
    printf("== directed ==\n");
    Graph *dg = createGraph(4, true);
    addEdge(dg, 0, 1);
    addEdge(dg, 0, 2);
    addEdge(dg, 1, 2);
    addEdge(dg, 2, 0);
    addEdge(dg, 2, 3);
    printGraph(dg);

    /* 无向图：同样的边，addEdge 会对称地置两格 */
    printf("\n== undirected ==\n");
    Graph *ug = createGraph(4, false);
    addEdge(ug, 0, 1);
    addEdge(ug, 0, 2);
    addEdge(ug, 1, 2);
    addEdge(ug, 2, 3);
    printGraph(ug);

    freeGraph(dg);
    freeGraph(ug);
    return 0;
}
