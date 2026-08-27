## Kruskal's Algorithm — Implementation（实现）

前置条件：G 是一个无向图

- 实现
  ```
  KruskalMST(G):
  1.  T.V = G.V
  2.  T.E = ∅
  3.  for each vertex v ∈ G.V:          # 为每个顶点建立一个独立的连通分量
  4.      MakeSet(v)
  5.  Let e1, e2, ..., em be the edges in G.E sorted by weight in non-decreasing order
  6.  for i = 1 to m:
  7.      Let (u, v) = ei
  8.      if FindSet(u) ≠ FindSet(v):          # 检查 u 和 v 是否位于 T 的不同连通分量中
  9.          T.E = T.E ∪ {(v, u)}              # 把安全边 (v, u) 加入 T
  10.         Union(u, v)                        # 现在 u 和 v 位于 T 的同一个连通分量中
  11. return T
  ```
- NOTE：若 G 不连通，Kruskal's Algorithm 将生成一个 Minimum Spanning Forest（最小生成森林）
- 最坏情况运行时间：O(n + m log n)（若输入图是连通的，则为 O(m log n)；推导过程见 [complexity.md](complexity.md)）
