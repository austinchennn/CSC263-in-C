#include "graph.h"
#include "bfs.h"
#include <stdio.h>

/*
 * 示例用 CLRS 里的无向图（顶点重命名为 0..7）：
 *   0=r 1=s 2=t 3=u 4=v 5=w 6=x 7=y
 *   r-s, r-v, s-w, w-t, w-x, t-x, t-u, x-u, x-y, u-y
 * 从 s(=1) 出发，期望距离：s0 r1 w1 v2 t2 x2 u3 y3
 */
int main(void) {
    const char *name[] = {"r", "s", "t", "u", "v", "w", "x", "y"};
    Graph *g = createGraph(8, false);
    addEdge(g, 0, 1);   /* r-s */
    addEdge(g, 0, 4);   /* r-v */
    addEdge(g, 1, 5);   /* s-w */
    addEdge(g, 5, 2);   /* w-t */
    addEdge(g, 5, 6);   /* w-x */
    addEdge(g, 2, 6);   /* t-x */
    addEdge(g, 2, 3);   /* t-u */
    addEdge(g, 6, 3);   /* x-u */
    addEdge(g, 6, 7);   /* x-y */
    addEdge(g, 3, 7);   /* u-y */

    printGraph(g);

    int dist[8], pred[8];
    int s = 1;
    bfs(g, s, dist, pred);

    printf("\nBFS from %s:\n", name[s]);
    printf("  v   dist  path\n");
    for (int v = 0; v < g->n; v++) {
        printf("  %s   %2d    ", name[v], dist[v]);
        printPath(pred, s, v);
        printf("\n");
    }

    /* 加一个孤立顶点演示不可达 */
    Graph *g2 = createGraph(3, true);
    addEdge(g2, 0, 1);
    bfs(g2, 0, dist, pred);
    printf("\ndirected 0->1, vertex 2 isolated:  dist[2] = %d (BFS_INF)\n", dist[2]);

    freeGraph(g);
    freeGraph(g2);
    return 0;
}
