## Heap Sort — Implementation（实现）

- 实现
  ```
  HeapSort(A)
  1. 把 A 转换为 max-heap
  2. 令 count 指向 A 的末尾
     count = A.size
  3. 提取最大元素
     - 调用 HeapExtractMax(A[1 : count + 1])
     - 把提取出的最大元素放到 count 所指向的位置
     - count 减一
     while count > 0:
         extract_max = HeapExtractMax(A[1 : count + 1])
         A[count] = extract_max
         count -= 1
  4. 重复步骤 3，直到 count 为 0
  ```
- 最坏情况运行时间：Θ(n log n)

## BuildMaxHeap — Implementation（实现）

- 实现
  ```
  BuildMaxHeap(A):
      A.heap_size = A.length
      for i = ⌊A.length / 2⌋ down to 1:
          MaxHeapify(A, i)
  ```
- 最坏情况运行时间：Θ(log n)（讲义原文如此；注意这与 [complexity.md](complexity.md) 中自底向上构建的 O(n) 摊还结论不一致，疑似讲义笔误，实现方式本身并无差异）
