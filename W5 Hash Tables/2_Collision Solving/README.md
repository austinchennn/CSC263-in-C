## Collision Solving（碰撞处理）— 总览

### 为什么会有碰撞

- 哈希函数 h : U → {0, 1, ..., m − 1} 把 key 从全集 U「压缩」到 m 个 slot
- 通常 |U| ≫ m，所以必然存在 k₁ ≠ k₂ 使 h(k₁) = h(k₂) —— 这就是 collision（碰撞）
- 「怎么设计 h」是另一件事，见 [1_Hash Function](../1_Hash%20Function/)；本节讨论「碰撞发生后怎么办」

### 两种解决思路

| | Chaining（链式法） | Open Addressing（开放定址） |
|---|---|---|
| 核心思路 | 每个 bucket 挂一条链表，碰撞的 key 都放进链表 | 所有元素直接存在数组 T 里，碰撞时按规则找下一个空 slot（probing） |
| 额外空间 | 每个节点多一个 next 指针 | 无额外指针 |
| load factor α = n/m | 可以 > 1（链表能无限长） | 必须 ≤ 1（元素不能超过数组容量） |
| 查找成本 | Θ(1 + α) | 与 α 强相关，α → 1 时急剧变差 |
| 删除 | 直接从链表摘除，简单 | 麻烦：不能直接置空，否则会截断别人的探测链（需要 tombstone 标记） |
| 适用 | α 可能较大、元素数波动大 | α 能控制在较小值（实践中 < 0.5） |
| 笔记 | [2.1_Chaining](2.1_Chaining/) | [2.2_Open Addressing](2.2_Open%20Addressing/) |

### Complexity 对比

α = n/m 为 load factor；下表为**平均情况**的期望步数（Chaining 基于 SUHA，Open Addressing 基于 uniform hashing 假设）。

| | Chaining | Open Addressing |
|---|---|---|
| 查找失败 unsuccessful | 1 + α | 1 / (1 − α) |
| 查找成功 successful | 1 + α/2 − α/(2n) ≈ 1 + α/2 | (1/α) · ln(1/(1 − α)) |
| Insert | Θ(1 + α) | ≈ 1 / (1 − α)（先做一次 unsuccessful search） |
| Delete | Θ(1 + α) | 同查找 + tombstone 处理 |
| 渐进（平均） | **Θ(1 + α)**，若 α ∈ Θ(1) 则 Θ(1) | α 越接近 1 越差；实践中要求 α < 0.5 |
| 最坏情况（所有 key 撞一起 / 探测链满） | Θ(n) | Θ(n) |

直观感受（代入几个 α）：

| α | Chaining 成功 | Chaining 失败 | Open Addr. 成功 | Open Addr. 失败 |
|---|---|---|---|---|
| 0.5 | ≈ 1.25 | 1.5 | ≈ 1.39 | 2 |
| 0.9 | ≈ 1.45 | 1.9 | ≈ 2.56 | 10 |
| 0.99 | ≈ 1.50 | 1.99 | ≈ 4.65 | 100 |

- Chaining 对 α 是**线性**增长，即使 α > 1 也只是链表变长，不会「爆」
- Open Addressing 对 α 有 `1/(1−α)` 的**渐近奇点**，α → 1 时急剧恶化，且 α 不能超过 1
- 注：中文教材的 ASL 只数关键字比较，会写成 `ASL_succ ≈ 1 + α/2`、`ASL_unsucc ≈ α`（少一个 +1，因为不计「算 h(k) + 首次访问 T[i]」那一步），数量级与结论一致
- 完整推导见 [2.1_Chaining/complexity.md](2.1_Chaining/complexity.md) 与 [2.2_Open Addressing/](2.2_Open%20Addressing/)（含 Linear / Quadratic / Double Hashing 三个子文件夹的分别分析）

### 层级关系（容易搞混）

```
解决 collision
├── Chaining                              → 2.1_Chaining/
└── Open Addressing                       → 2.2_Open Addressing/
    ├── Linear Probing      (h(k) + i) mod m            → 2.2.1_Linear Probing/
    ├── Quadratic Probing   (h(k) + c₁i + c₂i²) mod m   → 2.2.2_Quadratic Probing/
    └── Double Hashing      (h₁(k) + i·h₂(k)) mod m     → 2.2.3_Double Hashing/
```

- **Chaining vs Open Addressing** 是并列的两种思路
- **Linear / Quadratic / Double Hashing** 不是和 Chaining 并列，它们是 Open Addressing 内部的三种具体探测策略

### 与 Hash Function 的关系

- Hash function（Division / Multiplication）和碰撞处理方法是**正交**的
- 任何一种 hash function 都可以搭配 Chaining 或 Open Addressing
