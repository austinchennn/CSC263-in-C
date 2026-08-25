## Prim's Algorithm — Implementation（实现）

前置条件：G 是一个连通无向图，r 是 G 中的一个顶点

- 实现
  ```
  PrimMST(G, r):
  1.  T.V = G.V
  2.  T.E = ∅
  3.  for each vertex v ∈ G.V:
  4.      v.key = ∞          # v.key 保存 v 与 T 之间的最短距离
  5.      v.p = nil            # v.p 保存 v 通过最轻的边与 T 中的哪个顶点相连
  6.  r.key = 0                 # 令 r 作为 min-heap 的根
  7.  H = BuildMinHeapGraph(G)
  8.  While H not empty:
  9.      u = ExtractMin(H)
  10.     if u.p ≠ nil:          # u.p 仅在 u = r 时为 nil
  11.         T.E = T.E ∪ {(u.p, u)}         # 把一条安全边加入 MST
  12.     for each v ∈ G.adj[u]:              # u 的所有邻居到 T 的距离都需要更新
  13.         if v ∈ H and w((u, v)) < v.key:
  14.             v.p = u
  15.             DecreaseKey(H, v.pos, w((u, v)))
  16. return T
  ```
- 最坏情况运行时间：O((n + m) log n)（若 G 连通，则为 O(m log n)；推导过程见 [complexity.md](complexity.md)）
