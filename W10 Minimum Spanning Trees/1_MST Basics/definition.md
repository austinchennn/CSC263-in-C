## Minimum Spanning Tree — 定义

给定一个连通的无向带权图，MST 问题要找出一组权重最小的边，使得这些边既能把所有顶点连通起来，又不含任何冗余（不形成环）

- 设 G = (V, E) 是一个连通的无向带权图
- G 的 Minimum Spanning Tree（最小生成树）T：
  - 是 G 的一个子图（sub-graph）
  - 包含 G 的所有顶点 -> spanning（生成）
  - 无环且连通 -> tree（树）
  - 总权重最小 -> minimum（最小）
- NOTE：一个图可能存在不止一个 MST
- 讲义中给出的反例（与合法 MST 对照）：
  - 一个不连通的子图 —— 不合法（不满足 spanning/连通）
  - 一个连通、包含所有顶点，但总权重不是最小的子图 —— 不合法（不满足 minimum）
  - 一个包含环的子图 —— 不合法（不满足 tree/acyclic）

## Review：树的性质

设 T 是一棵有 n 个顶点的树，则：
- T 恰好有 n − 1 条边
- 给 T 增加一条边会产生一个环
- 从 T 中删去一条边会使图不连通

一个连通无向图 G = (V, E) 的 MST 有 |V| 个顶点、|V| − 1 条边

## Safe Edge / Cut / Crosses — 定义

- Safe Edge（安全边）：若 T.E ∪ {e} 是 G 的某个 MST 的边集的子集，则称边 e 对 T 是安全的（safe）
- Cut（割）(S1, S2)：无向图 G 的一个割是把 V 划分成两个不相交的子集 S1、S2
  - 即 S1 ∩ S2 = ∅ 且 S1 ∪ S2 = V
- Crosses（跨越）：若一条边的两个端点分别位于 S1 和 S2 中，则称这条边跨越（crosses）这个割

### Theorem

设 G 是一个连通的无向带权图，T 是 G 的一个子图，且 T 是 G 的某个 MST 的边集的子集。设边 e 是所有跨越 T 中不同连通分量的边中权重最小的一条，那么 e 对 T 是安全的（safe）。
