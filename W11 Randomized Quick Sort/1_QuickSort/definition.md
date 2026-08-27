## QuickSort / Randomized QuickSort — 定义

- QuickSort 是一种分治（divide-and-conquer）、原地（in-place）的排序算法；Randomized QuickSort 在此基础上加入随机化步骤，使算法的性能与输入本身的排列顺序无关，从而在典型输入上规避掉 QuickSort Θ(n²) 的最坏情况

### QuickSort

- 思路（Idea）
  1. 若 len(A) 为 1，直接返回（递归基）
  2. 选取一个 pivot p
  3. 将数组划分（partition）为三部分
     - A1 — A 中小于 p 的元素
     - A2 — A 中等于 p 的元素
     - A3 — A 中大于 p 的元素
  4. 对 A1 和 A3 递归重复以上过程

### Randomized QuickSort

- 思路：先将输入数组均匀随机地打乱（shuffle），再对打乱后的数组调用普通 QuickSort
  - NOTE：打乱之后，数组看起来就像是从均匀分布中随机抽取出来的一样——这正是"随机化使性能与原始输入顺序无关"的关键
  - 另一种等价的随机化方式：不预先打乱整个数组，而是在每次划分时随机选取 pivot（而不是固定取最后一个元素）
- 按照"算法的随机性体现在哪里"这一标准，可以把随机算法分为两类
  - **Las Vegas Algorithm**：算法给出的解**保证正确**，但运行时间依赖于随机选择
    - Randomized QuickSort（先随机打乱数组，再调用 QuickSort）属于此类
    - 随机选取 pivot 的做法同样属于此类
  - **Monte Carlo Algorithm**：算法的运行时间是确定的，但输出结果依赖于随机选择（即输出不一定保证正确）
