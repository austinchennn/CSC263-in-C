## Double Hashing — Complexity

α = n/m 为 load factor（0 ≤ α < 1）。

### 探测次数（≈ uniform hashing 理论值）

| Search 类型 | 期望探测次数 |
|---|---|
| Unsuccessful | `1 / (1 − α)` |
| Successful | `(1/α) · ln(1/(1 − α))` |

因为探测序列约 m² 种、几乎不聚集，Double Hashing 的实际表现最接近这两个理论公式（Linear / Quadratic 都达不到）。

### 三种 Open Addressing 对比（unsuccessful search）

| α | Linear `½(1+1/(1−α)²)` | Quadratic ≈ `1/(1−α)` | Double Hashing `1/(1−α)` |
|---|---|---|---|
| 0.25 | 1.4 | 1.33 | 1.33 |
| 0.5  | 2.5 | 2.0  | 2.0  |
| 0.75 | 8.5 | 4.0  | 4.0  |
| 0.9  | 50.5 | 10.0 | 10.0 |

### 小结

| | 探测序列种类 | 聚集 | 约束 |
|---|---|---|---|
| Linear | m | primary + secondary | 无（覆盖全部 slot） |
| Quadratic | m | secondary | m 素数、α < 1/2 |
| Double Hashing | ≈ m² | 基本没有 | h₂(k) 与 m 互质（m 素数即可） |

- 最坏情况仍是 Θ(n)
- α → 1 时 `1/(1−α)` 依旧爆炸，所以实践中同样要求 α < 0.5
