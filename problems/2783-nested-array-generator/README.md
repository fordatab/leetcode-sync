# Nested Array Generator

**Difficulty:** Medium
**Tags:** generator, recursion, depth-first-search, tree-traversal

## Problem

Given a nested array structure containing integers and other arrays of arbitrary depth, implement a generator that yields all integers in the order they appear when traversing left to right. The array can be up to 10^5 elements when flattened and nested up to 10^5 levels deep. The challenge asks to avoid creating a flattened copy of the entire structure.

## Approach

The solution uses a recursive generator function that processes elements one at a time. For each element in the input array, it checks whether the element is itself an array using `Array.isArray()`. If the element is an array, it recursively calls `inorderTraversal` on that nested array and uses `yield*` to delegate to the recursive generator, which yields all values from the nested structure. If the element is not an array (i.e., it's an integer), it directly yields that value. This approach naturally handles arbitrary nesting depth through recursion and avoids materializing a flattened array in memory, instead yielding values on-demand as the generator is consumed.

## Complexity

- **Time:** O(n)
- **Space:** O(d)

## Stats

- Submitted: 2024-08-10 21:43 UTC
- Runtime: 190 ms
- Memory: 80.8 MB
- Language: JavaScript
