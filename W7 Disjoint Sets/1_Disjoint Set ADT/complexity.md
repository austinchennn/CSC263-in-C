## Disjoint Set（ADT）— Complexity

- 本节仅定义 ADT 接口（MakeSet / FindSet / Union），并不限定底层数据结构，因此没有固定的复杂度可言
- 具体操作的复杂度取决于底层实现方式，见后续小节
  - 链表实现（Circularly-Linked List、Linked List with Pointer to Head、以及加上 Union-By-Weight 的版本）— 见 `2_Linked List Implementations/complexity.md`
  - 树实现（Trees、Union-by-Rank、Path-Compression、以及两者结合）— 见 `3_Tree Implementations/complexity.md`
