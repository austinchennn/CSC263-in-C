## BFS — Implementation（实现）

### BFS(G, s)

- 实现
  ```
  BFS(G, s):
      for each vertex v ∈ V − {s}:          # 初始化顶点
          v.colour = White
          v.d = ∞          # v 到 BFS 起点的距离
          v.p = NIL         # 发现 v 时所经过的顶点
      Q = ∅
      s.colour = Grey       # 从发现源点开始 BFS
      s.d = 0                # s 到自身的距离为 0
      Enqueue(Q, s)
      while Q not empty:
          u = Dequeue(Q)
          for each v ∈ G.adj[u]:
              if v.colour == White:            # 只访问未访问过的顶点
                  v.colour = Grey
                  v.d = u.d + 1        # v 比 u 离 s 远 "1层"
                  v.p = u               # v 是作为 u 的邻居被发现的
                  Enqueue(Q, v)
          u.colour = Black       # u 的所有邻居都已被发现，因此 u 探索完毕
  ```
- NOTE：如果 G 是不连通图（disconnected graph），则存在若干顶点的 v.d 始终为 ∞（即从 s 不可达）
- 若要得到最短路径，只需从目标顶点 v 出发，沿着 .p 属性反向回溯，直到回到 s

### 最坏情况运行时间

- 使用 Adjacency List 表示图，总的工作量分为两部分
  1. 访问每个顶点时，Enqueue、Dequeue、给 v.colour、v.d、v.p 赋值等操作 → Θ(1)
     所有顶点总计 → Θ(n)
  2. 在每个顶点处，检查它的所有邻居；每条边最多被检查两次 → Θ(1)
     所有边总计 → Θ(m)
- 总运行时间：Θ(n + m)
- NOTE：|V| = n，|E| = m

### 配套代码

本目录自包含（`graph.h` / `graph.c` 是 [1_Graph Representations](../1_Graph%20Representations/) 的副本）：

- [bfs.h](bfs.h) / [bfs.c](bfs.c)：`bfs()` 用颜色数组 + 定长数组队列，回填 `dist[]` / `pred[]`；`printPath()` 沿 `pred` 回溯打印最短路径
- [main.c](main.c)：用 CLRS 无向图跑一遍，输出各顶点距离与路径
- 编译运行：`cc -Wall -Wextra graph.c bfs.c main.c -o demo && ./demo`（另见 [README.md](README.md)）
