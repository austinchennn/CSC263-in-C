#include "dfs.h"
#include <stdlib.h>

/*
 * 强连通分量，见 4_Strongly Connected Components/。CLRS 两趟 DFS：
 *   1. DFS(G) 求每个顶点的完成时间 f
 *   2. 构造转置图 G^T
 *   3. 在 G^T 上，按 f 递减顺序作为外层循环起点做 DFS；
 *      每棵 depth-first tree 的顶点集合就是一个 SCC
 */

static void sccVisit(const Graph *gt, int s, Color *color, int *comp, int id) {
    color[s] = GREY;
    comp[s] = id;
    for (EdgeNode *e = gt->adj[s]; e != NULL; e = e->next) {
        if (color[e->dest] == WHITE) sccVisit(gt, e->dest, color, comp, id);
    }
    color[s] = BLACK;
}

int sccCount(const Graph *g, int *comp) {
    int n = g->n;
    int *d = (int *)malloc(sizeof(int) * (size_t)n);
    int *f = (int *)malloc(sizeof(int) * (size_t)n);
    int *pred = (int *)malloc(sizeof(int) * (size_t)n);

    /* 1. DFS(G) 求完成时间 */
    dfsRun(g, d, f, pred);

    /* 顶点按完成时间递减排序（n 小，选择排序） */
    int *byFinish = (int *)malloc(sizeof(int) * (size_t)n);
    for (int i = 0; i < n; i++) byFinish[i] = i;
    for (int i = 0; i < n - 1; i++) {
        int mx = i;
        for (int j = i + 1; j < n; j++)
            if (f[byFinish[j]] > f[byFinish[mx]]) mx = j;
        int tmp = byFinish[i];
        byFinish[i] = byFinish[mx];
        byFinish[mx] = tmp;
    }

    /* 2. 转置图 */
    Graph *gt = transposeGraph(g);

    /* 3. 按完成时间递减顺序在 G^T 上 DFS */
    Color *color = (Color *)malloc(sizeof(Color) * (size_t)n);
    for (int v = 0; v < n; v++) color[v] = WHITE;

    int k = 0;
    for (int i = 0; i < n; i++) {
        int v = byFinish[i];
        if (color[v] == WHITE) {
            sccVisit(gt, v, color, comp, k);
            k++;
        }
    }

    free(color);
    freeGraph(gt);
    free(byFinish);
    free(pred);
    free(f);
    free(d);
    return k;
}
