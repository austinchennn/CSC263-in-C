<p align="center">
  <img src="assets/logo.png" alt="CSC263-in-C logo — a binary search tree" width="480">
</p>

# CSC263-in-C

C implementations of the data structures and algorithms covered in **CSC263H1: Data Structures and Analysis** (University of Toronto).

## Topics

Based on the course's lecture notes, organized by chapter. Checked items have an implementation in this repo.

- [x] Complexity — asymptotic notation, worst-case vs. average-case analysis
- [x] Priority Queues and Heaps — binary heap (array-based), heap sort
- [ ] Dictionaries and Binary Search Trees — BST insert/search/delete, successor
- [ ] AVL Trees and Augmented Data Structures — rotations, balance factor
- [ ] Hash Tables — chaining, open addressing (linear/quadratic/double hashing)
- [ ] Amortized Analysis — dynamic arrays, aggregate/accounting methods
- [ ] Disjoint Sets — union-by-rank, path compression
- [ ] Graphs and BFS — adjacency list/matrix, shortest paths
- [ ] DFS — topological sort, strongly connected components
- [ ] Minimum Spanning Trees — Kruskal's, Prim's
- [ ] Randomized Quick Sort

## Structure

```
1_PriorityQueue/
  1.2_Binary Heap Implementation/
    pq.h      # priority queue interface
    pq.c      # binary heap implementation
    main.c    # usage / manual tests
```

Each topic gets its own numbered top-level folder as it's implemented.

## Building

Each implementation is a standalone C project. From within a topic's folder:

```sh
clang -g main.c pq.c -o pq_demo
./pq_demo
```

## References

- Logo image is a screenshot from a video by bilibili UP主 [蓝不过海呀](https://space.bilibili.com/401399175?spm_id_from=333.788.upinfo.detail.click)
- [XinyueLi](https://github.com/hecateli/uoft/blob/main/CSC263_Course_Note.pdf) — CSC263 course notes
- [Zixin (Jenci) Wei](https://www.cs.toronto.edu/~wei/notes/) — CSC263 course notes
