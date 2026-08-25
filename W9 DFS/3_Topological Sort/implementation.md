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
