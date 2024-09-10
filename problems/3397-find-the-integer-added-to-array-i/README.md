# Find the Integer Added to Array I

**Difficulty:** Easy
**Tags:** sorting, array, math

## Problem

Given two equal-length arrays, determine the constant integer that was added to every element of the first array to transform it into the second array. Both arrays contain the same integers with identical frequencies after this transformation. The arrays can have 1 to 100 elements, with values ranging from 0 to 1000, and a valid transformation integer is guaranteed to exist.

## Approach

The solution sorts both input arrays in ascending order, then returns the difference between the first elements of the sorted arrays. Since the same constant is added to every element of nums1 to produce nums2, and the arrays have identical frequencies after transformation, the minimum element of nums2 minus the minimum element of nums1 gives us this constant. Sorting ensures we're comparing corresponding elements (both minimums) from the two sets, which directly reveals the additive constant.

This works because if every element in nums1 is increased by x to produce nums2, then `nums1[i] + x = nums2[i]` for all corresponding positions after sorting. Therefore, `x = nums2[0] - nums1[0]` holds for any index, but using the first (minimum) elements after sorting is the simplest approach.

## Complexity

- **Time:** O(n log n)
- **Space:** O(log n)

## Stats

- Submitted: 2024-09-10 06:53 UTC
- Runtime: 7 ms
- Memory: 34.8 MB
- Language: C++
