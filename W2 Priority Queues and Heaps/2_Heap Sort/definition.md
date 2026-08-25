## Heap Sort — 定义

给定一个 max-heap H，反复执行 n 次「提取最大元素」操作，就能由 H 得到一个数组：被提取出的键值依次排列，结果是一个不升序（non-ascending）的数组。

- 前置条件：A 是一个大小为 n 的任意数组（下标从 1 开始）
- 后置条件：A 按不降序（non-decreasing）排列

## BuildMaxHeap — 定义

总体思路：自底向上地构建一个 max-heap

1. 把数组视为一棵完全二叉树的层序遍历结果
2. 从树的底部开始，对所有非叶子节点调用 MaxHeapify
