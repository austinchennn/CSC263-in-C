## Hash Table — 定义

- 前置问题：像 Priority Queue 一样，我们希望能有一种数据结构支持 Θ(1) 的字典操作（Insert / Search / Delete），而无序数组虽然 Insert 是 Θ(1) 但 Search/Delete 是 Θ(n)，BST 虽然三者都是 Θ(h) 但最坏情况下 h 可退化为 Θ(n) ——Hash Table 就是为了解决“如何让字典操作在平均情况下逼近 Θ(1)”这一需求而设计的

### Universe（全集）

- Universe U：所有可能出现的 key 组成的集合

### Hash Function（哈希函数）

- 一个将 key 全集映射到 0 到 m − 1 之间整数的函数
  h : U → {0, 1, ..., m − 1}

### Hash Table（哈希表）

- 一个包含长度为 m 的数组 T 以及一个哈希函数 h 的数据结构
- h(k) 将 key k 映射到哈希表 T 的 m 个位置之一，即 h(k) 就是 key k 存储的下标
- 数组中的每个位置称为一个 slot（槽）或 bucket（桶）

### Collision（碰撞）

- 若 m ≥ |U|，则存在一个哈希函数 h 可以将每个 key 映射到唯一的 slot，这样的函数称为 perfect hash function（完美哈希函数）
- 实际情况中，可能出现的 key 的数量通常远大于数组的 slot 数量
- 若 m < |U|，则至少会发生一次 collision（碰撞）

## Chaining（链式法）— 定义

- Chaining 是解决 collision 的一种方式：数组中每个 bucket 都指向一个存储 key-value 对的链表（linked list）
