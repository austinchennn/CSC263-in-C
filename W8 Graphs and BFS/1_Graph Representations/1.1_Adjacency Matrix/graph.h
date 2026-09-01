#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/*
 * 图的 Adjacency Matrix（邻接矩阵）表示。
 * 顶点用 0 .. n-1 编号；adj 是一个 n×n 的 0/1 矩阵，
 * adj[u][v] == 1 表示存在边 u→v（无向图则 adj[u][v] 和 adj[v][u] 同时为 1）。
 *
 * 空间复杂度 Θ(n²)：不管边多少都要开满整个矩阵。
 * Edge Query（判断 u、v 之间有没有边）：Θ(1)，直接查 adj[u][v]。
 * 列出一个顶点的所有邻居：Θ(n)，要扫它对应的一整行。
 * 见 ../complexity.md。
 */

typedef struct {
    int n;                    /* 顶点数 |V| */
    int m;                    /* 边数 |E|（无向边算 1 条） */
    bool directed;
    int **adj;                /* n×n 矩阵，adj[u][v] ∈ {0, 1} */
} Graph;

Graph *createGraph(int n, bool directed);
void freeGraph(Graph *g);

/* 加一条边 u—v；无向图会同时置 adj[u][v] 和 adj[v][u] */
void addEdge(Graph *g, int u, int v);

/* 调试用：打印整个矩阵 */
void printGraph(const Graph *g);

#endif
