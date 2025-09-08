# Making A Large Island

**Difficulty:** Hard
**Tags:** depth-first-search, union-find, matrix, graph, connected-components

## Problem

Given an n×n binary grid where 1s represent land and 0s represent water, find the maximum island size (4-directionally connected 1s) after optionally changing at most one 0 to a 1. The grid dimensions can be up to 500×500, and if the grid is already all 1s, no change is needed.

## Approach

The solution uses a two-phase approach:

**Phase 1 - Island Identification:** Traverse the grid and use DFS to identify each connected island component. For each island found, assign it a unique identifier (idx) and calculate its size. Store a mapping from each cell coordinate to its island's identifier and size. Mark visited cells with value 2 to avoid revisiting.

**Phase 2 - Evaluate Flips:** For each cell containing a 0, examine its four neighbors to see which distinct islands they belong to (using a set to avoid counting the same island multiple times). Sum the sizes of these neighboring islands plus 1 (for the flipped cell itself) to calculate the potential new island size. Track the maximum across all possible flips.

The algorithm also tracks the current maximum island size during phase 1 to handle the case where no flip improves the result (e.g., when the grid is already entirely 1s).

## Complexity

- **Time:** O(n²)
- **Space:** O(n²)

## Stats

- Submitted: 2025-09-08 08:10 UTC
- Runtime: 521 ms
- Memory: 147.3 MB
- Language: C++
