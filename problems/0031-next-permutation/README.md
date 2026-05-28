# Next Permutation

**Difficulty:** Medium
<<<<<<< HEAD
**Tags:** array, two-pointers, greedy, permutation

## Problem

Given an array of integers, rearrange it in-place to produce the next lexicographically larger permutation. If the array is already the largest permutation (descending order), wrap around to the smallest permutation (ascending order). The solution must use constant extra space and modify the array directly.

## Approach

The solution implements the standard next permutation algorithm with a three-step process:

1. **Find the pivot**: Scan from right to left to find the longest non-increasing suffix. The element just before this suffix (at index `i-1`) is the pivot—the rightmost position where we can make a lexicographically larger change.

2. **Handle edge case**: If no such pivot exists (the entire array is non-increasing), we've reached the last permutation, so reverse the entire array to get the smallest permutation.

3. **Swap and reverse**: Find the smallest element in the suffix that is larger than the pivot (scanning from the right), swap it with the pivot, then reverse the suffix to get the next smallest lexicographic arrangement.

This approach works because the suffix is always in descending order, making the rightmost swap candidate easy to find and ensuring the reversal produces the minimal arrangement for that prefix.
=======
**Tags:** array, two-pointers, greedy, in-place

## Problem

Given an array of integers, rearrange it in-place to produce the next lexicographically larger permutation. If the array is already in descending order (the largest permutation), wrap around to the smallest permutation by sorting it in ascending order. The solution must use only constant extra space and modify the array directly.

## Approach

The algorithm finds the next permutation by identifying the rightmost position where the sequence can be increased. It scans from right to left to find the first element (`nums[i]`) that is smaller than its right neighbor, marking the pivot point. If no such element exists, the array is already the largest permutation, so the entire array is reversed to get the smallest permutation.

Once the pivot is found, the algorithm searches from the right end again to find the smallest element larger than `nums[i]` (call it `nums[j]`). These two elements are swapped, ensuring the position `i` now holds a larger value.

After the swap, all elements to the right of position `i` are in descending order (by the nature of how we found `i`). The final step reverses this suffix to transform it into ascending order, producing the lexicographically smallest arrangement for that tail and thus the next permutation overall.
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d

## Complexity

- **Time:** O(n)
- **Space:** O(1)

## Stats

<<<<<<< HEAD
- Submitted: 2024-09-16 05:53 UTC
- Runtime: 0 ms
- Memory: 14.9 MB
=======
- Submitted: 2026-04-21 20:27 UTC
- Runtime: 0 ms
- Memory: 15.6 MB
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
- Language: C++
