# Find the Middle Index in Array

**Difficulty:** Easy
**Tags:** prefix-sum, array, two-pointers

## Problem

Find the leftmost index in a zero-indexed integer array where the sum of all elements to its left equals the sum of all elements to its right. Elements at the boundaries have an implicit sum of zero on their empty side. The array has at most 100 elements with values ranging from -1000 to 1000.

## Approach

The solution uses a two-pointer technique with running sums to avoid repeatedly computing prefix and suffix sums. It initializes a left sum (`l`) to 0 and a right sum (`r`) to the total of all array elements. Then it iterates through the array from left to right: at each index, it first subtracts the current element from the right sum, checks if left equals right, and if so returns that index. If not, it adds the current element to the left sum and continues. This effectively maintains the invariant that `l` holds the sum of elements before the current index and `r` holds the sum after it. If no equilibrium index is found after checking all positions, it returns -1.

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

- Submitted: 2024-07-16 09:18 UTC
- Runtime: 0 ms
- Memory: 15.3 MB
- Language: C++
