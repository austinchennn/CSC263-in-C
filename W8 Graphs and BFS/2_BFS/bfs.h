#ifndef BFS_H
#define BFS_H

#include "graph.h"

#define BFS_INF (-1)   /* 不可达顶点的距离 */
#define BFS_NIL (-1)   /* BFS 树中无父节点 */

/*
 * BFS(G, s)：从 s 出发按层扩展，求 s 到每个可达顶点的最短距离。
 * 见 2_BFS/。
 *
 * 调用方分配长度为 g->n 的两个数组：
 *   dist[v] —— s 到 v 的最短距离（边数）；不可达为 BFS_INF
 *   pred[v] —— BFS 树中 v 的父节点；s 或不可达顶点为 BFS_NIL
 *
 * 时间复杂度 Θ(n + m)（邻接表）。
 */
void bfs(const Graph *g, int s, int *dist, int *pred);

/* 沿 pred 反向回溯，打印一条 s -> t 的最短路径 */
void printPath(const int *pred, int s, int t);

#endif
