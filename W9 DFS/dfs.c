#include "dfs.h"
#include <stdlib.h>

/* DFS(G)：时间戳版本，见 1_DFS/。scc.c 也复用它求完成时间。 */

typedef struct {
    const Graph *g;
    int *d, *f, *pred;
    Color *color;
    int time;
} DfsCtx;

static void dfsVisit(DfsCtx *c, int s) {
    c->time++;
    c->d[s] = c->time;
    c->color[s] = GREY;

    for (EdgeNode *e = c->g->adj[s]; e != NULL; e = e->next) {
        int t = e->dest;
        if (c->color[t] == WHITE) {
            c->pred[t] = s;
            dfsVisit(c, t);
        }
    }

    c->color[s] = BLACK;
    c->time++;
    c->f[s] = c->time;
}

void dfsRun(const Graph *g, int *d, int *f, int *pred) {
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
        if (c.color[s] == WHITE) dfsVisit(&c, s);
    }
    free(c.color);
}
