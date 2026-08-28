#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * @brief 创建 n 个顶点、无边的图。
 * @param directed true 为有向图，false 为无向图。
 */
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

/* 把 dest 头插进 src 的邻接表 */
static void addArc(Graph *g, int src, int dest) {
    EdgeNode *node = (EdgeNode *)malloc(sizeof(EdgeNode));
    node->dest = dest;
    node->next = g->adj[src];
    g->adj[src] = node;
}

/**
 * @brief 加一条边。无向图会加两条有向弧（u→v 和 v→u）。
 */
void addEdge(Graph *g, int u, int v) {
    assert(u >= 0 && u < g->n && v >= 0 && v < g->n);
    addArc(g, u, v);
    if (!g->directed) addArc(g, v, u);
    g->m++;
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
