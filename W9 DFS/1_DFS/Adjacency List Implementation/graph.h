#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/*
 * 图的 Adjacency List（邻接表）表示，顶点用 0 .. n-1 编号。
 * W9 的 DFS / 环检测 / 拓扑排序 / 强连通分量都建在这个结构上。
 *
 * 全局约定（复杂度里反复出现的 n、m）：
 *   n = 顶点数 |V|
 *   m = 边数   |E|（有向边算 1 条；无向边在两个方向各挂一个节点，但只算 1 条）
 */

typedef struct EdgeNode {
    int dest;                 /* 边的另一端顶点 */
    struct EdgeNode *next;
} EdgeNode;

typedef struct {
    int n;                    /* 顶点数 |V| */
    int m;                    /* 边数 |E| */
    bool directed;
    EdgeNode **adj;           /* 长度为 n 的邻接表头指针数组 */
} Graph;

Graph *createGraph(int n, bool directed);
void freeGraph(Graph *g);

/* 加一条边 u→v；无向图同时加 v→u */
void addEdge(Graph *g, int u, int v);

/* 返回转置图 G^T（所有边反向），SCC 用；仅对有向图有意义 */
Graph *transposeGraph(const Graph *g);

void printGraph(const Graph *g);

#endif
