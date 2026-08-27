## Prim's Algorithm — Complexity

假设使用 binary min-heap 和邻接表（adjacency lists）

| 步骤 | 操作 | 复杂度 |
|---|---|---|
| 1 | Line #3–#5 的 for 循环 | O(n) |
| 2 | 构建 Min-Heap（Building Min-Heap） | O(n) |
| 3 | 单次堆操作（Heap Operations） | O(log n) |
| 4 | 所有 ExtractMin 调用的总运行时间 | O(n log n) |
| 5 | 所有 DecreaseKey 调用的总运行时间 | O(m log n) |

总运行时间：O((n + m) log n)

若 G 连通，则运行时间为 O(m log n)

## Kruskal's vs Prim's — Comparison

| | Input Graph G | Keep track of Connected Components | Find Minimum Weight Edge |
|---|---|---|---|
| Kruskal's | If G is not connected, generates a minimum spanning forest | Disjoint-Sets ADT | Sort all edges according to weight |
| Prim's | G has to be connected | Keep One Tree plus Isolated Vertices | Use Priority Queue ADT |
