# Open the Lock

**Difficulty:** Medium
**Tags:** breadth-first-search, graph-traversal, hash-table, string-manipulation

## Problem

Given a four-digit combination lock starting at "0000", find the minimum number of single-digit turns needed to reach a target combination. Each wheel can be rotated forward or backward (wrapping from 9 to 0 and vice versa). Certain combinations are "deadends" that block further progress. If the target is unreachable or the starting position is a deadend, return -1.

## Approach

This solution uses **breadth-first search (BFS)** to explore all reachable lock states level by level. The deadends are stored in an unordered set for O(1) lookup. Starting from "0000", the algorithm processes states in layers, where each layer represents one additional turn. For each state, it generates all eight possible neighbors (incrementing or decrementing each of the four digits), checking whether each neighbor is already visited or is a deadend. Visited states are added to the deadend set to avoid revisiting. The search continues until the target is found (returning the current depth) or all reachable states are exhausted (returning -1). The level-by-level processing ensures the first time the target is encountered, it's via the shortest path.

## Complexity

- **Time:** O(10^4)
- **Space:** O(10^4)

## Stats

- Submitted: 2026-06-13 10:12 UTC
- Runtime: 110 ms
- Memory: 38.5 MB
- Language: C++
