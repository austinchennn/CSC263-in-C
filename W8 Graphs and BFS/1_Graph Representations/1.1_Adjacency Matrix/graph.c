#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * @brief 创建 n 个顶点、无边的图。adj 是一个全 0 的 n×n 矩阵。
 * @param directed true 为有向图，false 为无向图。
 */
Graph *createGraph(int n, bool directed) {
    assert(n > 0);
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;
    g->m = 0;
    g->directed = directed;

    /* n 个行指针，每行 n 个 int，全部清零 —— 一共 Θ(n²) */
    g->adj = (int **)malloc(sizeof(int *) * (size_t)n);
    for (int i = 0; i < n; i++) {
        g->adj[i] = (int *)calloc((size_t)n, sizeof(int));
    }
    return g;
}

void freeGraph(Graph *g) {
    if (g == NULL) return;
    for (int i = 0; i < g->n; i++) free(g->adj[i]);
    free(g->adj);
    free(g);
}

/**
 * @brief 加一条边。无向图会同时置 adj[u][v] 和 adj[v][u]。
 */
void addEdge(Graph *g, int u, int v) {
    assert(u >= 0 && u < g->n && v >= 0 && v < g->n);
    g->adj[u][v] = 1;
    if (!g->directed) g->adj[v][u] = 1;
    g->m++;
}

void printGraph(const Graph *g) {
    printf("Graph: n=%d, m=%d, %s\n", g->n, g->m,
           g->directed ? "directed" : "undirected");
    for (int u = 0; u < g->n; u++) {
        printf("  %d:", u);
        for (int v = 0; v < g->n; v++) printf(" %d", g->adj[u][v]);
        printf("\n");
    }
}
