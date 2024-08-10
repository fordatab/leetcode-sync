# Compact Object

**Difficulty:** Medium
**Tags:** recursion, depth-first-search, object-manipulation, array-filtering

## Problem

Given a JavaScript object or array (valid JSON output), remove all keys whose values are falsy (values where Boolean(value) returns false). This removal must happen recursively throughout the entire nested structure. Arrays are treated as objects with numeric indices as keys, and falsy values include null, 0, false, empty strings, undefined, and NaN.

## Approach

The solution uses recursive depth-first traversal to process the input structure. For arrays, it applies `filter(Boolean)` to remove falsy elements, then recursively processes remaining elements via `map(compactObject)`. For plain objects, it iterates through each key-value pair, recursively compacts the value, and only includes the key in the result if the compacted value is truthy. The base cases handle null (returns null), non-object primitives (returns as-is), ensuring the recursion terminates at leaf values. The critical insight is that filtering arrays and conditionally adding object properties based on truthiness naturally removes all falsy values while preserving the nested structure.

## Complexity

- **Time:** O(n)
- **Space:** O(d)

## Stats

- Submitted: 2024-08-10 21:54 UTC
- Runtime: 69 ms
- Memory: 59.7 MB
- Language: JavaScript
