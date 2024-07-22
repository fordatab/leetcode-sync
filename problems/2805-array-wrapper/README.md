# Array Wrapper

**Difficulty:** Easy
**Tags:** object-oriented-design, operator-overloading, array, prototype-methods

## Problem

Design a class that wraps an array of integers and supports two operations: when two instances are added with the + operator, return the sum of all elements from both arrays; when converted to a string, return the array formatted as bracket-enclosed, comma-separated values. The input arrays can contain 0 to 1000 integers, each in the range 0 to 1000.

## Approach

The solution implements an `ArrayWrapper` class that stores the input array and defines two prototype methods to customize JavaScript's type coercion behavior.

The `valueOf` method is defined on the prototype to handle numeric coercion. When the + operator is used, JavaScript calls `valueOf` on each operand. This method uses `reduce` to sum all elements in the wrapped array, starting from 0.

The `toString` method handles string coercion. When `String()` is called on an instance, this method formats the array by joining elements with commas and wrapping the result in square brackets using a template string.

By overriding these two built-in conversion methods, the class seamlessly integrates with JavaScript's operators while maintaining encapsulation of the underlying array.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-07-22 22:09 UTC
- Runtime: 60 ms
- Memory: 50.6 MB
- Language: JavaScript
