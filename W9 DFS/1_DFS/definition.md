## DFS — 定义

- DFS（Depth-First Search，深度优先搜索）是一种图遍历算法：优先沿着某一条路径尽量往深处走，直到无法继续再回溯，去探索其广度
- 基本思想：从起点 s 出发，先访问 s 的一个邻居 n1，再访问 n1 的一个未被访问过的邻居 n2，依此类推；若访问到 nk，且 nk 的所有邻居都已被访问过，则回溯去尝试 nk-1 的另一个邻居

### 改进：用颜色标记访问状态

- 为了避免重复访问同一个顶点，给每个顶点标记颜色
  - White（白色）— 未被访问过的顶点
  - Grey（灰色）— 已被发现（encountered）的顶点
  - Black（黑色）— 已被探索完的顶点；已被访问，且其所有邻居都已被探索完

### 核心思路

- 初始时所有顶点都是 White
- 第一次访问某个顶点时，把它的颜色改为 Grey
- 当一个顶点的所有邻居都已被发现（encountered）后，把它的颜色改为 Black
- 避免访问 Grey 或 Black 的顶点
- 最终，所有从源点可达的顶点都会变成 Black

### 记录信息

- `v.p` — 发现 v 时所处的顶点（即 v 在 DFS 树中的父节点）
- 为每个顶点 v 记录两个时间戳
  - Discovery Time（发现时间）— v 第一次被发现的时间，记为 v.d
  - Finishing Time（完成时间）— v 的所有邻居都被完全访问完的时间，记为 v.f

## DFS 的性质（Properties）

### Parenthesis Theorem（括号定理）

- 在对图 G 的任意一次 DFS 中，对任意两个顶点 u 和 v，以下三种关系必有一种成立
  - 区间 [v.d, v.f] 包含 [u.d, u.f]，或
  - 区间 [u.d, u.f] 包含 [v.d, v.f]，或
  - [v.d, v.f] 与 [u.d, u.f] 不相交

### Nesting of Descendant's Interval（后代区间的嵌套）

- 在图 G 的 depth-first forest 中，顶点 v 是顶点 u 的 proper descendant（真后代），当且仅当区间 [u.d, u.f] 包含 [v.d, v.f]，即
  - u.d < v.d < v.f < u.f
