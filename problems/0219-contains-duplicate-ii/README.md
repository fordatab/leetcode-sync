# Contains Duplicate II

**Difficulty:** Easy
**Tags:** sliding-window, hash-table, array

## Problem

Given an array of integers and a distance threshold k, determine whether any two identical values exist at positions whose indices differ by at most k. The array can contain up to 100,000 elements with values ranging from -10^9 to 10^9, and k can be up to 100,000.

## Approach

This solution uses a sliding window technique with a hash set to track elements within a window of size k+1. The algorithm maintains two pointers (l and r) where r iterates through the array from left to right. Before checking each element, if the window size exceeds k (when r - l > k), the leftmost element is removed from the set and the left pointer advances. For each element at position r, the code checks if it already exists in the set — if so, we've found a duplicate within the allowed distance and return true. Otherwise, the element is added to the set. If the entire array is processed without finding nearby duplicates, the function returns false. The set effectively maintains a sliding window of at most k+1 consecutive elements, ensuring any duplicate found satisfies the distance constraint.

## Complexity

- **Time:** O(n)
- **Space:** O(min(n, k))

## Stats

- Submitted: 2024-08-31 04:25 UTC
- Runtime: 128 ms
- Memory: 76.2 MB
- Language: C++
