# Maximum Sum With at Most K Elements

**Difficulty:** Medium
**Tags:** greedy, heap, sorting, priority-queue

## Problem

Given a 2D integer matrix, an array of row-wise limits, and a budget k, select at most k elements from the matrix to maximize their sum. Each row i can contribute at most limits[i] elements. The matrix dimensions can be up to 500×500, and element values can reach 10^5.

## Approach

The solution uses a greedy approach with a min-heap to track the k largest elements across all valid candidates.

First, each row is sorted in descending order to access the largest elements first. Then, for each row i, the solution considers the first limits[i] elements (which are now the largest in that row due to sorting).

A min-heap of size at most k maintains the k largest values seen so far. As each candidate element is encountered, it's added to the heap. If the heap exceeds size k, the smallest element is removed, ensuring only the k largest elements remain.

Finally, all elements in the heap are summed to produce the maximum achievable sum. This greedy strategy works because we always keep the globally k largest elements from the pool of row-constrained candidates.

## Complexity

- **Time:** O(n * m * log(n * m))
- **Space:** O(k)

## Stats

- Submitted: 2026-06-15 03:24 UTC
- Runtime: 225 ms
- Memory: 107.4 MB
- Language: C++
