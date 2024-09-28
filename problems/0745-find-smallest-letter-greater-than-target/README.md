# Find Smallest Letter Greater Than Target

**Difficulty:** Easy
**Tags:** binary-search, array

## Problem

Given a sorted array of lowercase letters and a target character, find the smallest letter in the array that is strictly greater than the target. The array is guaranteed to be sorted in non-decreasing order and contains at least two distinct characters. If no such letter exists (i.e., the target is greater than or equal to all letters in the array), return the first letter in the array, creating a wraparound effect.

## Approach

The solution uses binary search to efficiently locate the smallest letter greater than the target. It maintains two pointers, `l` and `r`, representing the search boundaries. During each iteration, it calculates the middle index and compares the middle element with the target:

- If `letters[mid] > target`, the answer could be at `mid` or to its left, so it moves `r` to `mid`.
- If `letters[mid] <= target`, the answer must be to the right, so it moves `l` to `mid + 1`.

The loop terminates when `l` and `r` converge. After the loop, there's a special case check: if `l` points to the last element and that element is less than or equal to the target, it means no valid answer exists in the array, so it returns `letters[0]` (the wraparound case). Otherwise, it returns `letters[l]`, which is the smallest letter greater than the target.

## Complexity

- **Time:** O(log n)
- **Space:** O(1)

## Stats

- Submitted: 2024-09-28 06:43 UTC
- Runtime: 16 ms
- Memory: 19.8 MB
- Language: C++
