## Strongly Connected Components — Implementation（实现）

### STRONGLY-CONNECTED-COMPONENTS(G)

- 实现
  ```
  STRONGLY-CONNECTED-COMPONENTS(G):
  1. 调用 DFS(G)，计算每个顶点 u 的完成时间 u.f
  2. 计算 G^T
  3. 调用 DFS(G^T)，但在 DFS 的主循环中，按第 1 步中计算出的 u.f 递减顺序来考虑各个顶点
  4. 将第 3 步得到的 depth-first forest 中，每一棵树的顶点集合输出为一个独立的 strongly connected component
  ```
- 最坏情况运行时间：Θ(n + m)（见 [complexity.md](complexity.md)）

### 配套代码

- [scc.c](scc.c)：`sccCount()`——第 1 趟 `dfsRun` 求完成时间，`transposeGraph` 得 G^T，第 2 趟按完成时间递减在 G^T 上 DFS；回填 `comp[]`，返回分量数
- [main.c](main.c)：CLRS 8 顶点示例图，打印每个 SCC。依赖 `../1_DFS/Adjacency List Implementation/` 的 `graph.*` / `dfs.*`，编译命令见 [README.md](README.md)
