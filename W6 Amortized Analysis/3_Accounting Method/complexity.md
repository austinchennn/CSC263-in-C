## Augmented Stack — Complexity

| 操作 | 说明 | 实际代价（actual cost） | 摊还代价（amortized cost） |
|---|---|---|---|
| `Push(S, x)` | 把对象 x 压入栈 S | 1 | 2 |
| `Pop(S)` | 弹出并返回栈顶对象；对空栈调用会报错 | 1 | 0 |
| `MultiPop(S, k)` | 移除栈顶的 k 个对象（若栈中元素少于 k 个，则弹出整个栈） | min(n, k) | 0 |

## Amortized Analysis — Complexity

| 分析角度 | 结果 |
|---|---|
| Worst-Case Sequence Complexity（m 次 Push/Pop/MultiPop） | T^{sq}_m ≤ Σ_{i=1}^{m} a_i ≤ 2m |
| Amortized Sequence Complexity | T^{sq}_m / m ∈ O(1) |

- 即：单次 MultiPop 最坏情况下代价可以高达 Θ(n)，但由于每个元素最多只能被 Push 一次、Pop（或 MultiPop）一次，摊还到整个序列中，平均每次操作只需 O(1)
