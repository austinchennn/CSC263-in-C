## Kruskal's Algorithm — 定义

Kruskal's Algorithm 是求解 MST 问题的一种贪心算法，基于 Growing Implementation 的思路（见 [1_MST Basics](../1_MST%20Basics/definition.md)），每一步都在整张图的边表中挑选当前权重最小的安全边加入 T

### Idea

1. 按边权重不降序（non-decreasing）依次处理所有边
   - 先将所有边按权重排序
2. 依次选择并加入每一条跨越 T 中两个不同连通分量的边
   - 按排序后的顺序从最轻到最重遍历边表
   - 若 FindSet(u) ≠ FindSet(v)，把 (u, v) 加入 T
   - 把 (u, v) 加入 T 后，执行 Union(u, v)
