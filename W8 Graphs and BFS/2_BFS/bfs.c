#include "bfs.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum { WHITE, GREY, BLACK } Color;

/**
 * @brief 广度优先搜索。对照 2_BFS/implementation.md 的伪代码：
 *        白=未入队，灰=已入队待处理，黑=邻居全部入队完毕。
 *
 * 队列用一个长度 n 的数组实现（每个顶点最多入队一次，容量足够）。
 */
void bfs(const Graph *g, int s, int *dist, int *pred) {
    Color *color = (Color *)malloc(sizeof(Color) * (size_t)g->n);
    for (int v = 0; v < g->n; v++) {
        color[v] = WHITE;
        dist[v] = BFS_INF;
        pred[v] = BFS_NIL;
    }

    int *queue = (int *)malloc(sizeof(int) * (size_t)g->n);
    int head = 0, tail = 0;

    color[s] = GREY;
    dist[s] = 0;
    queue[tail++] = s;

    while (head < tail) {
        int u = queue[head++];
        for (EdgeNode *e = g->adj[u]; e != NULL; e = e->next) {
            int v = e->dest;
            if (color[v] == WHITE) {
                color[v] = GREY;
                dist[v] = dist[u] + 1;   /* v 比 u 远一层 */
                pred[v] = u;
                queue[tail++] = v;
            }
        }
        color[u] = BLACK;
    }

    free(queue);
    free(color);
}

/**
 * @brief 打印 s -> t 的最短路径（递归沿 pred 回溯）。
 */
void printPath(const int *pred, int s, int t) {
    if (t == s) {
        printf("%d", s);
    } else if (pred[t] == BFS_NIL) {
        printf("(%d 不可达)", t);
    } else {
        printPath(pred, s, pred[t]);
        printf(" -> %d", t);
    }
}
