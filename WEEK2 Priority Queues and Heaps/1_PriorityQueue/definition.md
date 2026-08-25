## Priority Queue（ADT）— 定义

- Priority Queue 是一个**抽象数据类型（ADT, Abstract Data Type）**：只规定了一组对外暴露的操作接口，并不限定底层要用哪种数据结构实现
- 对象：一组元素的集合，每个元素都带有一个优先级
- 操作
  - `Insert(PQ, x, p)` — 将元素 x 以优先级 p 插入优先队列 PQ
  - `FindMax(PQ)` — 返回 PQ 中优先级最高的元素
  - `ExtractMax(PQ)` — 删除并返回 PQ 中优先级最高的元素
  - `IncreaseKey(PQ, x, k)` — 将元素 x 的优先级 p 提升为新值 k（假设 k 不小于原来的 p）

## Binary Heap（DS）— 定义

- Binary Heap 是一种具体的**数据结构（DS, Data Structure）**：是用来实现 Priority Queue 这一 ADT 的其中一种方式（其余方式见 [complexity.md](complexity.md) 中的对比表，例如无序/有序链表、数组、BST 等）

### Complete Binary Tree（完全二叉树）

- 一棵二叉树是完全二叉树，当且仅当它满足以下两个性质：
  1. 除最底层外，其余每一层都是满的
  2. 最底层的所有节点都尽量靠左排列
- 对于给定的节点数，完全二叉树的形状是唯一的

### Max-Heap / Min-Heap（大顶堆 / 小顶堆）

- Max/Min-Heap 性质：若树中每个节点的值都大于等于（或小于等于）其所有子孙节点的值，则称该树满足 Max/Min-Heap 性质
- Max/Min-Heap：满足 Max/Min-Heap 性质的完全二叉树
  - 推论：Max-Heap/Min-Heap 的任意子树也是 Max-Heap/Min-Heap

### 数组表示（Array Representation）

- 按层序遍历（从左到右、逐层）将树中节点存入数组
- 对于下标为 i 的节点（下标从 1 开始）：
  - 左子节点下标：2i
  - 右子节点下标：2i + 1
  - 父节点下标：⌊i / 2⌋
- 用于优先队列：数组 A 中每个元素 x 都带有键 x.p 表示其优先级，A 是一个基于优先级、以数组形式存储的 max-heap
