## Amortized Analysis — 定义

- 摊还分析（Amortized Analysis）要回答的问题：某些单次操作在最坏情况下代价很高，但如果把这次操作放到一个长的操作**序列**中来看，这种"最坏情况"是不是过于悲观？摊还分析试图刻画的是：在一个由 m 个操作组成的序列中，平均每次操作实际需要付出的代价
- NOTE：摊还分析只考虑（最坏情况下的）一整个操作序列，不涉及任何概率假设 —— 这一点区别于 average-case analysis（平均情况分析）

## Dynamic Array（动态数组）— 定义

- 记号
  - n — 数组中当前已存储的元素个数
  - k — 数组当前分配到的容量（大小）
  - 初始假设：从 k = 1，n = 0 开始
- 操作
  - `Append(A1, x)` — 把元素 x 存入数组 A1 的第一个空闲位置；若 A1 已满（n == k），则先创建一个大小为 A1 两倍的新数组 A2，把 A1 中所有元素复制到 A2，再把 x 接到 A2 末尾（完整算法见 [implementation.md](implementation.md)）

## Worst-Case Sequence Complexity / Amortized Sequence Complexity — 定义

- Worst-Case Sequence Complexity（序列的最坏情况复杂度）：对一个包含 m 个操作的序列，在最坏情况下完成这 m 个操作所需的总代价，记作 T^{sq}_m，其中 m 是序列中操作的个数
- Amortized Sequence Complexity（摊还序列复杂度）：把最坏情况总代价平均分摊到每一次操作上
  ```
  Amortized Sequence Complexity = (worst-case sequence complexity) / m = T^{sq}_m / m
  ```
- 结论：对 Dynamic Array 反复执行 Append 操作，其摊还序列复杂度为 Θ(1)（尽管单次 Append 最坏情况下需要 Θ(n) 时间来扩容并复制元素）
  - 具体证明见 2_Aggregate Method 与 3_Accounting Method 两种不同的证明技巧
