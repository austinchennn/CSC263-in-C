## Chaining — Complexity

### Worst-Case Running Time

- 最坏情况：所有元素都被哈希到同一个 bucket 中 → Θ(n)，其中 n 是哈希表中存储的元素总数
- 假设哈希值 h(k) 的计算是常数时间 → Θ(1)

| Operation | Worst-Case |
|---|---|
| Search | Θ(n) |
| Insert | Θ(n) |
| Delete | Θ(n) |

### Average-Case Running Time（基于 SUHA）

- Simple Uniform Hashing Assumption（SUHA，简单均匀哈希假设）：任意 key 被哈希到任意 bucket 的概率相等
- 令 t_{m,n}(k) 表示 HashSearch 在一个含 m 个 bucket、存储 n 个元素的哈希表中查找 k 所需的步数
- Load Factor（负载因子）：α = n/m
- 在 SUHA 下：E[t_{m,n}(k)] = 1 + 在 L_i 中查找 k 的期望运行时间（其中 i = h(k) ∈ Θ(1)）

| Search 类型 | 关键公式 | 结果 |
|---|---|---|
| Unsuccessful（查找失败） | Pr[h(k) = i] = 1/m；E[len_i] = n/m；E[t_{m,n}(k)] = 1 + n/m = 1 + α | Θ(1 + α) |
| Successful（查找成功） | Pr[k = k_i] = 1/n；E[t_{m,n}(k)] = (1/n)·Σ_{i=1}^{n} S_i = 1 + n/(2m) − 1/m = 1 + α/2 − α/(2n) | Θ(1 + α) |

- NOTE：若 n/m ∈ Θ(1)（即 m 至少与 n 成正比），则平均情况运行时间也在 Θ(1) 之内
- 所有哈希表操作（Search / Insert / Delete）的平均情况运行时间均为 Θ(α + 1)
- 结论：只要哈希表 slot 数量至少与元素数量成正比，所有字典操作都可以在常数平均运行时间内实现
