# Smallest Number in Infinite Set

**Difficulty:** Medium
**Tags:** heap, priority-queue, design, greedy

## Problem

Design a data structure representing an infinite set of positive integers [1, 2, 3, ...] that supports removing the smallest element and adding previously removed elements back. The structure must efficiently track which numbers have been removed and allow re-insertion of any removed number up to 1000, with at most 1000 total operations.

## Approach

The solution maintains a pointer `curr` that tracks the smallest number never yet popped from the original sequence. It uses a min-heap (priority queue) to store any numbers smaller than `curr` that have been added back after being popped. A boolean array `contains` tracks which numbers are currently in the min-heap to prevent duplicates.

When `popSmallest()` is called, if the min-heap is empty, the code returns `curr` and increments it (meaning we're consuming from the original sequence). Otherwise, it pops and returns the minimum from the heap.

When `addBack(num)` is called, the code only adds `num` to the heap if it's smaller than `curr` (meaning it was previously popped) and isn't already in the heap (checked via the `contains` array). This ensures we only track previously-removed numbers that are candidates for being the next smallest element.

## Complexity

- **Time:** O(log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-25 06:59 UTC
- Runtime: 52 ms
- Memory: 41 MB
- Language: C++
