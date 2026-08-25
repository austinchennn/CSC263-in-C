## DFS — Complexity

- 使用 adjacency list 时的总工作量

| 步骤 | 说明 | 复杂度 |
|---|---|---|
| 访问每个顶点 | 为 v.colour、v.d、v.p 等赋值 | Θ(1)（每个顶点），总计 Θ(n) |
| 检查每个顶点的邻居 | 每条边最多被检查两次 | Θ(1)（每条边），总计 Θ(m) |

- 总运行时间：Θ(n + m)

NOTE：|V| = n，|E| = m；若使用 adjacency matrix 而非 adjacency list，最坏情况运行时间为 Θ(n²)
