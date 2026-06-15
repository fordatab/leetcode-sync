# Maximum Sum With at Most K Elements

**Difficulty:** Medium
**Tags:** greedy, heap, sorting, priority-queue

## Problem

Given an n×m grid of integers, an array of per-row limits, and a budget k, select at most k elements such that no more than limits[i] elements come from row i. The goal is to maximize the sum of the selected elements.

## Approach

The solution uses a greedy selection strategy combined with a min-heap to track the top k candidates.

First, each row is sorted in descending order so that the largest elements appear first. Then, for each row i, the algorithm considers up to limits[i] elements (the largest ones available in that row) and pushes them into a min-heap.

The min-heap maintains at most k elements at any time. Whenever the heap size exceeds k, the smallest element is removed. This ensures that only the k largest elements encountered so far remain in the heap.

Finally, all elements remaining in the heap are summed to produce the maximum possible sum. This greedy approach works because sorting each row and using a min-heap guarantees we keep the globally largest k elements while respecting the per-row limits.

## Complexity

- **Time:** O(n*m*log(m) + n*m*log(k))
- **Space:** O(k)

## Stats

- Submitted: 2026-06-15 03:24 UTC
- Runtime: 225 ms
- Memory: 107.4 MB
- Language: C++
