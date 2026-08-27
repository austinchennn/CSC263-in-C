## Linked List Implementations — Complexity

### Circularly-Linked Lists

| MakeSet | FindSet | Union |
|---|---|---|
| Θ(1) | Θ(L) | Θ(L1 + L2) |

NOTE：L 是包含 x 的链表的长度

- 摊还结果：对于一个精心构造的"坏序列"，T^sq_m ∈ Θ(m²)，即 T^sq_m / m ∈ Θ(m)（推导过程见 [implementation.md](implementation.md)）

### Linked Lists with Pointer to Head

| MakeSet | FindSet | Union |
|---|---|---|
| Θ(1) | Θ(1) | Θ(L1 + L2) |

- 摊还结果：T^sq_m ∈ Θ(m²)，即 T^sq_m / m ∈ Θ(m)（推导过程见 [implementation.md](implementation.md)）
- NOTE：虽然 FindSet 的最坏情况复杂度从 Θ(L) 降到了 Θ(1)，但摊还复杂度并没有改进——瓶颈转移到了 Union 时更新所有节点 head 指针的开销上

### Linked Lists with Pointer to Head and Union-By-Weight

| MakeSet | FindSet | Union |
|---|---|---|
| Θ(1) | Θ(1) | Θ(L1 + L2) |

- 摊还结果：T^sq_m ∈ Θ(m + n log n) ∈ Θ(m log m)，即 T^sq_m / m ∈ Θ(log m)（推导过程见 [implementation.md](implementation.md)）
- 这是三种链表实现中唯一真正改进了摊还复杂度的版本

### 对比：三种链表实现的演进

Worst-case:

| 实现 | MakeSet | FindSet | Union |
|---|---|---|---|
| Circularly-Linked List | Θ(1) | Θ(L) | Θ(L1 + L2) |
| Linked List + Pointer to Head | Θ(1) | Θ(1) | Θ(L1 + L2) |
| Linked List + Pointer to Head + Union-By-Weight | Θ(1) | Θ(1) | Θ(L1 + L2) |

Amortized:

| 实现 | T^sq_m | T^sq_m / m |
|---|---|---|
| Circularly-Linked List | Θ(m²) | Θ(m) |
| Linked List + Pointer to Head | Θ(m²) | Θ(m) |
| Linked List + Pointer to Head + Union-By-Weight | Θ(m + n log n) ∈ Θ(m log m) | Θ(log m) |

- 结论：单纯加上指向头节点的指针（Pointer to Head）只改进了 FindSet 的最坏情况复杂度，并没有改进摊还复杂度；真正带来摊还复杂度改进的是 Union-By-Weight 这个启发式
