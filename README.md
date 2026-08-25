<p align="center">
  <img src="assets/logo.png" alt="CSC263-in-C logo — a binary search tree" width="480">
</p>

# CSC263-in-C

C implementations of the data structures and algorithms covered in **CSC263H1: Data Structures and Analysis** (University of Toronto).

## Topics

Based on the course's lecture notes, organized by week (Weeks 0-11). Checked items have an implementation in this repo.

- [ ] Week 0 — Orientation
   - Course syllabus, no lecture topic
1. [x] Week 1 — Complexity
   - Asymptotic notation, worst-case vs. average-case analysis
2. [x] Week 2 — Priority Queues and Heaps
   - Binary heap (array-based), heap sort
3. [ ] Week 3 — Dictionaries and Binary Search Trees
   - BST insert/search/delete, successor
4. [ ] Week 4 — AVL Trees and Augmented Data Structures
   - Rotations, balance factor
5. [ ] Week 5 — Hash Tables
   - Chaining, open addressing (linear/quadratic/double hashing)
6. [ ] Week 6 — Amortized Analysis
   - Dynamic arrays, aggregate/accounting methods
7. [ ] Week 7 — Disjoint Sets
   - Union-by-rank, path compression
8. [ ] Week 8 — Graphs and BFS
   - Adjacency list/matrix, shortest paths
9. [ ] Week 9 — DFS
   - Topological sort, strongly connected components
10. [ ] Week 10 — Minimum Spanning Trees
    - Kruskal's, Prim's
11. [ ] Week 11 — Randomized Quick Sort

## Structure

```
WEEK2 Priority Queues and Heaps/
  1_PriorityQueue/
    1.2_Binary Heap Implementation/
      pq.h      # priority queue interface
      pq.c      # binary heap implementation
      main.c    # usage / manual tests
  2_Heap Sort/
    heapsort.c  # in-place heap sort
```

Each week gets its own `WEEKn ...` top-level folder as it's implemented, with subfolders for each topic/subtopic within that week.

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
