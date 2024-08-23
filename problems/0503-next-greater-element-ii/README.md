# Next Greater Element II

**Difficulty:** Medium
**Tags:** stack, monotonic-stack, array, circular-array

## Problem

Given a circular array of integers where the last element wraps around to the first, find the next greater element for each position. For each element, locate the first value greater than it by searching forward in circular order. If no such element exists, return -1 for that position. The array can have up to 10,000 elements with values ranging from -10^9 to 10^9.

## Approach

The solution uses a monotonic decreasing stack to track indices of elements waiting to find their next greater element. It simulates the circular nature by iterating through the array twice (2*n iterations), using modulo arithmetic to wrap indices. During each iteration, it compares the current element with elements whose indices are stored in the stack. When a greater element is found, it pops the stack and records the answer for those indices. Crucially, indices are only pushed onto the stack during the first pass (i < n) to avoid duplicates, while the second pass allows elements from the first half to find their next greater elements that appear later in the circular traversal.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-23 03:03 UTC
- Runtime: 25 ms
- Memory: 26.7 MB
- Language: C++
