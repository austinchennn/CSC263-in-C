## Strongly Connected Components — 定义

- Strongly Connected Component（SCC，强连通分量）：有向图 G 的一个 SCC 是顶点集合 V 的一个极大子集 C ⊆ V，使得对 C 中任意一对顶点 u 和 v，既存在一条从 u 到 v 的路径，也存在一条从 v 到 u 的路径

### 图的转置（Transpose）

- G^T：G 的转置图，G^T = (V, E^T)
- E^T = {(v, u) ∈ V × V : (u, v) ∈ E} — 由 G 中所有边反转方向后组成
- NOTE：一个有向图与它的转置图拥有相同的 strongly connected components

### f(C) > f(C') 的论证

- 设 C 和 C' 是 G 中两个不同的 SCC
- 假设存在一条边 (u, v) ∈ E，满足 u ∈ C 且 v ∈ C'
- 那么 f(C) > f(C')，其中 f(U) = max_{u∈U}{u.f}，即集合 U 中所有顶点里最晚的完成时间
- 证明思路分两种情况
  1. 先搜索 C，再搜索 C'
     - 因为 C' 中所有顶点 y 都是 u 的后代（descendant），所以 u.f > f(C')，从而 f(C) ≥ u.f > f(C')
  2. 先搜索 C'，再搜索 C
     - 因为 C 与 C' 是不同的 SCC，所以必须先搜索完 C' 中的所有顶点，再搜索 C
