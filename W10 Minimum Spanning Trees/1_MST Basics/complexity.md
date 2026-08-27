## Initial Implementation — Complexity

一个有 n 个顶点的无向图最多有 n(n−1)/2 条边

| Approach | Idea | Worst-case Edges Processed |
|---|---|---|
| Deletion-based | T.E 从 G.E 开始，不断删除边，直到只剩下一个 MST | n(n−1)/2 − (n−1) ∈ Θ(n²) 条边被删除 |
| Addition-based | T.E 从空集开始，不断添加边，直到构建出一个 MST | n − 1 ∈ Θ(n) 条边被添加 |
