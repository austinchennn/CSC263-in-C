## Open Addressing — Complexity

### Probing 策略对比

| Probing 方式 | 探测序列公式 |
|---|---|
| Linear Probing | (h(k) + i) mod m，i ≥ 0 为整数 |
| Quadratic Probing | (h(k) + c1×i + c2×i²) mod m，i ≥ 0 为整数 |
| Double Hashing | (h1(k) + i × h2(k)) mod m，i ≥ 0 为整数 |

### Average-Case Running Time

| Search 类型 | 平均情况运行时间 |
|---|---|
| Unsuccessful（查找失败） | 1 / (1 − α) |
| Successful（查找成功） | (1/α) × ln(1 / (1 − α)) |

- 其中 α 为 load factor
- 实践中，Open Addressing 在 α < 0.5 时表现最好
