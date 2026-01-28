# Number of Islands II

**Difficulty:** Hard
**Tags:** union-find, disjoint-set, dynamic-connectivity, graph

## Problem

Given an m×n grid initially filled with water, perform a sequence of operations where each operation converts a water cell at a given position into land. After each operation, count the number of distinct islands (connected components of land cells, where connectivity is defined by horizontal or vertical adjacency). Return an array showing the island count after each operation. The grid dimensions and number of operations can each be up to 10^4, with the product m×n also capped at 10^4.

## Approach

The solution uses **Union-Find (Disjoint Set Union)** to dynamically track connected components as land cells are added.

- Each cell is mapped to a unique integer ID (row × n + col), and a parent array tracks the forest of set representatives. Initially all cells are marked as water (parent[id] = -1).

- For each position to add land: if already land (duplicate operation), the current island count is recorded. Otherwise, the cell becomes its own set (parent[id] = id) and the island count increments by one.

- The algorithm then checks all four orthogonal neighbors. For each neighbor that is already land (parent[nid] ≠ -1), it attempts to union the two sets. The union operation uses path compression in `find` and union-by-rank to maintain efficiency. Crucially, the island count decrements only when `unite` successfully merges two previously-separate components (returns true).

- The result array is built by appending the current island count after processing each operation.

## Complexity

- **Time:** O(k × α(m×n))
- **Space:** O(m×n)

## Stats

- Submitted: 2026-01-28 02:41 UTC
- Runtime: 9 ms
- Memory: 41.4 MB
- Language: C++
