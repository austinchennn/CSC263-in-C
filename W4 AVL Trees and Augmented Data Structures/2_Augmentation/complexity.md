## Augmented Data Structure — Complexity

- 讲义本节没有给出具体的表格或数值复杂度分析，只给出一个关键结论：
  - 若某节点的额外信息只依赖于该节点自身及其子节点所存储的信息（即可以“局部计算”），那么对 AVL tree 进行 augmentation 之后，维护这些额外信息不会改变 AVLInsert 与 AVLDelete 原本的 Θ(log n) 最坏情况运行时间
