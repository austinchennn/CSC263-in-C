## Accounting Method — Implementation（实现）

### 例子：Augmented Stack

- 操作定义
  - `Push(S, x)` — 把对象 x 压入栈 S，实际代价为 1
  - `Pop(S)` — 弹出栈 S 的栈顶对象并返回；对空栈调用 Pop 会产生错误，实际代价为 1
  - `MultiPop(S, k)` — 移除栈 S 顶部的 k 个对象（若栈中元素个数少于 k，则弹出整个栈），实际代价为 min(n, k)，其中 n 是当前栈的元素个数

### Step 1：为所有操作分配摊还代价

  ```
  Push 的摊还代价：2
  Pop 的摊还代价：0
  MultiPop 的摊还代价：0
  ```

### Step 2：证明对所有 k ∈ Z+ 及所有可能的序列，Σ a_i ≥ Σ c_i

- 证明
  ```
  用一张一元纸币代表一单位代价。
  当我们 Push 一个对象 x 时，用 1 元支付 Push 的实际代价，x 身上还剩下 1 元的信用（credit）。
  当对 x 执行 Pop 或 MultiPop 时，就用之前存在 x 身上的信用来支付这次操作的代价。
  不可能弹出一个从未被压入过的元素。
  所以对于任意可能的操作序列，栈中所有对象的信用总和始终非负。
  信用总和 = 摊还代价总和 − 实际代价总和。
  因此，对任意由 k 个 Push、Pop、MultiPop 组成的操作序列，都有：
      (Σ_{i=1}^{k} a_i − Σ_{i=1}^{k} c_i) ≥ 0
  即 Σ_{i=1}^{k} a_i ≥ Σ_{i=1}^{k} c_i 恒成立。
  ```

### Step 3：基于摊还代价求 T^{sq}_m 的上界

  ```
  T^{sq}_m = Σ_{i=1}^{m} c_i ≤ Σ_{i=1}^{m} a_i ≤ Σ_{i=1}^{m} 2 = 2m
  ⟹ T^{sq}_m / m ≤ 2m / m
  ⟹ T^{sq}_m / m ∈ O(1)
  ```

- 结论：Stack（配合 Push / Pop / MultiPop）的摊还序列复杂度为 O(1)
