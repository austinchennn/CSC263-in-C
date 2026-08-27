## Cycle Detection — Complexity

| 操作 | 复杂度 | 说明 |
|---|---|---|
| 检测图中是否存在环 | Θ(n + m) | 与普通 DFS（见 [DFS complexity.md](../1_DFS/complexity.md)）相同，因为判断 back edge 只是在 DFSVisit 原有的邻居遍历中多做一次颜色检查，不增加额外的渐进复杂度 |
