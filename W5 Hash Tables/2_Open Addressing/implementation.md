## Open Addressing — Implementation（实现）

### Search

- 实现
  ```
  OpenAddressingSearch(T, k):
  1. 沿用 Insertion 所用的同一套 probing 序列，依次检查各个 slot
     for i = 0, 1, 2, ...:
         slot = probe(k, i)     # 按 linear / quadratic / double hashing 计算探测位置
  2. 若探测到第一个存储 None 的 bucket，则返回 None（说明 k 不在表中）
         if T[slot] == None:
             return None
  3. 若探测到的 bucket 中存储的 key 恰为 k，则返回该元素
         if T[slot].key == k:
             return T[slot]
  ```
- NOTE：查找一个元素往往需要检查不止一个位置，而不能只看 h(k) 对应的那一个 slot
- 平均情况运行时间（unsuccessful search）：1 / (1 − α)
- 平均情况运行时间（successful search）：(1/α) × ln(1 / (1 − α))

### Probing（探测）

- Linear Probing
  ```
  probe_linear(k, i):
      return (h(k) + i) mod m      # 按线性序列依次检查 slot
  ```
- Quadratic Probing
  ```
  probe_quadratic(k, i):
      return (h(k) + c1*i + c2*i**2) mod m   # 按二次序列检查 slot
  ```
- Double Hashing
  ```
  probe_double(k, i):
      return (h1(k) + i * h2(k)) mod m       # 用第二个哈希函数生成依赖 key 的步长
  ```
- 实践中，α < 0.5 时 Open Addressing 表现最好
