#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Graph *createGraph(int n, bool directed) {
    assert(n > 0);
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;
    g->m = 0;
    g->directed = directed;
    g->adj = (EdgeNode **)calloc((size_t)n, sizeof(EdgeNode *));
    return g;
}

void freeGraph(Graph *g) {
    if (g == NULL) return;
    for (int i = 0; i < g->n; i++) {
        EdgeNode *cur = g->adj[i];
        while (cur != NULL) {
            EdgeNode *next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(g->adj);
    free(g);
}

static void addArc(Graph *g, int src, int dest) {
    EdgeNode *node = (EdgeNode *)malloc(sizeof(EdgeNode));
    node->dest = dest;
    node->next = g->adj[src];
    g->adj[src] = node;
}

void addEdge(Graph *g, int u, int v) {
    assert(u >= 0 && u < g->n && v >= 0 && v < g->n);
    addArc(g, u, v);
    if (!g->directed) addArc(g, v, u);
    g->m++;
}

/**
 * @brief 构造转置图 G^T：G 中每条 u→v 变成 v→u。
 * @note 为了让 G 和 G^T 的邻接表顺序一致（SCC 遍历结果稳定），
 *       这里按「顶点从大到小、每个顶点的邻接表也从大到小」的方式重建。
 */
Graph *transposeGraph(const Graph *g) {
    Graph *t = createGraph(g->n, true);
    for (int u = g->n - 1; u >= 0; u--) {
        for (EdgeNode *e = g->adj[u]; e != NULL; e = e->next) {
            addArc(t, e->dest, u);   /* v→u */
            t->m++;
        }
    }
    return t;
}

void printGraph(const Graph *g) {
    printf("Graph: n=%d, m=%d, %s\n", g->n, g->m,
           g->directed ? "directed" : "undirected");
    for (int i = 0; i < g->n; i++) {
        printf("  adj[%d]:", i);
        for (EdgeNode *e = g->adj[i]; e != NULL; e = e->next) printf(" %d", e->dest);
        printf("\n");
    }
}
