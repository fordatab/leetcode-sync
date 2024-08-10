# Function Composition

**Difficulty:** Easy
**Tags:** function-composition, higher-order-functions, array-iteration

## Problem

Given an array of functions, return a new function that represents their composition, where the rightmost function is applied first and each subsequent function is applied to the result of the previous one. The input value x ranges from -1000 to 1000, and the array can contain 0 to 1000 functions. An empty array should return the identity function that simply returns its input unchanged.

## Approach

The solution handles two cases: when the functions array is empty, it returns the identity function that passes through its input unchanged. For non-empty arrays, it returns a function that iterates through the functions array from right to left (starting at the last index and decrementing to 0), progressively applying each function to the accumulated result. The iteration begins with the input value x, then each function transforms the current result, which becomes the input for the next function in the chain. This right-to-left traversal naturally implements function composition where f(g(h(x))) means h is applied first, then g, then f.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 07:08 UTC
- Runtime: 63 ms
- Memory: 50.1 MB
- Language: JavaScript
