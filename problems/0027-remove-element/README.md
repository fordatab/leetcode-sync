# Remove Element

**Difficulty:** Easy
**Tags:** two-pointers, array, in-place

## Problem

Given an array of integers and a target value, modify the array in-place so that all elements not equal to the target are moved to the front, and return the count of such elements. The array can have up to 100 elements with values from 0 to 50, and the order of remaining elements doesn't matter.

## Approach

The solution uses a two-pointer technique to partition the array. A read pointer (`r`) scans through every element from left to right, while a write pointer (`l`) tracks where the next non-target element should be placed. When the read pointer encounters an element equal to `val`, it increments a counter (`c`) and moves on. When it finds an element not equal to `val`, that element is copied to the position indicated by the write pointer, and the write pointer advances. This effectively overwrites target values with subsequent non-target values, consolidating all keeper elements at the front of the array. The function returns the total length minus the count of removed elements.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-16 05:33 UTC
- Runtime: 4 ms
- Memory: 10.5 MB
- Language: C++
