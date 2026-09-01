# Cycle Detection（有向图）

| 文件 | 内容 |
|---|---|
| `cycle.c` | `hasCycle()`：DFS 遍历中遇到指向 Grey 顶点的边即判定有环 |
| `main.c` | 一张有环图 + 一张 DAG 各跑一遍 |

依赖 `../1_DFS/Adjacency List Implementation/` 的 `graph.*` / `dfs.h`。

## 编译运行

```sh
cc -Wall -Wextra "../1_DFS/Adjacency List Implementation/graph.c" cycle.c main.c -o demo && ./demo
```
