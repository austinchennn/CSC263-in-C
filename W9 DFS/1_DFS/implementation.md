## DFS — Implementation（实现）

### DFS(G)

- 实现
  ```
  DFS(G):
      for each t ∈ G.V:          # 总计 Θ(n)
          t.colour = White
          t.p = NIL
      time = 0
      for each s ∈ G.V:
          # 确保没有顶点被遗漏，都能被访问到
          if s.colour == White:
              DFSVisit(G, s)
  ```
- 最坏情况运行时间：Θ(n + m)（见 [complexity.md](complexity.md)）

### DFSVisit(G, s)

- 实现
  ```
  DFSVisit(G, s):
      time = time + 1        # time 是全局变量
      s.d = time
      s.colour = Grey
      for each t ∈ G.adj[s]:
          if t.colour == White:        # 只访问未被访问过的顶点
              t.p = s                    # t 被发现为 s 的邻居
              DFSVisit(G, t)
      s.colour = Black        # s 的所有邻居都已被发现，s 被标记为已探索完
      time = time + 1
      s.f = time                # 探索完所有邻居后记录完成时间
  ```
- 最坏情况运行时间：Θ(n + m)
  - 用 adjacency list 时：访问每个顶点、为其赋值的部分总计 Θ(n)；检查每个顶点的所有邻居，每条边最多被检查两次，总计 Θ(m)
  - NOTE：若用 adjacency matrix，最坏情况运行时间为 Θ(n²)

### 配套代码

- [../graph.h](../graph.h) / [../graph.c](../graph.c)：邻接表 + `transposeGraph`（SCC 用）
- [../dfs.h](../dfs.h) / [../dfs.c](../dfs.c)：`dfsRun()` 递归实现 DFS(G) / DFSVisit，回填 `d[]` / `f[]` / `pred[]`
- 环检测 / 拓扑排序 / SCC 分别在 [../cycle.c](../cycle.c) / [../toposort.c](../toposort.c) / [../scc.c](../scc.c)
- 编译：`cc graph.c dfs.c cycle.c toposort.c scc.c main.c -o demo`
