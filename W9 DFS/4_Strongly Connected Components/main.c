#include "../1_DFS/DFS with Timestamps/graph.h"
#include "../1_DFS/DFS with Timestamps/dfs.h"
#include <stdio.h>

/*
 * 强连通分量演示（见 definition.md / implementation.md）。CLRS 两趟 DFS。
 *
 * CLRS 示例图：a..h = 0..7
 *   a→b b→c b→e b→f c→d c→g d→c d→h e→a e→f f→g g→f g→h h→h
 *   SCC：{a,b,e} {c,d} {f,g} {h}
 */
static Graph *sccExample(void) {
    Graph *g = createGraph(8, true);
    addEdge(g, 0, 1); addEdge(g, 1, 2); addEdge(g, 1, 4); addEdge(g, 1, 5);
    addEdge(g, 2, 3); addEdge(g, 2, 6); addEdge(g, 3, 2); addEdge(g, 3, 7);
    addEdge(g, 4, 0); addEdge(g, 4, 5); addEdge(g, 5, 6); addEdge(g, 6, 5);
    addEdge(g, 6, 7); addEdge(g, 7, 7);
    return g;
}

int main(void) {
    Graph *sg = sccExample();
    int comp[8];
    int k = sccCount(sg, comp);

    printf("共 %d 个 SCC：\n", k);
    for (int c = 0; c < k; c++) {
        printf("  SCC %d:", c);
        for (int v = 0; v < sg->n; v++) if (comp[v] == c) printf(" %d", v);
        printf("\n");
    }

    freeGraph(sg);
    return 0;
}
