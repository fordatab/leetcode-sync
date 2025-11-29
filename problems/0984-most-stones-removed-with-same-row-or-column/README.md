# Most Stones Removed with Same Row or Column

**Difficulty:** Medium
**Tags:** depth-first-search, graph, hash-table, connected-components, union-find

## Problem

Given n stones placed at integer coordinates on a 2D plane, where each position contains at most one stone, determine the maximum number of stones that can be removed. A stone can only be removed if it shares a row or column with at least one other remaining stone. The input is an array of coordinate pairs, with up to 1000 stones and coordinates ranging from 0 to 10,000.

## Approach

The solution treats this as a graph connectivity problem where stones in the same row or column are implicitly connected. It builds two hash maps: one mapping each row to its column positions (h), and another mapping each column to its row positions (v). Then it performs depth-first search (DFS) to identify connected components—groups of stones that share rows or columns transitively.

For each unvisited stone, it initiates a DFS that marks all reachable stones by exploring both horizontally (same row, different columns) and vertically (same column, different rows). Each DFS traversal identifies one connected component.

The key insight is that within each connected component of k stones, exactly k-1 stones can be removed, leaving one stone behind. Therefore, if there are c connected components among n total stones, the answer is n - c (total stones minus the number of components that must remain).

## Complexity

- **Time:** O(n²)
- **Space:** O(n)

## Stats

- Submitted: 2025-11-29 11:08 UTC
- Runtime: 40 ms
- Memory: 33.5 MB
- Language: C++
