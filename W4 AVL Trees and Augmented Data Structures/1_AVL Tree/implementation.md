## AVL Tree — Implementation（实现）

### AVLInsert / AVLDelete

- 实现（以插入为例，删除同理）
  ```
  AVLInsert(root, x):
  1. 像 BST 一样插入
     if root == NIL:
         root = x
     else if root.key > x.key:
         AVLInsert(root.left, x)
     else:
         AVLInsert(root.right, x)
  2. 若仍然平衡，直接返回
     BF = root.right.height - root.left.height
  3. 否则（需要重新平衡）执行旋转
     if BF < -1 or BF > 1:
         fix_imbalance(root)
  4. 更新受影响节点的 height
     root.height = max(root.right.height, root.left.height) + 1
  ```
- 最坏情况运行时间：Θ(log n)
  - 步骤 1（按 BST 方式插入/删除）：Θ(h) = Θ(log n)
  - 步骤 2（检查平衡）：Θ(1)
  - 步骤 3（旋转）：Θ(1)
  - 步骤 4（更新 height）：Θ(log n)

### fix_imbalance

- 实现（根据 balance factor 判断需要哪一种旋转）
  ```
  fix_imbalance(D):
  1. 检查 balance factor 并执行相应旋转
     if D.balance_factor == -2:              # D 左重，对应 definition.md 中的情形 2
         if D.left.left.height == D.right.height + 1:
             right_rotate(D)                  # 对应情形 2.1：单次 right rotation
         else:  # D.left.right.height == D.right.height + 1
             left_rotate(D.left)               # 对应情形 2.2：left-right rotation
             right_rotate(D)                   # 先对 D.left 做 left rotation，再对 D 做 right rotation
     elif D.balance_factor == 2:               # D 右重，对应情形 1，与上面对称
         # 留作练习（讲义原文如此，与上面情形对称，未给出具体实现）
         ...
  ```
- 最坏情况运行时间：Θ(1)

### right_rotate

- 实现
  ```
  right_rotate(D):
  1. 引入临时变量，对应旋转示意图中的各个部分
     y = D.root
     x = D.left.root
     A = D.left.left
     B = D.left.right
     C = D.right
  2. 用 x 替换原来的根节点 y
     D.root = x
  3. x 的左子树保持为 A
     D.left = A
  4. 构造新的右子树：以 y 为根，B 为左子树，C 为右子树
     D.right = AVLTree(y, B, C)   # 假设已有构造函数 AVLTree(root, left, right)
  ```
- 最坏情况运行时间：Θ(1)
- 即：只需要重新连接常数个指针，不涉及递归或遍历
