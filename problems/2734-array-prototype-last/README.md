# Array Prototype Last

**Difficulty:** Easy
**Tags:** array, prototype, javascript

## Problem

Extend the JavaScript Array prototype with a last() method that returns the final element of an array, or -1 if the array is empty. The input arrays are valid JSON arrays with lengths from 0 to 1000 elements.

## Approach

The solution adds a `last` method to `Array.prototype`, making it available on all array instances. The method uses a ternary operator to check the array's length: if the length is truthy (non-zero), it accesses the element at index `this.length - 1` to retrieve the last element; otherwise, it returns -1 for empty arrays. This approach leverages JavaScript's zero-based indexing where the last element is always at position length minus one.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:44 UTC
- Runtime: 49 ms
- Memory: 48.8 MB
- Language: JavaScript
