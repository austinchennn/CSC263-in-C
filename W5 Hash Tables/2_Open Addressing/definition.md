## Open Addressing — 定义

- 前置问题：Chaining 需要为每个 bucket 额外维护链表结构（指针开销），Open Addressing 提供了另一种解决 collision 的思路——不使用额外的链表，而是把所有元素都直接存储在哈希表数组 T 本身之中
- 定义：所有元素都直接存储在 T 中（不使用 chaining）；若发生 collision，则按某种系统化的方式寻找另一个空闲位置，这个过程称为 probing（探测）
- NOTE：哈希表中存储的 key 数量不能超过数组的长度

### Search

- 沿用与 Insertion 相同的 probing 方式进行查找
- 当探测到第一个存储 None 的 bucket 时，Search 返回 None
- NOTE：查找一个元素往往需要检查不止一个位置

### Probing（探测）的三种方式

- Linear Probing（线性探测）：按线性序列检查 slot
  (h(k) + i) mod m，其中 i ≥ 0 为整数
- Quadratic Probing（二次探测）：按非线性序列检查 slot
  (h(k) + c1×i + c2×i²) mod m，其中 i ≥ 0 为整数
- Double Hashing（双重哈希）：使用第二个哈希函数生成依赖于 key 的步长
  (h1(k) + i × h2(k)) mod m，其中 i ≥ 0 为整数
