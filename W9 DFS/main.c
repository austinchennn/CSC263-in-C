#include "graph.h"
#include "dfs.h"
#include <stdio.h>

/* CLRS 强连通分量示例图：a..h = 0..7
 * a→b b→c b→e b→f c→d c→g d→c d→h e→a e→f f→g g→f g→h h→h
 * SCC：{a,b,e} {c,d} {f,g} {h} */
static Graph *sccExample(void) {
    Graph *g = createGraph(8, true);
    addEdge(g, 0, 1); addEdge(g, 1, 2); addEdge(g, 1, 4); addEdge(g, 1, 5);
    addEdge(g, 2, 3); addEdge(g, 2, 6); addEdge(g, 3, 2); addEdge(g, 3, 7);
    addEdge(g, 4, 0); addEdge(g, 4, 5); addEdge(g, 5, 6); addEdge(g, 6, 5);
    addEdge(g, 6, 7); addEdge(g, 7, 7);
    return g;
}

int main(void) {
    /* ---- 1_DFS：时间戳 ---- */
    printf("== DFS timestamps ==\n");
    Graph *g = createGraph(6, true);
    addEdge(g, 0, 1); addEdge(g, 0, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 4); addEdge(g, 2, 5);
    addEdge(g, 3, 1);
    addEdge(g, 4, 3);
    addEdge(g, 5, 5);
    int d[6], f[6], pred[6];
    dfsRun(g, d, f, pred);
    printf("  v : d / f  (pred)\n");
    for (int v = 0; v < g->n; v++)
        printf("  %d : %d / %d  (%d)\n", v, d[v], f[v], pred[v]);

    /* ---- 2_Cycle Detection ---- */
    printf("\n== Cycle detection ==\n");
    printf("  上面这张图 hasCycle = %s (1→4→3→1 成环)\n", hasCycle(g) ? "true" : "false");
    Graph *dag = createGraph(5, true);
    addEdge(dag, 0, 1); addEdge(dag, 0, 2);
    addEdge(dag, 1, 3); addEdge(dag, 2, 3); addEdge(dag, 3, 4);
    printf("  DAG 0→1,0→2,1→3,2→3,3→4  hasCycle = %s\n", hasCycle(dag) ? "true" : "false");

    /* ---- 3_Topological Sort ---- */
    printf("\n== Topological sort ==\n");
    int order[6];   /* 够大：dag 有 5 个顶点，下面对 g 试跑时 g 有 6 个 */
    if (topoSort(dag, order) == 0) {
        printf("  DAG 拓扑序:");
        for (int i = 0; i < dag->n; i++) printf(" %d", order[i]);
        printf("\n");
    }
    printf("  对有环图 topoSort 返回 %d (-1 表示有环)\n", topoSort(g, order));

    /* ---- 4_Strongly Connected Components ---- */
    printf("\n== Strongly connected components ==\n");
    Graph *sg = sccExample();
    int comp[8];
    int k = sccCount(sg, comp);
    printf("  共 %d 个 SCC：\n", k);
    for (int c = 0; c < k; c++) {
        printf("    SCC %d:", c);
        for (int v = 0; v < sg->n; v++) if (comp[v] == c) printf(" %d", v);
        printf("\n");
    }

    freeGraph(g);
    freeGraph(dag);
    freeGraph(sg);
    return 0;
}
