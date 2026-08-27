## Quadratic Probing（二次探测）— 定义

- 探测函数：`probe(k, i) = (h(k) + c₁·i + c₂·i²) mod m`，i = 0, 1, 2, ...（c₂ ≠ 0）
- 本实现取 c₁ = 0、c₂ = 1，即 `probe(k, i) = (h(k) + i²) mod m`
- 探测序列：`h(k), h(k)+1, h(k)+4, h(k)+9, ...`，步长按平方增长，「跳着」检查 slot，从而打散 Linear Probing 那种连续占用段

### 探测序列例子

- m = 13，h(k) = k mod 13，插入 k 且 h(k) = 1：
  - i=0 → T[1]，i=1 → T[2]，i=2 → T[5]，i=3 → T[10]，i=4 → T[(1+16) mod 13] = T[4] ……

### Secondary Clustering（二次聚集）

- Linear Probing 的 primary clustering 没了（不再形成连续段）
- 但探测序列**只由 h(k) 和 i 决定，跟 key 本身无关** → 所有 h(k) 相同的 key 会走**完全一样**的探测序列，依然互相加长探测路径
- 这种较弱的聚集叫 secondary clustering

### 探测序列覆盖不全的问题

- 与 Linear 不同，`h(k), h(k)+1, h(k)+4, ...` **不保证遍历所有 m 个 slot**，可能出现「明明有空位却探测不到」
- 因为 i 和 m−i 给出相同的偏移（i² ≡ (m−i)² mod m），最多只有 ⌈m/2⌉ 个不同的探测位置
- **保证能插入的条件**：m 取**素数**，且 **α < 1/2**（表不超过半满）
  - 此时 i = 0, 1, ..., ⌊m/2⌋ 对应的探测位置两两不同，共 ⌊m/2⌋+1 个；表不到半满 → 其中必有一个非 OCCUPIED
