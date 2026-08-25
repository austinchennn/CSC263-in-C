## QuickSort / Randomized QuickSort — Complexity

| 情形 | 运行时间 |
|---|---|
| Worst-Case（QuickSort，任意固定 pivot 策略） | O(n²) |
| Worst-Case（Randomized QuickSort，最坏情形仍可能发生，只是概率极低） | O(n²) |
| Average-Case（QuickSort，对所有输入排列取平均） | Θ(n log n) |
| Expected Running Time（Randomized QuickSort，对随机选择取期望，**任意固定输入**） | Θ(n log n) |

- Worst-Case 分析在证明什么：把整个 QuickSort 过程中 Line #4（`if A[j] ≤ x`）被执行的次数作为运行时间的度量。由于每个元素至多被选为一次 pivot，且一旦某元素成为 pivot 之后就不会再与任何其他元素比较，因此数组中任意一对元素 (a, b) 至多被比较一次；比较次数的上界即为所有元素对的个数 C(n,2) = n(n−1)/2，故 T(n) ∈ O(n²)
- Average-Case 分析在证明什么：并不是直接估算"划分是否均衡"，而是逐对（pairwise）地计算每一对元素 zi、zj 被比较到的概率，再对所有 Θ(n²) 对元素求和取期望。其中用到的关键事实（定理）是：zi 与 zj 会被 QuickSort 比较，当且仅当在 {zi, zi+1, ..., zj} 这些元素中，zi 或 zj 是第一个被选为 pivot 的元素。最终把期望比较次数 E[t_n] 化简后落在 Θ(n log n)（推导过程见 [implementation.md](implementation.md)）
- QuickSort 本身的 Average-Case 是"对所有输入排列均匀取平均"的结果，前提是输入排列本身服从均匀分布；而 Randomized QuickSort 通过先随机打乱数组，把这一前提**人为地强加**给了任意输入——因此对 Randomized QuickSort 而言，Θ(n log n) 是对任意固定输入、仅对算法内部随机选择取期望后的 Expected Running Time，而不再依赖"输入本身是否随机"这一假设
