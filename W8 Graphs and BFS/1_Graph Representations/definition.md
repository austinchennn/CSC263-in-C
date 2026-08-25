## Graph Representations — 定义

- Graph（图）用来建模一组对象之间的**成对关系（pairwise relationship）**与**连通性（connectivity）**——比如网络中的节点与连接、地图中的城市与道路
- Graph 是一个二元组 G = (V, E)，其中 V 是顶点（vertices）的集合，E 是边（edges）的集合
  - E 中的元素是形如 (vi, vj) 的元组，vi, vj ∈ V

### 图的分类

- Directed Graph（有向图）— 边具有方向的图
  - 即 (vi, vj) ≠ (vj, vi)
- Undirected Graph（无向图）— 边没有方向的图
  - 即 (vi, vj) = (vj, vi)
- Weighted Graph（加权图）— 每条边都被赋予一个权重（weight）的图
  - NOTE：边的权重可以表示成本（cost）、长度（length）或容量（capacity）等含义

### 基本定义

- Adjacent（相邻）— 如果两个顶点之间存在一条边，则称它们相邻，互为邻居（neighbours）
- Path（路径）— 顶点 u 到 w 之间的路径是一条由互不相同的边组成的序列 (v0,v1),...,(vk,vk−1)，其中 u = v0，w = vk，且序列中每个元组 (vi, vj) 里的 vi、vj 都各不相同
  - Length of path（路径长度）— 路径中边的数量
- Distance（距离）— 两个顶点之间最短路径的长度
  - 一个顶点到自身的距离恒为 0
- Connected Graph（连通图）— 图中任意一对顶点之间都存在路径
  - 一个有 n 个顶点的无向连通图，其边数的最小值为 n − 1
- Cycle（环）— 一个顶点到其自身的路径
  - NOTE：环的长度至少为 3
- Tree（树）— 连通且不含环的图
- Forest（森林）— 若干棵互不相交的树组成的集合
