# Adjacency List Implementation

DFS 的邻接表版。和 `../Adjacency Matrix Implementation/` 结构对应。

| 文件 | 内容 |
|---|---|
| `edgenode.c` | 边节点 `EdgeNode` 定义（`adjvex` + `next`） |
| `dfs.c` | 递归 `DFS(AdjList, u)`：从 u 出发，只走可达顶点。单次 Θ(deg(u))，全程 Θ(n + m) |
| `dfs_unconnected.c` | `#include "dfs.c"`，加 `DFSTraverse()` 外层循环覆盖所有顶点 + 数连通分量 + `main` 演示 |

## 编译运行

```sh
cc -Wall -Wextra dfs_unconnected.c -o demo && ./demo
```
