## Strongly Connected Components — Complexity

| 步骤 | 复杂度 |
|---|---|
| Step 1: 调用 DFS(G)，计算每个顶点的 u.f | Θ(n + m) |
| Step 2: 计算 G^T | Θ(n + m) |
| Step 3: 按 u.f 递减顺序调用 DFS(G^T) | Θ(n + m) |
| Step 4: 输出 depth-first forest 中每棵树作为一个 SCC | Θ(n) |
| 总运行时间 | Θ(n + m) |

NOTE：源材料只明确给出了 Step 1（即 DFS(G)）的复杂度 Θ(n + m)（见 [DFS complexity.md](../1_DFS/complexity.md)）；Step 2-4 的复杂度是基于"构造转置图需要遍历一次所有边"以及"DFS(G^T) 与 DFS(G) 同阶"这些自然推论得到的，源材料并未逐项给出
