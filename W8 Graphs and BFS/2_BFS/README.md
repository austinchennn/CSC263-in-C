# BFS Implementation

自包含：`graph.h` / `graph.c` 是 `1_Graph Representations/1.2_Adjacency List/` 的副本，方便这个目录单独编译。

| 文件 | 内容 |
|---|---|
| `graph.h` / `graph.c` | 邻接表（副本，改动请以 `1_Graph Representations/1.2_Adjacency List/` 为准） |
| `bfs.h` / `bfs.c` | `bfs()`：三色 + 定长数组队列，回填 `dist[]` / `pred[]`；`printPath()` 沿 `pred` 回溯 |
| `main.c` | CLRS 无向图跑一遍，输出各顶点距离与最短路径 |

## 编译运行

```sh
cc -Wall -Wextra graph.c bfs.c main.c -o demo && ./demo
```
