## Graph Representations — Implementation（实现）

- NOTE：源材料中这两种表示法只给出了数据布局的定义式，并没有给出完整的算法伪代码，因此本节以“数据结构描述”为主，而非逐步的算法过程

### Adjacency Matrix（邻接矩阵）

- 设 V = {v1,...,vn}（|V| = n）
- 设 A 为一个 n × n 的矩阵
  - 若 (vi, vj) ∈ E，则 A[i,j] = 1；否则 A[i,j] = 0
- 对于无向图，邻接矩阵是对称的
- 对于加权图
  - 若 (vi, vj) ∈ E，则在 A[i, j] 中存储权重 w(vi, vj)
  - 否则存储 −1 / 0 / ∞（NOTE：源材料给出了三种可能的“无边”占位值，具体取哪一个取决于应用场景，并未统一规定）

### Adjacency List（邻接表）

- 设 V = {v1,...,vn}（|V| = n）
- 设 L 为一个长度为 n 的列表
- L[i] 对应顶点 vi，存储一个列表 Ai，包含所有从 vi 出发有边相连的顶点
  - 即 Ai 包含 vj 当且仅当 (vi, vj) ∈ E
- NOTE：对于无向图，一条边 (u, v) 会被存储两次（分别出现在 u 和 v 各自的邻接表中）

### 配套代码

两种表示各一份，API 一样（`createGraph` / `addEdge` / `freeGraph` / `printGraph`），
用同一张图，方便对比：

- [1.1_Adjacency Matrix/](1.1_Adjacency%20Matrix/)：`int **adj` 是 n×n 的 0/1 矩阵。空间 Θ(n²)，Edge Query Θ(1)，列邻居 Θ(n)
- [1.2_Adjacency List/](1.2_Adjacency%20List/)：每个顶点挂一条链表。空间 Θ(n + m)，列邻居 O(度数)

编译命令见各目录 `README.md`。
