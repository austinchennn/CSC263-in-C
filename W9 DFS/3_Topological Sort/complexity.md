## Topological Sort — Complexity

| 步骤 | 复杂度 |
|---|---|
| Step 1: 调用 DFS(G) | Θ(n + m) |
| Step 2-3: 每完成一个顶点，就将其插入链表头部（每次 Θ(1)） | Θ(n) |
| 总运行时间 | Θ(n + m) |

NOTE：源材料未显式给出 TopologicalSort 整体的复杂度；此表格是基于 DFS 本身 Θ(n + m) 的复杂度（见 [DFS complexity.md](../1_DFS/complexity.md)）与"每个顶点完成时插入链表头部为 Θ(1)"这一操作直接推出的
