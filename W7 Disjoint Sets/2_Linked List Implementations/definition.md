## Linked List Implementations — 定义

### Circularly-Linked Lists

- 每个集合对应一个循环链表（circularly-linked list）
- 链表的头节点（head）就是该集合的代表元

### Linked Lists with Pointer to Head

- 每个集合对应一个链表
- 除头节点外，链表中的每个节点都有一个指针 `x.rep` 直接指向头节点
- 头节点就是该集合的代表元
- 头节点还存有一个指向链表尾部的指针 `x.tail`，便于快速找到尾节点以支持后续的合并操作
- 相比 Circularly-Linked Lists 的改进：FindSet 不再需要沿着链表走到头节点，而是直接读取 `x.rep`，从 Θ(L) 降为 Θ(1)

### Linked Lists with Pointer to Head and Union-By-Weight

- 结构与上面相同（每个节点有 `x.rep` 指向头节点，头节点有 `x.tail` 指向尾节点），但头节点额外存储链表的大小 `x.size`
- Union 时总是把**较短**的链表接到**较长**的链表后面（而不是任意顺序拼接）——这就是 union-by-weight（也叫 union-by-size）启发式
- 相比上一版本的改进：单次 Union 的最坏情况复杂度不变，但通过总是把短链表接到长链表上，限制了任意元素的 `rep` 指针被更新的总次数，从而改进了摊还复杂度（详见 [complexity.md](complexity.md)）
