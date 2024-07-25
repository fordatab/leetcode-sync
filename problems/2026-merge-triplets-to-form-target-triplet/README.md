# Merge Triplets to Form Target Triplet

**Difficulty:** Medium
**Tags:** greedy, hash-set, array

## Problem

Given a list of triplets (arrays of three integers) and a target triplet, determine whether the target can be formed by repeatedly merging pairs of triplets using an element-wise max operation. Each merge replaces one triplet with the component-wise maximum of itself and another triplet. The goal is to check if any sequence of such merges can produce the exact target triplet.

## Approach

The solution uses a greedy filtering strategy. It recognizes that any triplet with even one component exceeding the corresponding target value can never contribute to forming the target (since the max operation only increases values). Therefore, it first filters out all triplets where any element exceeds the target.

For the remaining valid triplets, it tracks which target positions can be matched. A hash set `g` records the indices (0, 1, or 2) where at least one valid triplet has a value equal to the corresponding target value.

The key insight is that if we can find valid triplets that collectively cover all three positions of the target (one triplet matching position 0, another matching position 1, and another matching position 2 — possibly with overlap), then merging these triplets will eventually produce the target. The solution returns true if all three positions are covered (set size equals 3).

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-25 01:18 UTC
- Runtime: 407 ms
- Memory: 167.6 MB
- Language: C++
