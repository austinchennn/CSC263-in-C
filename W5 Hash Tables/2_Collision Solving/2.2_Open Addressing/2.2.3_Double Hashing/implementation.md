## Double Hashing — Implementation（实现）

配套代码：[hashtable.h](hashtable.h) / [hashtable.c](hashtable.c) / [main.c](main.c)

### 两个哈希函数

```
h1(k) = k mod m
h2(k) = 1 + (k mod (m - 1))          # 落在 [1, m-1]，m 素数时与 m 互质

probe_double(k, i):
    return (h1(k) + i * h2(k)) mod m
```

### Search / Insert / Delete

骨架与 Linear / Quadratic 一样（见 [../README.md](../README.md)），把 `probe` 换成 `probe_double`：

```
Search(T, k):
  s0 = h1(k);  step = h2(k)
  for i = 0 .. m-1:
      s = (s0 + i * step) mod m
      if T[s].state == EMPTY:                       return NULL
      if T[s].state == OCCUPIED and T[s].key == k:  return &T[s]
  return NULL

Insert(T, k, v):
  同上，s = (h1(k) + i * h2(k)) mod m
  # m 素数 => gcd(h2(k), m) = 1 => 探测序列遍历所有 slot，表没满就一定插得进
```

### 复杂度

- 探测序列约 m² 种，最接近 uniform hashing
- unsuccessful ≈ `1/(1−α)`，successful ≈ `(1/α)·ln(1/(1−α))`（几乎就是理论值）
- 详见 [complexity.md](complexity.md)

### 代价

- 每次探测多算一个 h₂(k)（不过 h₂(k) 只需算一次，之后是加法）
- 内存访问最跳跃，cache 局部性最差
