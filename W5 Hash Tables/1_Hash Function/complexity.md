## Hash Function — Complexity

- 计算 h(k) 本身在两种方法下均为 Θ(1)（常数时间）
- 这里的“复杂度”关注点不是运行时间，而是对参数 m 的 robustness（鲁棒性）——即哈希函数是否会因为 m 选得不好而导致 key 分布不均匀

| Method | 对 m 的敏感性 |
|---|---|
| Decision Method（Division Method） | 敏感于 m 的取值，限制了表大小的选择 |
| Multiplication Method | 不敏感于 m 的取值 |
