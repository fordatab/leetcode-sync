# Filter Elements from Array

**Difficulty:** Easy
**Tags:** array, two-pointers, in-place-algorithm

## Problem

Given an integer array and a filtering function that takes an element and its index, return a new array containing only elements for which the function returns a truthy value. The solution must be implemented without using JavaScript's built-in Array.filter method. The array can have up to 1000 elements with values ranging from -10^9 to 10^9.

## Approach

The solution implements an in-place filtering algorithm using a two-pointer technique. It maintains a `filteredIndex` pointer that tracks the next position where a filtered element should be placed. As it iterates through the array with index `i`, whenever the filtering function returns truthy for `arr[i]`, it swaps that element to position `filteredIndex` (if they're different positions) and increments `filteredIndex`. This effectively partitions the array so all elements passing the filter are moved to the front. After the loop completes, it truncates the array to length `filteredIndex`, removing all elements that didn't pass the filter. The function modifies and returns the original array rather than creating a new one.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-08-10 21:53 UTC
- Runtime: 46 ms
- Memory: 49.1 MB
- Language: JavaScript
