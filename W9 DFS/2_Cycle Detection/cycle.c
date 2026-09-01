#include "../1_DFS/Adjacency List Implementation/dfs.h"
#include <stdlib.h>

/*
 * 环检测（有向图），见 2_Cycle Detection/。
 * DFS 过程中，若从当前 Grey 顶点看到一条指向另一个 Grey 顶点的边，
 * 这条边就是 back edge（指向祖先）——图中存在环。
 */

static bool cycleVisit(const Graph *g, int s, Color *color) {
    color[s] = GREY;
    for (EdgeNode *e = g->adj[s]; e != NULL; e = e->next) {
        int t = e->dest;
        if (color[t] == WHITE) {
            if (cycleVisit(g, t, color)) return true;
        } else if (color[t] == GREY) {
            return true;          /* back edge -> 有环 */
        }
        /* BLACK：forward / cross edge，不构成环 */
    }
    color[s] = BLACK;
    return false;
}

bool hasCycle(const Graph *g) {
    Color *color = (Color *)malloc(sizeof(Color) * (size_t)g->n);
    for (int v = 0; v < g->n; v++) color[v] = WHITE;

    bool found = false;
    for (int s = 0; s < g->n && !found; s++) {
        if (color[s] == WHITE) found = cycleVisit(g, s, color);
    }
    free(color);
    return found;
}
