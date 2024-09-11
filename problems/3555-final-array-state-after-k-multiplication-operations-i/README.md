# Final Array State After K Multiplication Operations I

**Difficulty:** Easy
**Tags:** heap, priority-queue, simulation, greedy

## Problem

Given an integer array, perform k operations where each operation finds the smallest element (with ties broken by earliest index), multiplies it by a given multiplier, and replaces it in the array. Return the final state of the array after all k operations. The array has at most 100 elements with values up to 100, k is at most 10, and the multiplier is at most 5.

## Approach

The solution uses a min-heap (priority queue) to efficiently track and retrieve the minimum element. Initially, all elements are pushed into the heap as pairs of (value, index), where the heap orders primarily by value and secondarily by index to handle tie-breaking.

For each of the k operations, the solution:
1. Extracts the top element (minimum value with smallest index)
2. Multiplies its value by the multiplier
3. Pushes the updated (value, index) pair back into the heap

After all k operations, the solution reconstructs the result array by extracting all elements from the heap and placing them at their original indices. The heap automatically maintains the min-element property and handles tie-breaking through the pair comparison, where pairs are compared lexicographically (value first, then index).

## Complexity

- **Time:** O((n + k) log n)
- **Space:** O(n)

## Stats

- Submitted: 2024-09-11 00:40 UTC
- Runtime: 4 ms
- Memory: 28.1 MB
- Language: C++
