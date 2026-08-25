## Tree Implementations — 定义

### Trees

- 每个集合对应一棵倒置的树（inverted tree）
- 每个元素只存一个指向父节点的指针 `x.p`（若是根节点，则指向自己）
- 树的根节点就是该集合的代表元，根节点指向自己
- NOTE：这里的树不一定是二叉树，一个节点的子节点数量可以是任意的

### Trees with Union-by-rank

- 结构与 Trees 相同，但根节点额外存储这棵树的 rank：`x.rank`
- rank（暂时）等于这棵树的高度（引入 path compression 之后，rank 只是高度的上界，不再精确等于高度，见下方）
- Union 时，让 rank 较小的根指向 rank 较大的根；如果两者 rank 相等，则任选一个作为新的根，并把新根的 rank 加一
- 相比普通 Trees 的改进：避免树退化成一条长链，从而把树的高度限制在 Θ(log n)

### Trees with Path-Compression

- 结构与 Trees 相同
- 改进发生在 FindSet 的过程中：为某个 x 调用 FindSet 时，记录下从 x 到根节点路径上经过的所有节点；一旦找到根节点，就把这些被经过的节点全部直接指向根节点
- 相比普通 Trees 的改进：让树在多次 FindSet 调用后逐渐变"扁平"，从而在摊还意义上大幅降低后续 FindSet 的开销

### Trees with Union-by-Rank and Path-Compression

- 同时使用 Union-by-rank 和 Path-Compression 两种启发式
- NOTE：path compression 会改变树的实际高度，但并不会去维护 rank 字段——所以在这个组合版本中，一个节点的 rank 只是其高度的**上界**，不再是精确的高度值
