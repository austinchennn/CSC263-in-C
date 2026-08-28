## Cycle Detection — Implementation（实现）

### 在 DFSVisit 中检测 back edge

- 思路：源材料给出的是环检测的论证过程（ancestor 与 back edge 的关系），而不是一段独立的伪代码；实际实现方式是在 DFSVisit(G, s) 原有的邻居遍历循环中，多加一次颜色判断
- 实现（基于 DFSVisit 的邻居遍历部分）
  ```
  # 在 DFSVisit(G, s) 遍历 s 的邻居 t 时：
  for each t ∈ G.adj[s]:
      if t.colour == White:
          t.p = s
          DFSVisit(G, t)
      else if t.colour == Grey:      # (s, t) 指向一个仍处于 Grey 状态的祖先
          # 检测到 back edge -> 图中存在环
          report cycle detected
  ```
- 最坏情况运行时间：Θ(n + m)（与 DFS 本身相同，见 [DFS complexity.md](../1_DFS/complexity.md)；该检查只是在已有的邻居遍历中多做一次颜色比较，不改变渐进复杂度）
- NOTE：源材料只给出了检测环存在性的论证（ancestor/back edge 的关系）以及"寻找指向 Grey 顶点的边"这一识别方法，并未给出独立于 DFSVisit 之外的完整伪代码；这里呈现的是在 DFSVisit 原有邻居遍历基础上的最小改动

### 配套代码

- [../cycle.c](../cycle.c)：`hasCycle()`——DFS 遍历中遇到指向 Grey 顶点的边即判定有环（针对有向图）
