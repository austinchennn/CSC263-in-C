## Hash Function — 定义

- 前置问题：Chaining 和 Open Addressing 都假设已经有一个“足够好”的哈希函数 h（例如满足 SUHA），但 h(k) = k mod m 这样朴素的取法本身是否总是好用？这一节讨论如何设计 h 本身
- 常见的两种设计方式：Decision Method（Division Method，除法散列法）与 Multiplication Method（乘法散列法）

### Decision Method（Division Method，除法散列法）

- 定义：h(k) = k mod m

### Multiplication Method（乘法散列法）

- 定义：将 k 乘以一个 0 < A < 1 的实数常数，取乘积的小数部分 x（0 < x < 1），再令 h(k) = ⌊m × x⌋
