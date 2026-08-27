## Quadratic Probing — Complexity

α = n/m 为 load factor。因为要求 m 素数且表不超过半满，实际使用时 **α < 1/2**。

### 探测次数

| Search 类型 | 近似期望探测次数 |
|---|---|
| Unsuccessful | 约 `1/(1 − α)`（比 Linear 好，比 Double Hashing 略差） |
| Successful | 约 `1 + ln(1/(1 − α))` 量级 |

- 没有 primary clustering，所以不像 Linear Probing 那样出现分母 `(1−α)²` 的恶化
- 但 secondary clustering 让它达不到 Double Hashing / uniform hashing 的理想值

### 代入数值（α < 0.5 区间）

| α | Linear 实际 unsucc `½(1+1/(1−α)²)` | Quadratic ≈ `1/(1−α)` | Double Hashing `1/(1−α)` |
|---|---|---|---|
| 0.25 | 1.4 | 1.33 | 1.33 |
| 0.4  | 1.9 | 1.67 | 1.67 |
| 0.5  | 2.5 | 2.0  | 2.0  |

（Quadratic 与 Double Hashing 的 unsuccessful 理论量级相同，差别在 secondary clustering 带来的常数项，此处从略。）

### 小结

- 探测序列种类数：只有 **m 种**（由 h(k) 决定），与 Linear 相同，所以还有 secondary clustering
- 硬约束：m 素数 + α < 1/2
- 最坏情况：Θ(n)
