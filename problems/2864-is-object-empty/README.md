# Is Object Empty

**Difficulty:** Easy
**Tags:** object-iteration, early-termination, javascript

## Problem

Given either a JavaScript object or array (assumed to be valid JSON), determine whether it contains any elements. An object is empty if it has no key-value pairs, and an array is empty if it has no elements. The input's serialized length can be up to 100,000 characters.

## Approach

The solution uses a `for...in` loop to iterate over the enumerable properties of the input. In JavaScript, `for...in` works for both objects (iterating over keys) and arrays (iterating over indices). The key insight is that we don't need to count all properties — we only need to know if at least one exists. The loop attempts to iterate once; if any property exists, it immediately returns `false`. If the loop completes without finding any properties (meaning the object/array is empty), it returns `true`. This achieves O(1) time complexity because we exit on the first property found rather than examining all properties.

## Complexity

- **Time:** O(1)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-24 00:39 UTC
- Runtime: 51 ms
- Memory: 49.5 MB
- Language: JavaScript
