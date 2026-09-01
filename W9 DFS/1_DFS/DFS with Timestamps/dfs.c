#include "dfs.h"
#include <stdlib.h>

/* DFS(G)：时间戳版本，见 1_DFS/。scc.c 也复用它求完成时间。 */

/*
 * DfsCtx：把递归过程中要「共享的一堆状态」打包成一个结构体。
 * 否则 dfsVisit 每次递归都得把 g、d、f、pred、color、time 六个参数一路传下去。
 * 现在只传一个指针 c，所有递归调用操作的都是同一份 DfsCtx。
 */
typedef struct {
    const Graph *g;        /* 图（只读，所以加 const） */
    int *d, *f, *pred;     /* 调用方传进来的三个数组：发现时间 / 完成时间 / 父节点 */
    Color *color;          /* 每个顶点的颜色，dfsRun 里 malloc 出来 */
    int time;              /* 全局时间戳，每染一次色 +1 */
} DfsCtx;

/*
 * 关于 c->xxx 这个写法：
 *   c 是一个指针（DfsCtx *），指向那份共享状态。
 *   c->time  等价于  (*c).time  —— 先解引用拿到结构体，再取它的 time 字段。
 *   ".": 变量是结构体本身时用；  "->": 变量是指向结构体的指针时用。
 * 所以 c->time++  就是「把 c 指向的那个结构体里的 time 字段加 1」。
 */
static void dfsVisit(DfsCtx *c, int s) {
    c->time++;                 /* 时间戳前进一步 */
    c->d[s] = c->time;         /* 记录顶点 s 的发现时间（第一次访问到 s） */
    c->color[s] = GREY;        /* 灰 = 正在处理（已发现，子树还没走完） */

    /* c->g->adj[s]：c 指向的结构体里的 g 字段（也是指针），再取 g 的 adj 数组第 s 项 */
    for (EdgeNode *e = c->g->adj[s]; e != NULL; e = e->next) {
        int t = e->dest;                  /* 边 s -> t 的另一端 */
        if (c->color[t] == WHITE) {       /* 白 = 还没访问过，才递归进去 */
            c->pred[t] = s;               /* 记 t 在 DFS 森林里的父节点是 s */
            dfsVisit(c, t);               /* 递归：注意传的还是同一个 c */
        }
    }

    c->color[s] = BLACK;      /* 黑 = s 的整棵子树都处理完了 */
    c->time++;
    c->f[s] = c->time;        /* 记录顶点 s 的完成时间 */
}

void dfsRun(const Graph *g, int *d, int *f, int *pred) {
    /* c 是栈上的一个 DfsCtx 结构体（不是指针），所以这里用 "." 赋值字段 */
    DfsCtx c;
    c.g = g;
    c.d = d;
    c.f = f;
    c.pred = pred;
    c.color = (Color *)malloc(sizeof(Color) * (size_t)g->n);
    c.time = 0;

    for (int v = 0; v < g->n; v++) {
        c.color[v] = WHITE;
        pred[v] = DFS_NIL;
        d[v] = f[v] = 0;
    }
    for (int s = 0; s < g->n; s++) {
        /* &c 取结构体的地址，传进去就是 DfsCtx *，函数里再用 c->xxx 访问 */
        if (c.color[s] == WHITE) dfsVisit(&c, s);
    }
    free(c.color);
}
