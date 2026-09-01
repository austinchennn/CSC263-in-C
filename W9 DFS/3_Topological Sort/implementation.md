## Topological Sort — Implementation（实现）

### TopologicalSort(G)

- 实现
  ```
  TopologicalSort(G):
  1. 调用 DFS(G)
  2. 在 DFS 过程中确保 G 不含有环；一旦在任意时刻检测到环，返回一个空链表
  3. 每当一个顶点完成（finished）时，将其插入到某个链表的头部
  4. 返回该顶点链表
  ```
- 最坏情况运行时间：Θ(n + m)（见 [complexity.md](complexity.md)）
- NOTE：拓扑排序与通常意义上的排序（sorting）不同

### 配套代码

- [toposort.c](toposort.c)：`topoSort()`——DFS，每个顶点完成时前插到 `order[]`；遇到指向 Grey 顶点的边则判定有环、返回 -1
- [main.c](main.c)：一张 DAG + 一张有环图各跑一遍。依赖 `../1_DFS/DFS with Timestamps/` 的 `graph.*` / `dfs.h`，编译命令见 [README.md](README.md)
