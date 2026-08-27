## Aggregate Method — Implementation（实现）

### 通用步骤

- 实现（证明配方）
  ```
  Aggregate Method:
  1. 求出执行一个操作序列（最坏情况下）的总代价
     T^{sq}_m = Σ_{i=1}^{m} c_i
  2. 把总代价除以序列中操作的个数 m
     T^{sq}_m / m
  ```

### 推导：对 Dynamic Array 的 m 次 Append 求 T^{sq}_m

- 设 T(i) 为序列中第 i 次 Append 的最坏情况运行时间，令 T'(i) = T(i) − 1（即去掉每次操作都要付出的那 1 个单位的基础代价，只留下"扩容部分"的代价）
- 推导
  ```
  Σ_{i=1}^{m} T(i) = Σ_{i=1}^{m} (1 + T'(i))
                    = m + Σ_{i=1}^{m} T'(i)
                    = m + Σ_{j=0}^{⌊log2 m⌋} 2^j        # 因为 2^0 ≤ m ≤ 2^{log2 m}，
                                                          # 扩容代价恰好是 1, 2, 4, ..., 2^{⌊log2 m⌋} 这样的等比数列
                    = m + 2^{⌊log2 m⌋+1} − 1  ∈ Θ(m)
  ```
- 因此
  ```
  T^{sq}_m = Σ_{i=1}^{m} T(i) ∈ Θ(m)
  ⟹ T^{sq}_m / m ∈ Θ(1)
  ```
- 结论：Dynamic Array 的 Append 操作，摊还序列复杂度为 Θ(1)
