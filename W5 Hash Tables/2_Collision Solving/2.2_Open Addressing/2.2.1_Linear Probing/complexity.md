## Linear Probing — Complexity

α = n/m 为 load factor（0 ≤ α < 1）。

### 理论 vs 实际

| Search 类型 | uniform hashing 理论值 | Linear Probing 实际值（Knuth，含 primary clustering） |
|---|---|---|
| Unsuccessful | `1 / (1 − α)` | `½ (1 + 1/(1 − α)²)` |
| Successful | `(1/α) · ln(1/(1 − α))` | `½ (1 + 1/(1 − α))` |

线性探测因为 primary clustering，实际探测次数比「理想 probe」更多，尤其是 unsuccessful（分母是 `(1−α)²`）。

### 代入数值（实际值）

| α | Successful ≈ ½(1 + 1/(1−α)) | Unsuccessful ≈ ½(1 + 1/(1−α)²) |
|---|---|---|
| 0.5 | 1.5 | 2.5 |
| 0.75 | 2.5 | 8.5 |
| 0.9 | 5.5 | 50.5 |

- α 从 0.5 涨到 0.9，unsuccessful 从 2.5 飙到 50，说明**必须把表维持在低负载**
- 最坏情况：所有 key 形成一条长探测链 → Θ(n)

### 小结

- 优点：实现最简单、cache 局部性好
- 缺点：primary clustering 使高负载时性能急剧下降
- 缓解：负载因子控制得更低，或改用 Quadratic Probing / Double Hashing
