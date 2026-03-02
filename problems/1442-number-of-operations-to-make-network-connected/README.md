# Number of Operations to Make Network Connected

**Difficulty:** Medium
**Tags:** union-find, disjoint-set, graph, connected-components

## Problem

Given n computers and a list of ethernet cable connections between them, determine the minimum number of cable reconnection operations needed to make all computers form a single connected network. Cables can be removed from any existing connection and placed between any two disconnected computers. If there aren't enough cables to connect all computers, return -1. The number of computers can be up to 100,000.

## Approach

The solution uses a Disjoint Set Union (Union-Find) data structure to track connected components. First, it checks if there are at least n-1 cables available, which is the minimum needed to connect n computers into a tree. If not, it returns -1 immediately.

It then processes all connections using the DSU's `unite` operation, which merges components that are directly connected. The DSU implementation uses path compression in `find` and union-by-rank in `unite` for efficiency.

After processing all connections, it counts the number of distinct connected components by checking how many nodes are their own parent (root nodes). The answer is `components - 1` because connecting k components requires exactly k-1 cables, and any extra cables beyond the initial n-1 can be reused for this purpose.

## Complexity

- **Time:** O(n + m α(n))
- **Space:** O(n)

## Stats

- Submitted: 2026-03-02 23:12 UTC
- Runtime: 8 ms
- Memory: 42.2 MB
- Language: C++
