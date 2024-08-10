# Group By

**Difficulty:** Medium
**Tags:** array, prototype, hash-table, reduce

## Problem

Extend the Array prototype with a groupBy method that takes a callback function and returns an object where keys are the results of applying the callback to each array element, and values are arrays of all elements that produced that key. The callback always returns a string key, and the grouped values must preserve their original order from the input array.

## Approach

The solution uses the `reduce` method to iterate through the array and build up a result object. For each element, it applies the callback function to generate a string key. If that key doesn't yet exist in the accumulator object, it initializes an empty array for it. Then it appends the current element to the array associated with that key. The accumulator object is returned at each step and becomes the final grouped result after processing all elements.

## Complexity

- **Time:** O(n)
- **Space:** O(n)

## Stats

- Submitted: 2024-08-10 21:45 UTC
- Runtime: 128 ms
- Memory: 73.2 MB
- Language: JavaScript
