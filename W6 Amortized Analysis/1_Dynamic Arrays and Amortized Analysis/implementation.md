## Dynamic Array — Implementation（实现）

### Append

- 实现
  ```
  Append(A1, x):
  1. 检查数组是否已满
     if n == k:
  2. 若已满，创建一个大小为原数组两倍的新数组 A2
         Create a new array A2 with size 2 × k
  3. 把 A1 中所有元素复制到 A2
         Copy all the elements from A1 to A2
  4. 更新容量 k，并把 x 接到 A2 末尾
         k = k × 2
         n = n + 1
         A2[n] = x
     else:
  5. 若未满，直接把 x 接到 A1 末尾
         n = n + 1
         A1[n] = x
  ```
- 最坏情况运行时间（单次 Append）
  - 未触发扩容：Θ(1)
  - 触发扩容（需要复制 n 个已有元素）：Θ(n)

### 例（Example Trace）

- 从 k = 1, n = 0 开始，依次执行 `Append(10)`, `Append(20)`, `Append(5)`, `Append(7)`, `Append(9)`
- 数组容量随着每次被填满而翻倍：k = 1 → 2 → 4 → 4 → 8，对应 n = 1, 2, 3, 4, 5
- 第 n 次 Append 的代价：
  ```
  T(n) = 1 + n     若 n 是 2 的幂（触发一次 resize / copy）
  T(n) = 1         否则（直接插入，无需扩容）
  ```
- 直觉：虽然某几次 Append 会很贵（需要把之前所有元素复制一遍），但这样的"贵"操作出现得越来越稀疏（容量每次翻倍），使得整个序列的总代价仍然可控——具体推导见 2_Aggregate Method 和 3_Accounting Method
