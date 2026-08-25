## Priority Queue — Complexity

| Underlying Structure | Insert | FindMax | ExtractMax |
|---|---|---|---|
| Unsorted Linked List | Θ(1) | Θ(n) | Θ(n) |
| Unsorted Array | Θ(1) | Θ(n) | Θ(n) |
| Sorted Array | Θ(n) | Θ(1) | Θ(1) |
| Ordered Linked List | Θ(n) | Θ(1) | Θ(1) |
| Binary Search Tree | Θ(h) | Θ(h) | Θ(h) |
| Binary Heap (array-based) | Θ(h) = Θ(log n) | Θ(1) | Θ(h) = Θ(log n) |

## Binary Heap Operations

| Operation | Complexity |
|---|---|
| MaxHeapInsert | Θ(log n) |
| FindMax | Θ(1) |
| IncreaseKey | Θ(log n) |
| HeapExtractMax (MaxHeapify) | Θ(log n) |
