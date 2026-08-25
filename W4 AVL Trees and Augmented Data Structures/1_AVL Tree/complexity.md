## AVL Tree — Complexity

| Operation | Worst-Case Running Time |
|---|---|
| AVLSearch | Θ(log n) |
| AVLInsert | Θ(log n) |
| AVLDelete | Θ(log n) |
| Rotation（single or double） | Θ(1) |

### AVLInsert / AVLDelete 各步骤开销

| Step | Complexity |
|---|---|
| 1. 像 BST 一样插入/删除 | Θ(h) = Θ(log n) |
| 2. 检查是否仍然平衡 | Θ(1) |
| 3. 若不平衡，执行旋转 | Θ(1) |
| 4. 更新受影响节点的 height | Θ(log n) |

### 高度上界

- 含 n 个节点的 AVL tree，其高度 h 满足 h ≤ 1.44 log2(n + 2)，因此 h ∈ Θ(log n)，这是上述所有操作能达到对数时间复杂度的根本原因
