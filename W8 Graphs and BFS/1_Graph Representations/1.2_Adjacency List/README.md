# Adjacency List Implementation

邻接表表示图。`n` = 顶点数 |V|，`m` = 边数 |E|。

| 文件 | 内容 |
|---|---|
| `graph.h` / `graph.c` | `Graph` 结构体、`createGraph` / `addEdge` / `freeGraph` / `printGraph` |
| `main.c` | 建有向 / 无向图各一个，打印邻接表 |

## 编译运行

```sh
cc -Wall -Wextra graph.c main.c -o demo && ./demo
```
