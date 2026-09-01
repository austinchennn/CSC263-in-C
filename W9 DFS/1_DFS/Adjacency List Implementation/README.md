# Adjacency List Implementation

DFS(G) 的邻接表递归实现。`n` = 顶点数 |V|，`m` = 边数 |E|。

| 文件 | 内容 |
|---|---|
| `graph.h` / `graph.c` | 邻接表 `Graph` + `createGraph` / `addEdge` / `freeGraph` / `printGraph` / `transposeGraph`（SCC 用） |
| `dfs.h` / `dfs.c` | `dfsRun()`：三色 + 全局时间戳，回填 `d[]` / `f[]` / `pred[]` |
| `main.c` | 一张有向图跑一遍，打印发现 / 完成时间 |

环检测 / 拓扑排序 / SCC 在 `../../2_Cycle Detection/`、`../../3_Topological Sort/`、
`../../4_Strongly Connected Components/`，它们 `#include` 本目录的 `dfs.h`。

## 编译运行

```sh
cc -Wall -Wextra graph.c dfs.c main.c -o demo && ./demo
```
