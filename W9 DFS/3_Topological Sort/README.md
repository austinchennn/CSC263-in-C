# Topological Sort

| 文件 | 内容 |
|---|---|
| `toposort.c` | `topoSort()`：DFS，顶点完成时前插到 `order[]`；遇到指向 Grey 的边判定有环、返回 -1 |
| `main.c` | 一张 DAG + 一张有环图各跑一遍 |

依赖 `../1_DFS/Adjacency List Implementation/` 的 `graph.*` / `dfs.h`。

## 编译运行

```sh
cc -Wall -Wextra "../1_DFS/Adjacency List Implementation/graph.c" toposort.c main.c -o demo && ./demo
```
