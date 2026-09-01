#include "../1_DFS/DFS with Timestamps/graph.h"
#include "../1_DFS/DFS with Timestamps/dfs.h"
#include <stdio.h>

/*
 * 有向图环检测演示（见 definition.md / implementation.md）。
 * hasCycle()：DFS 中遇到指向 Grey 顶点的边（back edge）即判定有环。
 */
int main(void) {
    /* 有环：1→4→3→1 */
    Graph *g = createGraph(6, true);
    addEdge(g, 0, 1); addEdge(g, 0, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 4); addEdge(g, 2, 5);
    addEdge(g, 3, 1);
    addEdge(g, 4, 3);
    addEdge(g, 5, 5);
    printf("图 0→1,0→3,1→4,2→4,2→5,3→1,4→3,5→5  hasCycle = %s (1→4→3→1 成环)\n",
           hasCycle(g) ? "true" : "false");

    /* 无环 DAG */
    Graph *dag = createGraph(5, true);
    addEdge(dag, 0, 1); addEdge(dag, 0, 2);
    addEdge(dag, 1, 3); addEdge(dag, 2, 3); addEdge(dag, 3, 4);
    printf("DAG 0→1,0→2,1→3,2→3,3→4                hasCycle = %s\n",
           hasCycle(dag) ? "true" : "false");

    freeGraph(g);
    freeGraph(dag);
    return 0;
}
