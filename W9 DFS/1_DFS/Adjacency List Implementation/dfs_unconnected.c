#include "dfs.c"
#include <stdlib.h>

/* 头插一条有向边 u→v 到邻接表（无向图两个方向各调一次） */
void addEdge(EdgeNode* AdjList[], int u, int v){
    EdgeNode* node = malloc(sizeof(EdgeNode));
    node->adjvex = v;
    node->next = AdjList[u];
    AdjList[u] = node;
}

/*
 * DFSTraverse：对整张图做 DFS，覆盖所有顶点（非连通 / 有向不可达也不漏）。
 * 每次外层循环启动一次新的 DFS，就是发现了一个新的连通分量。
 */
void DFSTraverse(EdgeNode* AdjList[], int n){

    int cnt = 0;  //记录连通分量的个数

    for (int i = 0; i < n; i++) {//初始化标记数组
        visited[i] = false;
    }

    //枚举每一个点，对尚未访问的点调用DFS函数
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(AdjList, i);
            cnt++;  //从 i 起又走了一棵 DFS 树 -> 一个新的连通分量
        }
    }

    printf("\n该图有 %d 个连通分量\n", cnt);
}

int main(void){
    //示例：6 个顶点，3 个连通分量 {0,1,2} {3,4} {5}
    int n = 6;
    EdgeNode* AdjList[MAXV] = {0};  //每个顶点一个链表头，初始全 NULL

    addEdge(AdjList, 0, 1); addEdge(AdjList, 1, 0);
    addEdge(AdjList, 1, 2); addEdge(AdjList, 2, 1);
    addEdge(AdjList, 3, 4); addEdge(AdjList, 4, 3);

    DFSTraverse(AdjList, n);
    return 0;
}
