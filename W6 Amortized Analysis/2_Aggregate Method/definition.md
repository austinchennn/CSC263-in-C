## Aggregate Method — 定义

- Aggregate Method（聚合法）要解决的问题：如何**证明**一个操作序列的摊还序列复杂度确实是某个界（例如证明 Dynamic Array 的 Append 摊还复杂度是 Θ(1)），而不是仅仅停留在直觉描述上
- 做法分两步
  1. 求出执行一个操作序列（最坏情况下）的总代价
  2. 把总代价除以序列中操作的个数
- 记号
  - c_i — 序列中第 i 个操作的实际代价（actual cost）
  - 于是序列的总代价（即 Worst-Case Sequence Complexity）为
    ```
    T^{sq}_m = Σ_{i=1}^{m} c_i
    ```
- 摊还序列复杂度即为 T^{sq}_m / m（与 1_Dynamic Arrays and Amortized Analysis 中给出的定义一致）

## 应用：对 Dynamic Array 的 Append 使用 Aggregate Method

- 设序列由 m 次 Append 操作组成，T(i) 表示序列中第 i 次操作的最坏情况运行时间
- 目标：证明 Σ_{i=1}^{m} T(i) ∈ Θ(m)，从而 T^{sq}_m / m ∈ Θ(1)
- 具体推导（变量替换 T'(i) = T(i) − 1，再套用等比数列求和）见 [implementation.md](implementation.md)
