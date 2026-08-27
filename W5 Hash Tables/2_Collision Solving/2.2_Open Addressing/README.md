## Open Addressing（开放定址）— 总览

- 前置问题：Chaining 需要为每个 bucket 额外维护链表（指针开销）。Open Addressing 换一种思路——**不用链表，所有元素直接存在哈希表数组 T 本身之中**
- 定义：发生 collision 时，按某种系统化的方式在 T 里继续寻找空闲位置，这个过程称为 **probing（探测）**
- 因为元素都存在数组里：存储的 key 数量不能超过数组长度，即 **n ≤ m，load factor α = n/m ≤ 1**

### Probe 序列

- 探测函数 `probe(k, i)`，i = 0, 1, 2, ... 依次给出要检查的 slot 下标
- `probe(k, 0) = h(k)`（第一个探测位置就是哈希值本身）
- 三种具体的 probe 方式，见对应子文件夹：

| 方式 | 公式 | 关键问题 | 子文件夹 |
|---|---|---|---|
| Linear Probing | `(h(k) + i) mod m` | Primary clustering（一次聚集） | [2.2.1_Linear Probing/](2.2.1_Linear%20Probing/) |
| Quadratic Probing | `(h(k) + c₁i + c₂i²) mod m` | Secondary clustering（二次聚集）；探测序列可能覆盖不全 | [2.2.2_Quadratic Probing/](2.2.2_Quadratic%20Probing/) |
| Double Hashing | `(h₁(k) + i·h₂(k)) mod m` | h₂(k) 必须与 m 互质 | [2.2.3_Double Hashing/](2.2.3_Double%20Hashing/) |

### 三种 slot 状态

Open Addressing 的删除比 Chaining 麻烦，必须区分三种状态：

- **EMPTY**：从没被用过 —— Search 一旦探测到它就可以断定「key 不在表中」并停止
- **OCCUPIED**：存了一个 key-value 对
- **DELETED（tombstone，墓碑）**：曾经有元素、现在被删了 —— Search 遇到它要**继续**往下探测（不能停），Insert 可以把它当空位复用

若删除时直接把 slot 置为 EMPTY，会截断别人的探测链：后面那些「本该经过这个 slot 才能找到」的 key 就搜不到了。

### 通用操作

```
Search(T, k):
  for i = 0, 1, 2, ..., m-1:
      s = probe(k, i)
      if T[s] is EMPTY:        return NOT_FOUND      # 探测链到头
      if T[s] is OCCUPIED and T[s].key == k:  return T[s]
      # DELETED 或 key 不匹配 -> 继续
  return NOT_FOUND

Insert(T, k, v):
  记录第一个遇到的 DELETED 位置（可复用）
  沿 probe 序列走：遇到 k 本身 -> 覆盖 value；遇到 EMPTY -> 停
  把 (k, v) 放到「第一个 DELETED」或「那个 EMPTY」

Delete(T, k):
  按 Search 找到 k -> 把该 slot 标记为 DELETED
```

### Average-Case Running Time（基于 uniform hashing 假设）

| Search 类型 | 期望探测次数 |
|---|---|
| Unsuccessful（查找失败） | `1 / (1 − α)` |
| Successful（查找成功） | `(1/α) · ln(1 / (1 − α))` |

- 这是「理想 probe 方式」下的结果，只有 Double Hashing 比较接近；Linear / Quadratic 因为聚集问题实际更差（见各自 complexity.md）
- α → 1 时 `1/(1−α)` 爆炸；实践中让 **α < 0.5**
- 最坏情况（探测链退化）：Θ(n)
