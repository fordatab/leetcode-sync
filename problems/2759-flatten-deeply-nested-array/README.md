# Flatten Deeply Nested Array

**Difficulty:** Medium
**Tags:** array, stack, iteration, depth-first-traversal

## Problem

Given a nested array and a depth limit n, flatten the array up to n levels deep. Elements at depth less than n should have their immediate sub-arrays unwrapped and their contents placed at the current level, while sub-arrays at depth n or greater remain unchanged. The solution must be implemented without using the built-in Array.flat method.

## Approach

The solution uses an iterative stack-based approach to avoid recursion. Each element is paired with its remaining flattening depth and pushed onto a stack. The algorithm processes items from the stack: if an item is an array and its depth counter is positive, the array's elements are pushed back onto the stack with decremented depth counters; otherwise, the item (whether a primitive or an array that has reached its depth limit) is added to the result array. Since stack operations process items in reverse order, the final result is reversed to restore the original left-to-right ordering of elements.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 21:49 UTC
- Runtime: 143 ms
- Memory: 84.1 MB
- Language: JavaScript
