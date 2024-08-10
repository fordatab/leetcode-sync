# Apply Transform Over Each Element in Array

**Difficulty:** Easy
**Tags:** array, function, iteration

## Problem

Given an integer array and a transformation function, create a new array where each element is the result of applying the function to the corresponding element and its index from the original array. The solution must not use the built-in Array.map method, and the array can contain up to 1000 elements with values ranging from -10^9 to 10^9.

## Approach

The solution uses an in-place transformation approach with a simple for loop. It iterates through each index of the input array, applies the given function `fn` to the current element and its index, and directly overwrites the original array element with the result. After processing all elements, it returns the modified array. While the problem asks for a "new array," this implementation mutates the input array itself, which saves space but may have unintended side effects if the caller expects the original array to remain unchanged.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:42 UTC
- Runtime: 49 ms
- Memory: 48.7 MB
- Language: JavaScript
