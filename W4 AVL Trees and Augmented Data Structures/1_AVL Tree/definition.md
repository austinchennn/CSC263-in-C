## AVL Tree — 定义

- BST 在最坏情况下可能退化（例如变成一条链），导致各操作失去对数时间的运行时间保证；AVL Tree 通过维护一个平衡不变量，保证树高始终维持在 Θ(log n)

### Balance Factor（平衡因子）

- 定义：节点 n 的右子树高度减去左子树高度
  BF(n) = n.right.height − n.left.height
- 性质
  - 若 BF(x) = +1，称 x 为 right heavy（右重）
  - 若 BF(x) = −1，称 x 为 left heavy（左重）
  - 若 BF(x) = 0，称 x 为 balanced（平衡）

### AVL Invariant / AVL-Balanced / AVL Tree

- AVL Invariant：节点 n 满足 AVL invariant，当且仅当 −1 ≤ BF(n) ≤ 1
- AVL-Balanced：一棵二叉树中所有节点都满足 AVL invariant，则称该树是 AVL-balanced
- AVL Tree：满足 AVL-balanced 的 BST

注：Height 以层数衡量（即从根节点到叶节点的最长路径上的节点数）

- 性质：含 n 个节点的 AVL tree，其高度至多为 1.44 log2(n + 2)，因此 h ∈ Θ(log n)

### 附加存储信息

- 每个节点 x 额外存储 x.height
- AVLSearch：与 BSTSearch 相同
- AVLInsert 与 AVLDelete 需要
  1. 维护所有受影响节点的 AVL invariant
  2. 维护 BST property
  3. 相应更新受影响节点的 height

## Rotation（旋转）— 定义

### 观察

1. 插入/删除一个节点只会改变其祖先节点的 balance factor
2. 受影响节点的 balance factor 变化幅度至多为 1；受影响节点的 balance factor 只可能变为 -2 或 2

### 前提假设

- 设 y 是变得不平衡的最低祖先节点（即 y 的所有后代都满足 AVL invariant）

### 情形与对应旋转

1. 新节点插入到 y 的右子树，且 y 在插入前是 right-heavy
   1. 新节点插入到 x 的右子树（x 是 y 的右子节点）→ 需要 left rotation
      - 旋转前：y 的左子树高度为 h；y 的右子节点为 x；x 的右子树高度为 h，插入后变为 h+1，导致 y 的 balance factor 变为 +2
      - 旋转过程：x 成为新的子树根节点，y 成为 x 的左子节点，x 原来的左子树 C 变为 y 新的右子节点
      - 旋转后：两侧高度重新恢复平衡
   2. 新节点插入到 x 的左子树 → 需要 right-left rotation（先右旋、后左旋的双旋转）
      - 结构：y - x（x 是 y 的右子节点）- z（z 是 x 的左子节点）；新节点插入到 z 下方
      - 旋转过程：先以 x 为轴做 right rotation，再以 y 为轴做 left rotation；z 成为新的子树根节点，y 成为 z 的左子节点，x 成为 z 的右子节点，z 原本的两棵子树分别拆分给 y 和 x
2. 新节点插入到 y 的左子树，且 y 在插入前是 left-heavy
   1. 新节点插入到 x 的左子树（x 是 y 的左子节点）→ 需要 right rotation（是情形 1.1 的镜像）
   2. 新节点插入到 x 的右子树 → 需要 left-right rotation（是情形 1.2 的镜像）

四种失衡类型（LL/RR/LR/RL）的速查表、判定流程和树形图例见 [4种失衡情况.md](4种失衡情况.md)。
