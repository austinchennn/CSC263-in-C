## Priority Queue — Implementation（实现）

### FindMax

- 实现
  ```
  HeapMaximum(A): 返回 A 的根节点
      return A[1]
  ```
- 最坏情况运行时间：Θ(1)

### IncreaseKey

- 实现（假设 i 是元素 x 在数组中的下标）
  ```
  HeapIncreaseKey(A, i, k):
  1. 将 x 的优先级设为 k
     A[i].p = k
  2. 不断与父节点交换，把 x 上浮到合适位置，直到 k 不大于父节点的优先级
     i = A.size
     while i > 1:
         curr_p = A[i].p
         parent_p = A[i // 2].p
         if curr_p <= parent_p:          # 已满足堆性质，跳出循环
             break
         else:
             A[i], A[i // 2] = A[i // 2], A[i]
             i = i // 2
  ```
  例：`HeapIncreaseKey(A, 5, 12)`
- 最坏情况运行时间：Θ(log n)
- 即：把一个叶子节点一路上浮到根节点
- Θ(h) = Θ(log n)，其中 h 是堆的高度，n 是堆中的节点数

### MaxHeapInsert

- 实现
  ```
  MaxHeapInsert(A, x, k):
  1. 将 x 插入到能保持完全二叉树性质的（唯一）位置
     A.size += 1
     A[A.size].item = x
     A[A.size].p = k
  2. 把 x 上浮到合适位置以维持 max-heap 性质
     …  # 与 IncreaseKey 相同
  ```
- 最坏情况运行时间：Θ(log n)

### MaxHeapify

- 前置条件：i 是完全二叉树 B 中的一个节点，以 Left(i) 和 Right(i) 为根的子树均已经是 max-heap
- 后置条件：以 i 为根的子树是 max-heap
- 实现
  ```
  MaxHeapify(B, i): 通过与子节点交换，把 i 下沉到合适位置
  1. 比较根节点与其子节点
     - 若根节点最大，则该树已经是 Max-Heap
     - 否则，把根节点与较大的子节点交换
  2. 对被交换的子节点所在的子树重复步骤 1，以维持 max-heap 性质
     while i * 2 <= B.size:
         curr_p = B[i].p
         left_p = B[2 * i].p
         right_p = B[2 * i + 1].p

         if curr_p >= left_p and curr_p >= right_p:
             break
         else if left_p >= right_p:
             B[i], B[2 * i] = B[2 * i], B[i]
             i = 2 * i
         else:
             B[i], B[2 * i + 1] = B[2 * i + 1], B[i]
             i = 2 * i + 1
  ```
- 最坏情况运行时间：Θ(log n)
- 即：把根节点一路下沉到叶子节点

### HeapExtractMax

- 实现
  ```
  HeapExtractMax(H):
  1. 返回树的根节点
     root = H[1]
  2. 用堆中最后一个节点 f 替换根节点，以保持树仍是完全二叉树
     H[1] = H[H.size]
     H.size -= 1
  3. 把 f 下沉到合适位置以维持 max-heap 性质
     i = 1
     …  # 与 MaxHeapify 相同
  ```
- 最坏情况运行时间：Θ(log n)

## 小结（Conclusion）

- 直觉：堆是一棵部分有序的树 — 足以让查询类操作变快，同时不需要在每次更新后都完全排序
- 完全二叉树：保证树的高度较小
- 堆序性质：支持更快的堆操作
