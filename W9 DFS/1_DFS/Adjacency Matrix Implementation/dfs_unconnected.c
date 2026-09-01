#include "dfs.c"

/*
 * DFSTraverse：对整张图做 DFS，覆盖所有顶点（非连通 / 有向不可达也不漏）。
 * 每次外层循环启动一次新的 DFS，就是发现了一个新的连通分量。
 */
void DFSTraverse(int G[MAXV][MAXV], int n){

    int cnt = 0;  //记录连通分量的个数

    for (int i = 0; i < n; i++) {//初始化标记数组
        visited[i] = false;
    }

    //枚举每一个点，对尚未访问的点调用DFS函数
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(G, n, i);
            cnt++;  //从 i 起又走了一棵 DFS 树 -> 一个新的连通分量
        }
    }

    printf("\n该图有 %d 个连通分量\n", cnt);
}

int main(void){
    //示例：6 个顶点，3 个连通分量 {0,1,2} {3,4} {5}
    int n = 6;
    int G[MAXV][MAXV] = {0};
    G[0][1] = G[1][0] = 1;
    G[1][2] = G[2][1] = 1;
    G[3][4] = G[4][3] = 1;

    DFSTraverse(G, n);
    return 0;
}
