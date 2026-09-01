#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/*
 * 图的 Adjacency List（邻接表）表示。
 * 顶点用 0 .. n-1 编号；每个顶点挂一条链表，存它的所有出边终点。
 * 空间复杂度 Θ(n + m)。见 1_Graph Representations/。
 */

typedef struct EdgeNode {
    int dest;                 /* 边的另一端顶点 */
    struct EdgeNode *next;
} EdgeNode;

typedef struct {
    int n;                    /* 顶点数 |V| */
    int m;                    /* 边数 |E|（无向边算 1 条） */
    bool directed;
    EdgeNode **adj;           /* 长度为 n 的邻接表头指针数组 */
} Graph;

Graph *createGraph(int n, bool directed);
void freeGraph(Graph *g);

/* 加一条边 u—v；无向图会同时把 u 加进 v 的表、v 加进 u 的表 */
void addEdge(Graph *g, int u, int v);

/* 调试用：打印每个顶点的邻接表 */
void printGraph(const Graph *g);

#endif
