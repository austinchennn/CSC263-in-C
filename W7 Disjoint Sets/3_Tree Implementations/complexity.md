## Tree Implementations — Complexity

### Trees

| MakeSet | FindSet | Union |
|---|---|---|
| Θ(1) | Θ(h) ~ Θ(n)，h 是包含 x 的树的高度 | Θ(h1 + h2) |

- 摊还结果：T^sq_m ∈ Θ(m²)，即 T^sq_m / m ∈ Θ(m)（推导过程见 [implementation.md](implementation.md)）

### Trees with Union-by-rank

| MakeSet | FindSet | Union |
|---|---|---|
| Θ(1) | Θ(h) ~ Θ(log n) | Θ(h1 + h2) |

- 摊还结果：T^sq_m ∈ Θ(m log m)，即 T^sq_m / m ∈ Θ(log m)（推导过程见 [implementation.md](implementation.md)）

### Trees with Path-Compression

| MakeSet | FindSet | Union |
|---|---|---|
| Θ(1) | Θ(h) | Θ(h1 + h2) |

- 摊还结果：对于含 n 次 MakeSet（至多 n − 1 次 Union）和 f 次 FindSet 的序列，T^sq_m ∈ Θ(n + f × (1 + log_{2 + f/n} n))（推导过程见 [implementation.md](implementation.md)）
- NOTE：源材料没有给出把这一结果除以 m 后的化简形式，此处保留原始的 T^sq_m 表达式

### Trees with Union-by-Rank and Path-Compression

| MakeSet | FindSet | Union |
|---|---|---|
| Θ(1) | Θ(h) | Θ(h1 + h2) |

- 摊还结果：对于含 m 次操作、其中 n 次 MakeSet（至多 n − 1 次 Union）的序列，T^sq_m ∈ O(m × α(n))，其中 α(n) 是**反阿克曼函数（inverse Ackermann function）**
- α(n) 增长得极其缓慢——它是阿克曼函数（一个增长速度远快于任何多项式甚至指数塔的函数）的反函数；对于任何实际场景中可能出现的 n（哪怕大到宇宙中原子数量的量级），α(n) 的值也不超过 4~5，因此可以把它当作常数处理
- 于是 T^sq_m ∈ O(m)，即 T^sq_m / m ∈ O(1) —— 这是四种树实现中唯一能达到（近似）常数摊还复杂度的版本

### 对比：四种树实现的演进

Worst-case:

| 实现 | MakeSet | FindSet | Union |
|---|---|---|---|
| Trees | Θ(1) | Θ(h) ~ Θ(n) | Θ(h1 + h2) |
| + Union-by-rank | Θ(1) | Θ(h) ~ Θ(log n) | Θ(h1 + h2) |
| + Path-Compression | Θ(1) | Θ(h) | Θ(h1 + h2) |
| + Union-by-Rank + Path-Compression | Θ(1) | Θ(h) | Θ(h1 + h2) |

NOTE：这里 worst-case 一栏的表达式看起来形式相似（都含有 h），但四种实现中 h（树的高度）的实际取值范围差异很大；真正体现出改进的是下面的摊还复杂度对比

Amortized:

| 实现 | T^sq_m | T^sq_m / m |
|---|---|---|
| Trees | Θ(m²) | Θ(m) |
| + Union-by-rank | Θ(m log m) | Θ(log m) |
| + Path-Compression | Θ(n + f(1 + log_{2+f/n} n)) | 源材料未给出简化形式 |
| + Union-by-Rank + Path-Compression | O(m × α(n)) ≈ O(m) | O(1)（α(n) 视为常数） |
