## Augmented Data Structure — 定义

- 背景：有时我们希望在已有数据结构的基础上支持一些新的查询或操作，而不想从头设计一个全新的数据结构；Augmented Data Structure 提供了一种系统化的改造方法
- 定义：Augmented Data Structure 是对现有数据结构的一种修改，通过存储额外信息，和/或支持额外的操作来实现

### 设计步骤（通用方法）

1. 选择要增强（augment）的数据结构
2. 确定需要存储的额外信息
3. 检查这些额外信息能否在原有操作执行过程中被正确维护
4. 实现新增的操作

### AVL Tree 的 Augmentation

- 在对 AVL tree 进行 augmentation 时，如果某节点的额外信息只依赖于该节点自身以及其子节点所存储的信息，那么这些额外信息就可以在 AVLInsert 和 AVLDelete 的执行过程中被高效地维护，且不会影响它们原本的最坏情况运行时间
