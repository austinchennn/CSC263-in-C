## Aggregate Method — Complexity

- 对 Dynamic Array 的 m 次 Append 操作序列：

| 量 | 结果 |
|---|---|
| Σ_{i=1}^{m} T(i)（总代价） | m + 2^{⌊log2 m⌋+1} − 1 ∈ Θ(m) |
| T^{sq}_m | Σ_{i=1}^{m} T(i) ∈ Θ(m) |
| T^{sq}_m / m（摊还序列复杂度） | Θ(1) |

- 即：用 Aggregate Method 证明了 Dynamic Array 的 Append 操作，其摊还序列复杂度为 Θ(1)，与直觉描述（1_Dynamic Arrays and Amortized Analysis 中的结论）一致
