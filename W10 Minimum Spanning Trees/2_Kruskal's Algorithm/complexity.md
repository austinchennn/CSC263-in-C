## Kruskal's Algorithm — Complexity

前置假设：Disjoint-Sets 用带 union-by-rank 和 path-compression 的树实现

| 步骤 | 操作 | 复杂度 |
|---|---|---|
| 1 | 对边排序（Sorting edges） | O(m log m) |
| 2 | Line #3–#4 的 for 循环（MakeSet） | O(n) |
| 3 | Line #6–#10 的 for 循环（FindSet 与 Union） | O(m α(n)) ≈ O(m) |

总运行时间：O(n + m log m)

由于 m ≤ n(n−1)/2，有 m ∈ O(n²) ⟹ log m ∈ O(log n² = 2 log n) ∈ O(log n)

总运行时间：O(n + m log n)

若输入图是连通的（m ≥ n − 1 ⟹ n ∈ O(m)），运行时间为 O(m log n)
