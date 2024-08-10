# Sort By

**Difficulty:** Easy
**Tags:** sorting, array, custom-comparator, higher-order-function

## Problem

Given an array and a function that maps each element to a numeric value, return the array sorted in ascending order based on those numeric values. The function is guaranteed to produce unique numbers for each element in the array, and the array can contain any valid JSON values (primitives, objects, or arrays).

## Approach

The solution uses JavaScript's built-in `Array.prototype.sort()` method with a custom comparator function. The comparator takes two elements `a` and `b`, applies the provided function `fn` to each, and returns the difference `fn(a) - fn(b)`. This difference determines the sort order: a negative value places `a` before `b`, a positive value places `b` before `a`, and zero keeps them in their current relative positions. Since the sort is done in-place and the sorted array is returned, this provides a straightforward one-line solution that leverages JavaScript's native sorting capabilities.

## Complexity

- **Time:** O(n log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-10 21:39 UTC
- Runtime: 132 ms
- Memory: 66.5 MB
- Language: JavaScript
