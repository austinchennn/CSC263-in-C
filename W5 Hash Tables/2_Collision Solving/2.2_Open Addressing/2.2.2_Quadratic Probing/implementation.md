## Quadratic Probing — Implementation（实现）

配套代码：[hashtable.h](hashtable.h) / [hashtable.c](hashtable.c) / [main.c](main.c)

### 探测函数

```
probe_quadratic(k, i):
    return (h(k) + i*i) mod m        # c1 = 0, c2 = 1；h(k) = k mod m
```

- 代码里 i*i 先对 m 取模再相加，避免 i 较大时溢出

### Search / Insert / Delete

骨架与 Linear Probing 完全一样（见 [../README.md](../README.md)），只把 `probe` 换成 `probe_quadratic`：

```
Search(T, k):
  for i = 0 .. m-1:
      s = (h(k) + i*i) mod m
      if T[s].state == EMPTY:                       return NULL
      if T[s].state == OCCUPIED and T[s].key == k:  return &T[s]
  return NULL

Insert(T, k, v):
  同 Linear，只是 s = (h(k) + i*i) mod m
  # 注意：只有在 m 为素数且 α < 1/2 时才保证一定能找到空位
```

### 与 Linear Probing 的取舍

- 好处：消除 primary clustering，高负载时比 Linear 好
- 代价：
  1. secondary clustering 仍在
  2. 必须维持 m 素数 + α < 1/2，否则可能插不进去
  3. 内存访问跳跃，cache 局部性不如 Linear

### 复杂度

- 介于 Linear Probing 和 Double Hashing 之间
- 详见 [complexity.md](complexity.md)
