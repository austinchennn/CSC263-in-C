#ifndef DFS_H
#define DFS_H

#include "graph.h"

typedef enum { WHITE, GREY, BLACK } Color;

#define DFS_NIL (-1)

/*
 * DFS(G)：外层循环遍历所有顶点，对每个白色顶点调用 DFSVisit。
 * 见 1_DFS/。调用方分配长度为 g->n 的数组：
 *   d[v]    —— 发现时间（discovery time）
 *   f[v]    —— 完成时间（finishing time）
 *   pred[v] —— depth-first forest 中 v 的父节点（根为 DFS_NIL）
 * 时间戳从 1 递增到 2n。时间复杂度 Θ(n + m)。
 */
void dfsRun(const Graph *g, int *d, int *f, int *pred);

/* 环检测（有向图）：DFS 中遇到指向 Grey 顶点的边即 back edge -> 有环。见 2_Cycle Detection/ */
bool hasCycle(const Graph *g);

/*
 * 拓扑排序（见 3_Topological Sort/）：
 *   顶点完成时插入链表头部 -> 按完成时间递减即为拓扑序。
 * order 由调用方分配（长度 n）。成功返回 0；图中有环返回 -1（order 内容未定义）。
 */
int topoSort(const Graph *g, int *order);

/*
 * 强连通分量（见 4_Strongly Connected Components/），CLRS 两趟 DFS：
 *   1. DFS(G) 求完成时间
 *   2. 在 G^T 上按完成时间递减顺序做 DFS，每棵树是一个 SCC
 * comp 由调用方分配（长度 n），comp[v] = v 所属分量编号（0..k-1）。返回分量数 k。
 */
int sccCount(const Graph *g, int *comp);

#endif
