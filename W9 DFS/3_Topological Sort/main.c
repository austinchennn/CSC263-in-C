#include "../1_DFS/DFS with Timestamps/graph.h"
#include "../1_DFS/DFS with Timestamps/dfs.h"
#include <stdio.h>

/*
 * 拓扑排序演示（见 definition.md / implementation.md）。
 * topoSort()：DFS，每个顶点「完成」时前插到 order[]；有环返回 -1。
 */
int main(void) {
    /* DAG：0→1,0→2,1→3,2→3,3→4 */
    Graph *dag = createGraph(5, true);
    addEdge(dag, 0, 1); addEdge(dag, 0, 2);
    addEdge(dag, 1, 3); addEdge(dag, 2, 3); addEdge(dag, 3, 4);

    int order[5];
    if (topoSort(dag, order) == 0) {
        printf("DAG 拓扑序:");
        for (int i = 0; i < dag->n; i++) printf(" %d", order[i]);
        printf("\n");
    }

    /* 有环图：topoSort 返回 -1 */
    Graph *g = createGraph(3, true);
    addEdge(g, 0, 1); addEdge(g, 1, 2); addEdge(g, 2, 0);
    int tmp[3];
    printf("有环图 0→1→2→0  topoSort 返回 %d (-1 表示有环)\n", topoSort(g, tmp));

    freeGraph(dag);
    freeGraph(g);
    return 0;
}
