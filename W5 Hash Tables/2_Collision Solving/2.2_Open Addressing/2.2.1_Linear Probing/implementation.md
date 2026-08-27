## Linear Probing — Implementation（实现）

配套代码：[hashtable.h](hashtable.h) / [hashtable.c](hashtable.c) / [main.c](main.c)

### 探测函数

```
probe_linear(k, i):
    return (h(k) + i) mod m       # h(k) = k mod m
```

### Search / Insert / Delete

通用骨架见 [../README.md](../README.md)，这里只是把 `probe` 换成 `probe_linear`：

```
Search(T, k):
  for i = 0 .. m-1:
      s = (h(k) + i) mod m
      if T[s].state == EMPTY:                       return NULL
      if T[s].state == OCCUPIED and T[s].key == k:  return &T[s]
  return NULL

Insert(T, k, v):
  first_deleted = -1
  for i = 0 .. m-1:
      s = (h(k) + i) mod m
      if T[s].state == OCCUPIED and T[s].key == k:  T[s].value = v; return
      if T[s].state == DELETED and first_deleted < 0: first_deleted = s
      if T[s].state == EMPTY:
          pos = (first_deleted >= 0) ? first_deleted : s
          T[pos] = OCCUPIED(k, v); n++; return
  # 到这里说明表满（且没有可复用的 DELETED）

Delete(T, k):
  按 Search 找到 k 的 slot s -> T[s].state = DELETED; n--
```

### 复杂度

- 理论（uniform hashing）：unsuccessful `1/(1−α)`，successful `(1/α)·ln(1/(1−α))`
- 实际（Knuth，计入 primary clustering）：
  - unsuccessful ≈ `½ (1 + 1/(1−α)²)`
  - successful ≈ `½ (1 + 1/(1−α))`
- 详见 [complexity.md](complexity.md)
