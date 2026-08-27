## Chaining — Implementation（实现）

### Insertion

- 实现
  ```
  ChainedHashInsert(T, k, v):
  1. 计算 h(k)，令 i = h(k)
     i = h(k)
  2. 检查 T[i] 处的链表中是否已存在 key 为 k 的元素
     search T[i] for an element with key k
  3. 若存在，用 v 替换其原有的值；若不存在，将新节点插入链表头部
     if found:
         replace existing value with v
     else:
         insert new node at head of T[i]
  ```
- 最坏情况运行时间：Θ(n)
- 平均情况运行时间：Θ(1 + α)（详见 [complexity.md](complexity.md)）

### Search

- 实现
  ```
  ChainedHashSearch(T, k):
  1. 计算 h(k)，令 i = h(k)
     i = h(k)
  2. 访问表中下标 i 的位置
     access T[i]
  3. 在 T[i] 处的链表中查找 key 为 k 的元素
     search T[i] for an element with key k
  ```
- 最坏情况运行时间：Θ(n)
- 平均情况运行时间：Θ(1 + α)

### Deletion

- 实现
  ```
  ChainedHashDelete(T, k):
  1. 计算 h(k)，令 i = h(k)
     i = h(k)
  2. 在 T[i] 处的链表中查找 key 为 k 的元素
     search T[i] for an element with key k
  3. 若找到，将其从链表中删除
     if found: remove it from the list
  ```
- 最坏情况运行时间：Θ(n)
- 平均情况运行时间：Θ(1 + α)
