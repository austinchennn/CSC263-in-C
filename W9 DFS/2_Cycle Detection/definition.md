## Cycle Detection（环检测）— 定义

- 背景：DFS 可以用来检测有向图中是否存在环（cycle）
- 核心论证
  1. 考虑一个图 G
  2. 假设在 G 的某棵 DFS-forest 中，u 是 v 的祖先（ancestor）
  3. 这意味着存在一条从 u 到 v 的路径
  4. 现在假设存在一条从 v 到 u 的边
  5. 那么就可以说图中存在一个环（因为从 u 经过 v 又回到了 u，相当于 u 到自身的一条路径）

### 边的分类

- Tree Edge（树边）— DFS-forest 中的边
- Back Edge（反向边）— 一条非树边，从某个顶点指向它在 DFS forest 中的祖先

### Lemma

- 一个图含有环，当且仅当 DFS 产生了一条 back edge

### 如何识别 back edge

- 寻找指向 Grey（灰色）顶点的边：如果存在这样的边，它就是一条 back edge
