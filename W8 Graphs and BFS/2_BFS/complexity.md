## BFS — Complexity

- 使用 Adjacency List 表示图，设 |V| = n，|E| = m

| 操作 | 单次成本 | 总成本 |
|---|---|---|
| 访问每个顶点（Enqueue、Dequeue、赋值 v.colour / v.d / v.p 等） | Θ(1) | Θ(n) |
| 检查每个顶点的所有邻居（每条边最多被检查两次） | Θ(1) | Θ(m) |

- 总运行时间：Θ(n + m)
