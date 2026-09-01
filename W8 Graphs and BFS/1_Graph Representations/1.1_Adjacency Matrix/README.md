# Adjacency Matrix Implementation

邻接矩阵表示图。`n` = 顶点数 |V|，`m` = 边数 |E|。

| 文件 | 内容 |
|---|---|
| `graph.h` / `graph.c` | `Graph` 结构体（`int **adj` 是 n×n 的 0/1 矩阵）、`createGraph` / `addEdge` / `freeGraph` / `printGraph` |
| `main.c` | 建有向 / 无向图各一个（和 `../1.2_Adjacency List/` 同一张图），打印矩阵 |

| | 邻接矩阵 | 邻接表 |
|---|---|---|
| 空间 | Θ(n²) | Θ(n + m) |
| Edge Query（u、v 间有无边） | Θ(1) | O(min(m, n)) |
| 列出一个顶点的邻居 | Θ(n) | O(该顶点度数) |

## 编译运行

```sh
cc -Wall -Wextra graph.c main.c -o demo && ./demo
```
