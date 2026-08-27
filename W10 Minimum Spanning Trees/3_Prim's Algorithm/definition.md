## Prim's Algorithm — 定义

Prim's Algorithm 是求解 MST 问题的另一种贪心算法，同样基于 Growing Implementation 的思路（见 [1_MST Basics](../1_MST%20Basics/definition.md)），但每一步只从一棵正在生长的单一树向外扩张（而非像 Kruskal's Algorithm 那样在整张图的边表中挑选）

### Idea

- 任选 G 中的一个顶点 r 作为 T 的起始顶点
- 每次给 T 添加一条边，逐步扩张 T
  - 在任意时刻，T 由一个包含 r 的连通分量，以及若干与 r 不连通的单顶点分量（singleton component）组成，每一个这样的单顶点分量称为一个 isolated vertex（孤立顶点）
  - 每一步都选择权重最小的一条跨越边（crossing edge）
- 用一个 min-heap 保存所有 isolated vertices
  - min-heap 的键（key）是各个 isolated vertex 到 T 的跨越边的权重
