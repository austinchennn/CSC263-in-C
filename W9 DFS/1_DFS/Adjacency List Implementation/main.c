#include "graph.h"
#include "dfs.h"
#include <stdio.h>

/*
 * DFS(G) 时间戳演示（见 ../../definition.md / ../../implementation.md）。
 * 有向图：0→1 0→3 1→4 2→4 2→5 3→1 4→3 5→5
 * 输出每个顶点的发现时间 d、完成时间 f、DFS 森林父节点 pred。
 */
int main(void) {
    Graph *g = createGraph(6, true);
    addEdge(g, 0, 1); addEdge(g, 0, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 4); addEdge(g, 2, 5);
    addEdge(g, 3, 1);
    addEdge(g, 4, 3);
    addEdge(g, 5, 5);

    int d[6], f[6], pred[6];
    dfsRun(g, d, f, pred);

    printf("== DFS timestamps ==\n");
    printf("  v : d / f  (pred)\n");
    for (int v = 0; v < g->n; v++)
        printf("  %d : %d / %d  (%d)\n", v, d[v], f[v], pred[v]);

    freeGraph(g);
    return 0;
}
