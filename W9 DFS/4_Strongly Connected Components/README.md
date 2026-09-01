# Strongly Connected Components

| 文件 | 内容 |
|---|---|
| `scc.c` | `sccCount()`：第 1 趟 `dfsRun` 求完成时间，`transposeGraph` 得 G^T，第 2 趟按完成时间递减在 G^T 上 DFS；回填 `comp[]`，返回分量数 |
| `main.c` | CLRS 8 顶点示例图，打印每个 SCC |

依赖 `../1_DFS/DFS with Timestamps/` 的 `graph.*` / `dfs.*`（用到 `dfsRun` 和 `transposeGraph`）。

## 编译运行

```sh
cc -Wall -Wextra "../1_DFS/DFS with Timestamps/graph.c" "../1_DFS/DFS with Timestamps/dfs.c" scc.c main.c -o demo && ./demo
```
