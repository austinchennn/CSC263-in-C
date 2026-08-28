#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/*
 * 图的 Adjacency List（邻接表）表示，顶点用 0 .. n-1 编号。
 * W9 的 DFS / 环检测 / 拓扑排序 / 强连通分量都建在这个结构上。
 */

typedef struct EdgeNode {
    int dest;
    struct EdgeNode *next;
} EdgeNode;

typedef struct {
    int n;
    int m;
    bool directed;
    EdgeNode **adj;
} Graph;

Graph *createGraph(int n, bool directed);
void freeGraph(Graph *g);

/* 加一条边 u→v；无向图同时加 v→u */
void addEdge(Graph *g, int u, int v);

/* 返回转置图 G^T（所有边反向），SCC 用；仅对有向图有意义 */
Graph *transposeGraph(const Graph *g);

void printGraph(const Graph *g);

#endif
