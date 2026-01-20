# Tallest Billboard

**Difficulty:** Hard
**Tags:** meet-in-the-middle, dynamic-programming, hash-table, subset-sum

## Problem

Given an array of rod lengths, partition the rods into two disjoint groups such that both groups have equal total length. Return the maximum possible equal length achievable, or 0 if no valid partition exists. Constraints include at most 20 rods with individual lengths up to 1000 and total sum at most 5000.

## Approach

The solution uses a meet-in-the-middle technique to avoid exponential blowup. It splits the rods array roughly in half and processes each half independently.

For each half, the `helper` function generates all possible states by iterating through rods and maintaining pairs (left_sum, right_sum) representing allocations to two supports. These states are stored in a set to avoid duplicates.

The helper then converts these state pairs into a map where the key is the difference (left - right) and the value is the maximum left sum achievable for that difference. This compression is crucial for efficiency.

Finally, the main function merges results from both halves by looking for complementary differences: if the first half has difference `d` with left sum `L1`, and the second half has difference `-d` with left sum `L2`, then combining them yields equal supports of height `L1 + L2`. The maximum such height is returned.

## Complexity

- **Time:** O(3^(n/2) * n)
- **Space:** O(3^(n/2))

## Stats

- Submitted: 2026-01-20 04:47 UTC
- Runtime: 1012 ms
- Memory: 227.5 MB
- Language: C++
