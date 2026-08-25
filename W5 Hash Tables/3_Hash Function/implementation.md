## Hash Function — Implementation（实现）

### Decision Method（Division Method，除法散列法）

- 实现
  ```
  h(k):
      return k mod m     # 用 k 除以 m 取余作为哈希值
  ```
- Pitfall（缺点）：对 m 的取值敏感，限制了表大小的选择
  - k mod 2^p 只依赖于 k 的最后 p 位，因此若 m 恰为 2 的幂，哈希值会只由 k 的低位决定
  - 较好的选择：取 m 为一个不接近 2 的整数次幂的素数
- NOTE：若选择了不好的 m，key 会分布不均匀（未被充分“打散”）
- 计算 h(k) 的运行时间：Θ(1)

### Multiplication Method（乘法散列法）

- 实现
  ```
  h(k):
  1. 将 k 乘以一个实数常数 A（0 < A < 1）
     product = k * A
  2. 取 k × A 的小数部分 x（注意 0 < x < 1）
     x = fractional_part(product)
  3. 令 h(k) = ⌊m × x⌋
     return floor(m * x)
  ```
- 优点：不敏感于 m 的取值
- 计算 h(k) 的运行时间：Θ(1)
