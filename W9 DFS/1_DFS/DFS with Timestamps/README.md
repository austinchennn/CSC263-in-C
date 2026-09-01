# DFS with Timestamps（CLRS DFS(G)）

带发现 / 完成时间戳的 DFS，`2_Cycle Detection/`、`3_Topological Sort/`、
`4_Strongly Connected Components/` 都建在这份代码上。

比 `../Adjacency List Implementation/` 的极简版多的东西：
- `Graph` 结构体（`n` / `m` / `directed` / `adj`），一个指针带着所有信息
- 三色 WHITE / GREY / BLACK（区分「祖先」和「已完成的旁支」，环检测要用）
- `d[]` 发现时间、`f[]` 完成时间、`pred[]` DFS 森林父节点
- `transposeGraph`（SCC 第 2 趟要在 G^T 上跑）

| 文件 | 内容 |
|---|---|
| `graph.h` / `graph.c` | 邻接表 `Graph` + `createGraph` / `addEdge` / `freeGraph` / `printGraph` / `transposeGraph` |
| `dfs.h` / `dfs.c` | `dfsRun()`：三色 + 全局时间戳，回填 `d[]` / `f[]` / `pred[]` |
| `main.c` | 一张有向图跑一遍，打印发现 / 完成时间 |

时间复杂度 Θ(n + m)。

## 编译运行

```sh
cc -Wall -Wextra graph.c dfs.c main.c -o demo && ./demo
```
