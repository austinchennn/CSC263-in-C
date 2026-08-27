## Linked List Implementations — Implementation（实现）

### Circularly-Linked Lists

#### MakeSet

- 实现
  ```
  MakeSet(DS, v): 创建一个新的循环链表，节点 x 存储元素 v
      x.next = x
  ```
  （NOTE：源材料原文写的是 "set x.next = v"，但结合上下文——单节点循环链表的头节点应当指向自己以形成环——这里应为 `x.next = x`，疑似源材料笔误，此处按照循环链表的定义改写）
- 最坏情况运行时间：Θ(1)

#### FindSet

- 实现
  ```
  FindSet(DS, x): 沿着 next 指针走，直到回到头节点 r
      r = x
      while r 不是头节点:
          r = r.next
      return r
  ```
- 最坏情况运行时间：Θ(L)，其中 L 是包含 x 的链表的长度

#### Union

- 实现
  ```
  Union(DS, x, y):
  1. 分别找到 x、y 所在链表的头节点
     l1 = FindSet(DS, x)
     l2 = FindSet(DS, y)
  2. 交换 l1.next 和 l2.next，把两个循环链表拼接成一个
     l1.next, l2.next = l2.next, l1.next
  ```
- 最坏情况运行时间：Θ(L1 + L2)

#### 摊还分析（"坏序列"）

- 考虑依次执行：m/4 次 MakeSet，然后 m/4 − 1 次 Union，然后 m/2 + 1 次 FindSet
- 经过 m/4 次 MakeSet 和 m/4 − 1 次 Union 后，会形成一个大小为 m/4 的链表
- 之后每次 FindSet 最坏情况下运行时间为 Θ(m/4)，(m/2 + 1) 次 FindSet 总运行时间为 (m/2 + 1) × Θ(m/4) ∈ Θ(m²)
- m/4 次 MakeSet 总运行时间为 Θ(m)
- (m/4 − 1) 次 Union 总运行时间为 1 + 2 + ... + (m/4 − 1) ∈ Θ(m²)
- 因此 T^sq_m ∈ Θ(m²)，即 T^sq_m / m ∈ Θ(m)

### Linked Lists with Pointer to Head

#### MakeSet

- 实现
  ```
  MakeSet(DS, v): 创建一个新链表，节点 x 存储元素 v
      x.rep = x
      x.tail = x
  ```
- 最坏情况运行时间：Θ(1)

#### FindSet

- 实现
  ```
  FindSet(DS, x):
      return x.rep
  ```
- 最坏情况运行时间：Θ(1)

#### Union

- 实现
  ```
  Union(DS, x, y):
  1. 把其中一个链表接到另一个链表的尾部
  2. 更新 tail 指针
  3. 把被接上的那条链表中所有节点的 rep 指针更新为新的头节点
  ```
- 最坏情况运行时间：Θ(L1 + L2)（更新 rep 指针需要遍历被接上的那条链表）

#### 摊还分析（"坏序列"）

- 考虑依次执行：m/2 + 1 次 MakeSet，然后 m/2 − 1 次 Union，且每次都把较长的链表接到只有单个元素的链表后面
- 更新 head 指针（rep）的总开销为 1 + 2 + ... + (m/2 − 1) ∈ Θ(m²)
- m/2 + 1 次 MakeSet 总运行时间为 Θ(m)
- 因此 T^sq_m ∈ Θ(m²)，即 T^sq_m / m ∈ Θ(m)
- NOTE：这里"坏序列"针对的瓶颈与 Circularly-Linked Lists 不同——问题不再是 FindSet 本身变慢，而是每次 Union 都要更新被接上那条链表里所有节点的 rep 指针，摊还开销依然是 Θ(m)，相比 Circularly-Linked Lists 没有本质改进

### Linked Lists with Pointer to Head and Union-By-Weight

#### MakeSet

- 实现
  ```
  MakeSet(DS, v): 创建一个新链表，节点 x 存储元素 v
      x.rep = x
      x.tail = x
      x.size = 1
  ```
- 最坏情况运行时间：Θ(1)

#### FindSet

- 实现
  ```
  FindSet(DS, x):
      return x.rep
  ```
- 最坏情况运行时间：Θ(1)

#### Union

- 实现
  ```
  Union(DS, x, y):
  1. 把较短的链表接到较长的链表尾部          # union-by-weight
  2. 更新 tail 指针
  3. 更新合并后新链表的 size
  4. 把被接上的那条（较短的）链表中所有节点的 rep 指针更新为新的头节点
  ```
- 最坏情况运行时间：Θ(L1 + L2)（与上一版本相同，最坏情况没有改进，改进的是摊还复杂度）

#### 摊还分析

- 考虑一个含 m 次操作的序列，设其中 MakeSet 操作有 n 次，因此序列中元素总数不会超过 n
- 对任意元素 x，想证明 x.rep 被更新的次数有上界
- x.rep 只有在 x 所在的集合与一个**不小于**它的集合合并时才会被更新（因为 union-by-weight 总是把短链表接到长链表上）
- 也就是说，x.rep 每被更新一次，合并后集合的大小至少翻倍
- 而元素总数只有 n 个，因此最多能翻倍 log n 次
- 所以 x.rep 被更新的次数不会超过 log n 次
- 对于 (m/2 + 1) = n 次 MakeSet，然后 m/2 − 1 次 Union 构成的序列：所有 x.rep 更新的总次数至多为 n log n；其余操作总运行时间为 Θ(m)
- 因此 T^sq_m ∈ Θ(m + n log n) ∈ Θ(m log m)，即 T^sq_m / m ∈ Θ(log m)
