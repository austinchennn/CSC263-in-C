#include "edgenode.c"
#include <stdio.h>
#include <stdbool.h>
#define MAXV 100

bool visited[MAXV];  //标记每个点是否被访问，默认false



/*
 * DFS：深度优先搜索（邻接表版）
 * AdjList: 邻接表
 * u: 起始顶点
 *
 * 时间复杂度：
 *   - O(n + m)，其中 n 为顶点数，m 为边数。
 *
 * 空间复杂度：邻接表本身 Θ(n + m)，加上 visited[] Θ(n) 和递归栈最深 Θ(n)。
 */
void DFS(EdgeNode* AdjList[], int u){
    //不撞南墙不回头

    //1.访问定点u —— O(1)
    printf("%d ", u);
    visited[u] = true;  //标记顶点u已访问

    //2.扫 u 的邻接链表找未访问的邻接顶点 v，递归下去 —— 每次调用 Θ(deg(u))
    for (EdgeNode* p = AdjList[u]; p != NULL; p = p->next) {
        int v = p->adjvex;  //邻接点v的下标
        if (visited[v] == false) {  //v未被访问
            DFS(AdjList, v);  //让他作为新的起始顶点v递归调用DFS函数
        }
    }
}

