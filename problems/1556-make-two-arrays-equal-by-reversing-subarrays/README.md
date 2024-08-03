# Make Two Arrays Equal by Reversing Subarrays

**Difficulty:** Easy
**Tags:** sorting, array, greedy

## Problem

Given two integer arrays of equal length, determine whether one array can be transformed into the other through any number of subarray reversal operations. The arrays have lengths between 1 and 1000, with element values ranging from 1 to 1000. The key insight is recognizing what invariant property is preserved across all possible reversal operations.

## Approach

The solution recognizes that reversing subarrays is a rearrangement operation that can achieve any permutation of elements. Therefore, two arrays can be made equal through reversals if and only if they contain the same multiset of elements.

The code sorts both input arrays in place using the standard library sort function. After sorting, if both arrays contain the same elements with the same frequencies, the sorted versions will be identical.

Finally, it performs a direct equality comparison between the sorted arrays. If they match element-by-element, the original arrays could be made equal through reversals; otherwise, they cannot.

## Complexity

- **Time:** O(n log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-08-03 01:27 UTC
- Runtime: 7 ms
- Memory: 17.5 MB
- Language: C++
