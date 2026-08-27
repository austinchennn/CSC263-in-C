## Dynamic Array — Complexity

- 例：从 k = 1, n = 0 开始，依次执行 Append，插入 10, 20, 5, 7, 9：数组每次被填满就翻倍，容量变化为 k = 1 → 2 → 4 → 4 → 8，对应 n = 1, 2, 3, 4, 5
- 第 n 次 Append 操作的最坏情况代价 T(n)：

| n 是否为 2 的幂 | 是否触发扩容（resize + copy） | T(n) |
|---|---|---|
| 是 | 是 | 1 + n |
| 否 | 否 | 1 |

## Amortized Analysis — Complexity

| 分析角度 | 结果 |
|---|---|
| 单次 Append（最坏情况） | Θ(n)（触发扩容时，需要复制全部 n 个已有元素） |
| Worst-Case Sequence Complexity（m 次 Append） | T^{sq}_m ∈ Θ(m) |
| Amortized Sequence Complexity | T^{sq}_m / m ∈ Θ(1) |

- 即：单次 Append 最坏情况看起来是 Θ(n)，但由于扩容操作在整个序列中出现得足够稀疏（容量按指数增长），把总代价摊到每次操作上，平均下来只有 Θ(1)
