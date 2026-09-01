#include "graph.h"
#include <stdio.h>

/*
 * 演示邻接表（Adjacency List）表示：建图、加边、打印每个顶点的邻接表。
 * 空间 Θ(n + m)；列出一个顶点的邻居 O(该顶点度数)。对照 complexity.md。
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

    /* 无向图：同样的边，addEdge 会在两个方向各挂一个节点 */
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
