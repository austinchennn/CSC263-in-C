#include <stdio.h>
#include <stdbool.h>

#define MAXV 100
bool visited[MAXV];  //标记每个点是否被访问，默认false
/*
 * DFS：深度优先搜索（邻接矩阵版）
 * G: 邻接矩阵
 * n: 顶点数
 * u: 起始顶点
 *
 * 时间复杂度：
 *   - 单次 DFS(u)：下面的 for 循环固定扫矩阵的一整行 v = 0..n-1，
 *     不管 u 实际有几条边，都是 Θ(n)。
 *   - visited[] 保证每个顶点最多作为参数进入 DFS 一次，所以 DFS 总共被调用 n 次。
 *   - 合计 n × Θ(n) = Θ(n²)。
 *   （对比邻接表版：只扫真实存在的边，是 Θ(n + m)。矩阵版慢在“扫整行找邻居”。）
 *
 * 空间复杂度：矩阵 G 本身 Θ(n²)，加上 visited[] Θ(n) 和递归栈最深 Θ(n)。
 */
void DFS(int G[MAXV][MAXV], int n, int u){
    //不撞南墙不回头

    //1.访问定点u —— O(1)
    printf("%d ", u);
    visited[u] = true;  //标记顶点u已访问

    //2.扫第 u 行找未访问的邻接顶点 v，递归下去 —— 每次调用固定 Θ(n)
    for(int v = 0; v < n; v++){
        if(G[u][v] == 1 && !visited[v]){  //u和v相邻且v未被访问
            DFS(G, n, v);  //让他作为新的起始顶点v递归调用DFS函数
        }
    }
}
 