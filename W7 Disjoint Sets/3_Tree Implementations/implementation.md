## Tree Implementations — Implementation（实现）

### Trees

#### MakeSet

- 实现
  ```
  MakeSet(DS, v): 创建一棵树，节点 x 存储元素 v
      x.p = x    # 根节点指向自己
  ```
- 最坏情况运行时间：Θ(1)

#### FindSet

- 实现
  ```
  FindSet(DS, x): 沿着 parent 指针一路向上，直到到达根节点 r
      r = x
      while r.p != r:
          r = r.p
      return r
  ```
- 最坏情况运行时间：Θ(h)，其中 h 是包含 x 的树的高度；最坏情况下树退化成一条链，Θ(h) ~ Θ(n)

#### Union

- 实现
  ```
  Union(DS, x, y):
  1. 分别找到 x、y 所在树的根节点
     l1 = FindSet(DS, x)
     l2 = FindSet(DS, y)
  2. 让其中一棵树的根指向另一棵树的根
     l1.p = l2
  ```
- 最坏情况运行时间：Θ(h1 + h2)

#### 摊还分析（"坏序列"）

- 依次执行：m/4 次 MakeSet，然后 m/4 − 1 次 Union，然后 m/2 + 1 次 FindSet
- 经过 m/4 次 MakeSet 和 m/4 − 1 次 Union 后，如果每次都把新树接到已有链的末端，会形成一条长度为 m/4 的长链（树退化成链表）
- 对于 (m/2 + 1) 次 FindSet，每次最坏情况下都要走完整条链，总运行时间为 (m/4)(m/2 + 1) ∈ Θ(m²)
- 因此 T^sq_m ∈ Θ(m²)，即 T^sq_m / m ∈ Θ(m)

### Trees with Union-by-rank

#### MakeSet

- 实现
  ```
  MakeSet(DS, v): 创建一棵树，节点 x 存储元素 v
      x.p = x
      x.rank = 0
  ```
- 最坏情况运行时间：Θ(1)

#### FindSet

- 实现
  ```
  FindSet(DS, x): 沿着 parent 指针一路向上，直到到达根节点 r
      r = x
      while r.p != r:
          r = r.p
      return r
  ```
- 最坏情况运行时间：Θ(h) ~ Θ(log n)（有了 union-by-rank 之后，树的高度被限制住了，见下方定理）

#### Union

- 实现
  ```
  Union(DS, x, y):
  1. 分别找到 x、y 所在树的根节点
     l1 = FindSet(DS, x)
     l2 = FindSet(DS, y)
  2. 让 rank 较小的根指向 rank 较大的根
     如果两个根的 rank 相等：
         任选一个作为新的根
         新根的 rank += 1
  ```
- 最坏情况运行时间：Θ(h1 + h2)

#### 摊还分析

- 定理：设 T 是由一系列 MakeSet 和使用 union-by-rank 启发式的 Union 操作生成的树，r 是 T 的 rank，n 是 T 中的节点数，则 2^r ≤ n，即 r ≤ log2 n
- 因此这类操作序列中的每个操作最坏情况下开销至多为 Θ(log n)
- 对于 m/4 = n 次 MakeSet，然后 m/4 − 1 次 Union，然后 m/2 + 1 次 FindSet 构成的序列：
  - T^sq_m ∈ Θ(m log m)，即 T^sq_m / m ∈ Θ(log m)

### Trees with Path-Compression

#### MakeSet

- 实现
  ```
  MakeSet(DS, v): 创建一棵树，节点 x 存储元素 v
      x.p = x
  ```
- 最坏情况运行时间：Θ(1)

#### FindSet

- 实现
  ```
  FindSet(DS, x):
  1. 记录从 x 到根节点路径上经过的所有节点
     path = []
     r = x
     while r.p != r:
         path.append(r)
         r = r.p
  2. 把刚才记录下的所有节点都直接指向根节点 r    # path compression
     for node in path:
         node.p = r
     return r
  ```
- 最坏情况运行时间：Θ(h)（单次调用仍需先走到根节点，因此最坏情况不变；改进体现在摊还复杂度上）

#### Union

- 实现
  ```
  Union(DS, x, y):
  1. 分别找到 x、y 所在树的根节点
     l1 = FindSet(DS, x)
     l2 = FindSet(DS, y)
  2. 让其中一棵树的根指向另一棵树的根
     l1.p = l2
  ```
- 最坏情况运行时间：Θ(h1 + h2)

#### 摊还分析

- 对于一个含 n 次 MakeSet（因此至多 n − 1 次 Union）和 f 次 FindSet 的操作序列：
  - T^sq_m ∈ Θ(n + f × (1 + log_{2 + f/n} n))
- 直觉：随着 FindSet 被反复调用，路径上的节点不断被压缩、直接挂到根节点下，树会越来越"扁平"，后续 FindSet 的开销也随之下降

### Trees with Union-by-Rank and Path-Compression

- 同时使用上面两种启发式：Union 时按 rank 合并，FindSet 时做路径压缩
- NOTE：path compression 会改变节点的实际深度，但不会同步更新 rank——因此在这个组合版本里，rank 不再精确等于高度，只是高度的一个上界

#### MakeSet

- 实现
  ```
  MakeSet(DS, v): 创建一棵树，节点 x 存储元素 v
      x.p = x
      x.rank = 0
  ```
- 最坏情况运行时间：Θ(1)

#### FindSet

- 实现
  ```
  FindSet(DS, x):
  1. 记录从 x 到根节点路径上经过的所有节点
     path = []
     r = x
     while r.p != r:
         path.append(r)
         r = r.p
  2. 把记录下的所有节点都直接指向根节点 r    # path compression
     for node in path:
         node.p = r
     return r
  ```
- 最坏情况运行时间：Θ(h)

#### Union

- 实现
  ```
  Union(DS, x, y):
  1. 分别找到 x、y 所在树的根节点
     l1 = FindSet(DS, x)
     l2 = FindSet(DS, y)
  2. 让 rank 较小的根指向 rank 较大的根        # union-by-rank
     如果两个根的 rank 相等：
         任选一个作为新的根
         新根的 rank += 1
  ```
- 最坏情况运行时间：Θ(h1 + h2)

#### 摊还分析

- 对于一个含 m 次操作、其中有 n 次 MakeSet（因此至多 n − 1 次 Union）的序列：
  - T^sq_m ∈ O(m × α(n))，其中 α(n) 是反阿克曼函数
  - α(n) 增长得极其缓慢，对于任何实际场景中可能遇到的 n，α(n) 都不超过 4~5，可以视为常数
  - 因此 T^sq_m ∈ O(m)——这是四种树实现中摊还性能最好的一种
