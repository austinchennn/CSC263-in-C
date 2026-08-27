## Graph Representations — Complexity

- 设 |V| = n（顶点数），|E| = m（边数）
- 两种常见操作
  - Edge Query（边查询）— 给定顶点 u、v，返回 G 中是否存在边 (u, v) 或 (v, u)
  - Neighbourhood（邻域查询）— 给定顶点 v，返回所有满足 (u, v) ∈ E 的顶点 u 组成的集合

| | Adjacency Matrix | Adjacency Lists |
|---|---|---|
| Space Complexity | Θ(n²) | Θ(n + m) |
| Add/Remove a Vertex | Θ(n) | Θ(1)（增加）；Θ(m)（删除） |
| Edge Query | Θ(1) | O(n) ~ O(min(m, n)) |
| Neighbourhood | Θ(n) | O(n) ~ O(min(m, n)) |
