#include "../1_DFS/Adjacency List Implementation/dfs.h"
#include <stdlib.h>

/*
 * 拓扑排序，见 3_Topological Sort/。
 * 对 DAG 做 DFS，每个顶点「完成」时把它插到结果链表头部；
 * 全部完成后，链表即为一个拓扑序（等价于按完成时间 f 递减排列）。
 * 过程中若遇到指向 Grey 顶点的边 -> 有环 -> 无拓扑序。
 */

typedef struct {
    const Graph *g;
    Color *color;
    int *order;
    int pos;          /* 下一个写入位置，从 n-1 往前（完成即前插） */
    bool cyclic;
} TopoCtx;

static void topoVisit(TopoCtx *c, int s) {
    c->color[s] = GREY;
    for (EdgeNode *e = c->g->adj[s]; e != NULL; e = e->next) {
        int t = e->dest;
        if (c->color[t] == WHITE) {
            topoVisit(c, t);
        } else if (c->color[t] == GREY) {
            c->cyclic = true;
        }
    }
    c->color[s] = BLACK;
    c->order[c->pos--] = s;
}

int topoSort(const Graph *g, int *order) {
    TopoCtx c;
    c.g = g;
    c.order = order;
    c.pos = g->n - 1;
    c.cyclic = false;
    c.color = (Color *)malloc(sizeof(Color) * (size_t)g->n);
    for (int v = 0; v < g->n; v++) c.color[v] = WHITE;

    for (int s = 0; s < g->n; s++) {
        if (c.color[s] == WHITE) topoVisit(&c, s);
    }
    free(c.color);
    return c.cyclic ? -1 : 0;
}
