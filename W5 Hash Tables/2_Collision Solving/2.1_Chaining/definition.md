## Chaining（链式法）— 定义

Hash Table 本身的定义（Universe、Direct-Address Table、Hash Function、collision）见 [W5 Hash Tables/README.md](../../README.md)，这里只讲 Chaining 这一种碰撞处理方式。

- Chaining 是解决 collision 的一种方式：数组中每个 bucket 都指向一个存储 key-value 对的链表（linked list）
- 落到同一个 bucket 的所有 key（即发生碰撞的 key）都挂在同一条链表上
- T[i] 保存链表的表头指针；空 bucket 的 T[i] 为 NULL
- 插入固定采用**头插**（插到链表头部），这样 Insert 本身是 Θ(1)，不需要走到链表尾

### 例子

- 设 m = 13，哈希函数用 Division Method：h(k) = k mod 13
- 依次插入 key：1, 14, 27, 5, 18
  | key | h(k) = k mod 13 | 落入 bucket |
  |---|---|---|
  | 1  | 1  | T[1] |
  | 14 | 1  | T[1]（与 1 碰撞） |
  | 27 | 1  | T[1]（与 1、14 碰撞） |
  | 5  | 5  | T[5] |
  | 18 | 5  | T[5]（与 5 碰撞） |
- 因为是头插，后插入的排在链表更靠前的位置：T[1] 里顺序是 27 → 14 → 1

### 图例

```
          T (长度 m = 13)
        ┌──────┐
   0    │ NULL │
        ├──────┤
   1    │  ●───┼──▶ [27|•]──▶ [14|•]──▶ [1|NULL]
        ├──────┤
   2    │ NULL │
        ├──────┤
  ...   │ ...  │
        ├──────┤
   5    │  ●───┼──▶ [18|•]──▶ [5|NULL]
        ├──────┤
  ...   │ ...  │
        ├──────┤
  12    │ NULL │
        └──────┘

   [key|next]  一个链表节点；实际还存有 value
```

- **Search(27)**：算 h(27) = 1 → 走到 T[1] 的链表 → 逐个比较 27 → 14 → 1，第一个就命中
- **Search(40)**：h(40) = 1 → 遍历 T[1] 整条链表（27、14、1）都不等 → 返回「未找到」
- **Delete(14)**：h(14) = 1 → 在 T[1] 链表中找到 14 → 把它前驱 27 的 next 指向 14 的后继 1，即 27 → 1
- 若某个 bucket 的链表很长（大量碰撞），该 bucket 上的操作退化到 Θ(链表长度）——最坏情况全部 key 落同一 bucket 时为 Θ(n)（详见 [complexity.md](complexity.md)）
