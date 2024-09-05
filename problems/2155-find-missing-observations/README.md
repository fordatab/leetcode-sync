# Find Missing Observations

**Difficulty:** Medium
**Tags:** math, array, greedy, simulation

## Problem

Given observations of m six-sided dice rolls and knowing that n rolls are missing, determine what the n missing rolls could be such that the average of all (n + m) rolls equals a given mean value. Each die shows a value between 1 and 6. If no valid set of missing rolls exists, return an empty array.

## Approach

The solution first calculates the total sum needed for all (n + m) rolls by multiplying the mean by the total count. It then subtracts the sum of the observed rolls to find what the missing n rolls must sum to.

Next, it validates feasibility: the required sum must be at least n (all dice showing 1) and at most 6n (all dice showing 6). If this constraint isn't met, an empty array is returned.

To construct the result, it initializes an array of n zeros and distributes the required sum one unit at a time in a round-robin fashion across all positions. This continues until the entire sum is distributed, ensuring each die value stays within the valid range [1, 6].

## Complexity

- **Time:** O(m + sum)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-05 23:40 UTC
- Runtime: 92 ms
- Memory: 116.3 MB
- Language: C++
