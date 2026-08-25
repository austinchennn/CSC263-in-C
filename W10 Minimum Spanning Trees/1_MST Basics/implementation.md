## Initial Implementation — Implementation（实现）

### Idea 1：Deletion-based

- T.V = G.V，T.E 初始为 G.E，不断删除边，直到只剩下一个 MST
- 最坏情况下需要删除 n(n−1)/2 − (n−1) ∈ Θ(n²) 条边（因为一个有 n 个顶点的无向图最多有 n(n−1)/2 条边）

### Idea 2：Addition-based

- T.V = G.V，T.E 初始为空集，不断添加边，直到构建出一个 MST
- 最坏情况下需要添加 n − 1 ∈ Θ(n) 条边

## Growing Implementation — Implementation（实现）

- 直觉：在扩张 T 的过程中，只要始终保证 T 是 G 的某个 MST 的子图，那么最终 T 就会成为一个 MST

### GenericMST

- 实现
  ```
  GenericMST(G):
      T.V = G.V              # 初始化 MST 的顶点集
      T.E = ∅                 # 从空的边集开始
      While T 尚未构成一棵生成树:
          find e ∈ G.E，e 是所有跨越 T 中两个不同连通分量的边中权重最小的一条
          # 把边 e 加入 MST
          T.E = T.E ∪ {e}
      return T
  ```
